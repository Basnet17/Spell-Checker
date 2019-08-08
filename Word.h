/*
Author: Pritam Basnet
Date: November 29, 2018
FileName: Word.h
This program generates the alternative words as the suggestions for those misspelled
words.
*/

#ifndef WORD_H
#define WORD_H

#include "SeperateChain.h"
#include <functional>
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

class word
{
  private:
    string value;

  public:
    word (){

    }

    word (string word1){   //constructor when string is passed to the word.
      value = word1;
    }


    //This alters each adjacent pairs of the word to produce suggestion
    //vector containing those suggestions is returned
    vector<string> alterWords(string s){
      vector<string> altvec;
      string temp = s;
      for (int i=0; i<s.length()-1; i++){   //goes up to the last element
        swap(temp[i],temp[i+1]);   //adjacent elements are swapped
        altvec.push_back(temp);    //then pushed back into vector
        temp= s;   //and the temp is changed back to original string
      }
      return altvec;
    }


    //This returns the vector generating all those words after inserting a-z before
    //the first and after the last character.
    vector<string> firstLast(string val){
      string temp = val;
      vector<string> altvec1;
      for (char f = 'a'; f <= 'z'; f++){
        temp.insert(0,string(1,f));   //every character is inserted before the first
        altvec1.push_back(temp);
        temp = val;
        temp.insert(temp.length(),string(1,f));   //every character is inserted after the last
        altvec1.push_back(temp);
        temp = val;
      }
      return altvec1;   //vectors containing all the suggestions is returned.
    }


    //This returns the vector after inserting characters between adjacent pairs
    //in the string except before the first and after the last
    //all the process is same as before
    //Little more efficient than doing everything in the same function
    vector<string> betweenChars(string val){
      string temp = val;
      vector<string> altvec1;
      for (int i = 1; i<val.length(); i++){
        for (char f = 'a'; f <= 'z'; f++){
          temp.insert(i,string(1,f));
          altvec1.push_back(temp);
          temp = val;
        }
      }
      return altvec1;
    }


    //This merges all three vectors which have produced the suggestions
    vector<string> wordchecker(string s){
      word word1(s);
      vector<string> vecWord;
      vecWord = word1.betweenChars(s);   //vector inserting characters between adjacent pairs
      vector<string> vecWord1;
      vecWord1 = word1.firstLast(s);    //vector inserting characters before first and after last
      vector<string> vecWord2;
      vecWord2 = word1.alterWords(s);   //vector altering adjacent pairs
      vecWord.insert(vecWord.end(), vecWord1.begin(), vecWord1.end());   //merging process
      vecWord.insert(vecWord.end(), vecWord2.begin(), vecWord2.end());   //merging process
      return vecWord;
    }
};
#endif
