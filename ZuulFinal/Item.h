#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Item{
 public:
  Item();
  void setName(char*);//sets the name of item
  char* getName(); 
  void setL(Room*); //Sets which room it is in
  Room* getL(); //Returns  room it is in
  char* name; //holds the name of item
  Room* L; 
};
#endif
