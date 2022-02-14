#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int* allocateHeapInt(int value)
{
    int* data = (int*) calloc(1, sizeof(int));
    *data = value;
    return data;
}

// > ./main
// 9 
// 7 
// 5
// 3
int main() 
{
    STACK_T* stack = stackCreate(10);
    stackPush(stack, allocateHeapInt(3));
    stackPush(stack, allocateHeapInt(5));
    stackPush(stack, allocateHeapInt(7));
    stackPush(stack, allocateHeapInt(9));
    while (stackSize(stack) > 0) 
    {
        void* data;
        stackPop(stack, &data);
        printf("%d\n", *(int *)data);
    }
    return 0;
}