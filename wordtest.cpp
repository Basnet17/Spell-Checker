#include "Word.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void test(){
  word word1;
  vector<string> vecWord;
  vecWord = word1.betweenChars("LNE");
  for (int i=0; i<vecWord.size(); i++){
    cout << vecWord[i] << endl;
  }


  //word word1("wordlist.txt");
  //word1.printThings();
  /*
  string val = "Pritam";
  string stringArray[val.length()+1];
  string c;

  string temp = val;
  vector<string> altvec1;
  for (char f = 'A'; f <= 'Z'; f++){
    temp.insert(0,string(1,f));
    altvec1.push_back(temp);
    temp = val;
    temp.insert(temp.length(),string(1,f));
    altvec1.push_back(temp);
    temp = val;
  }

  for (int i = 1; i<val.length(); i++){
    for (char f = 'A'; f <= 'Z'; f++){
      temp.insert(i,string(1,f));
      cout << temp << endl;
      temp = val;
    }
  }*/
  /*
  for (int i = 0; i< val.length(); i++){
    for (char f = 'A'; f<='Z'; f++){
      val.insert(i,string(1,f));
    }
  }
  char f = 'A';
  for (int i =0; i<val.length(); i++){
    val.insert(0,"P");
  }*/
  //char f = 'G';
  //val.insert(0,string(1,f));
  //cout << val << endl;

  /*
  for (int i=0; i<val.length(); i++){
    stringArray[i] = val[i];
    //for ( c ="A";c<="Z";c++){
    //  val.insert(i,c);
    //}
  }
  int j = 0;
  for (int i= sizeof(stringArray)/sizeof(stringArray[0]); i>=0; i--){
    //stringArray[0] = "A";
    cout << stringArray[j] << endl;
    j++;}*/
}

int main(){
  test();
  return 0;
}
