//
// Created by Vincent Lee on 03/11/2019.
// Note to self: grid starts at top left
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "gameOfLife.hpp"

#include "error.hpp"
#include "inputOutput.hpp"
#include "rule.hpp"
#include "table.hpp"

//Variables
Table* fullTable = nullptr;

int setupGameOfLife(int xSize, int ySize){
    fullTable = new Table();
    checkValidity(fullTable->initTable(xSize, ySize));

    // The following sets the initial table with random true values
    // For each item in the grid
    for (int row = 1; row < ySize; row++) {
        for (int col = 0; col < xSize; col++) {
            // random num generator
            // Should use the C++11 implementation of the random number gen
            int randomNum = rand() % 2;
            // If number is 1 then turn the box to true
            if(randomNum == 1){
                fullTable->setVal(col, row, true);
            }
        }
    }
    return SUCCESS;
}

int runGameOfLife(){
    Table* workingTable = nullptr;
    if(fullTable == nullptr){
        return TABLE_NOT_INITIALISED;
    }

    clearScreen();
    // Create a table for the working calculations
    workingTable = new Table();
    int arrayWidth = fullTable->getArrayWidth();
    int generations = fullTable->getArrayHeight();

    checkValidity(workingTable->initTable(arrayWidth, generations));
    if(workingTable == nullptr){
        return TABLE_NOT_INITIALISED;
    }

    // for each x and y value
    for (int row = 1; row < generations; row++) {
        for (int col = 0; col < arrayWidth; col++) {
            // get the Number of neighbors around the cord
            int neighbors = fullTable->getNumAround(col, row);
            // get it's state
            bool state = fullTable->getVal(col, row);

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
    fullTable = new Table(*workingTable);
    fullTable->debugTable();
    delete(workingTable);
    return SUCCESS;
}

