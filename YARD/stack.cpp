#include "stack.h"
#include <iostream>

using namespace std;

stack :: stack(node* newhead) { //CONSTRUCTOR
  stackhead = newhead;
}

node* stack :: peek() {
return stackhead;
}
node* stack :: pop() {//CHANGES THE TAIL
  node* current = stackhead;
  node* toreturn = NULL;
  if (current != NULL) {//IF STHE STACK ACTUALLY EXISTS
    while (current -> getNext() != NULL && current -> getNext() -> getNext() != NULL) {//checks 2 ahead to set next nul
      //pop();
      current = current -> getNext();
    }
    if (current -> getNext() != NULL) {
      toreturn = current -> getNext();
      current -> setNext(NULL);
    }
    else {
      toreturn = current;
      stackhead = NULL;
    }
  }
  return toreturn;//RETURN 
}

void stack :: push(node* toadd) {//NODE TO END
  if (stackhead != NULL) {
    node* current = stackhead;
    while (current -> getNext() != NULL) {
      //push (current ->getNext());
      current = current -> getNext();
    }
    current -> setNext(toadd);//END WITH IT
  }
  else {
    stackhead = toadd;//PUTS STACK
  }
}
