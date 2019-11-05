//
// Created by Vincent Lee on 04/11/2019.
//
#include <iostream>
#include <vector>
#include <unistd.h>
#include "error.hpp"
#include "generation.hpp"
#include "inputOutput.hpp"
#include "table.hpp"
#include "gameOfLife.hpp"

int main(){
    setupGameOfLife(50, 50);
    while(true){
        runGameOfLife(50, 50);
        usleep(500000);
    }
    return 1;
}