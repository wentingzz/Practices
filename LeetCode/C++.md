# C++ Tips and Best Practices

This document contains various tips and best practices for optimizing your C++ code.

## Check if an Element Appears in a Data Structure

| Data Structure           | Insert Time Complexity | Lookup Time Complexity | Remove Time Complexity | Space Complexity | Best Usage Scenario                                                   |
|--------------------------|------------------------|------------------------|------------------------|------------------|-----------------------------------------------------------------------|
| **`unordered_set`**  | O(1) average, O(n) worst | O(1) average, O(n) worst | O(1) average, O(n) worst | O(n)             | When you need constant-time lookups, and the order of elements doesn't matter. |
| **`set`**            | O(log n)               | O(log n)               | O(log n)               | O(n)             | When you need ordered elements and logarithmic-time lookups are acceptable.    |
| **Sorted Array**          | O(n)                   | O(log n) (binary search) | O(n)                   | O(n)             | When you have a pre-sorted array and need binary search.                       |
| **`bitset`**         | O(1)                   | O(1)                   | O(1)                   | O(1) (for small ranges) | For small integer ranges with fast constant-time lookups.             |
| **`vector`**         | O(1) amortized         | O(n)                   | O(n)                   | O(n)             | When you have small data and prefer simplicity over performance.              |

---
- **Code**:
     ```cpp
     std::unordered_set<int> us = {1, 2, 3, 4, 5};
     us.insert(6); // Adding element 6
     if (s.find(3) != s.end()) std::cout << "Element found!" << std::endl;
     us.erase(3); 
     
     std::set<int> s = {1, 2, 3, 4, 5};
     s.insert(6); // Adding element 6
     if (s.find(3) != s.end())  std::cout << "Element found!" << std::endl;
     s.erase(3);
     
     std::vector<int> v = {1, 2, 3, 4, 5}; // Must be sorted
     v.push_back(6);
     if (std::binary_search(v.begin(), v.end(), 3))  std::cout << "Element found!" << std::endl;
     v.erase(std::remove(v.begin(), v.end(), 3), v.end());

     std::bitset<100> b;
     b[3] = 1; // Set bit 3 to represent number 3
     if (b[3]) std::cout << "Element found!" << std::endl;
     
     std::vector<int> v = {1, 2, 3, 4, 5};
     if (std::find(v.begin(), v.end(), 3) != v.end()) std::cout << "Element found!" << std::endl;
     b.reset(3); 
     ```

### Conclusion: Best Option Based on Needs

1. **If you need constant-time lookup and the order of elements doesn't matter**, go for `std::unordered_set` (hash table).
2. **If you need sorted elements and logarithmic time lookups**, use `std::set` or a sorted array with `std::binary_search`.
3. **If you're working with integers in a small, fixed range**, use `std::bitset` for O(1) lookups.
4. **If the data is small and you prefer simplicity**, a `std::vector` with linear search or `std::binary_search` (if sorted) might be good enough.

In most cases, for general-purpose fast lookups, **`std::unordered_set`** provides the best performance due to its average O(1) lookup time.
