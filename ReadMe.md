# Data Structures in C

This repository contains implementations of fundamental data structures in C:

- Linked List
- Stack
- Queue
- Binary Tree
- Hash Table
- Graph

Each structure is demonstrated in a single file (`DataStructuresExample.c`) with example usage in `main()`.

---

## Getting Started

### Prerequisites

- GCC or any C compiler
- A terminal or command prompt

### Compilation

```bash
gcc DataStructuresExample.c -o DataStructuresExample
```

### Running the Program

You’ll see outputs showcasing each data structure in action:

- Linked list traversal
- Stack push/pop
- Queue enqueue/dequeue
- Binary tree inorder traversal
- Hash table insertion/search
- Graph adjacency list printing

```bash
DataStructuresExample.exe
```

### Expected output

```bash
$ ./DataStructuresExample.exe
=== Linked List ===
1 -> 2 -> 3 -> NULL

=== Stack ===
Pop: 20

=== Queue ===
Dequeue: 5

=== Binary Tree ===
30 50 70

=== Hash Table ===
Found key 11 with value 200

=== Graph ===
Vertex 0: 4 1
Vertex 1: 2 0
Vertex 2: 1
Vertex 3:
Vertex 4: 0
```

## Comprehensive Unit Notes

### Complexity and Performance Basics

- **Big O:** Upper bound of growth (worst-case trend)
- **Big Theta:** Tight bound (exact growth order)
- **Big Omega:** Lower bound (best-case trend)
- Typical ranking: `O(1) < O(log n) < O(n) < O(n log n) < O(n^2)`
- In practice, constants and memory overhead also affect performance.

### Linear vs Non-Linear Data Structures

- **Linear:** Elements follow a sequence (arrays, linked lists, stacks, queues)
- **Non-linear:** Hierarchical/network relationships (trees, graphs)
- Use linear structures for simple sequential processing.
- Use non-linear structures for hierarchical and relationship-heavy problems.

### Arrays

- Contiguous memory gives direct indexing in `O(1)`.
- Insertion/deletion in the middle usually costs `O(n)` due to shifting.
- Best when fast index-based lookup is required.

### Linked Lists

- Node-based structure with pointers, non-contiguous memory.
- Efficient insertion/deletion at known positions (`O(1)` pointer update).
- Sequential access/search costs `O(n)`.

### Stacks and Queues

- **Stack (LIFO):** push/pop at top, commonly `O(1)`.
- **Queue (FIFO):** enqueue/dequeue order, commonly `O(1)`.
- Stack use cases: recursion, undo/redo, expression evaluation.
- Queue use cases: scheduling, buffering, BFS traversal.

### Trees and BST

- Trees model hierarchy (file systems, XML/DOM, expression trees).
- Traversals: preorder, inorder, postorder.
- BST rule enables average `O(log n)` search if reasonably balanced.
- Skewed BST can degrade to `O(n)`.

### Hash Tables

- Hash function maps key to index for near-constant average lookup.
- Collision handling (like chaining) is essential.
- Average operations: `O(1)`; poor hashing/high load can approach `O(n)`.

### Graphs, BFS, DFS

- Graphs model pairwise relationships and network structures.
- **BFS:** level-order traversal using a queue.
- **DFS:** deep traversal using recursion/stack.
- Traversal complexity with adjacency list: `O(V + E)`.

### Searching and Sorting

- **Linear Search:** works on unsorted arrays, `O(n)`.
- **Binary Search:** sorted arrays only, `O(log n)`.
- **Bubble/Selection/Insertion:** easy to implement, typically `O(n^2)`.
- **Merge/Quick:** generally faster for large input, around `O(n log n)` average.

### Dynamic Programming vs Greedy

- **Greedy:** locally optimal choices; may fail globally.
- **DP:** stores subproblem answers to build global optimum.
- Coin change is a classic case where DP can outperform greedy correctness.

### Quick Selection Guide (Exam Revision)

- Need direct index access: choose array.
- Need frequent inserts/deletes: choose linked list.
- Need backtracking/undo: choose stack.
- Need fair processing order: choose queue.
- Need ordered hierarchy and search: choose BST/tree.
- Need key-value speed: choose hash table.
- Need relationship modeling: choose graph.

## Algorithm Notes (with clearly defined examples)

### 1) Linear Search

**Problem:** Find the position of a target value in an unsorted array.

**Input:** `arr = [7, 2, 9, 4]`, `target = 9`

**Output:** `index = 2`

```c
int linearSearch(int arr[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
			return i;
	}
	return -1;
}
```

**Time complexity:** `O(n)`

### 2) Binary Search (sorted array)

**Problem:** Search efficiently in a sorted array.

**Input:** `arr = [2, 4, 7, 9, 12, 18]`, `target = 12`

**Output:** `index = 4`

```c
int binarySearch(int arr[], int size, int target)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == target)
			return mid;
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}
```

**Time complexity:** `O(log n)`

