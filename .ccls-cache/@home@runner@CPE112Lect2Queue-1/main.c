#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

int* allocateHeapInt(int value)
{
    int* data = (int*) calloc(1, sizeof(int));
    *data = value;
    return data;
}

// > ./main
// 3 
// 5 
// 7
// 9
// 11
int main() 
{
    int retVal;
    void* data;

    // enqueue test data
    QUEUE_T* queue = queueCreate(5);
    queueEnqueue(queue, allocateHeapInt(3));
    queueEnqueue(queue, allocateHeapInt(5));
    queueEnqueue(queue, allocateHeapInt(7));
    queueEnqueue(queue, allocateHeapInt(9));
    queueEnqueue(queue, allocateHeapInt(11));
    
    // test overflow detection
    retVal = queueEnqueue(queue, allocateHeapInt(13));
    if (retVal == 1)
    {
        printf("Error: we should not be able to enqueue 13!!!");
        return -1;
    }

    // print all elements in the queue
    while (queueSize(queue) > 0) 
    {
        queueDequeue(queue, &data);
        printf("%d\n", *(int *)data);
    }

    // test queue empty detection
    retVal = queueDequeue(queue, &data);
    if (retVal == 1)
    {
        printf("Error: we should not be able to dequeue anymore!!!");
        return -1;
    }
    return 0;
}