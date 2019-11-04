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
  // Displays a menu for choosing how what type of first generation we should use
  void firstGenMenu();
  // Processes the user's chosen type of first generation
  bool processFirstGen(int choice);
  // Allows the user to set their own generation
  void customGenerator();
  // Displays a menu for editing a custom generation we should use
  void customMenu();
  // Processes the user's chosen operation on their custom generation
  bool processCustom(int choice);
  // Allows the user to add to their custom generation
  int addToVector();
  // Allows the user to remove items from their custom generation
  int removeFromVector();
  // Displays a menu for removing an element from a custom generation
  void displayRemoval();
  // Removes the user's chosen element or skips the process if the user types in -1
  int processRemoval(int choice);

 public:
  // Constructor to set values to defaults
  Generation();
  // Allows the user to set a first generatiom
  void firstGenerator();
  // Returns the generation pointer
  std::vector<bool>* returnGen();
};

#endif