### 3) Inorder Traversal (Binary Tree)

**Problem:** Visit tree nodes in `left -> root -> right` order.

**Input tree:**

```text
	50
   /  \
 30    70
```

**Output traversal:** `30 50 70`

```c
void inorder(TreeNode *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
```

**Time complexity:** `O(n)`

### 4) Hash Table Search (chaining)

**Problem:** Retrieve a value by key from a hash table.

**Input operations:**

- `insert(1, 100)`
- `insert(11, 200)`
- `search(11)`

**Output:** `Found key 11 with value 200`

```c
int hash(int key) { return key % TABLE_SIZE; }

Entry *searchHash(int key)
{
	int h = hash(key);
	Entry *e = table[h];
	while (e)
	{
		if (e->key == key)
			return e;
		e = e->next;
	}
	return NULL;
}
```

**Average time complexity:** `O(1)`
**Worst-case time complexity:** `O(n)`

### 5) Bubble Sort

**Problem:** Repeatedly swap adjacent elements if they are in the wrong order.

**Input:** `arr = [5, 1, 4, 2]`

**Output:** `arr = [1, 2, 4, 5]`

```c
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
```

**Time complexity:** `O(n^2)`

### 6) Selection Sort

**Problem:** For each position, find the minimum element from the unsorted part and place it at the front.

**Input:** `arr = [29, 10, 14, 37, 13]`

**Output:** `arr = [10, 13, 14, 29, 37]`

```c
void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}
```

**Time complexity:** `O(n^2)`

### 7) Insertion Sort

**Problem:** Build a sorted portion by inserting each new element into its correct position.

**Input:** `arr = [9, 5, 1, 4, 3]`

**Output:** `arr = [1, 3, 4, 5, 9]`

```c
void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
```

**Time complexity:** `O(n^2)`

## Unit Completion Pack

### 8) Sorting Comparison Matrix

| Algorithm      | Best       | Average    | Worst      | Stable | In-place |
| -------------- | ---------- | ---------- | ---------- | ------ | -------- |
| Bubble Sort    | O(n)       | O(n^2)     | O(n^2)     | Yes    | Yes      |
| Selection Sort | O(n^2)     | O(n^2)     | O(n^2)     | No     | Yes      |
| Insertion Sort | O(n)       | O(n^2)     | O(n^2)     | Yes    | Yes      |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | Yes    | No       |
| Quick Sort     | O(n log n) | O(n log n) | O(n^2)     | No     | Yes      |

### 9) BFS and DFS (Worked Graph Example)

**Graph (adjacency list):**

- `0: 1, 2`
- `1: 0, 3, 4`
- `2: 0, 5`
- `3: 1`
- `4: 1, 5`
- `5: 2, 4`

**Start vertex:** `0`

**BFS traversal:** `0 1 2 3 4 5`

**DFS traversal (one valid order):** `0 1 3 4 5 2`

```c
void bfs(int graph[6][6], int start)
{
	int visited[6] = {0};
	int queue[6], front = 0, rear = 0;

	visited[start] = 1;
	queue[rear++] = start;

	while (front < rear)
	{
		int u = queue[front++];
		printf("%d ", u);

		for (int v = 0; v < 6; v++)
		{
			if (graph[u][v] && !visited[v])
			{
				visited[v] = 1;
				queue[rear++] = v;
			}
		}
	}
}
```

**Complexity:** `O(V + E)` for adjacency list representation.

### 10) Binary Search Tree (Insert/Search/Delete)

**BST property:** Left subtree values are smaller, right subtree values are larger.

**Example inserts:** `50, 30, 70, 20, 40, 60, 80`

**Example search:** `search(60)` -> `found`

```c
TreeNode *searchBST(TreeNode *root, int key)
{
	if (root == NULL || root->data == key)
		return root;
	if (key < root->data)
		return searchBST(root->left, key);
	return searchBST(root->right, key);
}
```

**Complexity:**

- Average insert/search/delete: `O(log n)`
- Worst-case (skewed tree): `O(n)`

### 11) Dynamic Programming vs Greedy (Coin Change)

**Problem:** Make amount `6` using coins `[1, 3, 4]` with minimum number of coins.

**Greedy attempt:** `4 + 1 + 1` -> `3 coins` (not optimal)

**Optimal (DP):** `3 + 3` -> `2 coins`

```c
int minCoinsDP(int amount, int coins[], int m)
{
	int dp[100];
	dp[0] = 0;

	for (int i = 1; i <= amount; i++)
		dp[i] = 1000000;

	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
				dp[i] = dp[i - coins[j]] + 1;
		}
	}

	return dp[amount];
}
```

**Complexity:** `O(amount * number_of_coins)`

## View the documentation as a website

- [Data Structures Documentation Website Link](https://lewis-2000.github.io/DataStructures/)

## Repository

Find the full source code here

- [GitHub Repository](https://github.com/lewis-2000/DataStructures.git)
