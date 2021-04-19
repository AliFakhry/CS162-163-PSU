#ifndef STUDENT_H
#define STUDENT_H


class Student {

 public:
  void setFName(char*); //Sets the student's first name
  char* getFName(); //returns fname

  void setLName(char*); //Sets the student's last name
  char* getLName(); //returns last name

  void setID(int); //Sets the students 6 digit ID number
  int getID(); //Returns ID

  void setGPA(double); //Sets the students gpa to 2 decimal place
  double getGPA(); //Returns to two decimal places

  char* fname; //keeps the student's first name
  char* lname; //keeps the student's last name
  int id; //keeps the student's 6 digit id number
  double gpa; //keeps the student's gpa

};
#endif
