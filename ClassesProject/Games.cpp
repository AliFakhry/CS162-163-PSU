#include <iostream>
#include <cstring>
#include "Media.h"
#include "Games.h"
using namespace std;

Games::Games() //constructor
{
}
int Games::takeType() { //creates virtual pointer, 2, that says it is a game
  return 2;
}

char* Games::takePublisher() //return the publisher
{
  return publisher;
}

double* Games::takeRating() //returns the rating 
{
  return &rating;
}
Games::~Games() //destructor
{
  delete []publisher;
  delete []title;
}
