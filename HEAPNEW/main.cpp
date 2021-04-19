//ALI FAKHRY
//FEBUARY 22 2020
//USES A MAX HEAP TO ORGANIZE AN INPUT, BY EITHER FILE NAME OR DIRECT INPUT. THE PARENT WILL ALWAYS BE LARGER THAN THE CHILDS, SO ORGANIZE IT SUCH
//PRINT THE TREE VISUALLY, AND THEN PRINT THE OUTPUT FROM LARGER TO SMALLER
#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdlib.h>

using namespace std;

//METHOD AFTER THE USER FINISHED IMPLEMENTING THE TREE ON THE FIRST RUN
//This method is used to organize and build the tree
//Citation: wikipedia
void build (int input[], int n);


//DELETE THE HEAP SLOWLY, PRINTING THE NUMBERS FROM HIGHEST TO SMALLEST
void deleteHeap(int* heap, int length)
{

//cout << "GOOD" <<endl;
while (length > 0)
{
length --;
//cout << length << endl;
cout << heap[0] << ",";
heap[0] = heap[length]; //MAKES THE LAST NUMBER THE ROOT
build(heap,length); //ORGANIZES IT AGAIN
}
cout << "" << endl;
}

void HEAP (int input[], int n, int i)
{
  int LARGE = i;
  int x = 2 * i + 1;
  int y = 2 * i + 2;
  
  //condition 1 (seeing for greater between adult and child)
  if (x < n) {
    if (input[x] > input[LARGE]){
      LARGE = x;
    }
  }
  //condition 2 (Seeing for greater between adult and child)
  if (y < n) {
    if (input[y] > input[LARGE]){
      LARGE = y;
    }   
  }
  if (LARGE != i) 
    {
      swap(input[i] , input[LARGE]);
      HEAP(input, n, LARGE);
    }
}
//builds the heap, and then pushes it into heap method to organize it
void build (int input[], int n)
{
  int START = (n/2) -1;
  for (int x = START; x >= 0; x--) {
    HEAP(input,n,x);
  }
}

//displays the tree heap, PRINTS SIDEWAYS with spaces to seperate it
void displayHeap(int* heap,int length,int count,int i)
{

  //  cout << "" <<endl;

  //integer of left and right position
  int LEFTESTPOSITION = 2*i;
  int RIGHTESTPOSITION = 2*i+1;
  if (RIGHTESTPOSITION <= length) 
    {
      displayHeap(heap,length,count+1, RIGHTESTPOSITION);
    }

  int current = count;
  //while count is larger than 0
  while (count > 0) 
    {
      cout << "    ";
      count --;
    }
	//print it out
  cout << heap[i-1] << endl;
  //recursivley print again
  if (LEFTESTPOSITION <= length)
    {
      displayHeap(heap,length,current +1, LEFTESTPOSITION);
    }
}
//main method
int main() 
{
  cout << "WELCOME TO HEAP" <<endl;
  //conditions and values
  char c [60];
  bool RUN = true;
  bool GOOD =true;
  //while run is true
  while ( RUN == true) {                                                                                                    
    cout << "DIRECT OR FILE" << endl;
    cin >> c;                                                                                                                             
    int heap [100]; 
    int length;
    for(int i = 0; i < 100; i++) {
    heap[i] = 0;
    }

//direct input is wanted
    if (strcmp(c, "DIRECT") == 0) {                                                                                           
      //cout << "1" << endl;
      RUN = false;                                                                                                                        
      bool stillIn = true;                                                                                                          
      int count = 0;                                                                                                        
       cin.ignore();                                                                                                           
      while(stillIn == true) {
        cout << "INPUT NUMBERS: SAY END TO STOP" << endl;
        char input [60];                                                                                           
        cin.getline(input,60);        
		//if they end the code, end it and put it in the method                                                                                                      
        if(strcmp(input, "END") == 0) {                                                                                        
          stillIn = false;
	  //	  displayHeap(heap,length,0,1);                                                                                                                 
	  for (int i = 0; i < sizeof(heap)/sizeof(heap[0]); i++) {
            if (heap[i] == 0) {
              length = i;
              //displayHeap(heap,length,0,1);                                                                                                                  
              break;

            }
          }
	  displayHeap(heap,length,0,1);
	  deleteHeap(heap, length);
	  //cout << count <<endl;
	}
//keep on going, if they don't want to end it
        else{
	  heap[count] = atoi(input);                                                                 
          count++;                                                                                                     
	  int n = sizeof(heap) / sizeof(heap[0]); 
	  build(heap, n);
	  int length;
	  for (int i = 0; i < sizeof(heap)/sizeof(heap[0]); i++) {            
	    if (heap[i] == 0) {
	      length = i;
	      //displayHeap(heap,length,0,1);
	      break;
	
	    }
	  }
	  // cout << "" <<endl; 
	  //	  displayHeap(heap,length,0,1);
	 // int* point = new int;
	 //  point = &length;
	}
      }
      // method(heap, length);
    }
  
  //if FILE input is whhat they want
    else if (strcmp(c, "FILE") == 0) {
	cout << "INPUT THE EXACT FILE NAME INCLUDING .txt IF APPLICABLE. IT WILL READ IN BASED BY THE NUMBER OF SPACES AS SEPERATE NUMBERS" << endl;
	char filename[80];//storage for the filename                                               
	cin.ignore();                                                         
	cin.getline(filename, 80);//gets the name                                         
	ifstream newFile; //creates the new file                                                            
	newFile.open(filename);//opens the given file                             
	//   if (newFile == NULL) {//if file doesn't exist                                   
	//  cout << "There was an error reading the file" << endl;                        
	// }                                                                                    
        GOOD = false;                                                   
        int i = 0; //keeps track of the spot location in the heap array                                             
        while (newFile.eof() != true) {                     
          newFile >> heap[i];//puts it into the heap                 
          i++;
        }

	newFile.close();//                                                        
      }
      if (GOOD == false) {// if input is properly inputed                                                
	int length;
	for (int i = 0; i < sizeof(heap)/sizeof(heap[0]); i++) {//calculates the length                                      
	    if (heap[i] == 0) {
	      length = i;
	      break;
	    }
	}
	//build the heap, display it, and thens tart the method
	build(heap,length);
	displayHeap(heap,length,0,1);
	deleteHeap(heap, length);
        RUN =false;
	// method(heap, length);
      }
  }  
}
          
  // cout << "YOU FINISHED YOUR TREE! YOU WANT TO MODIFY? 'ADD' or 'DELETE'?" <<endl;
  // char newINPUT[10];
  // cin.getline(newINPUT,10);  
  // cin.ignore(10, '\n');
  // cin.get();
  //cout << newINPUT << endl;
  //int n = sizeof(heap) / sizeof(heap[0]);
  //int length = n;
  //Method used after the initial tree is built, used for adding and deleting information from the tree
