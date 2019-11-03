#ifndef START_GEN
#define START_GEN

#include <string>
#include <vector>

void firstGenMenu();
void customMenu();

class Generation {
 private:
  std::vector<bool>* gen;
  std::string errorBuffer;

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