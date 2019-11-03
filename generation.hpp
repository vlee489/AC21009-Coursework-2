#ifndef START_GEN
#define START_GEN

#include <vector>

void firstGenMenu();
void customMenu();

class Generation {
 private:
  std::vector<bool>* gen;

 public:
  Generation();
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