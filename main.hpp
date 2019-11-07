#ifndef MAIN_H
#define MAIN_H

// Imports methods which allows the user to set their own generation
#include "generation.hpp"
// Imports methods to generate rules and convert numbers to binary and decimal
#include "rule.hpp"
// Imports methods for storing a table of values
#include "table.hpp"
#include <string>

// Stores pointers for global objects
Table* fullTable;
Rule* ruleObj;
Generation* generationObj;

// Initialises global objects for each external class
// But only does so, if it is yet uninitialised or the erase flag is turned on
void initObjects(bool erase);
// Displays the main menu
void displayMenu();
// Processes the user's chosen operation
bool processMenu(int choice);
// Lets the user create and setup their own cellular automaton
void createAutomaton();
// Allows the user to load a previously saved cellular automaton
void loadAutomaton();
// Processes loading a table from a file
bool processLoad(std::string filename);
// Allows the user to save their cellular automaton to an external file
void saveAutomaton();
// Processes saving the table to a file
bool processSave(std::string filename);
// Runs a simulation of Conway's Game of Life
void gameOfLife();
// Runs a simulation of Langton's ant
void langtonsAnt();

#endif