#include <iostream>
#include <cstring>
#include "Media.h"
#include "Songs.h"
using namespace std;

Songs::Songs()
{
}
int Songs::takeType() { //returns the virtual pointer
  return 3;
}
char* Songs::takeArtist() //gets the artist 
{
  return artist;
}

char* Songs::takePublisher() //gets the publisher and 
{
  return publisher;
}

double* Songs::takeDuration() //gets the duration
{
  return &duration;
}
Songs::~Songs() { //destructor
  delete []publisher;
  delete []artist;
  delete []title;
}
