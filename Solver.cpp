#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;


class Node {
  int nodeIndex[30];
  bool _isEndOfWord;

  public:
  Node(){
    memset(nodeIndex,-1,sizeof nodeIndex);
    setEndOfWord(false);
  }

  void setIndex(int idx, int val){
    nodeIndex[idx] = val;
  }

  int getIndex(int idx){
    return nodeIndex[idx];
  }

  void setEndOfWord(bool isEndOfWord){
    this->_isEndOfWord = isEndOfWord;
  }

  bool isEndOfWord(){
    return this->_isEndOfWord;
  }

};

class Util{
  public:
    static int getCharIndex(char c){
      if( c >= 'a' && c <= 'z' ){
        return c - 'a';
      }else{
        return c - 'z';
      }
    }

    static bool isNoSpecialChars(string &s){
      bool ret = true;
      for(int i=0;i<(int)s.size();i++){
        ret = ret && ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') );
      }
      return ret;
    }

};

class Trie {
  vector<Node> trie;

  Trie(){
    trie.push_back(Node());
  }

  bool check(string &word){
    if( ! Util::isNoSpecialChars(word) )
      return false;
    int node = 0;
    int i = 0;
    while(i < (int)word.size()){
      int charIdx = Util::getCharIndex(word[i]);
      if( trie[node].getIndex(charIdx) == -1 ){
        return false;
      }else{
        node = trie[node].getIndex(charIdx);
        i++;
      }
    }
    return trie[node].isEndOfWord();
  }

  bool insert(string &word){
    if( ! Util::isNoSpecialChars(word) )
      return false;
    int node = 0;
    int i = 0;
    while(i < (int)word.size()){
      int charIdx = Util::getCharIndex(word[i]);
      if( trie[node].getIndex(charIdx) == -1 ){
        trie[node].setIndex(charIdx, trie.size());
        trie.push_back(Node());
      }else{
        node = trie[node].getIndex(charIdx);
      }
      i++;
    }

    return true;
  }
};

int main(){

}
