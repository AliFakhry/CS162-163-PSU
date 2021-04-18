#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
//Game: Guessing Game
//Description: User inputs numbers (1-100) and the code will tell the user if it is too big/small and will keep running till the user guesses the number correctly
//Name: Ali Fakhry
//Date: Septemeber 13 2019
//Period: 3
int main()
{
  srand (time(NULL));
  int randomnum = rand() % 100;
  int input = 101;
  int attempts =0; 
  char again = 'z';
  cout <<"Welcome to the guessing game! Choose a number from 0-100: \n\n ";
  while (input != randomnum) { //while the number guessed isn't equal to the random number, continue guessing
  cin >> input;
  if (randomnum > input ) //if the guessed number is too small, output that it's too small
  {
    cout << "Guess is too small!\n Guess Again: \n\n";
    attempts++; //increase the number of attempts
  }
  else if (randomnum < input) //the guessed number is too big, output that it's too big
    {
      cout << "Guess is too big! \n Guess Again: \n\n";
      attempts++; //increase the number of attempts
    }
  else //if guessed right
    {
      attempts++; //increase the number of attempts
      cout << "Good you guessed the number in: ";
      cout << attempts;
      cout << " attempts! ";
      cout << "Do you want to play again (y/n)\n\n"; //ask if they want to play again 
      cin >> again;
      if (again == 'y') {
        attempts =0;
        input = 101;
        randomnum = rand() % 100;
	cout <<"Welcome to the guessing game! Choose a number from 0-100: \n\n ";
      }
      else if (again == 'n') {
	cout <<"Thanks for playing!";
    }
  }
  }
  return 0;
}
