//NODE CPP CLASS
#include "node.h"
#include <iostream>

node :: node(int newdata) { //constructor
    left = NULL;
    right = NULL;
    data = newdata;
    head = NULL;
}

node :: ~node() {//destructor
    left = NULL;
    right = NULL;
    head = NULL;
}

void node :: setLeft(node* newLeft) {//sets left location
  left = newLeft;
}

void node :: setRight(node* newRight) {//sets right location
  right = newRight;
}

node* node :: getLeft() {//gets left location
  return left;
}

node* node :: getRight() {//gets right location
  return right;
}

void node :: setData(int newdata) {//used to set data
  data = newdata;
}

int node :: getData() {//used to get data
  return data;
}

void node :: setHead(node* newHead)
{
    head = newHead;
}
