//
// Created by Vincent Lee on 03/11/2019.
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
int x = 10;
int y = 10;

char box = "█";
char blankSpace = " ";

int runGameOfLife(){
    Table* fullTable = new Table();
    clearScreen();
    vector<bool>* firstGen = generationObj->returnGen();
    checkValidity(fullTable->initTable(*firstGen, 10));

    int arrayWidth = fullTable->getArrayWidth();
    for (int row = 1; row < generations; row++) {
        for (int col = 0; col < arrayWidth; col++) {
            int neighbors = fullTable->getNeighbourhood(col, row);
            int state = 1;
            if(state == 0 && neighbors  == 3){
                //setstate to 1
            }else if(state == 1 && (neighbors < 2 || neighbors > 3)){
                //setstate to 0
            }else{
                // keep same
            }
        }

    }


}

