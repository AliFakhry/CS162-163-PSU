#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdlib.h>

using namespace std;

void HEAP (int input[], int n, int i)
{
  int LARGE = i;
  int x = 2 * i + 1;
  int y = 2 * i + 2;
  
  if (x < n) {
    if (input[x] > input[LARGE]){
      LARGE = x;
    }
  }
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
void build (int input[], int n)
{
  int START = (n/2) -1;
  for (int x = START; x >= 0; x--) {
    HEAP(input,n,x);
  }
}
void displayHeap(int* heap,int length,int count,int i)
{
  //  cout << "" <<endl;
  int LEFTESTPOSITION = 2*i;
  int RIGHTESTPOSITION = 2*i+1;
  if (RIGHTESTPOSITION <= length) 
    {
      displayHeap(heap,length,count+1, RIGHTESTPOSITION);
    }
  int current = count;
  while (count > 0) 
    {
      cout << "    ";
      count --;
    }
  cout << heap[i-1] << endl;
  if (LEFTESTPOSITION <= length)
    {
      displayHeap(heap,length,current +1, LEFTESTPOSITION);
    }
}

int main() 
{
  cout << "WELCOME TO HEAP" <<endl;
  char c [60];
  bool RUN = true;
  while ( RUN == true) {                                                                                                    
    cout << "DIRECT OR FILE" << endl;
    cin >> c;                                                                                                                             
    int heap [100];                                                                                                        
    for(int i = 0; i < 100; i++) {
    heap[i] = 0;
    }

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
        if(strcmp(input, "END") == 0) {                                                                                        
          stillIn = false;
        }
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
	  displayHeap(heap,length,0,1);       
	
      }
    }
  }
  }
}
