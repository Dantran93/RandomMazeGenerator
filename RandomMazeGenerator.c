/******************************************************************************
 * RandomMazeGenerator.c
 * Author: Daniel Tranfaglia
 *
 * Purpose: The main module for the random maze generator program.
 *****************************************************************************/


#include <stdio.h>
#include "Location2D.h"
#include "Stack.h"



void print_LocationStack (Stack *stack)
{
    StackItem *stackItem = stack->top;

    while (stackItem != NULL)
    {
        print_Location2D(stackItem->item);
        printf("\n");
        stackItem = stackItem->next;
    }
}

void test_Stack ()
{
    Stack *locationStack = new_Stack();

    push(locationStack, new_StackItem(new_Location2D(5, 10)));
    push(locationStack, new_StackItem(new_Location2D(13, 1)));
    push(locationStack, new_StackItem(new_Location2D(2, 2)));
    pop(locationStack);
    push(locationStack, new_StackItem(new_Location2D(0, -8)));

    //print_LocationStack(locationStack);
    StackItem *stackItem = peek(locationStack);
    print_Location2D(stackItem->item);
}



/******************************************************************************
 * main()
 *
 * Purpose:
 *
 * Parameters:
 *
 * Returns: 
 *****************************************************************************/

int main ()
{
    
    test_Stack();

    return 0;
} // main()
