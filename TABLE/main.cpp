//
//  main.swift
//  HashTable
//
//  Created by Ali Fakhry on 5/31/20.
//  Copyright © 2020 AliFakhry. All rights reserved.
//

//Githubs I looked at/Citations:  Sethu Eapen, Andrew Thomas, Sethu Eapen,Ethan Wan,Aryan G
#include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;

char* NAMEFIRST;
char* NAMESECOND;
char* FILENAMESECONDINPUTTED;
char* FILENAMEFIRSTINPUTTED;

//FIRST STRUCT FOR STUDENT
struct student
{
  char* NAMEFIRST;
  char* NAMESECOND;
  int id;
  float gpa;
};
//SECOND STRUCT
struct StudentSecond
{
  student* student = NULL;
  StudentSecond* next = NULL;
};

//USED TO RETURN THE INDEX
int RETURNHASHVALUE(int id, int size);
int  HASHAGAIN(StudentSecond* newHashTablle[], StudentSecond* oldHashTable[], int size);
student* create( char* NAMEFIRST, char* NAMESECOND, int id, float gpa);
void addStudent(StudentSecond* hashTable[],int index, student* student);
void print(StudentSecond* hashTable[], int size);
void DELETESTUDENT(StudentSecond* hashTable[], int id, int size);

