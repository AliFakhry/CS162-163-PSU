#include "node.h"
class stack {
 public:
 //THE METHODS NEEDED
  stack(node*); 
  node* pop(); // POP
  void push(node*); //PUSH
  node* peek(); //PEEK
  node* stackhead;//HEAD WHICH IS ESSENTIALL THE TAIL
};
