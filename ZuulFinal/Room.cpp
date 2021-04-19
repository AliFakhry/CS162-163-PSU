#include <iostream>
#include <map>
#include <cstring>
#include "Room.h"
using namespace std; 
Room::Room() {}
  void Room::setDes(char* newDes) {
    des = new char[100]; // what it is pointing to
    strcpy(des, newDes); //copies description to another the other pointer
  }

  char* Room::getDes() {
    return des;
  }

  void Room::setMap(map<char*, Room*>* newExits) {//pass the pointer to a map of char* and zuulroom*(for exits)
    exits = new map<char*, Room*>; //defines what exits it is pointing to
    exits = newExits; // store the exits
  }

  map<char*, Room*>* Room::getMap() {//returns pointer to the map of exits
    return exits;
  }

  void Room::setTitle(char* newTitle) {
    title = new char[80]; // defines what it is pointing to
    strcpy(title, newTitle); //copies name into the other pointer
  }

  char* Room::getTitle() {//gets the pointer to the name and returns it
    return title;
  }


