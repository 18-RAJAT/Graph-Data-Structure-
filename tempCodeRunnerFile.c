#include <stdio.h>
#include <stdlib.h>

// Heap :consist of a pointer to the array and variable size which will tell the size of the array
typedef struct Heap
{
    int *arr;
    int size;
} maxHeap;

// Tree Node : consist of data and two pointers->left,right
typedef struct Tnode
{
    int data int maxIndex;
    struct Tnode *left;
    struct Tnode *right;
} node;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// creating Node
node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// creating Heap
maxHeap *createHeap(int n)
{
    printf("1\n");
    maxHeap *temp = (maxHeap *)malloc(sizeof(maxHeap));
    printf("2\n");
    temp->arr = (int *)malloc(sizeof(int) * n);
    printf("3\n");
    temp->size = 0;
    printf("4\n");
    return temp;
}

// Heapify
void heapify(int a[], int size, int i)
{
    if (size == 0)
        return;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

        maxIndex = max( a[i], left, right)
    	if(i != maxIndex)
          	swap(a[i], a[maxIndex])
}

// inserting data in the MaxHeap
void insert(maxHeap **heap, int data)
{
    printf("Called\n");
    if ((*heap)->size == 0)
    {
        (*heap)->arr[0] = data;
        (*heap)->size++;
        printf("Here goes 1\n");
    }
    else
    {
        printf("Here goes 2\n");
        (*heap)->arr[(*heap)->size++] = data;
        for (int i = (*heap)->size / 2 - 1; i >= 0; i--)
        {
            heapify((*heap)->arr, (*heap)->size, i);
        }
    }
}

// printing Heap
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

// deleting Node
void deleteNode(maxHeap *heap, int data)
{
    int i;
    for (i = 0; i < heap->size; i++)
    {
        if (heap->arr[i] == data)
            break;
    }
    // swap the node with the last node of the heap
    swap(&(heap->arr[i]), &(heap->arr[heap->size - 1]));
    heap->size--;
    for (int i = heap->size / 2 - 1; i >= 0; i--)
    {
        heapify(heap->arr, heap->size, i);
    }
}

int main()
{
    int n;
    printf("Enter the size of Max Heap\n");
    scanf("%d ", &n);
    printf("hui\n");
    maxHeap *heap = createHeap(n);

    insert(&heap, 1);
    insert(&heap, 2);
    insert(&heap, 3);
    insert(&heap, 4);
    insert(&heap, 5);
    insert(&heap, 7);
    insert(&heap, 6);
    insert(&heap, 8);
    printArray(heap->arr, heap->size);
    deleteNode(heap, 5);
    printArray(heap->arr, heap->size);
    return 0;
}