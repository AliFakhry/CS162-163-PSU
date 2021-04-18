
#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;
Media::Media() 
{
}
int Media::takeType() {
}
char* Media::takeTitle() //gets the title
{
  return title;
}
int* Media::takeYear() //gets the year
{
  return &year;
}
Media::~Media() {}
