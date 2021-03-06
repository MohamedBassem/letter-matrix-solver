#include "Trie.h"
#include "Util.h"

Trie::Trie(){
  trie.push_back(Node());
  maxLength = 0;
}

bool Trie::check(string &word){
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

bool Trie::insert(string &word){
  if( ! Util::isNoSpecialChars(word) )
    return false;
  maxLength = max(maxLength, (int)word.size());
  int node = 0;
  int i = 0;
  while(i < (int)word.size()){
    int charIdx = Util::getCharIndex(word[i]);
    if( trie[node].getIndex(charIdx) == -1 ){
      trie[node].setIndex(charIdx, trie.size());
      node = trie.size();
      trie.push_back(Node());
    }else{
      node = trie[node].getIndex(charIdx);
    }
    i++;
  }
  trie[node].setEndOfWord(true);
  return true;
}

int Trie::getMaxLength(){
  return maxLength;
}

Node::Node(){
  memset(nodeIndex,-1,sizeof nodeIndex);
  setEndOfWord(false);
}

void Node::setIndex(int idx, int val){
  nodeIndex[idx] = val;
}

int Node::getIndex(int idx){
  return nodeIndex[idx];
}

void Node::setEndOfWord(bool isEndOfWord){
  this->_isEndOfWord = isEndOfWord;
}

bool Node::isEndOfWord(){
  return this->_isEndOfWord;
}
