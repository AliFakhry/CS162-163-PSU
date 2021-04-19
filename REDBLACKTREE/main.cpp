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
//
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

void print(node*, int);
void add(node**, node*, int);
void adjust(node**, node*);
void leftRotate(node**, node*);
void rightRotate(node**,node*);

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
        cout << "THIS IS RED-PURPLE TREE: COMMANDS - ADD, PRINT, READ, QUIT" << endl;
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
           else if (strcmp(input, "QUIT") == 0)
           {
           RUNNING = false;
           }
    }
}
    //citations: Myself
    void print(node* parentNode, int countNum)
    {
          if(parentNode -> getRight() != NULL)
          {
              print(parentNode -> getRight(), countNum + 1);
          }
          int tempVar = countNum;
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
          if (parentNode -> getLeft() != NULL)
          {
              print(parentNode -> getLeft(), tempVar + 1);
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
   

  void add (node** root, node* parentNode, int NUMBER){
      if (parentNode -> getData() == 0)
      {
        parentNode -> setCol(1); parentNode -> setData(NUMBER);
      }
      else
      {
        if(NUMBER < parentNode -> getData())
        {
            if (parentNode -> getLeft() == NULL)
            {
                node* newNode = new node();
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
        else {
        if (parentNode -> getRight() == NULL)
        {
            node* newNode = new node();
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

