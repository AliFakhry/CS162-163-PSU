#include <iostream>
#include <map>
#include "Room.h"
#include "Item.h"
using namespace std;
Item::Item() {}
  void Item::setName(char* newName) {
    name = new char[80]; 
    strcpy(name, newName); //Copy the item name to a char* name
  }

  char* Item::getName(){ //returns the name of the item
    return name; 
  }

  void Item::setL(Room* newL) { // pointer to the room it will be in
    L = newL;//store the pointer
  }
Room* Item::getL() {//returns pointer to the item place
  return L;
}
