/******************************************************************************
 * RandomMazeGenerator.c
 * Author: Daniel Tranfaglia
 *
 * Purpose: The main module for the random maze generator program.
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Location2D.h"
#include "Stack.h"



// Constants
#define TRUE           1
#define ERROR_OCCURRED 1



// Globals
char ** maze = NULL;
int size;
Stack *locationStack = NULL;



// Function Prototypes
int  getSize     ();
void initGrid    ();
void freeGrid    ();
void displayMaze ();


/*
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
*/


/******************************************************************************
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/

int getSize ()
{
    int size = 0;
    while (TRUE)
    {
        //
        printf("Enter a non-negative number for size: ");

        //
        if (scanf("%d", &size) == 0 || size < 1)
        {
            fprintf(stderr, "Invalid input.\n");
            exit(ERROR_OCCURRED);
        }
        break;
    }

    return size;
} // getSize()



/******************************************************************************
 *
 *
 *
 *
 *
 *
 *****************************************************************************/

void initGrid ()
{
    //
    maze = (char **)calloc(size, sizeof(char *));
    if (maze == NULL)
    {
        fprintf(stderr, "ERROR: No memory left!\n");
        exit(ERROR_OCCURRED);
    }

    //
    int i, j;
    for (i = 0; i < size; i++)
    {
        maze[i] = (char *)calloc(size, sizeof(char));
        if (maze[i] == NULL)
        {
            fprintf(stderr, "ERROR: No memory left!\n");
            exit(ERROR_OCCURRED);
        }
    }

    //
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            maze[i][j] = '*';
} // initGrid()



/******************************************************************************
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/

void freeGrid ()
{
    int i;
    for (i = 0; i < size; i++)
        free(maze[i]);
    free(maze);
} // freeGrid()



/******************************************************************************
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/

void displayMaze ()
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%c", maze[i][j]);
            if (j != size-1)
                printf(" ");
        }
        printf("\n");
    }
} // displayMaze()



/*
 */

void generateMaze ()
{
    srand(time(0));

    int startRow = 2*(rand() % ((size-1)/2))+1;
    int startCol = 2*(rand() % ((size-1)/2))+1;
    
    Location2D *startLocation = new_Location2D(startRow, startCol);

    maze[startRow][startCol] = '.';

} // generateMaze()



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
    //test_Stack();
    
    printf("Random Maze Generator!\n\n");
    size = 2 * getSize() + 1;

    initGrid();
    generateMaze();
    displayMaze();
    freeGrid();
    
    return 0;
} // main()
