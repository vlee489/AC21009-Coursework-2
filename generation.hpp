#ifndef START_GEN
#define START_GEN

#include <string>
#include <vector>

// Store values of a custom genertation of cells and allows the user to input
// their own
class Generation {
 private:
  // Stores a vector pointer to the generation of cells we are storing
  std::vector<bool>* gen;
  // Stores a string that will be used to display an error message to the user
  // if they do an invalid operation e.g. delete from an empty vector
  std::string errorBuffer;
  void firstGenMenu();
  bool processFirstGen(int choice);
  void customGenerator();
  void customMenu();
  bool processCustom(int choice);
  int addToVector();
  int removeFromVector();
  void displayRemoval();
  int processRemoval(int choice);

 public:
  // Constructor to set values to defaults
  Generation();
  // Allows the user to set a first generatiom
  void firstGenerator();
  //
  std::vector<bool>* returnGen();
};

#endif