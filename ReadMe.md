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

## Expected output

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

## View the documentation as a website

- [Data Structures Documentation Website Link](https://lewis-2000.github.io/DataStructures/)

## Repository

Find the full source code here

- [GitHub Repository](https://github.com/lewis-2000/DataStructures.git)
