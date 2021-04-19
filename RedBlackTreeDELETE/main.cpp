//
//  main.cpp
//  RBT
//
//  Created by Ali Fakhry on 3/13/20.
//  Copyright © 2020 Ali Fakhry. All rights reserved.
//
// Citations/Psuedo Code:
// https://www.andrew.cmu.edu/user/mm6/95-771/examples/RedBlackTreeProject/dist/javadoc/redblacktreeproject/RedBlackTree.html
// https://www.youtube.com/watch?v=UaLIHuR1t8Q
// https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
// https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
//https://iq.opengenus.org/red-black-tree-DELETEetion/
// Git Shell Coloring :
// https://gist.github.com/vratiu/9780109



//NOTE: RED BLACK TREE WILL BE REPRESENTED WITH RED COLOR AND PURPLE COLOR.
//PURPLE IS USED BECAUSE IF I USE BlACK AND THE BACKGROUND IS BLACK IT WON'T BE SEEN.



#include <iostream>
#include "node.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>
// #include <graphics.h>

void DELETE(node**, int);
void print(node*, int);
void add(node**, node*, int);
void adjust(node**, node*);
void leftRotate(node**, node*);
void rightRotate(node**,node*);
void DELETINGCASEVERISON1(node**, node*);
void DELETINGCASEVERISON2(node**, node*);
void DELETINGCASEVERISON3(node**, node*);
void DELETINGCASEVERISON4(node**, node*);
void DELETINGCASEVERISON5(node**, node*);
void DELETINGCASEVERISON6(node**, node*);
node* search(node*, int);
node* predecessor(node*);
node* findsib(node*);



using namespace std;

//setting grandparent
void setGrandparent(node* input)
{
    input -> getParent() -> setParent(input);
}

//getting the grandparent
node* getGrandparent(node* input)
{
    return input -> getParent() -> getParent();
}

//citations: Myself
int main(int argc, const char * argv[])
{
    node* root = new node();
    bool RUNNING = true;
    while(RUNNING == true)
    {
        cout << "THIS IS RED-PURPLE TREE: COMMANDS - ADD, PRINT, READ, QUIT, SEARCH, DELETE" << endl;
        char input [80];
        cin >> input;
        if (strcmp(input, "ADD") == 0)
        {
            cout << "WHICH NUMBER DO YOU WANT TO INSERT?" << endl;
            int in;
            cin >> in;
            add(&root, root, in);
            print(root,0);
           }
           else if (strcmp(input, "PRINT") == 0)
           {
               print(root,0);
           }
           else if (strcmp(input, "READ") == 0)
           {
                cout << "INPUT A FILE" << endl;
                char filename[100];
                cin.ignore();
                cin.getline(filename, 100);
                ifstream newFile;
                newFile.open(filename);
                  while (newFile.eof() != true) {
                    char* running = new char[3];
                    newFile.getline(running, 4, ' ');
                    int inputting = atoi(running);
                    add(&root, root, inputting);
                }
                newFile.close();
           }
            else if (strcmp(input, "SEARCH") == 0) {
                 int in;
                 cout << "WHAT NUMBER DO YOU WANT TO SEARCH FOR" << endl;
                 cin.ignore();
                 cin >> in;
                 search(root, in);
               }
               else if (strcmp(input, "DELETE") == 0) {
                 cout << "WHAT NUMBER DO YOU WANT TO DELETE" << endl;
                 int in;
                   cin >> in;
                 DELETE(&root, in);
               }
           else if (strcmp(input, "QUIT") == 0)
           {
           RUNNING = false;
           }
    }
}
    //citations: Myself
    void print(node* parentNode, int countNum)
{
      if(parentNode -> getNil() == true)
      {
        cout << "THE TREE IS CURRENTLY EMPTY" << endl;
      }
      else {
        if(parentNode -> getRight() != NULL)
        {
          print(parentNode -> getRight(), countNum + 1);
        }
        int temp = countNum;
       while (countNum > 0)
        {
              cout << "    ";
              countNum --;
        }
        if (parentNode -> getCol() == 1)
        {
            cout << "\033[4;35m" << parentNode -> getData() << "\033[0m" << endl;
        }
        else
        {
            cout << "\033[4;31m" << parentNode -> getData() << "\033[0m"  << endl;
        }
        if (parentNode -> getLeft() != NULL) {//if left exists
          print(parentNode -> getLeft(), temp + 1);//runs for one to the left
        }
      }
    }

