/******************************************************************************
 * Location2D.h
 * Author: Daniel Tranfaglia
 *
 * Purpose: Contains the structs, constants, and function prototypes associated
 *      with locations in a 2D grid.
 *****************************************************************************/



#ifndef LOCATION2D_H
#define LOCATION2D_H



// Struct to define a location in a 2D grid
typedef struct Location2D
{
    int row;      // Vertical coordinate
    int column;   // Horizontal coordinate
} Location2D;



// Constants
#define ERROR_OCCURRED 1



// Function Prototypes
Location2D * new_Location2D   (int row, int column);
void         print_Location2D (Location2D *location);



#endif
