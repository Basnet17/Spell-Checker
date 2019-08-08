/*
Author: Pritam Basnet
Date: November 29, 2018
FileName: SeperateChain.h
This program creates a hash table using two different techniques, one using teh
standard hash function next is using the hash function I created.
*/

#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

// SeparateChaining Hash table class
/**
 *
 * Implement your hash table here.  You are required to use the separate
 * chaining strategy that we discussed in lecture, meaning that collisions
 * are resolved by having each cell in the table be a linked list of all of
 * the strings that hashed to that cell.
 */

//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items

class HashTable
{
  public:
    HashTable( int size = 101 ){
      theLists.resize(size);     //Setting the initial list size to be 101
    }

    //This function returns the currentSize which is the number of entries in
    //the hash table
    int Size(){
      return currentSize;
    }


    //Takes a string and returns true if that string appears in the
    //hash table, false otherwise.
    bool contains( const string & x ) const
    {
      int hash = hashfunction(x);
        if (!theLists[hash].empty()){   //if that slot of table isn't empty
          for (auto it = theLists[hash].begin(); it != theLists[hash].end(); it++){  //traverse along the linked list
            if (*it == x)   //if the pointer to the node of list has the value
              return true;  //true is returned
          }
        }
      return false;
    }


    //Clears everything from the hash table by going to each slot of hash table
    //and clearing the linked list. Current size is decreased by 1 each time.
    void makeEmpty( )
    {
      for (int i=0; i< theLists.size(); i++){
        while (!theLists[i].empty()){
          theLists[i].pop_front();    //the word is popped from front
          currentSize--;   //current size is decreased each time.
        }
      }
    }


    //This is used for the standard hash function as it uses the std hash
    //key to check if the table contains the string provided
    bool containsStd( const string & x ) const
    {
      int hash = stdhashing(x);    //using the standard hashing technique
        if (!theLists[hash].empty()){
          for (auto it = theLists[hash].begin(); it != theLists[hash].end(); it++){
            if (*it == x)
              return true;
          }
        }
      return false;
    }


    //This is used as an insert method for the standard hashing, this inserts
    //element to the table whose hash key is produced by the std hash function
    bool insertStd(const string & x){
      if (containsStd(x))
        return false;
      int hashVal = stdhashing(x);      //produce the hash key
      theLists[hashVal].push_back(x);
      currentSize++;    //currentSize is increased each time

      if (currentSize/theLists.size() > 4.0){
        stdrehash();}     //the rehash is done if load factor is > 4.0
      return true;
    }


    //This insert uses my very own hash function that I designed.
    bool insert( const string & x )
    {
      if (contains(x))
        return false;
      int hash = hashfunction(x);
      theLists[hash].push_back(x);
      currentSize++;

      if (currentSize/theLists.size() > 4.0){
        rehash();}
      return true;
    }


    //stdrehash is using this function.
    //At this case we don't have to check if the table contains the string
    //because we would have already emptied every element which are unique
    bool insertStdAgain(string & x){
      int hashVal = stdhashing(x);
      theLists[hashVal].push_back(x);
      currentSize++;
      return true;
    }
     //the rehash which uses my own hash function is using it.
    bool insertAgain( string & x ){
      int hash = hashfunction(x);
      theLists[hash].push_front(x);
      currentSize++;
      return true;
    }


    //This returns the vector with the chain length of all the slots of the
    //hash table.
    vector<int> chainLengths(){
      vector<int> chains;
      for (int i = 0; i<theLists.size(); i++){
        int chain = 0;
        for (auto it = theLists[i].begin(); it != theLists[i].end(); it++){ //same as traversing along linked list
          chain +=1;}
        chains.push_back(chain);
      }
      return chains;
    }


    //This returns the maxLength of all the chain lengths returned by chainLengths
    int maxLength(){
      vector<int> calc;
      calc = chainLengths();    //vector with all the chain lengths.
      int max = 0;
      for (int i=0; i<calc.size(); i++){
        if (calc[i] > max){     //if specific value is greater than max
          max = calc[i];   //max will be set to that value
        }
      }
      return max;
    }


    //This returns the average chain length excluding all chain lengths of value 0
    double avgLength(){
      vector<int> calc;
      calc = chainLengths();
      int tot = 0;
      int avg = 0;
      for (int i=0; i<calc.size(); i++){
        if (calc[i] != 0){    //those chain lengths with value not equal to 0
          tot += calc[i];    //total chain lengths is calculated
          avg +=1;    //average is increased if the length isn't 0
        }
      }
      return double(tot/avg);    //average is returned.
    }

    //This returns the total chain lengths of value zero
    int zeroLength(){
      vector<int> calc;
      calc = chainLengths();
      int tot = 0;
      for (int i=0; i<calc.size(); i++){
        if (calc[i] == 0){
          tot+=1;
        }
      }
      return tot;
    }


    //This returns the size of the table
    int size1(){
      return theLists.size();
    }

    //This prints those words which are in specific location in the table
    void printStrings(int ind){
      while (!theLists[ind].empty()){
        cout << theLists[ind].back() << endl;
        theLists[ind].pop_back();
      }
    }

    //Returns the rehash freq;
    int getRehash(){
      return rehashfreq;
    }

  private:
    vector<list<string>> theLists;   // The array of Lists
    int currentSize;   //tracks tht total entry to the table
    int rehashfreq;   //tracks the number of times rehashing was done


    //This is the rehash used by the table created using my own hash function
    void rehash() {
        rehashfreq++;
        vector<list<string>> theLists1  = theLists;   //old table is stored in a variable
        int initialSize = theLists.size();   //initial size is taken into account
        theLists.resize(initialSize * 2);   //our size is resized into twice the size
        makeEmpty();    //then the list is made empty
        currentSize = 0;    //at that time current size is 0
        for (int i =0; i<theLists1.size(); i++){
          while (!theLists1[i].empty()){
            insertAgain(theLists1[i].back());   //now the insertAgain is used
            theLists1[i].pop_back();    //all those elements are popped back
          }
        }
    }


    //Same as above rehash except it is used for the std hash function
    void stdrehash(){
      rehashfreq++;
      vector<list<string>> theLists1  = theLists;
      int initialSize = theLists.size();
      theLists.resize(initialSize * 2);
      makeEmpty();
      currentSize = 0;
      for (int i =0; i<theLists1.size(); i++){
        while (!theLists1[i].empty()){
          insertStdAgain(theLists1[i].back());
          theLists1[i].pop_back();
        }
      }
    }
    /*
    void moveElements(list<string> list1, list<string>list2){
        while (!list2.empty()){
          list1.push_back(list2.back());
          list2.pop_back();
        }
    }
    */


    //This returns the key of the string using the standard hash function
    size_t stdhashing(const string & x) const{
      int val = hash<string>()(x);
      return val % theLists.size();
    }


    //This function returns the key of the string using the hash function I created
    size_t hashfunction( const string & x ) const
    {
      int total;
      total = 0;
      for (int i = 0; i< x.length(); i++){
        //total +=int(x[i])*(i+1);    //takes the ascii value of each string and multiplies with i+1 and added as total
        //total += int(x[i]) * (17^i);  //17 is my favorite number //this one is better than the first
        //total += (101-int(x[i]))* (i+1);  //not good at all
        //
        //total += int(x[i]) * (7 - int(x[i]) % 7); // very bad
        //total += int(x[i])^((17-int(x[i])%17) * (i+1));   //the worst of all
        total += int(x[i])*(11+(i+1)^11);   //as 11 is the prime number
      }
      return total % theLists.size();
    }
};

#endif
