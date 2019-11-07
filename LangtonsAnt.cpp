//
// Created by Vincent Lee on 06/11/2019.
//

#include <string>
#include <cstdlib>
#include "LangtonsAnt.hpp"

#include "error.hpp"
#include "inputOutput.hpp"
#include "table.hpp"

// Variables
// Store the location of the ant
int antX = 0;
int antY = 0;
// Stores table for the ant world
Table* LangtonsAntWorld = nullptr;

/**
 * Sets up Langton's ant
 * @param x the size of the Grid's X axis
 * @param y the size of the Grid's Y axis
 * @return Success/Error Code
 */
int setupLangtonsAnt(int xSize, int ySize){
    // Checks if table has been initialised already
    if(LangtonsAntWorld != nullptr)
        return INVALID_TABLE_PARAMETER;
    //sets update table and size
    LangtonsAntWorld = new Table();
    // checks if the table is initialised
    if(LangtonsAntWorld == nullptr)
        return TABLE_NOT_INITIALISED;

    // Sets size of the grid
    LangtonsAntWorld->initTable(xSize, ySize);
    if(LangtonsAntWorld->getArrayWidth() != xSize)
        return X_INDEX_OUT_OF_BOUNDS;
    if(LangtonsAntWorld->getArrayHeight() != ySize)
        return Y_INDEX_OUT_OF_BOUNDS;

    //Sets the ant to be in the middle of grid
    antX = xSize/2;
    antY = ySize/2;

    // sets each x,y to true (white)
    for(int i = 0; i < xSize; i++){
        for( int j = 0; j < ySize; j++){
            LangtonsAntWorld->setVal(i, j, true);
        }
    }
    return SUCCESS;
}
