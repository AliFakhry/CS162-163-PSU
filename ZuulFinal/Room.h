#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <map>
using namespace std;
class Room {
public:
  Room();
  void setDes(char*);// set room description
  char* getDes();//return room description
  void setMap(map<char*, Room*>*);//put  a map of exits
  map<char*, Room*>* getMap();//return a map of exits
  void setTitle(char*);// set room title
  char* getTitle();//return room title

  char* des;//stores description
  map<char*, Room*>* exits;//stores map
  char* title;//stores the room title
};
#endif
