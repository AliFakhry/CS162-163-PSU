#include <iostream>
#include "node.h"

node::node(char* setData)
{
 data = setData;
 right = NULL;
 left = NULL;
 next = NULL;
}

void node::setRight(node * newRight) //sets right
{ right = newRight;}

void node::setLeft(node * newLeft) //set left
{ left = newLeft;}

node * node::getRight() //get rght
{ return right;}

node * node::getLeft() //get left
{ return left;}

void node::setNext(node* newNext) //setnext
{ next = newNext; }

node* node::getNext() //get the next
{return next;}

char* node::getData() //get the data
{ return data; }

bool node::isRight() //if there right
{
  if (left != NULL) {
    return true;
  }
    return false;
}
bool node::isLeft() //if there is left
{
  if (left != NULL) {
    return true;
  }
    return false;
}
