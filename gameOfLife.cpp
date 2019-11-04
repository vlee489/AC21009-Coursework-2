//
// Created by Vincent Lee on 03/11/2019.
// Note to self: grid starts at top left
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "gameOfLife.h"

#include "error.hpp"
#include "inputOutput.hpp"
#include "rule.hpp"
#include "table.hpp"

//Variables
int x = 50;
int y = 50;
Table* fullTable = new Table();

void setupGameOfLife(){
    checkValidity(fullTable->initTable(x, y));

    // Following sets up starting items
    fullTable->setVal(3, 2 true);
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
    int arrayWidth = fullTable->getArrayWidth();
    for (int row = 1; row < generations; row++) {
        for (int col = 0; col < arrayWidth; col++) {
            int neighbors = fullTable->getNeighbourhood(col, row);
            bool state = fullTable->getVal(col, row);
            if(!state && neighbors  == 3){
                fullTable->setVal(col, row, true)
            }else if(state && (neighbors < 2 || neighbors > 3)){
               fullTable->setVal(col, row, false)
            }
        }

    }
    fullTable->debugTable()
}

void main(){
    
}

