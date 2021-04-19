//imports                                                                                                   
#ifndef node_H
#define node_H
#include <iostream>
#include <cstring>
using namespace std;

class node {
public:
  //METHODS AND VARIABLES NEEDED
  node(char*);
  void setRight(node*);
  void setLeft(node*);
  node* getRight();
  node* getLeft();
  bool isLeft();
  bool isRight();
  void setNext(node*);
  node* getNext();
  char* getData();
  node* next = NULL;
  node* left = NULL;
  node* right = NULL;
  char* data;
};

#endif