//INDEX IS THE % RATIO
int main()
{
  int size = 2;
  vector <char*> NAMEFIRSTs;
  vector <char*> NAMESECONDs;
  StudentSecond** hashTable = new StudentSecond* [100];
  vector<int> ids;
  for(int i = 0; i< 100; i++)
    {
      hashTable[i] = NULL;
    }
  int a = 0;
  cout << "WELCOME TO HASH TABLE- ALI FAKHRY" << endl;
  while(a != 5 )
    {
        cout << "STUDENT,"; cout << "GENERATE,"; cout << "DELETE,"; cout << "PRINT,"; cout<< "QUIT,";
    
      char * input = new char[80];
      cin.getline(input, 80);
        if (strcmp(input, "STUDENT") == 0)
        {
          bool availability = true;
          NAMEFIRST = new char[99];
          NAMESECOND = new char[99];
          int id = 0;
          float gpa;
          cout << "FIRST NAME"<< endl;
          cin.get(NAMEFIRST,99,'\n');
          cin.get();
          cout << "LAST NAME" << endl;
          cin.get(NAMESECOND,99,'\n');
          cin.get();
          cout << "ID" << endl;
          cin >> id;
          cin.get();
          cout << "GPA" << endl;
          cin >> gpa;
          cin.get();
     
          for(int i = 0 ; i < ids.size(); i++) // CHECK ID ON STUDENT LIST
            if (ids.at(i) == id)
              {
            availability = false;
              }
            
      if (availability == true) //IF AVAILABLE
      {
          ids.push_back(id);
          student* news;
          news = create(NAMEFIRST, NAMESECOND, id, gpa);
          int index = RETURNHASHVALUE(id, size);
          addStudent (hashTable, index, news );
          for(int i = 0; i< size; i++)
        {
          int NEWCOUNTVARIATION = 0;
          StudentSecond* counter = hashTable[i];
          if (counter == NULL)
            {
                }
              else
                {
                  while(counter != NULL) // COUNT THE NUMBERS
                {
                  counter = counter->next;
                  NEWCOUNTVARIATION += 1;
                }
                      if(NEWCOUNTVARIATION > 3  ) //REFRESH THE TABLE IF MORE THAN THREE
                    {
                      StudentSecond** HASHTABLETWOFORM = new StudentSecond*[size * 2 ]; //NEW HASHTABLE
                      size = HASHAGAIN(HASHTABLETWOFORM, hashTable, size); //THE DOUBLE SIZED IS RETURNED
                      delete[] hashTable; //CLEAN UP
                      hashTable = HASHTABLETWOFORM;
                    }
            }
          

        }
         
          cout << "STUDENT: " << news->NAMEFIRST << " " << news->NAMESECOND << endl;
          cout << "ID: " << news->id << "GPA" << news->gpa << endl;
          cout << "INDEX: " << index << endl;
        }
      else
        {
          cout << "EXISTS ALREADY!" << endl;
        }
      
    }
      else if (strcmp(input, "GENERATE") == 0)
    {
      //IF THEY WANT TO RANDOMLY GENERATE
      char* SEPERATEDONE;
      char fileInput[1000];
      cout << "SAY THE FILE NAME." << endl;
          FILENAMEFIRSTINPUTTED = new char [99];
      cin.get(FILENAMEFIRSTINPUTTED, 99 , '\n');
      cin.get();
      ifstream myfile;
      myfile.open(FILENAMEFIRSTINPUTTED);
    
      if (!myfile)
        {
          cout << "FILE CANT BE OPENED." << endl;
          return 13;
        }
      else
        {
          myfile.getline(fileInput,1000);
          SEPERATEDONE = strtok(fileInput," ");
          while(SEPERATEDONE != NULL)
        {
          NAMEFIRSTs.push_back(SEPERATEDONE);
          SEPERATEDONE = strtok(NULL, " ");
        }
        }
      for(int i = 0; i< NAMEFIRSTs.size(); i++)
        {
          cout << NAMEFIRSTs.at(i) << " ";
        }
      cout << endl;
      char fileInput2[1000];
      FILENAMESECONDINPUTTED = new char [99];
      cout << "FILE NAME INPUT." << endl;
      FILENAMESECONDINPUTTED = new char [99];
      cin.get(FILENAMESECONDINPUTTED, 99 , '\n');
      cin.get();
      ifstream myfile2;
      myfile2.open(FILENAMESECONDINPUTTED);
    
      if (!myfile2)
        {
          cout << "NO FILE SEEN." << endl;
          return 13;
        }
      else //IF THE FILE IS OPEN
        {
          myfile2.getline(fileInput2,1000);
          SEPERATEDONE = strtok(fileInput2," ");
          while(SEPERATEDONE != NULL)
        {
          NAMESECONDs.push_back(SEPERATEDONE);
          SEPERATEDONE = strtok(NULL, " ");
        }
        }
      for(int i = 0; i< NAMESECONDs.size(); i++)
        {
          cout << NAMESECONDs.at(i) << " ";
        }
      cout << endl;
      
      cout << "AMOUNT OF RANDOM YOU WANT TO GENERATE" << endl;
      
      
      int n = 0;
      cin >> n ;
      cin.get();
      
      int id = 0;
      //if there are no ids in the list
      if (ids.size() == 0)
        {
          id = (rand() % 600000) + 100000;
        
        }
      else //USE THE LARGEST ID THEN
        {
          for(int i = 0; i<ids.size(); i++)
        {
          if (ids.at(i) > id)
            {
              id = ids.at(i);
            }
        }
        }
      for(int i = 0; i <= n; i++)
        {

          NAMEFIRST = new char[99];
          NAMESECOND = new char[99];
          id += 1;
          float gpa;
          int fn = rand() % NAMEFIRSTs.size() +1;
          int ln = rand() % NAMESECONDs.size() +1;
          NAMEFIRST = NAMEFIRSTs.at(fn -1);
          NAMESECOND = NAMESECONDs.at(ln -1);
          gpa = ((float)((rand() % 500 ) + 100 )) / 100 ; //A RANDOM GPA IS PRODUCED
          ids.push_back(id);
          student* news = create(NAMEFIRST,NAMESECOND,id,gpa);
          int index = RETURNHASHVALUE(id,size);
          addStudent(hashTable,index,news);
           for(int i = 0; i< size; i++)
        {
          int NEWCOUNTVARIATION = 0;
          StudentSecond* counter = hashTable[i];
          if (counter == NULL)
            {

            }
          else
            {
              while(counter != NULL)
            {
              counter = counter->next;
              NEWCOUNTVARIATION += 1;
            }
              if(NEWCOUNTVARIATION > 3  )
            {
              StudentSecond** HASHTABLETWOFORM = new StudentSecond*[size * 2 ];
              size = HASHAGAIN(HASHTABLETWOFORM, hashTable, size);
              // IF THERE IS MORE THAN 3 STUDENTS
              delete[] hashTable;
              hashTable = HASHTABLETWOFORM;
              break;
            }
            }
          

        }
    
          cout << "NEW STUDENT AT" << news->NAMEFIRST << " " << news->NAMESECOND << endl;
          cout << "ID OF" << news->id << " and gpa: " << news->gpa << endl;
          cout << "INDEX OF" << index << endl;
          cout << endl;
        }
    }
      else if (strcmp(input, "DELETE") == 0)
    {
      cout << "WHAT'S THE ID OF THE STUDENT" << endl;
      int id;
      cin>>id;
      cin.get();
      cout << endl;
      bool exist = false;
      for(int i = 0; i < ids.size(); i++)
        {
          if (id == ids.at(i))
        {
          exist = true;
        }
        }
      if (exist == false)
        {
          cout << "STUDENT DOESN'T EXIST!" << endl;
        }
      else
        {
          DELETESTUDENT(hashTable,id,size);
     
        }
      cout << endl;
    }
      else if (strcmp(input, "PRINT") == 0)
    {
      // RUN THE PRINT FUNCTION
      print(hashTable,size);
      cout << endl;
    }
           else if (strcmp(input, "QUIT") == 0)
        {
          return 1000000;
        }
          else
        {
          cout << "ENTER A VALID NUMBER, THAT WAS INVALID." << endl;
          cout << endl;

        }
      
      
    }
  
}
int HASHAGAIN(StudentSecond* HASHTABLETWOFORM[], StudentSecond* oldHashTable[], int size)
{
      for( int i = 0; i< (size + size); i++)
        {
          HASHTABLETWOFORM[i] = NULL;
        }
      for( int i = 0; i< size; i++) //GO THROUGH THE OLD ONE
        {
          StudentSecond* n = oldHashTable[i];
          //RUN THROUGH THE INDEXES
          while(n != NULL)
        {
          int index = RETURNHASHVALUE(n->student->id, size *2); //GET THE NEWEST INDEX
          addStudent(HASHTABLETWOFORM,  index , n->student); //ADD
          n = n->next;//GO THROUGH THE INDEXES
        }
        }


  size = size * 2 ; //NEW SIZE RETURN
  return size;
}

    void addStudent(StudentSecond* hashTable[], int index, student* news)
    {
    //NO STUDENTS AT THE NEXT INDEXED LEVEL
        if (hashTable[index] == NULL)
            {
              StudentSecond* temp = new StudentSecond();
              temp->student = news;
              hashTable[index] = temp;
            }
          else
            {
              //LEAVE BACK TO THE START
              StudentSecond* current = hashTable[index];
              StudentSecond* temp = new StudentSecond();
              //PUT CURRENT FIRST
              temp->next = current;
              temp->student = news;
            
              hashTable[index] = temp;
              current = temp;
              int length;
                length = 1;
            
            }
    }


    //DETERMINES LOCATION
    void DELETESTUDENT(StudentSecond* hashTable[], int id, int size)
    {
      int index = RETURNHASHVALUE(id,size);
      StudentSecond* head = hashTable[index];
          if (head == NULL)
        //NO STUDENTS GIVEN WITH THAT INDEX
            {
              cout << "STUDENT DOESN'T EXIST" << endl;
              return;
            }
      else
        {
          //IF THERE APPEARS TO BE ONLY ONE STUDENT
              if (head->student->id == id && head->next == NULL)
             {
              cout << "STUDENT: " << head->student->NAMEFIRST << " " << head->student->NAMESECOND << endl;
              cout << "ID: " << head->student->id << "GPA: " << head->student->gpa << endl;
              cout << "GIVE THE INDEX: " << index << " DELETED." << endl;
              delete head;
              hashTable[index] = NULL;
            }
              else if (head->student->id == id && head->next != NULL)
              {
              //IF THERE IS MORE THAN ONE STUDENT
              cout << "STUDENT: " << head->student->NAMEFIRST << " " << head->student->NAMESECOND << endl;
                  
              cout << "ID: " << head->student->id << "GPA: " << head->student->gpa << endl;
                  
              cout << "GIVE THE INDEX: " << index << " DELETED." << endl;
              hashTable[index] = head->next;
              delete head;
               }
          else
          {
          //TRACK THE PREVIOUS
          StudentSecond* temp = head;
          StudentSecond* previous = temp;
          while( temp != NULL)
            {
                  if (temp->student->id == id)
                {
                  
                  break;
                }
                    else
                    {
                      previous = temp;
                      temp = temp ->next;
                      
                    }
                }
                  if (temp ->next == NULL)
                    {
                      previous->next = NULL;
                    }
                      else
                    {
                      previous->next = temp ->next;
                    }
          cout << "STUDENT: " << temp->student->NAMEFIRST << "" << temp->student->NAMESECOND << endl;
          cout << "ID: " << temp->student->id << "WITH A GPA OF: " << temp->student->gpa << endl;
          cout << "INDEX: " << index << " DELETED." << endl;
          delete temp;
          
        }
          

        }
       
    }

int RETURNHASHVALUE(int id, int size)
{
  return id % size;
  
}
void print(StudentSecond* hashTable[], int size)
{
  cout << "LIST OF STUDENTS" << endl;
  cout << endl;
      
  StudentSecond* n; //POINTER THAT WALKS THROUGH
  for(int i= 0; i<size; i++)
    {
      cout << i << endl;
      cout << endl;
      
      if(hashTable[i] != NULL)
    {
      n = hashTable[i];
    
      while(n != NULL) //PRINTS ALL THE STUDENTS
        {
          if (n->student!=NULL) //PRINT OUT THE STUDENTS IF THEY EXIST
        {
          cout << "Student: " << n->student->NAMEFIRST << "" << n->student->NAMESECOND << endl;
          cout << "ID: " << n->student->id << "  GPA: " << n->student->gpa << endl;
          cout << endl;
       
        }
          n = n->next;
        }
    }
      else
    {
        
    }
    }

}
student* create( char* NAMEFIRST, char* NAMESECOND, int id, float gpa)
{
  student * news = new student();
  news->NAMEFIRST = NAMEFIRST;
  news->NAMESECOND = NAMESECOND;
  news->id = id;
  news->gpa = gpa;
  return news;
}

