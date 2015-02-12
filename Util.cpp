#include "Util.h"

int Util::getCharIndex(char c){
  if( c >= 'a' && c <= 'z' ){
    return c - 'a';
  }else{
    return c - 'z';
  }
}

bool Util::isNoSpecialChars(string &s){
  bool ret = true;
  for(int i=0;i<(int)s.size();i++){
    ret = ret && ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') );
  }
  return ret;
}

