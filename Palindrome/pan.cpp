
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>

//Name: Ali Fakhry
//Date: Septemeber 16 2019
//Period: 3
//Description: User puts in a word and it is compared to see if it is equal forward and backwards
//Game: Palindrome
using namespace std;

int main()
{
  char str[80]; //original input string 
  cin.get(str,80); //get from the first char to the the 81
  cin.get(); 
  int count = 0;
  char x;
  int i=0;
  int z=0;
  int y=0;
  int length = strlen(str); //get the length of the origianl cstring input
  for (int i = 0; i < length; i++) { //change the char from uper to lower
    x = str[i]; 
    if (x == 'A') {
      str[i] = 'a';
    }
    else if (x == 'B') {
      str[i] = 'b';
    }
    else if (x == 'C') {
      str[i] = 'c';
    }
    else if (x == 'D') {
      str[i] = 'd';
    }
    else if (x == 'E') {
      str[i] = 'e';
    }
    else if (x == 'F') {
      str[i] = 'f';
    }
    else if (x == 'G') {
      str[i] = 'g';
    }
    else if (x=='H') {
      str[i] = 'h';
    }
    else if (x== 'I') {
      str[i] = 'i';
    }
    else if (x== 'J') {
      str[i]= 'j';
    }
    else if (x =='K') {
      str[i] = 'k';
    }
    else if (x == 'L') {
      str[i] = 'l';
    }
    else if (x == 'M') {
      str[i] = 'm';
    }
    else if (x == 'N') {
      str[i] = 'n';
    }
    else if (x == 'O') {
      str[i] = 'o';
    }
    else if (x == 'P') {
      str[i] = 'p';
    }
    else if (x == 'Q') {
      str[i] = 'q';
    }
    else if (x == 'R') {
      str[i] = 'r';
    }
    else if (x== 'S') {
      str[i] = 's';
    }
    else if (x== 'T') {
      str[i] = 't';
    }
    else if (x == 'U') {
      str[i] = 'u';
    }
    else if (x == 'V') {
      str[i] = 'v';
    }
    else if (x== 'W') {
      str[i] = 'w';
    }
    else if (x == 'X') {
      str[i] = 'x';
    }
    else if (x == 'Y')  {
      str[i] = 'y';
	  }
    else if ( x == 'Z') {
      str[i] = 'z';
    }
  }
  for (int i =0; i < length; i++) { //gets the length of alnum in original input
    if (isalnum(str[i])) {
     z++;
     }
  }
  char str2[z]; //makes cstring based on the size of the original input
  for (int i = 0; i < length; i++) { //place alnum characters in original string to a new string
    if (isalnum(str[i])) {
      str2[y] = str[i];
      y++;
    }
  }
  for (int i =0; i < z+1; i++) { //if all the characters match back and forth its a palidrone
    if (count == z) {
      i =z + 1;
      cout << "\n\nPalidrome!\n\n";
      }
    else if (str2[i] == str2[z-1-i]) {
      count++;
    }
    else if (str2[i] != str2[z-1-i]) { //if it is not, say it is not a palidrone
        i=z + 1;
        cout << "\n\nNot a palidrome!\n\n";
  }
  }
    return 0;
}
