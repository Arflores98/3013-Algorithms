# H02 Hashing - Ashley Flores
## Part A: Conceptual Questions:
### 1. Defining Hashing and Collision Resolution
* What is a hash table and why is collision resolution necessary?
  * A hash table is a data structure that stores key-value pairs and provides efficient lookup, insertion, and deletion operations. It uses a hash function to map keys to indices in an array, where the corresponding values are stored. Ideally, this allows for O(1) average-time complexity for these operations.
* Explain the key differences between open hashing (chaining) and closed hashing (open addressing).
  * Each index in the hash table stores a linked list (or another data structure like a BST).
  * When a collision occurs, the new key-value pair is added to the linked list at that index.
