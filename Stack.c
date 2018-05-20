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
 * Purpose:
 *
 * Parameters: None.
 *
 * Returns: Stack *.
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
 * Purpose: 
 *
 * Parameters:
 *      void *newItem -- 
 *
 * Returns: StackItem *.
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
 * push()
 *
 * Purpose:
 *
 * Parameters:
 *      Stack *stack --
 *      StackItem newItem -- 
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
 *
 *
 *
 *
 *
 *
 *****************************************************************************/

StackItem * pop (Stack *stack)
{
    return NULL;
} // pop()



/******************************************************************************
 *
 *
 *
 *
 *
 *
 *****************************************************************************/

StackItem * peek (Stack *stack)
{
    return NULL;
} // peek()
