#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SIZE 100
#define TABLE_SIZE 10
#define V 5

/* ---------------- Linked List ---------------- */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* ---------------- Stack ---------------- */
typedef struct
{
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int isEmptyStack(Stack *s) { return s->top == -1; }
int isFullStack(Stack *s) { return s->top == MAX - 1; }

void push(Stack *s, int val)
{
    if (!isFullStack(s))
        s->arr[++s->top] = val;
}

int pop(Stack *s)
{
    if (!isEmptyStack(s))
        return s->arr[s->top--];
    return -1;
}

/* ---------------- Queue ---------------- */
typedef struct
{
    int arr[SIZE];
    int front, rear, count;
} Queue;

void initQ(Queue *q) { q->front = q->rear = q->count = 0; }
int isEmptyQ(Queue *q) { return q->count == 0; }
int isFullQ(Queue *q) { return q->count == SIZE; }

void enqueue(Queue *q, int val)
{
    if (!isFullQ(q))
    {
        q->arr[q->rear] = val;
        q->rear = (q->rear + 1) % SIZE;
        q->count++;
    }
}

int dequeue(Queue *q)
{
    if (!isEmptyQ(q))
    {
        int val = q->arr[q->front];
        q->front = (q->front + 1) % SIZE;
        q->count--;
        return val;
    }
    return -1;
}

/* ---------------- Binary Tree ---------------- */
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createTreeNode(int data)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* ---------------- Hash Table ---------------- */
typedef struct Entry
{
    int key;
    int value;
    struct Entry *next;
} Entry;

Entry *table[TABLE_SIZE];

int hash(int key) { return key % TABLE_SIZE; }

void insertHash(int key, int value)
{
    int h = hash(key);
    Entry *newEntry = malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = table[h];
    table[h] = newEntry;
}

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

/* ---------------- Graph ---------------- */
typedef struct GNode
{
    int vertex;
    struct GNode *next;
} GNode;

typedef struct
{
    GNode *adj[V];
} Graph;

GNode *createGNode(int v)
{
    GNode *node = malloc(sizeof(GNode));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void initGraph(Graph *g)
{
    for (int i = 0; i < V; i++)
        g->adj[i] = NULL;
}

void addEdge(Graph *g, int src, int dest)
{
    GNode *node = createGNode(dest);
    node->next = g->adj[src];
    g->adj[src] = node;
    node = createGNode(src);
    node->next = g->adj[dest];
    g->adj[dest] = node;
}

void printGraph(Graph *g)
{
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d:", i);
        GNode *temp = g->adj[i];
        while (temp)
        {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* ---------------- Main Demo ---------------- */
int main()
{
    printf("=== Linked List ===\n");
    Node *head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    printList(head);

    printf("\n=== Stack ===\n");
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    printf("Pop: %d\n", pop(&s));

    printf("\n=== Queue ===\n");
    Queue q;
    initQ(&q);
    enqueue(&q, 5);
    enqueue(&q, 15);
    printf("Dequeue: %d\n", dequeue(&q));

    printf("\n=== Binary Tree ===\n");
    TreeNode *root = createTreeNode(50);
    root->left = createTreeNode(30);
    root->right = createTreeNode(70);
    inorder(root);
    printf("\n");

    printf("\n=== Hash Table ===\n");
    insertHash(1, 100);
    insertHash(11, 200);
    Entry *e = searchHash(11);
    if (e)
        printf("Found key 11 with value %d\n", e->value);

    printf("\n=== Graph ===\n");
    Graph g;
    initGraph(&g);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 2);
    printGraph(&g);

    return 0;
}