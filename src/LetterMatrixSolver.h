#include "stdincludes.h"
#include "Trie.h"

#ifndef _SOLVER_H_
#define _SOLVER_H_

class LetterMatrixSolver {
  string seriallizedMatrix;
  vector<string> grid;
  int width, length;
  Trie trie;

  public:
    LetterMatrixSolver();
    vector<string> solve(string seriallizedMatrix);
  private:
    bool loadDictInMemory();
    vector<string> deserializeMatrix(string seriallizedMatrix);

};

#endif // _SOLVER_H_

