#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;


int main() 
{
  char input = ' ';
  char input2 = ' ';
  char board[3][3];
  int play =1;
  char player = 'x';
  board[0][0] = ' ';
  board[0][1] = ' ';
  board[0][2] = ' ';
  board[1][0] = ' ';
  board[1][1] = ' ';
  board[1][2] = ' ';
  board[2][0] = ' ';
  board[2][1] = ' ';
  board[2][2] = ' ';
 
  cout << "  1 2 3" << endl;
  cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
  cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[0][2] << endl;
  cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[0][2] << endl;

  cout << "Welcome to TicTacToe!";
  
  while (play == 1) {
    cout << "Put in a letter!";
    cin >> input;
    cout << "Put in the number!";
    cin >> input2;
  
  if (input == 'a' && input2 == '1') {
  if (board[0][0] == ' ') {
  board[0][0] = player; 
  cout << "  1 2 3" << endl;
  cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
  cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
  cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;

  if (player == 'x') {
      player = 'o';
 }
    else if (player == 'o')  {
    player = 'x';
    }
 }
    }
  else if (input == 'a' && input2 == '2') {
  if (board[0][1] == ' ') {
  board[0][1] = player; 
  cout << "  1 2 3" << endl;
  cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
  cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
  cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
  if (player == 'x') {
      player = 'o';
 }
    else if (player == 'o')  {
    player = 'x';
    }
    
  }
}
else if (input == 'a' && input2 == '3') {
  if (board[0][2] == ' ') {
  board[0][2] = player; 
  cout << "  1 2 3" << endl;
  cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
  cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
  cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
  if (player == 'x') {
      player = 'o';
 }
    else if (player == 'o')  {
    player = 'x';
    }
    
  }
}
 else if (input == 'b' && input2 == '1') {
  if (board[1][0] == ' ') {
   board[1][0] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
  else if (input == 'b' && input2 == '2') {
  if (board[1][1] == ' ') {
   board[1][1] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
  else if (input == 'a' && input2 == '3') {
  if (board[1][0] == ' ') {
   board[0][2] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
 else if (input == 'b' && input2 == '3') {
  if (board[1][2] == ' ') {
   board[1][2] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
 else if (input == 'b' && input2 == '3') {
  if (board[1][2] == ' ') {
   board[1][2] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
 else if (input == 'b' && input2 == '3') {
  if (board[1][2] == ' ') {
   board[1][2] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
 else if (input == 'c' && input2 == '1') {
  if (board[2][0] == ' ') {
   board[2][0] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
 else if (input == 'c' && input2 == '1') {
  if (board[2][0] == ' ') {
   board[2][0] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
  else if (input == 'c' && input2 == '1') {
  if (board[2][0] == ' ') {
   board[2][0] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
  else if (input == 'c' && input2 == '1') {
  if (board[2][0] == ' ') {
   board[2][0] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
 else if (input == 'c' && input2 == '2') {
  if (board[2][1] == ' ') {
   board[2][1] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
  else if (input == 'c' && input2 == '3') {
  if (board[2][2] == ' ') {
   board[2][2] = player; 
   cout << "  1 2 3" << endl;
   cout << 'a' << ' ' << board[0][0] << ' ' << board[0][1] << ' ' << board[0][2] << endl;
   cout << 'b' << ' ' << board[1][0] << ' ' << board[1][1] << ' ' << board[1][2] << endl;
   cout << 'c' << ' ' << board[2][0] << ' ' << board[2][1] << ' ' << board[2][2] << endl;
   if (player == 'x') {
       player = 'o';
  }
     else if (player == 'o')  {
     player = 'x';
     }
    
   }
 }
  
}
}
