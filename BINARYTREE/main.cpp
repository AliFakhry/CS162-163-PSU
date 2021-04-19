#include <iostream>
#include "node.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

void ADDEDOFTHENODE(node*);
node* BINARYARRAYMETHOD(int*, int);
void BUILD(node*, int*, int);
void ADDNODE(node*, node*);
void DISPLAYBINARYARRAY(node*, int);
void DELETEFUNCTION(node*, int);
node* DELETEFUNCTION2(node*, int);
void searchFunction(node*, int);

void searchFunction(node* comp, int del)
{
    bool exists = false;
    bool running = true;
    //    cout << "LOOK FOR WHICH NUMBER?" << endl;

         // cout << length;
         if(del < comp -> getData()) {
            if (comp -> getLeft() != NULL) {
              if (comp -> getLeft() -> getData() == del) {
            if (comp -> getLeft() -> getLeft() == NULL && comp -> getLeft() -> getRight() == NULL){
              //delete comp -> getLeft();
              //comp -> setLeft(NULL);
            cout << "DOES  EXIST" << endl;
            return;
            }
              }
              searchFunction(comp -> getLeft(), del);
            }
            else{
              cout << "DOES NOT EXIST" << endl;
              return;
            }
          }
          else if(del > comp -> getData()) {
            if (comp -> getRight() != NULL) {
              if (comp -> getRight() -> getData() == del) {
            if (comp -> getRight() -> getLeft() == NULL && comp -> getRight() -> getRight() == NULL){
              cout << "DOES  EXIST" << endl;
              return;
            }
              }
             searchFunction(comp -> getRight(),del);
            }
            else{
              cout << "DOES NOT EXIST" << endl;
              return;
            }
          }
          else {
              cout << "DOES  EXIST" << endl;
          }
}

int main() {
  int lengths = 0;
  cout << "BINARY SEARCH TREE" << endl;
  char c [80];
  bool b = true;
  int BINARYARRAY [100];
  while ( b == true) {
    cout << "DIRECT OR FILE" << endl;
    cin >> c;
      for(int i = 0; i < 100; i++){
      BINARYARRAY[i] = 0;
    }
    if (strcmp(c, "DIRECT") == 0) {
      b = false;
      bool stillIn = true;
      int count = 0;
      cin.ignore();
      while(stillIn == true) {
          lengths++;
    cout << "KEEP TYPING NUMBERS UNTIL YOU SAY END TO END IT" << endl;
    char input [1000];
    cin.getline(input,1000);
    if(strcmp(input, "END") == 0) {
      stillIn = false;
    }
    else{
      BINARYARRAY[count] = atoi(input);
      count++;
    }
      }
    }
    else if (strcmp(c, "FILE") == 0) {//if file
      cout << "INPUT THE FILE DON'T FORGET THE EXTENSION IF YOU NEED IT" << endl;
      char filename[80];//for name of file
      cin.ignore();//ignores past cin
      cin.getline(filename, 80);//takes in the name
      ifstream newFile; //new file
      newFile.open(filename);//opens file with the name put in

    b = false;
    int i = 0;
    while (newFile.eof() != true) {//while not end of file
      newFile >> BINARYARRAY[i];//puts each number seperated by whitespace in
      i++;
      lengths++;
    }

      newFile.close();//closes file
    }
  }
  int length;
  for (int i = 0; i < sizeof(BINARYARRAY)/sizeof(BINARYARRAY[0]); i++) {//calculates elements in int array, puts in length
    if (BINARYARRAY[i] == 0) {
      length = i;
        length = lengths;
      break;
    }
  }
  
  node* root = BINARYARRAYMETHOD(BINARYARRAY, length); //creates tree of array
  DISPLAYBINARYARRAY(root, 0);//prints the tree
  bool s = true;
  while(s == true) {//repeats till quit is typed
    cout << "DELETE, SEARCH, QUIT, INSERT" << endl;
    char input [80];
    cin >> input;
    if (strcmp(input, "INSERT") == 0)
    {
      if (root == NULL)
      {
          cout << "What number do you want to insert?" <<endl;
          cin.ignore();
          int insertnum;
          cin >> insertnum;
          node* newnode = new node(insertnum);
          root = newnode;
	  cout << insertnum << endl;
      }
      else {
      ADDEDOFTHENODE(root);//runs insert
      }
    }
    else if (strcmp(input, "QUIT") == 0) {
      s = false;//exits loop and program
    }
    else if (strcmp(input, "DELETE") == 0) {
    cout << "WHICH NUMBER YOU TRYING TO DELETE" << endl;
    cin.ignore();
    int delnum;
    cin >> delnum;//takes in val to delete
    if (root -> getData() != delnum)
    {
    DELETEFUNCTION(root, delnum);// deletes the number
    }
    else if (root -> getData() == delnum)
    {
        root = DELETEFUNCTION2 (root,delnum);
    }
    DISPLAYBINARYARRAY(root, 0);//prints tree
    }
    else if (strcmp(input, "PRINT") == 0) {
      DISPLAYBINARYARRAY(root, 0);//prints the tree
    }
    else if (strcmp(input, "SEARCH") == 0)
    {
        cout << "WHICH NUMBER YOU TRYING TO SEARCH FOR" << endl;
        cin.ignore();
        int delnum;
        cin >> delnum;//takes in val to delete
       searchFunction(root, delnum);
    }
  }
}


