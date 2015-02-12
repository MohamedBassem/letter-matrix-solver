#include "stdincludes.h"
#include "LetterMatrixSolver.h"
#include "Trie.h"

LetterMatrixSolver::LetterMatrixSolver(){
  loadDictInMemory();
}

bool LetterMatrixSolver::loadDictInMemory(){
  fstream dictFile("/usr/share/dict/words", fstream::in);
  if( dictFile.is_open() ){
    string line;
    while( getline(dictFile, line) ){
      trie.insert(line);
    }
  }else{
    cerr << "Cannot read the dict file." << endl;
    exit(1);
  }
}

vector<string> LetterMatrixSolver::deserializeMatrix(string seriallizedMatrix){
  stringstream ss;
  ss << seriallizedMatrix;
  vector<string> ret;
  string tmp;
  while( ss >> tmp ){
    ret.push_back(tmp);
  }
  return ret;
}

vector<string> LetterMatrixSolver::solve(string seriallizedMatrix){
  this->seriallizedMatrix = seriallizedMatrix;
  grid = deserializeMatrix(seriallizedMatrix);
  width = grid[0].size();
  length = grid.size();
  map<string, int> extractedWords;
  for(int i=0;i<length;i++){
    for(int j=0;j<width;j++){

      string stringToBeChecked, stringToBeCheckedRev;
      // Vertical Search
      stringToBeChecked = "";
      stringToBeCheckedRev = "";

      for(int k=i;k<length;k++){
        stringToBeChecked += grid[k][j];
        stringToBeCheckedRev = grid[k][j] + stringToBeCheckedRev;
        if( stringToBeChecked.size() < 3 ) continue;
        if( trie.check(stringToBeChecked) ){
          extractedWords[stringToBeChecked]++;
        }
        if( trie.check(stringToBeCheckedRev) ){
          extractedWords[stringToBeCheckedRev]++;
        }
      }

      // Horizontal Search
      stringToBeChecked = "";
      stringToBeCheckedRev = "";
      for(int k=j;k<width;k++){
        stringToBeChecked += grid[i][k];
        stringToBeCheckedRev = grid[i][k] + stringToBeCheckedRev;
        if( stringToBeChecked.size() < 3 ) continue;
        if( trie.check(stringToBeChecked) ){
          extractedWords[stringToBeChecked]++;
        }
        if( trie.check(stringToBeCheckedRev) ){
          extractedWords[stringToBeCheckedRev]++;
        }
      }

      // Diagonal Search
      stringToBeChecked = "";
      stringToBeCheckedRev = "";
      for(int k=0;k<min(j-width,i-length);k++){
        stringToBeChecked += grid[i+k][j+k];
        stringToBeCheckedRev = grid[i+k][j+k] + stringToBeCheckedRev;
        if( stringToBeChecked.size() < 3 ) continue;
        if( trie.check(stringToBeChecked) ){
          extractedWords[stringToBeChecked]++;
        }
        if( trie.check(stringToBeCheckedRev) ){
          extractedWords[stringToBeCheckedRev]++;
        }
      }
    }
  }

  // Convert Map to vector
  vector<string> ans;
  for(map<string,int>::iterator pos = extractedWords.begin();pos != extractedWords.end();pos++){
    ans.push_back( pos->first );
  }
  return ans;

}
