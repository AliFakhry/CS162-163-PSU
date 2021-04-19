#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public: 
  //initilzes the student constructor
  Student(char* setFirstName, char* setLastName, int setID, double setGPA);
  //student destructor
  ~Student();
  //variables
  char* getFirstName();
  char* getLastName();
  double getGPA();
  int getID();
  char lastName[10];
  char firstName[10];
  int ID;
  double GPA;


};
#endif
