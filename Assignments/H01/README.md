# H01 - AVL Tree Graphs
### Description:
In this set, we will insert the values 10, 20, 30, 15, 25, 5, 35, 27 sequentially into an AVL Tree and perform rotations when necessary to maintain balance. We will identify where single rotations (LL or RR) and double rotations (LR or RL) occur.

|#|File|Description|
|---|---|---|
|1| [Set 1 Graph](Assignments/H01/AVL.drawio.png) |Set 1: AVL Graph|

### Steps
1. Insert 10
2. Insert 20, balance Factor of 10 = -1 (Right-heavy), No rotation needed
3. Insert 30, balance Factor of 10 = -2 (Right-heavy), Balance Factor of 20 = -1 (Right-heavy), RR imbalance, Left Rotation on 10
4. Insert 15, balance Factor of 20 = 1 (Left-heavy), No rotation needed
5. Insert 25, balance Factor of 30 = 1 (Left-heavy), No rotation needed
6. Insert 5, balance Factor of 10 = 1 (Left-heavy), No rotation needed
7. Insert 35, balance Factor of 30 = 0, No rotation needed
8. Insert 27, balance Factor of 30 = 1 (Left-heavy), No rotation needed


<img src=https://github.com/Arflores98/3013-Algorithms/blob/main/Assignments/H01/AVL.drawio.png>
