//Ali Fakhry
//Period 3
//12 Decemeber 2019
//Linked List, using nodes and no structs for a student list code type

#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;
  
//initilize the methods
void add(char* firstName, char* lastName, int ID, double GPA);
void print (Node* head);


int main ()
{ 
  char firstNameINPUT[10];
  char lastNameINPUT[10];
  double GPA;
  int ID;
  bool run = true;
  while (run == true) { //continously runs, adding the student and prints
      cout << "FirstName?" <<endl;
      cin.get(firstNameINPUT,10);
      cin.get();
      cout << "LastName?" <<endl;
      cin.get(lastNameINPUT,10);
      cin.get();
      cout << "ID?" << endl;
      cin >> ID;
      cin.get();
      cout << "GPA?" <<endl;
      cin >> GPA;
      cin.get();
      add(firstNameINPUT, lastNameINPUT, ID, GPA);
    
  }
}

void add(char* firstName, char* lastName, int ID, double GPA){  //add method
  Student* a = NULL;
  Student* b = NULL;
  bool running = true;
  bool running2 = true;
  Node* head = NULL;
  Student* newStudent;
  newStudent= new Student(firstName,lastName,ID,GPA); //creates the new student
  Node* current = head;
  if(current == NULL) { //if the head is the equal to null, set it equal to the student node
      head = new Node(a);
      head -> setStudent (newStudent); 
    }
  else if (current != NULL) { //if the pointer is not at the end of the array make it equal to the next node
      if (current->getNext() != NULL) 
	{
	  running2 =false;
	}
      while (running2 == true) //while running is true
      {
	current = current -> getNext(); //make the node equal to next
      }
      current -> setNext(new Node(b)); //create a new node
      current -> getNext() -> setStudent(newStudent); //place node into the input of the function
    }
    print(head); //put the node into the printer
  }
void print(Node* temp) { //print recursivley, printing out the whole list 
	if (temp != NULL)
	  {
	    cout << "FIRST NAME:" << temp -> getStudent()->getFirstName() << endl;
	    cout << "LAST:" << temp->getStudent()->getLastName() << endl;
	    cout << "ID:"<<  temp->getStudent()->getID() << endl;
	    cout << "GPA:" << temp -> getStudent() -> getGPA();
	    print (temp -> getNext()); //recursivley print till finished
	    cout<< endl;
	    cout<<endl;
	  }
      }

