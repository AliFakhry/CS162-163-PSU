#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movies.h"
using namespace std;

Movies::Movies()
{
}
int Movies::takeType() { //makes a virtual pointer that returns 1
  return 1;
}
char* Movies::takeDirector() //gets and returns the director
{
  return director;
}

double* Movies::takeRating()//gets and returns the rating
{
  return &rating;
}

double* Movies::takeDuration() //gets and returns the duration
{
  return &duration;
}
Movies::~Movies() //destructor
{
  delete []title;
  delete []director;
}
