#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;
Node::Node(Student* inStudent) { //constructor
  student = inStudent;
  next = NULL;
}
Node::~Node() { //destructor
  delete &student;
  next = NULL;
}
void Node::setStudent(Student* newStudent) {//sets the student
  student = newStudent;
}
Student* Node::getStudent() {//gest the student
  return student;
}
void Node::setNext(Node* newNext) { //sets the next student
  next = newNext;
}
Node* Node::getNext() { //gets the next
  return next;
}
