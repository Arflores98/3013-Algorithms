#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Bst {
private:
    Node* root;
    void _insert(Node*& sub_root, int x) {
        if (sub_root == nullptr) {
            sub_root = new Node(x);
        }
        else {
            if (x < sub_root->data) {
                _insert(sub_root->left, x);
            }
            else {
                _insert(sub_root->right, x);
            }
        }
    }
    void _print(Node* root) {
        if (!root) {
            return;
        }
        _print(root->right);
        cout << root->data << " ";
        _print(root->left);
    }

    // Helper function to find the minimum value node
    Node* _findMin(Node* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }

    // Helper function to delete a node
    Node* _delete(Node* root, int x) {
        if (!root) {
            return root;
        }

        // Traverse the tree to find the node to delete
        if (x < root->data) {
            root->left = _delete(root->left, x);
        }
        else if (x > root->data) {
            root->right = _delete(root->right, x);
        }
        else {
            // Node with only one child or no child
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = _findMin(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = _delete(root->right, temp->data);
        }

        return root;
    }
public:
    Bst() { root = nullptr; }
    void insert(int x) {
        _insert(root, x);
    }
    void deleteNode(int x) {
        root = _delete(root, x);
    }

    //bool search() { return 0; }
    void print() { _print(root); }
};
int main()
{
    Bst tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(1);
    tree.insert(11);
    tree.insert(7);
    tree.insert(15);
    //for(int i=0;i<1000;i++){
    //tree.insert(rand()%1000);}
    //tree.print();

    cout << "Before deletion: ";
    tree.print();
    cout << endl;

    tree.deleteNode(3); // Deleting a node with one child
    cout << "After deleting 3: ";
    tree.print();
    cout << endl;

    tree.deleteNode(11); // Deleting a node with two children
    cout << "After deleting 11: ";
    tree.print();
    cout << endl;

    tree.deleteNode(7); // Deleting a leaf node
    cout << "After deleting 7: ";
    tree.print();
    cout << endl;
}
