#ifndef FIRST_GEN_H
#define FIRST_GEN_H

#include <vector>

int addToVector(std::vector<bool>* firstGen);
void custom(std::vector<bool>* firstGen);
void customMenu();
void displayFirstGenMenu();
void displayRemoval(std::vector<bool>* firstGen);
void firstGenerator(std::vector<bool>* firstGen);
bool processCustom(int choice, std::vector<bool>* firstGen);
bool processFirstGen(std::vector<bool>* firstGen, int choice);
int processRemoval(std::vector<bool>* firstGen, int choice);
int removeFromVector(std::vector<bool>* firstGen);

#endif