//    pseudocode for
//    RB-Insert(T,z)
//       y = nil[T]
//       x = root[T]
//       while x != nil[T]
//            y = x
//            if key[z] < key[x] then
//                x = left[x]
//            else
//                x = right[x]
//       p[z] = y
//       if y = nil[T]
//            root[T] = z
//       else
//          if key[z] < key[y] then
//             left[y] = z
//          else
//             right[y] = z
//       left[z] = nil[T]
//       right[z] = nil[T]
//       color[z] = RED
//       RB-Insert-fixup(T,z)
   

  void add (node** root, node* parentNode, int NUMBER)
{
      if (parentNode -> getNil() == true)
      {
          parentNode -> setNil(false);
          parentNode -> setCol(1);//becomes black
          parentNode -> setData(NUMBER);//sets the data to be input
      }
      else
      {
        if(NUMBER < parentNode -> getData())
        {
            if (parentNode -> getLeft() == NULL)
            {
                node* newNode = new node();
                newNode -> setNil(false);
                newNode -> setData(NUMBER);
                newNode -> setParent(parentNode);
                parentNode -> setLeft(newNode);
                adjust(root, newNode);
            }
            
            else
            {
                add(root, parentNode -> getLeft(), NUMBER);
            }
        }
        else
        {
        if (parentNode -> getRight() == NULL)
        {
            node* newNode = new node();
            newNode -> setNil(false);
            newNode -> setData(NUMBER);
            newNode -> setParent(parentNode);
            parentNode -> setRight(newNode);
            adjust(root, newNode);
        }
          else
          {
            add(root, parentNode -> getRight(), NUMBER);
          }
        }
      }
    }

//Low-level Pseudo-code for RB-Insert-fixup
// RB-Insert-fixup(T,z)
// while color[p[z]] = RED {
//   if p[z] == left[p[p[z]]] {
//        y = right[p[p[z]]]
//        if color[y] = RED {
//            color[p[z]] = BLACK
//            color[y] = BLACK
//            color[p[p[z]]] = RED
//            z = p[p[z]]
//        }
//        else {
//            if z = right[p[z]] {
//                 z = p[z]
//                 LEFT-Rotate(T,z)
//            }
//            color[p[z]] = BLACK
//            color[p[p[z]]] = RED
//            RIGHT-Rotate(T,p[p[z]])
//        }
//   }
//   else {
//        y = left[p[p[z]]]
//        if color[y] = RED {
//            color[p[z]] = BLACK
//            color[y] = BLACK
//            color[p[p[z]]] = RED
//            z = p[p[z]]
//        }
//        else
//            {
//            if z = left[p[z]] {
//                 z = p[z]
//                 RIGHT-Rotate(T,z)
//            }
//            color[p[z]] = BLACK
//            color[p[p[z]]] = RED
//            LEFT-Rotate(T,p[p[z]])
//        }
//   }
//   color[root[T]] = BLACK
// }


