/******************************************************************************
 * Stack.h
 * Author: Daniel Tranfaglia
 *
 * Purpose: Contains the structs, constants, and function prototypes associated
 *      with stacks and the items contained within them.
 *****************************************************************************/



#ifndef STACK_H
#define STACK_H



// Struct to define an item in a stack
typedef struct StackItem
{
    void *item;               // Generic item
    struct StackItem *next;   // Next item
} StackItem;



// Struct to define a stack of items
typedef struct Stack
{
    StackItem *top;      // Top item in the stack
} Stack;



// Constants
#define ERROR_OCCURRED 1



// Function Prototypes
Stack     * new_Stack      ();
StackItem * new_StackItem  (void *newItem);
void        free_StackItem (StackItem *stackItem);
int         push           (Stack *stack, StackItem *newItem);
int         pop            (Stack *stack);
StackItem * peek           (Stack *stack);



#endif
