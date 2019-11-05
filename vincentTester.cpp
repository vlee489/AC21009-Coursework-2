//
// Created by Vincent Lee on 04/11/2019.
//
#include <iostream>
#include <vector>
#include "error.hpp"
#include "generation.hpp"
#include "inputOutput.hpp"
#include "table.hpp"
#include "gameOfLife.hpp"

void main(){
    setupGameOfLife();
    while(true){
        runGameOfLife();
    }
}