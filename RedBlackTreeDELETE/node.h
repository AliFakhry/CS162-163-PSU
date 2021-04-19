//
//  node.h
//  RBT
//
//  Created by Ali Fakhry on 3/14/20.
//  Copyright © 2020 Ali Fakhry. All rights reserved.
//

#ifndef guard
#define guard
class node {
 public:
  node();//CONSTRUCTOR
  ~node();//DEESTRUCTOR
  node* getLeft();
  node* getRight();
  node* getParent();
  void setData(int);
  int getData();
  void setCol(bool);
  bool getCol();
  void setLeft(node*);
  void setRight(node*);
  void setParent(node*);
  node* left;//LEFT NODE HOLDER
  node* right;//RIGHT NODE HOLDER
  node* parent;//PARENT NODE HOLDER
  int data;//HOLDS THE DATA
  bool color;//holds color
  void setNil(bool);
  bool getNil();
  bool isNil;
};

#endif
