/*
Author: Pritam Basnet
Date: November 29, 2018
FileName: wordchecker.cpp
This program does everything in question menu i.e it does three works 1, 2 and 5.
*/

#include "Word.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <sstream>
#include <cstdlib>
using namespace std;


//Makes the hash table using my own hash function I created exctracting words from
//wordlist
HashTable MakeTable(string filename){
  HashTable table1;
  ifstream file;
  file.open(filename);   //file is opened
  string word;
  getline(file,word);    //the first line which has number is read first
  while (file >> word){   //while the words
    table1.insert(word);   //words are inserted in the table1
  }
  return table1;
}


//Makes the hash table using the standard hash function.
//Everything is same as above function
HashTable MakeSecondTable(string filename){
    HashTable table1;
    ifstream file;
    file.open(filename);
    string word;
    getline(file, word);
    while(file >> word){
      table1.insertStd(word);
    }
    return table1;
}


//Spellchecker function to suggest those words which are misspelled and suggestions
//are provided.
void spellchecker(string filename, int request){
  word word1;
  HashTable table1;
    table1 = MakeSecondTable("wordlist.txt");   //table is created using std hash
    int suggestion = 0;    //vector containig suggestions
    string entered;
    bool flag1 = true;
    if (flag1 == true){    //if flag1 is true
      cout << "Please Enter a Sentence>>" << endl;
      while (getline(cin, entered)){   //asking sentence from users
        istringstream iss(entered);    //using istringstream to read each word
        string wording;
        bool flag;   //new flag
        flag= true;
        int count =0;
        while(iss >> wording) {    //use the stream to take each wording from teh input
          if (count ==0){    //Display this result thing only once
            cout << "RESULT: " << endl;
            cout << "*****************" << endl;
          }
          flag = true;
          string newWord;
          for (int i=0; i<wording.length(); i++){   //checks for the upper case
            if (isalpha(tolower(wording[i])))   //also if something like . is contained then it takes care of it
              newWord+=tolower(wording[i]);
          }
          wording = newWord;
          if (!table1.containsStd(wording)){   //if that word isn't in table it is misspelled
            cout << "Word Not Found: "<< wording << endl;
            cout << "-----------------------" << endl;
            cout << "Perhaps you meant:" << endl;
            vector<string> checker = word1.wordchecker(wording);   //checker stores all the words to produce suggestions
            for (int i=0; i<checker.size(); i++){
              if (table1.containsStd(checker[i]))   //now among those suggestions which are correct
                cout << "\t"<<checker[i] << endl;   //those are displayed
                suggestion++; }
            }
            count +=1;   //count is increased to stop displaying result thing each time
            flag = false;
          }
          if (flag == false){
          if (suggestion ==0)   //if no any misspelling
            cout << "No any misspelling in this sentence. Thank you!"<< endl;

          string cmmnd;
          cout << "Please type 'quit' if you want to end the spell checker or 'resume' to continue" <<endl;
          cin >> cmmnd;
          if (cmmnd == "resume"){   //resumes the process
            cout << "Please Enter a Sentence>>" << endl;
            flag1 = true;}

          else if (cmmnd == "quit")   //if user wants to quit the program is ended.
            exit(0);
          }
        }
  }
}


//This displays the result from my own hash function ahd from the standard hash
//function
void loadingtest(string filename, int request){
  HashTable table1;
  if (request == 1 || request == 2){   //if the request is one or two
    if (request == 1){
      cout << "Using Standard Hash Function" << endl;   // 1 is using standard hash function
      cout << "----------------------------" << endl;
      table1 = MakeSecondTable("wordlist.txt");
    }
    if (request == 2){    //but if the request is two table creation is different
      cout << "Using My Own Hash Function" << endl;
      cout << "----------------------------" << endl;
      table1 = MakeTable("wordlist.txt");
    }
    cout << "RESULTS:"<< endl;
    cout << "***********" << endl;
    cout << "Initial hash table size: 101" << endl;   //initial list size is 101
    cout << "Max Load factor: 4.00" << endl;    //max load factor is set to be 4.0
    cout <<"No.of times rehashing were done: " << table1.getRehash() <<endl;
    cout << "Final hash table size is: " << table1.size1() << endl;
    cout << "Current load factor= " << float(table1.Size()/table1.size1()) << endl;
    cout << "Max chain length: " << table1.maxLength() << endl;
    cout << "Avg chain Length: " << table1.avgLength() << endl;
    cout << "Number of zero-length chains: " << table1.zeroLength() << endl;}
}


int main(){
  int process;
  cout << "Enter (1,2 or 5)"<< endl;
  cout << "1>> Load wordlist to Separate Chaining using STANDARD HASH" << endl;
  cout << "2>> Load wordlist to Separate Chaining using MY OWN HASH" << endl;
  cout << "5>> Run Spell Checker" << endl;
  cin >> process;
  loadingtest("wordlist.txt", process);
  if (process == 5){   //if process is 5 then the spellchecker is run
    spellchecker("wordlist.txt", process);}
}
