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
int x = 50;
int y = 50;
Table* fullTable = nullptr;
Table* workingTable = nullptr;

void setupGameOfLife(){
    printf("Setup Done\n");
    fullTable = new Table();
    checkValidity(fullTable->initTable(x, y));

    // Following sets up starting items
    fullTable->setVal(3, 2, true);
    fullTable->setVal(5, 2, true);
    fullTable->setVal(4, 3, true);
    fullTable->setVal(5, 3, true);
    fullTable->setVal(4, 4, true);

    fullTable->setVal(4, 5, true);
    fullTable->setVal(3, 10, true);
    fullTable->setVal(5, 10, true);
    fullTable->setVal(3, 11, true);
    fullTable->setVal(4, 11, true);

}

void runGameOfLife(){
    printf("run Done\n");
    clearScreen();
    // Create a table for the working calculations
    workingTable = new Table();
    int arrayWidth = fullTable->getArrayWidth();
    int generations = fullTable->getArrayHeight();

    // for each x and y value
    for (int row = 1; row < generations; row++) {
        for (int col = 0; col < arrayWidth; col++) {
            // get the Number of neighbors around the cord
            int neighbors = fullTable->getNumAround(col, row);
            // get it's state
            bool state = fullTable->getVal(col, row);

            // Cell is born as conditions are right
            if(!state && neighbors  == 3){
                workingTable->setVal(col, row, true);
            }
            // Cell dies due to underpopulation || over population
            else if(state && (neighbors < 2 || neighbors > 3)){
                workingTable->setVal(col, row, false);
            }
            // Keep the state the same
            else{
                workingTable->setVal(col, row, state);
            }
        }
    }
    // sets the working table as the new active table.
    fullTable = new Table(*workingTable);
    fullTable->printTable();
}

