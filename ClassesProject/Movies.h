#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <cstring>
#include "Media.h"
class Movies: public Media //class definition
{
 public:
  Movies();//constructor
  ~Movies();//destructor
  virtual int takeType(); //returns an int that says that it is a movie
  char* takeDirector(); //returns the director
  double* takeRating(); //returns the rating
  double* takeDuration(); //returns the duration
  double rating; //creates the rating
  double duration; //creates the duration
  char director[20]; //creates the director
 
};
#endif
