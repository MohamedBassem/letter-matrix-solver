#include "stdincludes.h"
#include "LetterMatrixSolver.h"

int main(){
  LetterMatrixSolver solver;
  int numberOfLines;
  while( cin >> numberOfLines ){
    cin.ignore();
    string seriallizedMatrix = "";
    string line = "";
    for(int i=0;i<numberOfLines;i++){
      getline(cin, line);
      seriallizedMatrix += line;
      if( i+1 != numberOfLines )
        seriallizedMatrix += " ";
    }
    vector<string> ans = solver.solve(seriallizedMatrix);
    cout << ans.size() << endl;
    for(int i=0;i<(int)ans.size();i++){
      cout << ans[i] << endl;
    }
  }
  return 0;
}
