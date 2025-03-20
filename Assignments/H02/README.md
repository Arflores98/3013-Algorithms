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

## 2. Collision Resolution Techniques
### Briefly describe at least two methods for resolving collisions in open addressing (e.g., linear probing, quadratic probing, double hashing).
1. **Linear Probing:** If collision occurs, check for the next available slot sequentially
2. **Quadratic Probing:** Uses a quadratic function (e.g. 1<sup>2</sup>, 2<sup>2</sup>, 3<sup>2</sup>, etc.) to find the next available slot.

### Explain the pros and cons of each method.
1. **Linear Probing**
   * Pros: Simple implementation, cache friendly.
   * Cons: Causes primary clustering (long groups of occupied slots), which slows down searches.
2. **Quadratic Probing**
   * Pros: Reduces clustering compared to Linear Probing.
   * Cons: Still susceptible to secondary clustering.

### Which collision resolution technique can handle more values than table slots. Explain.
**Chaining (Seperate Chaining - Closed Addressing)** Why?
 * It can handle more values than the number of table slots because it allows multiple elements to be stored at the same index using linked lists (or other data structures)
 * Since LL are *dynamically allocated*, they can grow as needed without being restricted by the number of table slots
 * The table slots doesn't impose a *hard limit* on the number of elements - only memory constraints do.

### What is the worst performance (big oh) for each type of collision resolution technique?
|Collision Resolution|Worst-time Complexity|Reason|Best when|
|---|---|---|---|
|Seperate Chaining (Linked List)|O(n)|All keys hash to the same bucket, forming a long chain|The hash function distributes keys well, keeping chains short|
|Seperate Chaining (BST)|O(log n)|A balanced BST is used instead of linked lists|"|
|Linear Probing|O(n)|Primary clsutering causes long search sequences|The table is kept less than 70% full to minimize clustering|
|Quadratic Probing|O(n)|Secondary clustering increases search time|A prime-sized table and a good hash function are used to reduce clustering|
|Double Hashing|O(n)|Poor secondary hash function can still lead to long searches|A good secondary hash function is used to minimize clustering|

## 3. Impact of Hash Table Size
The size determines how well the keys are distributed across the table. A *well-chosen* table size reduces collsions and improves performance, while a *poorly-chosen* table size can lead to clustering and inefficient lookups.
### How does the choice of table size affect the distribution of keys?
1. **Prime Number Table Size -> Better Distributions**
   * When the table size is a prime number, the hash function spreads keys more evenly, reducing clustering.
   * This is because **modulo operations** (`key % table_size`) distribute keys more uniformly when `table_size` has fewer divisors.
2. **Non-Prime Table Sizes -> Increased Collisions**
   * If the table has many factors, keys tend to collide more often because `key % table_size` maps multiple keys to the same few indices.

### What are the pitfalls of using a poor table size (for example, a table size that is a round number or a power of 2)?
1. **Power of 2 Table Size** (e.g., 16, 32, 64, etc.) **-> Poor Distribution**
   * Issue: The modulo (`key % table_size`) **ignores higher-order bits** of the key, leading to clustering.
   * Ex. Suppose `table_size = 16 (2^4)`. If keys are multiple of 16, they will all hash to index 0, causing clustering. Because `x % 16` will always be 0 for multiples of 16.
2. **Round Numbers (e.g., 100, 200, 500) -> Skewed Hashing**
   * Issue: Many real-world keys (ex. timestamps, IDs, generated numbers) follow patterns that align with round numbers
   * Ex. If a hash table is size 100, keys that are multiples of 100 will hash index 0, leading to clustering
   * Many poor hash functions also amplify this issue by producing periodic hash values.
  
## Part B: Simulation and Diagram Exercises
