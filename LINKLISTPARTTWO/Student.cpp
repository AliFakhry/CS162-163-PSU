#include "Student.h"
#include <cstring> //For strcpy

void Student :: setFName(char* newFName) { //Studen's first name
  fname = new char[80];//Makes fname
  strcpy(fname, newFName); //copies the passed first name into fname
}

char* Student :: getFName() { //Returns student's first name
  return fname;
}

void Student :: setLName(char* newLName) { //Sets student's last name
  lname = new char[80];//Makes last name
  strcpy(lname, newLName); 
}

char* Student :: getLName() { //Returns student's last name
  return lname;
}

void Student :: setID(int newID) { //Sets the student's ID
  id = newID;
}

int Student :: getID() { //returns the students ID
  return id;
}

void Student :: setGPA(double newGPA) { //Sets the student's gpa
  gpa = newGPA;
}

double Student :: getGPA() { //Returns gpas
  return gpa;
}
