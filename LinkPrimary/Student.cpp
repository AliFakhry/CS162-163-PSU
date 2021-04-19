#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(char* setFirstName, char* setLastName, int setID, double setGPA) { //constructor used for student, used to initilize first,last, id and gpa
  // char firstName[10];
  // char lastName[10];
  //int ID;
  //double GPA;
  strcpy(firstName, setFirstName);
  strcpy(lastName, setLastName);
  ID = setID;
  GPA = setGPA;
}
Student:: ~Student() { //destructor if needed
  delete &firstName;
  delete &lastName;
  delete &ID;
  delete &GPA;
}

char* Student::getFirstName() { //gets the first name
  return firstName;
}
char* Student::getLastName() { //gets the last name
  return lastName;
}
double Student::getGPA() { //gets the gpa
  return GPA;
}
int Student::getID() { //gets the ID
  return ID;
}
