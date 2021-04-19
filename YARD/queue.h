#include "node.h"
class queue {
 public:
  //prototypes
  queue();
  //METHODS AND VARIABLES
  void enqueue(node*);
  node* getQueueHead();
  node* getQueueTail();
  node* dequeue();
  node* queuehead;//HEAD (ESSENTIALLY THE HEAD)
  node* queuetail;//TAIL
};
