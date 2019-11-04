#ifndef START_GEN
#define START_GEN

#include <string>
#include <vector>

void firstGenMenu();
void customMenu();

// Store values of a genertation
class Generation {
 private:
  std::vector<bool>* gen;
  std::string errorBuffer;

 public:
  // Constructor to set values to defaults
  Generation();
  // Allows the user to set a first generatiom
  void firstGenerator();
  bool processFirstGen(int choice);
  void custom();
  bool processCustom(int choice);
  int addToVector();
  int removeFromVector();
  void displayRemoval();
  int processRemoval(int choice);
  std::vector<bool>* returnGen();
};

#endif