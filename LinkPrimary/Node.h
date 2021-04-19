#ifndef NODE_H
#define NODE_H 
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node {
 public:
  //constructor
  Node(Student*);
  //destructor
  ~Node();
  //variables
  void setStudent(Student*);
  Student* getStudent();
  void setNext(Node* newNext);
  Node* getNext();
  Student* student;
  Node* next;
};
#endif
