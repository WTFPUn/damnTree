#include "stack.h"
#include <stdlib.h>

/* Create a new stack with the specify capacity
 * Return pointer to the stack structure if successful
 *        or NULL if the stack can't be created 
 *        e.g. memory allocation error  
 */
STACK_T* stackCreate(int capacity)
{
    // allocate the stack structure
    STACK_T* stack = (STACK_T*) calloc(1, sizeof(STACK_T));
    if (stack == NULL)
    {
        return NULL;
    }
    // allocate an array to store the data
    stack->data = listCreate(capacity);
    if (stack->data == NULL)
    {
        return NULL;
    }
    return stack;
}

/* Destroy the stack and release all memory
 */
void stackDestroy(STACK_T* stack)
{
    if (stack != NULL)
    {
        listDestroy(stack->data);
        free(stack);
    }
}

/* Returns the number of elements (could be zero)
 * or -1 if the stack has not been created
 */
int stackSize(STACK_T* stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    return listSize(stack->data);
}

/* Add new element to the top of the stack
 * Return -1 if the stack hasn't been created
 *        -2 if the stack is full 
 *         1 if the operation is successful
 */
int stackPush(STACK_T* stack, void* data)
{
    if (stack == NULL)
    {
        return -1;
    }
    return listAppend(stack->data, data);
}

/* Remove an element from the top of the stack
 * Return -1 if the stack hasn't been created
 *        -2 if the stack is empty
 *         1 if the operation is successful
 */
int stackPop(STACK_T* stack, void** data)
{
    if (stack == NULL)
    {
        return -1;
    }

    int retVal;
    int index = listSize(stack->data) - 1;
    void* tmp;

    retVal = listGet(stack->data, index, &tmp);
    if (retVal != 1)
    {
        return retVal;
    }

    retVal = listRemoveAt(stack->data, index);
    if (retVal != 1)
    {
        return retVal;
    }

    *data = tmp;
    return 1;
}