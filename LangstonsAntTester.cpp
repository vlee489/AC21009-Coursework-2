//
// Created by Vincent Lee on 07/11/2019.
//

#include <unistd.h>

#include <iostream>

#include "LangtonsAnt.hpp"
#include "error.hpp"
using namespace std;

int main() {
  checkValidity(setupLangtonsAnt(50, 50));
  cout << "setup done" << endl;
  while (true) {
    checkValidity(runLangtonsAnt());
    usleep(500000);
  }
  return 1;
}