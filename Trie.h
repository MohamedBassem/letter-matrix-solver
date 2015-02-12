#include "stdincludes.h"

#ifndef _TRIE_H_
#define _TRIE_H_


class Node {
  int nodeIndex[30];
  bool _isEndOfWord;

  public:
    Node();
    void setIndex(int idx, int val);
    int getIndex(int idx);
    void setEndOfWord(bool isEndOfWord);
    bool isEndOfWord();
};

class Trie {
  vector<Node> trie;

  public:
    Trie();
    bool check(string &word);
    bool insert(string &word);
};

#endif // _TRIE_H_

