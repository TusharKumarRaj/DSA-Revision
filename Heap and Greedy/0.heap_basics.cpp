# HEAP BASICS (C++)

// What is a Heap?

// A Heap is a complete binary tree that follows a specific ordering property called Heap Property.

// There are two types of heaps:
// 1. Max Heap - Parent is always greater than or equal to its children. Largest element stays at the top.
// 2. Min Heap - Parent is always smaller than or equal to its children. Smallest element stays at the top.

// IMPORTANT -
// A heap is NOT a sorted binary tree.
// Only parent-child ordering is guaranteed.
// Left and right children don't have a fixed ordering.
// A heap is a complete binary tree (all levels are filled except possibly the last, which fills from left to right).


// 1. HOW TO DEFINE A HEAP?

// C++ provides a container adapter called priority_queue.

// By default, priority_queue implements a MAX HEAP.

// MAX HEAP:

priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top(); // 30

// MIN HEAP:

priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top(); // 10


// Remember:
// Max Heap - priority_queue<int> pq;
// Min Heap - priority_queue<int, vector<int>, greater<int>> pq;


// 2. UNDERSTANDING THE 3 PARAMETERS

// Syntax:
// priority_queue<DATA_TYPE, CONTAINER, COMPARATOR> pq;

// DATA_TYPE - Type of elements stored.
// CONTAINER - Underlying container (usually vector).
// COMPARATOR - Determines priority ordering.

// Example:
// priority_queue<int, vector<int>, greater<int>> pq;

// int - Stores integers.
// vector<int> - Uses a vector internally.
// greater<int> - Creates a min heap.

// By default, priority_queue uses vector internally and less as its comparator, giving us a max heap.


// 3. IMPORTANT HEAP OPERATIONS

// Insert - pq.push(x) - O(log n)
// Get top - pq.top() - O(1)
// Remove top - pq.pop() - O(log n)
// Check size - pq.size() - O(1)
// Check empty - pq.empty() - O(1)

// IMPORTANT -
// pq.pop() only removes the top element. It does NOT return it.

// To retrieve and remove:
// int x = pq.top();
// pq.pop();


// 4. HEAP WITH PAIRS

// We can also store pairs in a heap.

// MAX HEAP OF PAIRS:

priority_queue<pair<int,int>> pq;

// C++ compares pairs lexicographically:
// 1. First compares .first.
// 2. If .first is equal, compares .second.

// Example:
// pq.push({2, 3});
// pq.push({1, 5});
// pq.push({2, 1});
// pq.push({3, 0});

// Extraction order:
// {3, 0}
// {2, 3}
// {2, 1}
// {1, 5}

// MIN HEAP OF PAIRS:

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

// Extraction order:
// {1, 5}
// {2, 1}
// {2, 3}
// {3, 0}

// IMPORTANT -
// greater<pair<int,int>> compares both elements lexicographically.
// First compares .first, then .second if there is a tie.


// 5. MIN HEAP VS MAX HEAP - WHEN TO USE?

// Get largest element quickly - Max Heap.
// Get smallest element quickly - Min Heap.
// Find K largest elements - Min Heap of size K.
// Find K smallest elements - Max Heap of size K.
// Process elements in ascending order - Min Heap.
// Process elements in descending order - Max Heap.

// THE K ELEMENTS TRICK:

// Finding K smallest elements:
// Maintain a MAX HEAP of size K.
// The largest among the selected K stays at the top.
// If a smaller candidate arrives, remove the top element.

// Finding K largest elements:
// Maintain a MIN HEAP of size K.
// The smallest among the selected K stays at the top.
// If a larger candidate arrives, remove the top element.


// 6. HEAP VS SORTING

// Heap:
// Get minimum (min heap) - O(1).
// Get maximum (max heap) - O(1).
// Insert one element - O(log n).
// Get all elements in sorted order - O(n log n).

// Sorting:
// Sort N elements - O(n log n).
// Get minimum after sorting - O(1).
// Get maximum after sorting - O(1).

// Heap is useful when we repeatedly need the minimum or maximum element,
// or only need K elements rather than sorting everything.

// 7. COMPLEXITY CHEAT SHEET

// Insert one element - O(log n).
// Delete top element - O(log n).
// Access top element - O(1).
// Build heap using repeated insertion - O(n log n).
// Build heap using make_heap - O(n).
// Extract all N elements - O(n log n).

// SPACE COMPLEXITY:
// A heap containing N elements requires O(n) space.