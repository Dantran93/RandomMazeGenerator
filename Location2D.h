/******************************************************************************
 * Location2D.h
 *
 * Purpose:
 *
 *****************************************************************************/



#ifndef LOCATION2D_H
#define LOCATION2D_H



// 
typedef struct Location2D
{
    int row;
    int column;
} Location2D;



// Function Prototypes
Location2D * new_Location2D      (int row, int column);
char       * toString_Location2D (Location2D *location);



#endif
