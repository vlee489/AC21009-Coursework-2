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
Table* GameOfLifeTable = nullptr;

/**
 * Sets up the game of life grid and the location of the random activated squares
 * @param xSize the size of the X axis
 * @param ySize the size of the Y axis
 * @return If the intalisation was susscessful or an error code
 */
int setupGameOfLife(int xSize, int ySize){
    //sets update table and size
    GameOfLifeTable = new Table();
    // checks if the table is initialised
    if(GameOfLifeTable == nullptr)
        return TABLE_NOT_INITIALISED;

    GameOfLifeTable->initTable(xSize, ySize);
    if(GameOfLifeTable->getArrayWidth() != xSize)
        return X_INDEX_OUT_OF_BOUNDS;
    if(GameOfLifeTable->getArrayHeight() != ySize)
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
                GameOfLifeTable->setVal(col, row, true);
            }
        }
    }
    return SUCCESS;
}

/**
 * Runs the game of life calculations and then displays the grid
 * @return error code
 */
int runGameOfLife(){
    clearScreen();

    // checks the table is setup
    if(GameOfLifeTable == nullptr){
        return TABLE_NOT_INITIALISED;
    }

    // Create a table for the working calculations
    Table* workingTable = new Table();
    if(workingTable == nullptr){
        return TABLE_NOT_INITIALISED;
    }

    // Sets the size of the grid for the working table based on the main fullTable
    int arrayWidth = GameOfLifeTable->getArrayWidth();
    int generations = GameOfLifeTable->getArrayHeight();
    checkValidity(workingTable->initTable(arrayWidth, generations));


    // for each x and y value
    for (int row = 1; row < generations; row++) {
        for (int col = 0; col < arrayWidth; col++) {
            // get the Number of neighbors around the cord
            int neighbors = GameOfLifeTable->getNumAround(col, row);
            // get it's state
            bool state = GameOfLifeTable->getVal(col, row);

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
    GameOfLifeTable = new Table(*workingTable);
    // Displays table
    GameOfLifeTable->debugTable();
    //removes the working table
    delete(workingTable);
    return SUCCESS;
}

