#include <string>

// Imports methods to generate rules and convert numbers to binary and decimal
#include "rule.hpp"
// Imports methods for storing a table of values
#include "table.hpp"
// Imports methods which allows the user to set their own generation
#include "generation.hpp"

// Stores pointers for objects of classes
Table* fullTable;
Rule* ruleObj;
Generation* generationObj;

// Headers for the methods in this file
void initObjects(bool erase);
void displayMenu();
bool processMenu(int choice);
void createAutomaton();
void loadAutomaton();
bool processLoad(std::string filename);
void saveAutomaton();
bool processSave(std::string filename);
void gameOfLife();
void langtonsAnt();