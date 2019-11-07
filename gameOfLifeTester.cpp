//
// Created by Vincent Lee on 04/11/2019.
//
#include <unistd.h>
#include "gameOfLife.hpp"

int main() {
  setupGameOfLife(50, 50);
  while (true) {
    runGameOfLife();
    usleep(500000);
  }
  return 1;
}