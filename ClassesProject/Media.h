
#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>
using namespace std;
class Media{
public: 
  Media();
  virtual int takeType();
  char* takeTitle();
  ~Media();
  int* takeYear();
  char title[10];
  int year;
};

#endif
