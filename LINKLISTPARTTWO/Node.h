// Node Header File

#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();
  void setStudent(Student*);
  Student* getStudent();
  void setNext(Node* NextNextNode);
  Node* getNext();
 private:
  Student* student;
  Node* nextNode;

};

#endif