void adjust(node** root, node* newNode)
{
     while(newNode -> getParent() != NULL && newNode -> getParent() -> getCol() == 0 && newNode != (*root))
     {
         
     if(newNode -> getParent() == getGrandparent(newNode) -> getLeft())
         {
            node* nextNode = getGrandparent(newNode) -> getRight();
             if(nextNode != NULL && nextNode -> getCol() == 0)
             {
                 newNode -> getParent() -> setCol(1); nextNode -> setCol(1); getGrandparent(newNode) -> setCol(0);
                 newNode = getGrandparent(newNode);
            }
            else
                {
                     if(newNode == newNode -> getParent() -> getRight())
                     {
                            newNode = newNode -> getParent();
                            leftRotate(root, newNode);
                     }
                    newNode -> getParent() -> setCol(1); getGrandparent(newNode) -> setCol(0);
                    rightRotate(root, getGrandparent(newNode));
                    }
            }
    else
         {
            if (getGrandparent(newNode) -> getLeft() != NULL && getGrandparent(newNode) -> getLeft() -> getCol() ==0)
            {
                node* inputting = new node(); inputting = getGrandparent(newNode) -> getLeft();
                newNode -> getParent() -> setCol(1); inputting -> setCol(1); getGrandparent(newNode) -> setCol(0); //setting colors
                newNode = getGrandparent(newNode);

            }
            else
            {
                if (newNode == newNode -> getParent() -> getLeft())
                {
                    newNode = newNode -> getParent();
                    rightRotate(root, newNode);
                }
                newNode -> getParent() -> setCol(1); getGrandparent(newNode) -> setCol(0); leftRotate(root, getGrandparent(newNode));

            }
         }
     }
    (*root) -> setCol(1);
}

//pseudocode for left rotations
//pre: right[x] != nil[T]
//pre: root's parent is nill[T]
//
//Left-Rotate(T,x)
//   y = right[x]
//   right[x] = left[y]
//   p[left[y]] = x
//   p[y] = p[x]
//
//
//   if p[x] == nil[T] then root[T] = y
//   else
//      if x == left[p[x]] then left[p[x]] = y
//      else
//         right[p[x]] = y
//   left[y] = x
//   p[x] = y

void leftRotate(node** root, node* nextNode)
{
    node* current = nextNode -> getRight();
    
    nextNode -> setRight(current -> getLeft());
    
    if(current -> getLeft() != NULL)
    {
      current -> getLeft() -> setParent(nextNode); //set current's left to the parent of the nextNode (the inputted node)
    }
    current -> setParent(nextNode -> getParent());
    
    if(nextNode == *root)
        {
          *root = current; //The new root is now the current
        }
    else
    {
          if(nextNode == nextNode -> getParent() -> getLeft())
          {
            nextNode -> getParent() -> setLeft(current);
          }
          else
          {
            nextNode -> getParent() -> setRight(current);
          }
    }
    current -> setLeft(nextNode);
    
    nextNode -> setParent(current);
}

//
//pseudocode for right rotation
//pre: left[x] != nil[T]
//pre: root's parent is nill[T]
//Right-Rotate(T,x)
//   y = left[x]           // y now points to node to left of x
//   left[x] = right[y]    // y's right subtree becomes x's left subtree
//   p[right[y]] = x       // right subtree of y gets a new parent
//   p[y] = p[x]           // y's parent is now x's parent
//
//   // if x is at root then y becomes new root
//   if p[x] == nil[T] then root[T] = y
//   else
//       // if x is a left child then adjust x's parent's left child or...
//
//        if x == left[p[x]] then left[p[x]] = y
//        else
//        // adjust x's parent's right child
//           right[p[x]] = y
//   // the right child of y is now x
//   right[y] = x
//   // the parent of x is now y
//   p[x] = y

