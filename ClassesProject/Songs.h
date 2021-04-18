#ifndef SONGS_H
#define SONGS_H
#include <iostream>
#include <cstring>
#include "Media.h"
class Songs: public Media 
{
 public:
   Songs(); //constructor
  ~Songs(); //destructor
  virtual int takeType(); //returns an int to say that it is a song
  char* takePublisher(); //returns the publisher
  char* takeArtist(); //returns the artist
  double* takeDuration(); //returns the duration
  char artist[20]; //creates the artist
  double duration; //creates the duration
  char publisher[20]; //creates the publisher array
 
};
#endif
