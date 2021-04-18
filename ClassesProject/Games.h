#ifndef GAMES_H
#define GAMES_H
#include <iostream>
#include <cstring>
#include "Media.h"
class Games: public Media
{
 public:
  Games(); //constructor
  ~Games(); //destructor
  virtual int takeType(); 
  char* takePublisher(); //returns the publisher
  double* takeRating(); //returns the rating
  char publisher[15]; //creates the publisher
  double rating; //creates the rating
  

};
#endif
