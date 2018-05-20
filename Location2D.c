/******************************************************************************
 * Location2D.c
 * Author: Daniel Tranfaglia
 *
 * Purpose: Contains the function definitions for the prototypes given in
 *      Location2D.h.
 *****************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "Location2D.h"



/******************************************************************************
 * new_Location2D()
 *
 * Purpose: Allocates and initializes a Location2D struct on the heap with the
 *      given row and column coordinates. A pointer to the struct is returned.
 *
 * Parameters:
 *      int row -- Row coordinate to set.
 *      int column -- Column coordinate to set.
 *
 * Returns: Location2D *. Pointer to the newly created Location2D node.
 *****************************************************************************/

Location2D * new_Location2D (int row, int column)
{
    // Create a node, check for malloc error
    Location2D *newLocation = (Location2D *)malloc(sizeof(Location2D));
    if (newLocation == NULL)
    {
        fprintf(stderr, "ERROR: No memory left!\n");
        exit(ERROR_OCCURRED);
    }

    // Initialize the node
    newLocation->row    = row;
    newLocation->column = column;

    return newLocation;
} // new_Location2D()



/******************************************************************************
 * print_Location2D()
 *
 * Purpose: Prints the given Location2D struct (given with a pointer) in the
 *      format: (row,column).
 *
 * Parameters:
 *      Location2D *location -- Location to print.
 *
 * Returns: void.
 *****************************************************************************/

void print_Location2D (Location2D *location)
{
    printf("(%d,%d)", location->row, location->column);
} // print_Location2D()
