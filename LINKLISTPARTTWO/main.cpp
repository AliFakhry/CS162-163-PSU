
//ALI FAKHRY: Help from Sethu Eapen and Tejash Panda
//11 January, 2020
//Linked List 
//Takes the first,last name of a student, id, and their gpa to make a student
//Student are put in  nodes that contain the next nodes in series which are linked lists
//The commands are ADD, PRINT, DELETE, and AVERAGE



#include <iostream>
#include "Node.h"
#include <cstring>
#include <ctype.h>
#include <iomanip>

using namespace std;




void add(Node*&, int, Student*, int);//asks for the students information -USING RECURSION
void add2(Node*&, Student*, int); //puts it in a linked list
Node* add3(int, Node*); //sorts the students by their ID - USING RECURSION                                                                                                                                                                  v
void print(Node*); //takes by value node to help print -USING RECURSION
void deletenode(int, Node*&, Node*, Node*);//passes reference to a specific node to be deleted, thus deleting the entire student -USING RECURSION
void average(Node*); //passes the node head, and finds the average of the GPAS


int main() {

   Node* head = NULL; //the head starts the linkedlist
  
  //START 
  bool run = true; //used to store if the program should continue
  while (run == true) {
    cout << "INPUT A COMMAND(ADD,PRINT,QUIT,AVERAGE,DELETE)" << endl;
    char input [80];
    cin.getline(input, 80); //takes in user's input
    
    if (strcmp(input, "ADD") == 0) { //if command is add run add function
      Student* stu = new Student(); //student that will be added to node                                                                                                                                                                
      int Z;
      add(head, 0,stu,Z);
    }

    else if (strcmp(input, "PRINT") == 0) { //if command is add run add function
      print(head);
    }
    
    else if (strcmp(input, "QUIT") == 0) { //if command is quit exits loop
      run = false;
    }
    else if (strcmp(input, "AVERAGE") == 0) { //if command is Average mean of gpa
      average(head);
    }
    
    else if (strcmp(input, "DELETE") == 0) { //if command is delete run delete function
      int delid;//holds id for student
      cout << "Please input the id of the student you wish to delete" << endl;
      cin >> delid; 
      cin.ignore(); 
      //help from SethuEapen <- For the DELETE
      deletenode(delid, head, head, head); //deletes the node at the id, beings with all 3 nodes being the head
    }

  }
  //help from SethuEapen <- For the "clean up"
  if(head != NULL) { 
    bool DELETENODE = false; //says not all is deleted
    Node* FIRSTVARIABLE = NULL; //one before current node
    while (DELETENODE == false) {//while not all deleted
      Node* TEMPORARY = head;
      while (TEMPORARY -> getNext() != NULL) { //if another in list
	FIRSTVARIABLE = TEMPORARY;//makes FIRSTVARIABLE equivalent to TEMPORARY
	delete FIRSTVARIABLE;//deletes FIRSTVARIABLE
	TEMPORARY = TEMPORARY -> getNext();//goes to next in list
      }
      //at end
      delete TEMPORARY;//deletes pointer 
    }
  }
}
//end
void add(Node*& head, int x, Student* stu, int ID2) {
  
  int ID3 = ID2;
  if (x==0) {
  cout << "Please input the first name" << endl;
  char* fname = new char[80]; //pointer for first name
  cin.getline(fname, 80); //makes the pointer point to input
  stu -> setFName(fname); //set student's first name
  x++;
  add(head,x, stu, 0);
  }
  else if (x==1) {
  cout << "Please input the last name" << endl;
  char* lname = new char[80];//pointer for last name
  cin.getline(lname, 80);// makes pointer point to input
  stu -> setLName(lname); //sets last name
  x++;
  add(head,x,stu, 0);
  }
  
  else if (x==2){
  bool corid = false;//whether id is valid
  int id; //holds id
  while (corid == false) { //if not valid
    cout << "Please input the student id" << endl;
    cin >> id; //puts input into in
    cin.ignore(); //for compat with cin.getline
    if(id > 99999 && id < 1000000) {//if 6 digits
      ID2=id;
      stu -> setID(id); //sets id
      corid = true;//exits while
    }
    else{
      cout << "Make sure the student id is six digits" << endl;
    }
  }
  x++;
  add(head,x,stu, ID2); //runs recursion
  }
  
  else if (x==3){
  double gpa;//double to hold gpa
  bool corgpa = false; //if gpa is valid or not
  while (corgpa == false) { //while not valid
    cout << "Input the Gpa" << endl;
    cin >> gpa;//puts input into double
    cin.ignore();
    if (gpa < 5 && gpa > -.001) {
      stu -> setGPA(gpa);//sets student gpa
      corgpa = true;//valid
    }
    else{
      cout << "Please input a gpa between 0 and 6" << endl;
    }
  }
  x++;
  add(head, x,stu, ID3);
  }
  else if (x==4) {
    add2(head, stu, ID3);
  }
}
//used online source on how to do some of this part, I can't find it again though. 
void add2(Node*& being, Student* stu, int ID2) {
  
Node* find = being; //the node that will be made                                                                                                                                                                                       

 if (find == NULL) {//if no existing list
    being = new Node(NULL); //being is a new node
    being -> setStudent(stu);
    being -> setNext(NULL);
  }
  else {
    Node* infront = add3(ID2, being);// runs sort to determine
    Node* newNode = new Node(NULL); //creates new node
    newNode -> setStudent(stu);// in new node put the student
    if(infront -> getNext() == NULL) { //if the one in front is at end of list
      if(ID2 < infront -> getStudent() -> getID()) {
	newNode -> setNext(infront);//puts before infront
	if(infront == being) {
	  being = newNode;//new node becomes head
	}
      }
      else {
	newNode -> setNext(NULL); //if id is greater
	infront -> setNext(newNode);
      }
    }
    else{
      if(infront == being && ID2 < infront -> getStudent() -> getID()) {//if next is not null and id is less than infront
	being = newNode;//Newnode is head
	newNode -> setNext(infront);//put at being of list
      }
      else {//some.where in the middle
	newNode -> setNext(infront -> getNext());//next is one after infront
	infront -> setNext(newNode);//new node is placed after infront
      }
    }
  }
}

