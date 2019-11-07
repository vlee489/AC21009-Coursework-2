//
// Created by Vincent Lee on 03/11/2019.
// Note to self: grid starts at top left
//

#include <string>
#include <cstdlib>
#include "gameOfLife.hpp"

#include "error.hpp"
#include "inputOutput.hpp"
#include "table.hpp"

//Variables
Table* gameOfLifeGrid = nullptr;

/**
 * Sets up the game of life grid and the location of the random activated squares
 * @param xSize the size of the X axis
 * @param ySize the size of the Y axis
 * @return If the intalisation was susscessful or an error code
 */
int setupGameOfLife(int xSize, int ySize){
    if(gameOfLifeGrid != nullptr)
        return INVALID_TABLE_PARAMETER;
    //sets update table and size
    gameOfLifeGrid = new Table();
    // checks if the table is initialised
    if(gameOfLifeGrid == nullptr)
        return TABLE_NOT_INITIALISED;

    gameOfLifeGrid->initTable(xSize, ySize);
    if(gameOfLifeGrid->getArrayWidth() != xSize)
        return X_INDEX_OUT_OF_BOUNDS;
    if(gameOfLifeGrid->getArrayHeight() != ySize)
        return Y_INDEX_OUT_OF_BOUNDS;

    // The following sets the initial table with random true values
    // For each item in the grid
    for (int row = 1; row < ySize; row++) {
        for (int col = 0; col < xSize; col++) {
            // random num generator
            // Should use the C++11 implementation of the random number gen
            int randomNum = rand() % 2;
            // If number is 1 then turn the box to true
            if(randomNum == 1){
                checkValidity(gameOfLifeGrid->setVal(col, row, true));
            }
        }
    }
    return SUCCESS;
}

/**
 * Runs the game of life calculations and then displays the grid
 * @return Success / error code
 */
int runGameOfLife(){
    clearScreen();

    // checks the table is setup
    if(gameOfLifeGrid == nullptr){
        return TABLE_NOT_INITIALISED;
    }

    // Create a table for the working calculations
    Table* workingTable = new Table();
    if(workingTable == nullptr){
        return TABLE_NOT_INITIALISED;
    }

    // Sets the size of the grid for the working table based on the main fullTable
    int arrayWidth = gameOfLifeGrid->getArrayWidth();
    int generations = gameOfLifeGrid->getArrayHeight();
    checkValidity(workingTable->initTable(arrayWidth, generations));


    // for each x and y value
    for (int row = 1; row < generations; row++) {
        for (int col = 0; col < arrayWidth; col++) {
            // get the Number of neighbors around the cord
            int neighbors = gameOfLifeGrid->getNumAround(col, row);
            // get it's state
            bool state = gameOfLifeGrid->getVal(col, row);

            // Cell is born as conditions are right
            if(!state && neighbors  == 3){
                checkValidity(workingTable->setVal(col, row, true));
            }
            // Cell dies due to underpopulation || over population
            else if(state && (neighbors < 2 || neighbors > 3)){
                checkValidity(workingTable->setVal(col, row, false));
            }
            // Keep the state the same
            else{
                checkValidity(workingTable->setVal(col, row, state));
            }
             

        }
    }
    // sets the working table as the new active table.
    gameOfLifeGrid = new Table(*workingTable);
    // Displays table
    gameOfLifeGrid->debugTable();
    //removes the working table
    delete(workingTable);
    return SUCCESS;
}

