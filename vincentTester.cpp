//
// Created by Vincent Lee on 04/11/2019.
//
#include <unistd.h>

#include <iostream>
#include <vector>

#include "error.hpp"
#include "gameOfLife.hpp"
#include "generation.hpp"
#include "inputOutput.hpp"
#include "table.hpp"

int main() {
  setupGameOfLife(50, 50);
  while (true) {
    runGameOfLife();
    usleep(500000);
  }
  return 1;
}