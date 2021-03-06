//ALI FAKHRY: SHUNTING YARD
//TAKE INPUT, SEPERATOR OPERATORS AND NUMBERS BY PRESEDENCE FOR OPERATORS, AND CHOSE THE METHOD OF PRINTING,INFIX, POSTFIX, PREFIX
//CITATIONS: SETHU EAPEN, WIKIPEDIA PSEUDO CODE
#include <iostream> //includes
#include "node.h"
#include "stack.h"
#include "queue.h"
#include <ctype.h>
#include <cstring>
//function prototypes
queue* shunt(queue*, char*);
bool check(char, char);
void postfix(node*);
void prefix(node*);
void infix(node*);
node* buildtree(queue* postfix);

using namespace std;

int main() {
  // cout << "DO NOT USE SPACES" << endl;
  cout << "INPUT EQUATION IN INFIX DON'T USE SPACES" << endl; 
  queue* POST = new queue();//WILL HOLD THE NEW QUEUE
  char* inf = new char [60];
  cin.getline(inf,60);
  POST = shunt(POST, inf); //runs shunting yard with input
  // node* postHead = POSTED -> getQueueHead();
  // while (POSTED -> getQueueHead() -> getNext() != NULL) 
  //  {
  //    cout << POSTED -> getQueueHead() -> getData();
  //    postHead = postHead -> getNext();
  //  }
  // cout << POSTED -> getQueueHead() -> getData();
  node* TREE = buildtree(POST);//builds tree

    cout << "postfix, prefix, infix" << endl;
    char* trans = new char [60];//holds command
    cin.getline(trans, 60);
    if (strcmp(trans, "postfix") == 0) {
      postfix(TREE);//postfix
      cout << endl;
    }
    else if (strcmp(trans, "prefix") == 0) {
      prefix(TREE);//prefix
      cout << endl;
    }
    else if (strcmp(trans, "infix") == 0) 
      {
      infix(TREE);//infix                                                                                                                                                                                                 
      cout << endl;
      }
}
//infix: PSEUDO CODE FROM WIKIPEDIA
void infix(node* Tree)
{
  if ((*Tree->getData() == '+' || '-' || '*' || '/' || '^' ))                                                                                                                                                               
    {
      cout << "(";                                                                                                                                                                                                  
    }
  if (Tree->getLeft() != NULL)                                                                                                                                                                              
  {
    infix(Tree->getLeft());                                                                                                                                                           
  }
cout << Tree->getData() << "";                                                                                                                                                                              
if (Tree->getRight() != NULL)                                                                                                                                                                     
  {
    infix(Tree->getRight());                                                                                                                                                          
  }
if ((*Tree->getData() == '+' || '-' || '*' || '/' || '^'  ))                                                                                                                                                               
  {
    cout << ")";
  }
}                                                                                         
//postfix: PSEDUO CODE SOURCES FROM WIKIPEDIA
void postfix(node* Tree) 
{
  if (Tree != NULL)  
    {
      
      if (Tree-> getLeft() != NULL)

	{
	  postfix(Tree->getLeft());
	}
      if(Tree->getRight() != NULL)
	{
	  postfix(Tree->getRight());
	}

      cout << Tree-> getData() << " ";
    }
}