void rightRotate(node** root, node* temp)
{
    node* nextNode = temp -> getLeft();
    
    temp -> setLeft(nextNode -> getRight());
    
    if(nextNode -> getRight() != NULL)
        {
          nextNode -> getRight() -> setParent(temp);
        }
    nextNode -> setParent(temp -> getParent());
    if(temp == (*root))
        {
          (*root) = nextNode;
        }
    else
        {
          if(temp == temp -> getParent() -> getLeft())
                  {
                    temp -> getParent() -> setLeft(nextNode);
                  }
          else if (temp != temp -> getParent() -> getLeft())
                  {
                    temp -> getParent() -> setRight(nextNode);
          }
        }
    nextNode -> setRight(temp);
    temp -> setParent(nextNode);
}
//RB-DELETEETEETE(T, z)
//  if z->left = null or z->right = null
//       then y ← z
//   else y ← TREE-SUCCESSOR(z)
//   if y->left ≠ null
//       then x ← y->left
//   else x ← y->right
// x->p ← y->p
// if y->p = null
// then T->root ← x
// else if y = y->p->left
// then y->p->left ← x
//else y->p->right ← x
//if y 3≠ z
// then z->key ← y->key
// copy y's satellite data into z
// if y->color = BLACK
// then RB-DELETEETE-FIXUP(T, x)
// return y
// RB-DELETEETE-FIXUP(T, x)
// while x ≠ T->root and x->color = BLACK
// do if x = x->p->left
// then w ← x->p->right
// if w->color = RED
// then w->color ← BLACK Case 1
// x->p->color ← RED Case 1
// LEFT-ROTATE(T, x->p) Case 1
// w ← x->p->right Case 1
// if w->left->color = BLACK and w->right->color = BLACK
// then w->color ← RED Case 2
// x ← x->p Case 2
// else if w->right->color = BLACK
// then w->left->color ← BLACK Case 3
 //   w->color ← RED Case 3
 //      RIGHT-ROTATE(T, w) Case 3
 //      w ← x->p->right Case 3
 //      w->color ← x->p->color Case 4
 //      x->p->color ← BLACK Case 4
 //      w->right->color ← BLACK Case 4
 //      LEFT-ROTATE(T, x->p) Case 4
 //      x ← T->root Case 4
 //      else (same as then clause with "right" and "left" exchanged)
 //          x->color ← BLACK
void DELETE (node** root, int DELETE)
{
  node* deleting = search((*root), DELETE);
  node* CURRENTAT = NULL;
  node* POINTINGCURRENT;
  node* NEXTNODE = new node();
  if (deleting != NULL)
  {
    if (deleting -> getLeft() == NULL || deleting -> getRight() == NULL)
    {
      CURRENTAT = deleting;
    }
    else 
    {
      CURRENTAT = predecessor(deleting);
    }
    if (CURRENTAT != deleting)
    {
      deleting -> setData(CURRENTAT -> getData());
    }
    if(CURRENTAT -> getLeft() != NULL)
    {
      POINTINGCURRENT = CURRENTAT -> getLeft();
    }
    else {
      POINTINGCURRENT = CURRENTAT -> getRight();
    }
    if (POINTINGCURRENT == NULL)
    {
      POINTINGCURRENT = NEXTNODE;
      POINTINGCURRENT -> setCol(1);
    }
    POINTINGCURRENT -> setParent(CURRENTAT -> getParent());
    if (CURRENTAT -> getParent() == NULL)
    {
      (*root) = POINTINGCURRENT;
    }
    else 
    {
      if(CURRENTAT == CURRENTAT -> getParent() -> getLeft())
      {
          CURRENTAT -> getParent() -> setLeft(POINTINGCURRENT);
      }
      else {
    CURRENTAT -> getParent() -> setRight(POINTINGCURRENT);
      }
    }
    if(CURRENTAT -> getCol() == 1)
    {
      if(POINTINGCURRENT -> getCol() == 1)
      {
    DELETINGCASEVERISON1(root, POINTINGCURRENT);
      }
      else {
    POINTINGCURRENT -> setCol(1);
      }
    }
    if((POINTINGCURRENT -> getNil() == true) && (POINTINGCURRENT != (*root)))
    {
      if(POINTINGCURRENT == CURRENTAT -> getParent() -> getLeft())
      {
    POINTINGCURRENT -> getParent() -> setLeft(NULL);
      }
      else {
    POINTINGCURRENT -> getParent() -> setRight(NULL);
      }
      POINTINGCURRENT -> setParent(NULL);
      delete POINTINGCURRENT;
    }
    delete CURRENTAT;
  }
}

node* findsib(node* checking)
{
  node* sibling;
  if(checking -> getParent() -> getLeft() == checking){
      
    sibling = checking -> getParent() -> getRight();
  }
  else {
    sibling = checking -> getParent() -> getLeft();
  }
  return sibling;
}

