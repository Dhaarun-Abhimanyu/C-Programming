#include <stdio.h>
#include <stdlib.h>

typedef struct Heap{
    int* array;
    int size;
} Heap;

Heap* createheap(){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (int*)malloc(sizeof(int));
    heap->size = 0;
    return heap;
}

void heapify(Heap* heap,int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && heap->array[left] > heap->array[largest])
        largest = left;
    if(right < n && heap->array[right] > heap->array[largest])
        largest = right;
    if(largest != i){
        int temp = heap->array[i];
        heap->array[i] = heap->array[largest];
        heap->array[largest] = temp;
        heapify(heap,n,largest);
    }
}

void buildheap(Heap* heap){
    int n = heap->size;
    for(int i=(n-1)/2;i >= 0;i--)
        heapify(heap,heap->size,i);
}

void input(Heap* heap){
    heap->array = (int*)realloc(heap->array, heap->size * sizeof(int));
    for(int i=0;i<heap->size;i++){
        int temp;
        scanf("%d",&temp);
        heap->array[i] = temp;
    }
    buildheap(heap);
}

void print(Heap* heap){
    printf("\nHeap : ");
    for(int i=0;i<heap->size;i++){
        printf("%d ",heap->array[i]);
    }
}

void sort(Heap* heap){
    int n = heap->size;
    for(int i=heap->size-1;i>=0;i--){
        int temp = heap->array[0];
        heap->array[0] = heap->array[i];
        heap->array[i] = temp;
        heapify(heap,i,0);
    }
}

int main(){
    int n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    Heap* heap = createheap();
    heap->size = n;
    input(heap);
    print(heap);
    sort(heap);
    print(heap);
    return 0;
}