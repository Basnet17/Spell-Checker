#include "SeperateChain.h"
#include <functional>
#include <unordered_map>
using namespace std;

void test()
{
  HashTable table1;
  table1.insert("people");
  cout << table1.printcode("people") << endl;
  table1.insert("machine");
  cout << table1.printcode("machine") << endl;
  table1.insert("peopleee");
  cout << table1.printcode("peopleee") << endl;
  table1.insert("peoplet");
  table1.insert("people");
  table1.insert("macine");
  table1.insert("poplet");table1.insert("eople");
  table1.insert("machie");
  table1.insert("peopeee");
  table1.insert("pplet");table1.insert("pee");
  table1.insert("mhine");
  table1.insert("peoe");
  table1.insert("peot");table1.insert("ople");
  table1.insert("machinesdf");
  table1.insert("peopleeefasdf");
  table1.insert("peopletasdf");table1.insert("peopleasdf");
  table1.insert("machinesdf");
  table1.insert("peopleeeasdf");
  table1.insert("peopletsadf");
  cout << table1.contains("machine") << endl;

  //table1.printStrings(0);
  //cout << table1.contains("peopleee") << endl;
  //cout << table1.contains("people") << endl;
  //cout << table1.hashfunction("How you doing?");
  //cout << table1.contains("peopleee") << endl;
  //cout <<table1.printcode("people") << endl;
  //cout << table1.printcode("peopleee") << endl;
  //cout << table1.contains("people");
  //table1.showContents();
  cout << table1.avgLength() << endl;
  //table1.makeEmpty();
  //cout << table1.size1() << endl;
  //cout << table1.Size() << endl;


  //HashTable table2;
  //table2.insertStd("people");
  //cout << table2.containsStd("people") << endl;
  //hash<string> table2;
  //cout << hash<string>()("machine") << endl;
  //hash<string> hasher;
  //size_t hash = hasher("people");
  //cout << hash << endl;
  //table1.showContents();
  //cout << table1.size1()/3 << endl;
  //table1.rehash();

  /*
  list<string> list1;
  list<string> list2;
  list1.push_back("hello");
  list1.push_back("hello");
  list1.push_back("how");
  list1.push_back("low");
  while (!list1.empty()){
    list2.push_back(list1.back());
    list1.pop_back();
  }
  cout << list2.size() << endl;*/

}
int main(){
  test();
  return 0;
}
