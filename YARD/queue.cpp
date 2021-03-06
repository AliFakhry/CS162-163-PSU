#include "queue.h"
#include <iostream>

using namespace std;

queue :: queue() {//constructor
  queuehead = NULL;
  queuetail = NULL;
}

node* queue :: getQueueHead() {///GET THE HEAD
  return queuehead;
}

node* queue :: getQueueTail() {//GET TAIL
  return queuetail;
}

node* queue :: dequeue() {//REMOVES THE TOP OFF QUEUE
  node* RETUTRNING = queuehead;
  if(queuehead != NULL) {
    queuehead = queuehead -> getNext();
  }
  if (queuehead == NULL) { 
    queuetail = NULL;
  }
  return RETUTRNING;
}

void queue :: enqueue(node* ADD) {//ADD TO END
  if (queuetail != NULL) {
    queuetail -> setNext(ADD);
    queuetail = ADD;
  }
  else {
    //makes first node the added
    queuehead = ADD;
    queuetail = ADD;
  }
}