void DELETEFUNCTION(node* comp, int del) {
   if(del < comp -> getData()) {
    if (comp -> getLeft() != NULL) {
      if (comp -> getLeft() -> getData() == del) {
    if (comp -> getLeft() -> getLeft() == NULL && comp -> getLeft() -> getRight() == NULL){
      delete comp -> getLeft();
      comp -> setLeft(NULL);
      return;
    }
      }
      DELETEFUNCTION(comp -> getLeft(), del);
    }
    else{
      cout << "DOES NOT EXIST" << endl;
      return;
    }
  }
  else if(del > comp -> getData()) {
    if (comp -> getRight() != NULL) {
      if (comp -> getRight() -> getData() == del) {//if right equals delete
    if (comp -> getRight() -> getLeft() == NULL && comp -> getRight() -> getRight() == NULL){
      delete comp -> getRight();
      comp -> setRight(NULL);
      return;
    }
      }
      DELETEFUNCTION(comp -> getRight(), del);
    }
    else{
      cout << "DOES NOT EXIST" << endl;
      return;
    }
  }
  else {
      if (comp -> getLeft() != NULL) {
          node* temp = comp -> getLeft();
          comp -> setData(temp -> getData());
          comp -> setLeft(temp -> getLeft());
          if (comp -> getRight() == NULL) {
          comp -> setRight(temp -> getRight());
          }
          else {
        node* curr = temp;
        while(curr -> getRight() != NULL) {
          curr = curr -> getRight();
        }
        curr -> setRight(comp -> getRight());
        comp -> setRight(temp -> getRight());
          }
          delete temp;//deletes node
          return;
        }
        else if(comp-> getRight() != NULL){
          node* temp = comp -> getRight();
          comp -> setData(temp -> getData());
          comp -> setLeft(temp -> getLeft());
          comp -> setRight(temp -> getRight());
          delete temp;
          return;
        }
      }
}
void ADDEDOFTHENODE (node* root) {
  cout << "INSERT WHICH NUMBER" << endl;
  cin.ignore();
  int insertnum;
  cin >> insertnum;
  node* newnode = new node(insertnum);
  ADDNODE(root, newnode);
  DISPLAYBINARYARRAY(root, 0);
  
}

void ADDNODE(node* comp, node* toin) {
   if(toin -> getData() < comp -> getData()) {
    if (comp -> getLeft() == NULL) {
      comp -> setLeft(toin);
    }
    else {
      ADDNODE(comp -> getLeft(), toin);
    }

  }
  else { //if right or equal
    if (comp -> getRight() == NULL) {
        comp -> setRight(toin);
    }
    else{
      ADDNODE(comp -> getRight(), toin);
    }
  }
}

