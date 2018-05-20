/******************************************************************************
 * Stack.c
 * Author: Daniel Tranfaglia
 *
 * Purpose: Contains the function definitions for the prototypes given in
 *      Stack.h.
 *****************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"



/******************************************************************************
 * new_Stack()
 *
 * Purpose: Allocates and initializes a Stack struct on the heap. A pointer to
 *      the struct is returned.
 *
 * Parameters: None.
 *
 * Returns: Stack *. Pointer to the newly created Stack.
 *****************************************************************************/

Stack * new_Stack ()
{
    // Create a stack, check for malloc error
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    if (newStack == NULL)
    {
        fprintf(stderr, "ERROR: No memory left!\n");
        exit(ERROR_OCCURRED);
    }

    // Initialize the stack
    newStack->top = NULL;

    return newStack;
} // new_Stack()



/******************************************************************************
 * new_StackItem()
 *
 * Purpose: Allocates and initializes a StackItem struct on the heap with the
 *      given generic value. A pointer to the struct is returned.
 *
 * Parameters:
 *      void *newItem -- Generic value to put into the StackItem.
 *
 * Returns: StackItem *. Pointer to the newly created StackItem.
 *****************************************************************************/

StackItem * new_StackItem (void *item)
{
    // Create a stack item, check for malloc error
    StackItem *newItem = (StackItem *)malloc(sizeof(StackItem));
    if (newItem == NULL)
    {
        fprintf(stderr, "ERROR: No memory left!\n");
        exit(ERROR_OCCURRED);
    }

    // Initialize the stack item
    newItem->item = item;
    newItem->next = NULL;

    return newItem;
} // new_StackItem()



/******************************************************************************
 * free_StackItem()
 *
 * Purpose: Frees the allocated memory for the given stack item.
 *
 * Parameters:
 *      StackItem *stackItem -- Stack item to free.
 *
 * Returns: void.
 *****************************************************************************/

void free_StackItem (StackItem *stackItem)
{
    free(stackItem->item);
    free(stackItem);
} // free_StackItem()



/******************************************************************************
 * push()
 *
 * Purpose: Pushes the given stack item to the top of the given stack.
 *
 * Parameters:
 *      Stack *stack -- Stack to push to.
 *      StackItem newItem -- Item to push to the stack.
 *
 * Returns: int. 1 if push was successful, 0 otherwise.
 *****************************************************************************/

int push (Stack *stack, StackItem *newItem)
{
    // No stack or no item, push unsuccessful
    if (stack == NULL || newItem == NULL)
        return 0;

    // First item to push
    if (stack->top == NULL)
        stack->top = newItem;

    // Other items to push
    else
    {
        newItem->next = stack->top;
        stack->top = newItem;
    }

    return 1;   // Push successful
} // push()



/******************************************************************************
 * pop()
 *
 * Purpose: Removes and frees the item at the top of the given stack.
 *
 * Parameters:
 *      Stack *stack -- Stack to pop from.
 *
 * Returns: int. 1 if pop was successful, 0 otherwise.
 *****************************************************************************/

int pop (Stack *stack)
{
    // No stack to pop from, pop unsuccessful
    if (stack == NULL)
        return 0;

    // Point to the item to pop
    StackItem *poppedItem = stack->top;

    // No item to pop, pop unsuccessful
    if (poppedItem == NULL)
        return 0;

    // Rearrange pointers to detach the top item
    if (poppedItem != NULL)
    {
        stack->top = poppedItem->next;
        poppedItem->next = NULL;
    }

    // Free the memory for the popped item
    free_StackItem(poppedItem);
    return 1;   // Pop successful
} // pop()



/******************************************************************************
 * peek()
 *
 * Purpose: Returns the stack item at the top of the given stack.
 *
 * Parameters:
 *      Stack *stack -- Stack to check for an item.
 *
 * Returns: StackItem *. Stack item at the top of the given stack.
 *****************************************************************************/

StackItem * peek (Stack *stack)
{
    return stack->top;
} // peek()