void DELETINGCASEVERISON1(node** root, node* checking) {
  if(checking -> getParent() != NULL) {
    DELETINGCASEVERISON2(root, checking);
  }
}

void DELETINGCASEVERISON2(node** root, node* checking) {
  node* sibling = findsib(checking);

  if (sibling -> getCol() == 0) {
    checking -> getParent() -> setCol(0);
    sibling -> setCol(1);
    if (checking == checking -> getParent() -> getLeft()) {
      leftRotate(root, checking -> getParent());
    }
    else {
      rightRotate(root, checking -> getParent());
    }
  }
  DELETINGCASEVERISON3(root, checking);
}

void DELETINGCASEVERISON3(node** root, node* checking) {
  node* sibling = findsib(checking);

  if((checking -> getParent() -> getCol() == 1) &&
     (sibling -> getCol() == 1) &&
     
     (sibling -> getLeft() == NULL || sibling -> getLeft() -> getCol() == 1) &&
     
     (sibling -> getRight() == NULL || sibling -> getRight() -> getCol() == 1)){
    
    sibling -> setCol(0);
    DELETINGCASEVERISON1(root, checking -> getParent());
  }
  else {
    DELETINGCASEVERISON4(root, checking);
  }
}

void DELETINGCASEVERISON4(node** root, node* checking) {
  node* sibling = findsib(checking);
  
  if(checking -> getParent() -> getCol() == 0 && sibling -> getCol() == 1){
      
    if((sibling -> getLeft() == NULL || sibling -> getLeft() -> getCol() == 1) && (sibling -> getRight() == NULL || sibling -> getRight() -> getCol() == 1)) {
      sibling -> setCol(0);
        
      checking -> getParent() -> setCol(1);
    }
    else {
      DELETINGCASEVERISON5(root, checking);
    }
  }
  else {
    DELETINGCASEVERISON5(root, checking);
  }
}

void DELETINGCASEVERISON5(node** root, node* checking)
{
  node* sibling = findsib(checking);

  if(sibling -> getCol() == 1)
  {
    if((checking == checking -> getParent() -> getLeft()) &&
       
       ((sibling -> getRight() == NULL) || (sibling -> getRight() -> getCol() == 1)))
    {
      sibling -> setCol(0);
        
      sibling -> getLeft() -> setCol(1);
        
      rightRotate(root, sibling);
    }
    else if((checking == checking -> getParent() -> getRight()) &&
            
        ((sibling -> getLeft() == NULL) || (sibling -> getLeft() -> getCol() == 1)))
    {
      sibling -> setCol(0);
        
      sibling -> getRight() -> setCol(1);
        
      leftRotate(root, sibling);
    }
  }
  DELETINGCASEVERISON6(root, checking);
}

void DELETINGCASEVERISON6(node** root, node* checking) {
    
  node* sibling = findsib(checking);

  sibling -> setCol(checking -> getParent() -> getCol());
    
  checking -> getParent() -> setCol(1);

  if(checking == checking -> getParent() -> getLeft())
  {
    sibling -> getRight() -> setCol(1);
      
    leftRotate(root, checking -> getParent());
  }
  else
  {
    sibling -> getLeft() -> setCol(1);
      
    rightRotate(root, checking -> getParent());
  }
  
}

node* predecessor(node* top)
{
  if(top -> getLeft() != NULL)
  {
    top = top -> getLeft();
  }
  while(top -> getRight() != NULL)
  {
    top = top -> getRight();
  }
  return top;
}
node* search (node* CHECKING, int in)
{
  while (CHECKING != NULL)
  {
    if (in == CHECKING -> getData())
    {
      cout << "THE NUMBER IS IN THE TREE AS OF THIS MOMENT" << endl;
      return CHECKING;
    }
    else if (in < CHECKING -> getData())
    {
      CHECKING = CHECKING -> getLeft();
    }
    else
    {
        CHECKING = CHECKING -> getRight();
    }
  }
  cout << "CURRENTLY THE NUMBER IS NOT IN THE TREE" << endl;
  return NULL;
}
