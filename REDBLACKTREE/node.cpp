//
//  node.cpp
//  RBT
//
//  Created by Ali Fakhry on 3/14/20.
//  Copyright © 2020 Ali Fakhry. All rights reserved.
//

#include "node.h"
#include <iostream>

node :: node() {
  left = NULL;
  right = NULL;
  parent = NULL;
  color = 0;
  data = 0;
}

bool node :: getCol() {//RETURNING THE COLOR
  return color;
}
node* node :: getLeft() {//GETTING LEFT
  return left;
}

node :: ~node() {//DESTRUCTOR
  left = NULL;
  right = NULL;
}

void node :: setLeft(node* newLeft) {//SETTING LEFT
  left = newLeft;
}

void node :: setRight(node* newRight) {//SETTING RIGHT
  right = newRight;
}

void node :: setParent(node* newParent) {//SETTING PARENT
  parent = newParent;
}

node* node :: getParent() {//GETTING PARENT
  return parent;
}

void node :: setData(int newdata) {//SETS THE DATA
  data = newdata;
}

int node :: getData() {//GETTING DATA
  return data;
}

void node :: setCol(bool newcol) {//SETTING THE COLOR
  color = newcol;
}


node* node :: getRight()
{//GETTING RIGHT
  return right;
}
