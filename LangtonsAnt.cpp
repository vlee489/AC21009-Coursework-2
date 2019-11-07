//
// Created by Vincent Lee on 06/11/2019.
//

#include "LangtonsAnt.hpp"

#include <iostream>
#include <string>

#include "error.hpp"
#include "inputOutput.hpp"
#include "table.hpp"
using namespace std;

// Variables
// Store the location of the ant
int antX = 0;
int antY = 0;
// antPoint is used for the direction the ant is point in
// 0 = up
// 1 = left
// 2 = down
// 3 = right
int antPoint = 0;
// Stores table for the ant world
Table* LangtonsAntWorld = nullptr;

/**
 * Sets up Langton's ant
 * @param x the size of the Grid's X axis
 * @param y the size of the Grid's Y axis
 * @return Success/Error Code
 */
int setupLangtonsAnt(int xSize, int ySize) {
  // Checks if table has been initialised already
  if (LangtonsAntWorld != nullptr)
    return INVALID_TABLE_PARAMETER;
  // sets update table and size
  LangtonsAntWorld = new Table();
  // checks if the table is initialised
  if (LangtonsAntWorld == nullptr)
    return TABLE_NOT_INITIALISED;

  // Sets size of the grid
  LangtonsAntWorld->initTable(xSize, ySize);
  if (LangtonsAntWorld->getArrayWidth() != xSize)
    return X_INDEX_OUT_OF_BOUNDS;
  if (LangtonsAntWorld->getArrayHeight() != ySize)
    return Y_INDEX_OUT_OF_BOUNDS;

  // Sets the ant to be in the middle of grid
  antX = xSize / 2;
  antY = ySize / 2;

  // sets each x,y to true (white)
  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {
      LangtonsAntWorld->setVal(i, j, true);
    }
  }
  return SUCCESS;
}

/**
 * Runs the Langton's Ant calculations and displays grid
 * @return Success/Error Code
 */
int runLangtonsAnt() {
  clearScreen();

  if (LangtonsAntWorld == nullptr) {
    return TABLE_NOT_INITIALISED;
  }

  // Get the state of block the ant is on.
  bool state = LangtonsAntWorld->getVal(antX, antY);

  // Points the ant in the right direction
  if (state) {
    antPoint++;
  } else {
    antPoint--;
  }

  // Makes sure antPoint doesn't go out of bounds of the numbers it's allows to
  // go to
  if (antPoint > 3) {
    antPoint = 0;
  } else if (antPoint < 0) {
    antPoint = 3;
  }

  // Flips the state of the cell the ant is on.
  LangtonsAntWorld->setVal(antX, antY, !state);

  // Moves the ant forward one block
  if (antPoint == 0) {  // up
    antY--;
  } else if (antPoint == 1) {  // Left
    antX++;
  } else if (antPoint == 2) {  // Down
    antY++;
  } else if (antPoint == 3) {  // Right
    antX--;
  } else {  // Not Valid direction
    return DIRECTION_OUT_OF_BOUNDS;
  }

  // Following does the wrapping for the ant
  // Get Size of grid
  int arrayWidth = LangtonsAntWorld->getArrayWidth();
  int generations = LangtonsAntWorld->getArrayHeight();
  // for x axis
  if (antX >= arrayWidth) {
    antX = 0;
  } else if (antX < 0) {
    antX = arrayWidth - 1;
  }
  // for y axis
  if (antY >= generations) {
    antY = 0;
  } else if (antY < 0) {
    antY = generations - 1;
  }

  // Display grid
  LangtonsAntWorld->antTable(antX, antY, antPoint);
  return SUCCESS;
}
