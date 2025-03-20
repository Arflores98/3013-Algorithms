# H02 Hashing - Ashley Flores
## Part A: Conceptual Questions:
## 1. Defining Hashing and Collision Resolution
### What is a hash table and why is collision resolution necessary?
  * A hash table is a data structure that stores key-value pairs and provides efficient lookup, insertion, and deletion operations. It uses a hash function to map keys to indices in an array, where the corresponding values are stored. Ideally, this allows for O(1) average-time complexity for these operations.
### Explain the key differences between open hashing (chaining) and closed hashing (open addressing).
Open Hashing:
  * Instead of storing multiple elements in a single index, it searches for the next available slot within the table itself.
  * Common techniques:
    * **Linear Probing:** Search for the next available slot sequentially.
    * **Quadratic Probing:** Use a quadratic function to find an open slot.
    * **Double Hashing:** Use a secondary hash function to determine the probing sequence.
      
 Closed Hashing:
  * Each index in the hash table stores a linked list (or another data structure like a BST).
  * When a collision occurs, the new key-value pair is added to the linked list at that index.

|Feature|Open Addressing|Closed Addressing|
|----|------|------|
|Handling Collisions|Searches for an open slot in the table|Stores multiple elements at the same index|
|Performance at High Load|Degrades significantley (~70% full or more)|Stays efficient|
|Memory Usage|Uses only array (compact)|Requires extra memory for chains|
|Storage Method|Stores everything in the main table|Uses Linked lists (or BST) at each index)|
|Best for|Low-load tables, fast lookups|Large datasets, frequent inserts/deletes|