//prefix: PSEUDO CODE SOURCE FROM WIKIPEDIA
void prefix(node* Tree) 
{
  if (Tree != NULL)
    cout << Tree->getData() << " ";
    {
      if (Tree -> isLeft() == true)
	{
	  prefix(Tree -> getLeft());
	}
      if (Tree -> isRight() == true)
	{
	  prefix(Tree-> getRight());
	}
    }

}
//MAIN SHUNTING PROGRAM:
queue* shunt(queue* POSTED, char* infix) {
  stack* STACKED = NULL; 
  //PUT OPERATOR ON THE STACK
  for(int i = 0; i < strlen(infix); i++) {//RUN THE LENGTH
    if(isdigit(infix[i]) == true) { 
	//builds array for data
	char* data = new char[60];
	bool run = true;
	int INITIALVAR = i;
	data[0] = infix[i];
	while (run == true){//PUT DIGITS IN A NEWEST ARRAY
	  if (isdigit(infix[i+1])) {
	    i = i+1;
	    data[i - INITIALVAR] = infix[i];
	  }
	  else{
	    run = false;//got full number
	  }
	}
	data[i+1] = '\0';
	node* newNode = new node(data);//CREATE A NEW NODE WITH THE DATA
	POSTED -> enqueue(newNode);//ADD IT
    }
    else if (infix[i] == '(') {//IF STARTING WITH OPEN
      char* WORK = new char[1];
      WORK[0] = '(';
      //WORK[1] = '\0';
      node* ANOTHER = new node(WORK);
      if (STACKED == NULL) {
	    STACKED = new stack(ANOTHER);
      STACKED -> peek(); //checks to see if it will run (DEBUGGER)
      }
      else{
	STACKED -> push(ANOTHER); 
      }
    }
    else if (infix [i] == ')'){
      bool remove = false;
      while (remove == false){
      node* pop = STACKED -> pop();
	if (pop -> getData()[0] != '(') { 	  
    POSTED -> enqueue(pop); //enqueue
	}
	else {

	  remove = true; //END
	}
      }
    }
//ALGORITHUM FROM: https://rosettacode.org/wiki/Parsing/Shunting-yard_algorithm
    else { //OPERATOR GEOST TO STACK
      if (STACKED == NULL) {
	//puts operator into array
	char* data = new char[2]; 
        data[0] = infix[i];
        //data[1] = '\0';
	node* newNode = new node(data);//MAKES THE NODE
	STACKED = new stack(newNode);//CREATE THE STACk
      }
      else {
	//puts opperator in array
	char* data = new char[2];
	data[0] = infix[i];
	//data[1] = '\0';
	node* newNode = new node(data);//CREATE THE NODE
	node* tocompare = STACKED -> pop();//TAKES OFF STACK
	bool prec = true;
	int count = 0;
	if (tocompare != NULL) {
	    prec = check(data[0], tocompare -> getData()[0]);//CHECKS THE PRESEDENCE
	    if (prec == true) {
	      POSTED -> enqueue(tocompare);//aDD it To THE QUEUE
	      count ++;
	      bool run = true;
	     
	      while (run == true) {
	        count ++;
	        node* putonque = STACKED -> pop();
	        if(putonque == NULL) {
	          run = false;
	        }
	        else if (check(data[0], putonque -> getData()[0]) == false) {//IF PRESEDENCE IS LOWER
	          STACKED -> push(putonque);//PUTS IT ON STACK
	          run = false;
	        }
	        else {
	          POSTED -> enqueue(putonque);//ADD TO QUEUE
	        }
	      }
	    }
	}
	if (count == 0) { 
	  STACKED -> push(tocompare);
	}
	STACKED -> push(newNode);      }
    }
  }
  //ENQUEUES THE STACK
  bool run = true;
  while (run == true) {
    node* toen = STACKED -> pop();
    if (toen == NULL) {
      run = false;
    }
    else {
      POSTED -> enqueue(toen);
    }
  }
  return POSTED;//RETURNS THE POSTED QUEUE
}
node* buildtree(queue* input) //BUILDS TREE HELP / CREDITS: FROM SETHU EAPEN
{
stack* tree = new stack(NULL);
while(input->getQueueHead() != 0)
{
if(isdigit(*input->getQueueHead()->getData()))
{
//push the input head
node* filler = new node(input->getQueueHead()->getData());
tree->push(filler);
input->dequeue();
//BUILD TREE
}
else
{
node* curr = new node(input->getQueueHead()->getData());
// node* new = new node(tree->peek()); 
curr->setRight(tree->pop());
// tree->pop();
//tree->pop();
curr->setLeft(tree->pop());
//tree->pop();
//tree->pop();
tree->push(curr);
input->dequeue();
// buildtree(input);
 }
}
return tree->peek();
}

//CHECK PRESEDENE
bool check  (char AFTER, char BEFORE){
  if((AFTER == '+' || AFTER == '-') && (BEFORE == '/' || BEFORE == '*' || BEFORE == '^')) {
    return true;
  }
  else if((AFTER == '-' || AFTER == '+') && (BEFORE == '-' || BEFORE == '+')) {
    return true;
  }
  else if((AFTER == '/' || AFTER == '*') && (BEFORE == '/' || BEFORE == '*')) {
    return true;
  }
  else if ((AFTER == '*' || AFTER == '/') && BEFORE == '^') {                                                                                                                  
  return true;
  }
  else {
    return false;
  }
}