Node* add3(int id, Node* check) {
  if(check -> getNext() != NULL){
    if(id < check -> getNext() -> getStudent() -> getID()) {
      return check; //will return the node 
    }
    else {
      check = add3(id, check -> getNext()); //sorts again, when place is found, check is set equal
      return check;//returns check again either to FIRSTVARIABLE sort or add
    }
  }
  else {
    return check;
  }
}

void print(Node* n) { //Print Function
  if(n != NULL) {//if the current node is not null
    cout << "First Name: " << n -> getStudent() -> getFName() << endl; //print out first name
    cout << "Last Name: " << n -> getStudent() -> getLName() << endl; //print out last name
    cout << "Id: " << n -> getStudent() -> getID() << endl; //prints id
    cout << "GPA: " << setprecision(3) << n -> getStudent() -> getGPA() << endl; //prints gpa
    cout << endl;
    print(n -> getNext()); //moves to next node
  }
}
//FINDS AND DELETES THE NODE NEEDING TO BE DELETED
void deletenode(int delid, Node*& head, Node* FIRSTVARIABLE, Node* del) {
  bool found = false; //USED TO KEEP TRACK FOR THE NODE NEEDING TO BE DELETED
  if (del != NULL){
    if (found == false){
      if (del -> getStudent() -> getID() == delid){//IF IT IS THE NODE NEEDED TO BE DELETED
	found = true;//FINDS THE NODE NEEDED
      }
      else{
	deletenode(delid, head, del, del -> getNext()); //RECURSIVE TO FIND IT
      }
    }
  
    if (found == true) {//TIME TO DELETE THE NODE! IT HAS BEEN FOUND
      cout << "FOUNDED!" <<endl;
      if (FIRSTVARIABLE == del && del -> getNext() != NULL){//IF THE FIRSTVARIABLE (FIRST NODE) HAS THE ID && ANOTHER NODE EXISTS AFTER (!=NULL)
	cout << "1" <<endl;
	head = del -> getNext();//HEAD CHANGES TO THE ONE AFTER DEL
	del -> ~Node(); //runs destructor 
      }
      else if(FIRSTVARIABLE == del) { //NEXT IS NULL 
      cout << "2" <<endl;
      cout << "2a" <<endl;
      head = NULL; //THE HEAD = NULL
      cout << "2b" <<endl;
      }
      else {
	if(del -> getNext() == NULL){ //AT THE END OF THE LINKED LIST
	  FIRSTVARIABLE -> setNext(NULL);//BEFORE IS HEAD
      }
	else{ 
	  FIRSTVARIABLE -> setNext(del -> getNext());//FIRSTVARIABLE IS POINTING TO THE ONE PAST THAT SHOULD BE DELETED
	}
      }
    }
  }
  else{ 
    //isn't even here
    cout << "WHAT? THAT DOESN'T EVEN EXIST!!" << endl; 
  }
}

void average(Node* being) {//will average  all nodes
  if (being != NULL) { //are there nodes
    int count = 0; //counts amounts
    double gpa = 0; //holds sum of terms
    while(being != NULL) {
      gpa += being -> getStudent() -> getGPA();
      count += 1;
      being = being -> getNext(); //on to the next node
    }
    gpa = gpa / count; //divides the total sum by number of terms
    cout << "The average GPA is " << setprecision(3) << gpa << endl;//prints gpa to two decimal points 
  }
  else {
    cout << "No Students" << endl;
  }
}