node* BINARYARRAYMETHOD(int* BINARRYARRAY, int length){
  node* root = new node(BINARRYARRAY[0]);
  for (int i = 1; i < length-1; i++) {
    BUILD(root, BINARRYARRAY, i);
  }
  return root;
}

void BUILD(node* comp, int* BINARYARRAY, int i) {
  node* newp = new node(BINARYARRAY[i]);
  if(BINARYARRAY[i] < comp -> getData()) {
    if (comp -> getLeft() == NULL) {
      comp -> setLeft(newp);
    }
    else {
      BUILD(comp -> getLeft(), BINARYARRAY, i);
    }
    
  }
  else {//if right
    if (comp -> getRight() == NULL) {
      comp -> setRight(newp);
    }
    else{
        BUILD(comp -> getRight(), BINARYARRAY, i);
    }
  }
}

void DISPLAYBINARYARRAY(node* parent, int count) {
  if (parent == NULL)
  {
      cout << "" <<endl;
      return;
  }
  else if(parent -> getRight() != NULL) {
    DISPLAYBINARYARRAY(parent -> getRight(), count + 1);
  }
  int temp = count;
  while (count > 0) {
    cout << "   ";
    count --;
  }
  cout << parent -> getData() << endl;
  if (parent -> getLeft() != NULL) {
    DISPLAYBINARYARRAY(parent -> getLeft(), temp + 1);
  }
}

node* DELETEFUNCTION2 (node* comp, int del) {

  //cout << comp -> getData() <<endl;
node* temp = comp;
node* curr2 = comp;
     if (comp -> getLeft() == NULL && comp -> getRight() == NULL)
     {
         free(comp);
         return NULL;
     }
    else if (comp -> getRight() != NULL && comp -> getLeft() == NULL)
    {
        DELETEFUNCTION(comp, del);
    }
    else if (comp -> getLeft() -> getRight() != NULL)
     {
         temp = temp -> getLeft();
         while(temp -> getRight() != NULL)
         {
             temp = temp -> getRight();
         }
         comp -> setData(temp -> getData());
         delete temp;
     
     if (curr2 -> getLeft() -> getRight() != NULL)
     {
         curr2 = curr2 -> getLeft();
         //cout << curr2 -> getData() << endl;
         if (curr2 -> getRight() != NULL)
         {
         while (curr2 -> getRight() != NULL)
          {
          cout << "REACHED HERE 1" <<endl;

          if (curr2 -> getRight() -> getData() != comp -> getData())
          {

         cout << curr2 -> getRight() -> getData() << endl;
         cout << "REACHED HERE" <<endl;
         cout << del <<endl;

         curr2 = curr2 -> getRight();
         //cout << curr2 -> getData() << endl;
         }
         cout << curr2 -> getData() << endl;
         curr2 -> setRight(NULL);
         break;
                }
             }
        }
         return comp;
     }
         else if (comp -> getLeft() -> getRight() == NULL)
         {
             if (comp -> getLeft() != NULL)
             {
                 comp ->setData(comp -> getLeft() ->getData());
             }
             node* compNew = comp;
             if (compNew -> getLeft() ->getLeft() !=NULL)
             {
                 compNew = compNew ->getLeft() -> getLeft();
                 node* compNew2 = compNew;
             cout << compNew -> getData() <<endl;
                 while (compNew2 -> getLeft() != NULL)
                 {
                     cout << compNew -> getData() <<endl;
                     compNew -> setLeft(compNew2 ->getLeft());
                     compNew2 = compNew2 -> getLeft();
                 }
             comp -> setLeft(compNew);
             }
             else if (compNew -> getLeft() != NULL)
             {
                 comp -> setLeft(compNew);
                 comp -> getLeft() -> setLeft(NULL);
             }
    }
    return comp;
}
