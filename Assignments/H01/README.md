# H01 - AVL Tree Graphs
## Set 1: Left-Right and Right-Left Rotations
### Description:
In this set, we will insert the values 10, 20, 30, 15, 25, 5, 35, 27 sequentially into an AVL Tree and perform rotations when necessary to maintain balance. We will identify where single rotations (LL or RR) and double rotations (LR or RL) occur.

|#|File|Description|
|---|---|---|
|1| [Set 1 Graph](Assignments/H01/AVL.drawio.png) |Set 1: AVL Graph|
|2| [Set 2 Graph](Assignments/H01/AVL2.drawio.png) |Set 2: AVL Graph|

### Steps
1. Insert 10
2. Insert 20, balance Factor of 10 = -1 (Right-heavy), No rotation needed
3. Insert 30, balance Factor of 20 = -1 (Right-heavy),
   * Balance Factor of 10 = -2 (Right-heavy),
   * RR imbalance, Left Rotation on 10
5. Insert 15, balance Factor of 20 = 1 (Left-heavy), No rotation needed
6. Insert 25, balance Factor of 30 = 1 (Left-heavy), No rotation needed
7. Insert 5, balance Factor of 10 = 0, No rotation needed
8. Insert 35, balance Factor of 30 = 0, No rotation needed
9. Insert 27, balance Factor of 25 = -1 (Right-heavy), No rotation needed
    * Balance Factor of 30 = 1 (Left-heavy), No rotation needed
    * Balance Factor of 20 = -1 (Right-heavy), No rotation needed

<img src=https://github.com/Arflores98/3013-Algorithms/blob/main/Assignments/H01/AVL.drawio.png>

## Set 2: Multiple Rotations in Different Branches
### Description:
In this set, we will insert the values 50, 40, 45, 60, 55, 70, 35, 30, 65, 75, 43 sequentially into an AVL Tree and perform rotations when necessary to maintain balance. We will identify where single rotations (LL or RR) and double rotations (LR or RL) occur.

### Steps
Steps are in the diagrams below

<img src=https://github.com/Arflores98/3013-Algorithms/blob/main/Assignments/H01/AVL2.drawio.png>
