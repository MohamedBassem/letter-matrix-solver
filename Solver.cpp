#include "stdincludes.h"
#include "Trie.h"

Trie trie;

bool loadDictInMemory(){
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

int main(){
  loadDictInMemory();
  string s;
  while(true){
    cin >> s;
    cout << trie.check(s) << endl;
  }
}
