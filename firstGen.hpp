
#include <vector>

#ifndef FIRST_GEN_H
#define FIRST_GEN_H

void firstGenerator(std::vector<bool>* firstGen);
void firstGenMenu();
bool processFirstGen(std::vector<bool>* firstGen, int choice);

void custom(std::vector<bool>* firstGen);
void customMenu();
bool processCustom(int choice, std::vector<bool>* firstGen);

int addToVector(std::vector<bool>* firstGen);

int removeFromVector(std::vector<bool>* firstGen);
void displayRemoval(std::vector<bool>* firstGen);
int processRemoval(std::vector<bool>* firstGen, int choice);

#endif


#ifndef START_GEN
#define START_GEN

class Generation {
    
};

#endif