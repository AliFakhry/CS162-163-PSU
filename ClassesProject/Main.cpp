//NAME: ALI FAKHRY
//DATE: 5 NOVEMEBER 2019
//FUNCTION: ADD A MOVIE,SONG,or GAME to a VECTOR MEDIA. SEARCH or DELETE from that vector.
//IMPLEMENTATION: Parent Class, Media, 3 sub daughter classes: SONGS, MOVIES, or GAMES
#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Songs.h"
#include "Movies.h"
#include "Games.h"

//initilization of the methods
void ADD(vector<Media*>* Med);
void SearchYear(vector<Media*>* Med, int year);
void SearchTitle(vector<Media*>* Med, char* title);
void DeleteYear(vector<Media*>* Med, int year);
void DeleteTitle(vector<Media*>* Med, char* title);
using namespace std;

//main function
int main() {
  vector <Movies*> Mov;
  vector <Media*> Med;
  vector <Games*> Gam;
  int z =1;
  int year;
  char input[7];
  char input2[5];
  char input3[10];
  char input4[10];
  cout << "WELCOME TO CLASSES!\n" << endl;
  while ( z==1) {
    cout << "\nWHAT DO YOU WANT TO DO?\n";
    cout << "ADD" << endl;
    cout << "SEARCH" << endl;
    cout << "DELETE" << endl;
    cout << "QUIT" << endl;
    cout << "THE WORD IS CAPITAL SENSITIVE!";
    cin >> input;
    if (strcmp(input, "ADD") == 0){ //if they want to ADD
      cin.clear();
      cin.ignore(10000, '\n');
      ADD(&Med); //pass by the address
    }

    else if (strcmp(input, "SEARCH") ==0) { //if they want to search
      cout <<"SEARCH BY TITLE OR YEAR?";
      cin >> input2;
      cin.clear();
      cin.ignore(1000000, '\n');

      if (strcmp(input2, "TITLE") == 0) { //if they want to search by title
	cout << "WHAT IS THE TITLE" << endl; 
	cin.get(input3, 10);
	cin.clear();
	cin.ignore(100000, '\n');
	SearchTitle(&Med, input3); //pass by the address and the title
      }
      else if (strcmp(input2, "YEAR") == 0){ //if they want to search by year
       	  cout << "WHAT IS THE YEAR?" <<endl;
	  cin >> year;
	  cin.clear();
	  cin.ignore(100000, '\n');
	  SearchYear(&Med, year); //pass by the address and the year
	}
      else {
	cout << "What?";
	cin.clear();
	cin.ignore(100000, '\n');
      }
    }
     else if (strcmp(input, "DELETE") ==0) { //if they want to DELETE
      cout <<"SEARCH BY TITLE OR YEAR?";
      cin >> input2;
      cin.clear();
      cin.ignore(1000000, '\n');

      if (strcmp(input2, "TITLE") == 0) { //if they want to DELETE by title
	cout << "WHAT IS THE TITLE" << endl; 
	cin.get(input3, 10);
	cin.clear();
	cin.ignore(100000, '\n');
	DeleteTitle(&Med, input3); //pass by the address and the title
      }
      else if (strcmp(input2, "YEAR") == 0){ //if they want to DELETE by year
       	  cout << "WHAT IS THE YEAR?" <<endl;
	  cin >> year;
	  cin.clear();
	  cin.ignore(100000, '\n');
	  DeleteYear(&Med, year); //pass by the address and the year
	}
      else {
	cout << "What?";
	cin.clear();
	cin.ignore(100000, '\n');
      }
    }

    else if (strcmp(input, "QUIT") ==0) {
      cout << "GOODBYE!" <<endl;
      z=0;
    }
    else {
      cout << "What?";
      cin.clear();
      cin.ignore(100000, '\n');
    }
  }
  return 0;
}
void SearchTitle(vector <Media*>* Med, char* title) { //Search & print by year
  vector <Media*>::iterator a;
  for (a = Med -> begin(); a != Med -> end(); ++a) {
    if(strcmp(title, (*a)->takeTitle()) == 0){
      cout << "YEAR: " << *(*a) -> takeYear() << endl;
      cout << "TITLE: " << (*a) -> takeTitle() << endl;
      if ((*a) -> takeType() == 1) { //print the extras (movies)
	cout << "Duration: " << dynamic_cast<Movies*>(*a)->takeDirector() << endl;
        cout << "Publisher: " << *dynamic_cast<Movies*>(*a)->takeDuration() << endl;
        cout << "Duration: " << *dynamic_cast<Movies*>(*a)->takeRating() << endl;
      }

      if ((*a) -> takeType() ==2) { //print the extras (games)
	cout << "Publisher: " << dynamic_cast<Games*>(*a)->takePublisher() << endl;
        cout << "Rating: " << *dynamic_cast<Games*>(*a)->takeRating() << endl;
      }

      if ((*a) -> takeType() ==3) { //print the extras (songs)
	cout << "Duration: " << *dynamic_cast<Songs*>(*a)->takeDuration() << endl;
        cout << "Publisher: " << dynamic_cast<Songs*>(*a)->takePublisher() << endl;
        cout << "Artist: " << dynamic_cast<Songs*>(*a)->takeArtist() << endl;
      }

    }
  }
}
void SearchYear(vector <Media*>* Med, int year) { // Search & print by year
  vector <Media*>::iterator a;
  for (a = Med ->begin(); a != Med-> end(); ++a) {
    if(year== *(*a) -> takeYear()) {
      cout << "YEAR: " << *(*a) -> takeYear() <<endl;
      cout << "TITLE: " << (*a) -> takeTitle() <<endl;
      if ((*a) -> takeType() == 1) { //print the extras (Movies)
	cout << "Duration: " << dynamic_cast<Movies*>(*a)->takeDirector() << endl;
        cout << "Publisher: " << *dynamic_cast<Movies*>(*a)->takeDuration() << endl;
	cout << "Duration: " << *dynamic_cast<Movies*>(*a)->takeRating() << endl <<endl;
      } 
      else if ((*a) -> takeType() == 2) { //print the extras(games)
	cout << "Publisher: " << dynamic_cast<Games*>(*a)->takePublisher() << endl;
        cout << "Rating: " << *dynamic_cast<Games*>(*a)->takeRating() << endl <<endl;
      }
      else if ((*a) -> takeType() == 3) { //print the extras (songs)
 	cout << "Duration: " << *dynamic_cast<Songs*>(*a)->takeDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Songs*>(*a)->takePublisher() << endl;
	cout << "Artist: " << dynamic_cast<Songs*>(*a)->takeArtist() << endl <<endl;
      }
      
    }
  }
    
}
void DeleteTitle(vector<Media*>* Med, char* title) { //delete by the title
  char YS[4];
  vector <Media*>::iterator a;
  for (a = Med -> begin(); a != Med -> end(); ++a) {
    if(strcmp(title, (*a)->takeTitle()) == 0){
      cout << "YEAR: " << *(*a) -> takeYear() << endl;
      cout << "TITLE: " << (*a) -> takeTitle() << endl;
      if ((*a) -> takeType() == 1) { //print the movies (extras)
        cout << "Duration: " << dynamic_cast<Movies*>(*a)->takeDirector() << endl;
        cout << "Publisher: " << *dynamic_cast<Movies*>(*a)->takeDuration() << endl;
        cout << "Duration: " << *dynamic_cast<Movies*>(*a)->takeRating() << endl;
      }

      else if ((*a) -> takeType() ==2) { //print the games (extras)
        cout << "Publisher: " << dynamic_cast<Games*>(*a)->takePublisher() << endl;
        cout << "Rating: " << *dynamic_cast<Games*>(*a)->takeRating() << endl;
      }

      else if ((*a) -> takeType() ==3) { //print the songs (extras)
        cout << "Duration: " << *dynamic_cast<Songs*>(*a)->takeDuration() << endl;
        cout << "Publisher: " << dynamic_cast<Songs*>(*a)->takePublisher() << endl;
        cout << "Artist: " << dynamic_cast<Songs*>(*a)->takeArtist() << endl;
      }
      //decide if they want to delete it or not
      cout << "Delete(YES or NO)" <<endl;
      cin >> YS;
      if (strcmp(YS, "YES")==0) {
	delete *a;
	a = Med -> erase(a);
 	return;      
      }
    }
  }
}
 void DeleteYear(vector<Media*>* Med, int year) {
     char input[10];
  vector<Media*>::iterator b;
  for(b = Med->begin(); b != Med->end(); ++b) {
    if(year == *(*b)->takeYear()) {
      cout << endl << "Title: " << (*b)->takeTitle() << endl;
      cout << "Year: " << *(*b)->takeYear() << endl;
      	if((*b)->takeType() == 1) {
	  cout << "Director: " << dynamic_cast<Movies*>(*b)->takeDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movies*>(*b)->takeDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movies*>(*b)->takeRating() << endl;
 	}
	else if((*b)->takeType() == 2) {
	  cout << "Publisher: " << dynamic_cast<Games*>(*b)->takePublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<Games*>(*b)->takeRating() << endl;
	}
	else if((*b)->takeType() == 3) {
	  cout << "Artist: " << dynamic_cast<Songs*>(*b)->takeArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Songs*>(*b)->takeDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Songs*>(*b)->takePublisher() << endl;
	}
	cout << "DELETE? YES or NO: ";
	cin.get(input, 10);
	cin.clear();
	cin.ignore(10000, '\n');

	if(strcmp(input, "YES") == 0) {
	  delete *b;
	  b = Med -> erase(b);
	  return;
	}
      }
    }
 }
void ADD (vector <Media*>* Med) { //ADD Method
      char input[6];
      cout << "GAMES MOVIES or SONGS (CASE SENSITIVE)" << endl;
      cin.get(input, 12);
      cin.clear();
      cin.ignore(10000, '\n');
      if (strcmp(input, "GAMES") ==0) { //if they input games
	  Games* games = new Games();
	  cout << "Whats the title?"; 
	  cin.get(games -> takeTitle(), 10); //input title
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  cout << "Year?";
	  cin >> *games -> takeYear(); //input year
	  cin.clear();
	  cin.ignore(100000, '\n');
	  cout << "Publisher?";
	  cin.get(games -> takePublisher(),15); //input publisher
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  cout << "Rating?";
	  cin >> *games -> takeRating(); //input rating
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  Med ->push_back(games);
	}
      else if(strcmp(input, "MOVIES")==0) { //if they chose to put in Movies
	Movies* movies = new Movies();  
	cout << "Whats the title?"; 
	cin.get(movies -> takeTitle(),10); //get title
	cin.clear();
	cin.ignore(100000, '\n');
	cout << "Whats the year?";
	cin >> *movies -> takeYear(); //get year
        cin.clear();
	cin.ignore(1000000, '\n');
	cout << "What's the director?"; 
	cin.get(movies -> takeDirector(), 20); //get the director
	cin.clear();
	cin.ignore(10000000, '\n');
	cout << "what's the duration?";
	cin >> *movies -> takeDuration(); //get the duration
	cin.clear();
	cin.ignore(1000000, '\n');
	cout << "whats the rating?";
	cin >> *movies -> takeRating(); //get the rating
	cin.clear();
	cin.ignore(100000, '\n');
	Med -> push_back(movies);
	}
      else if (strcmp(input, "SONGS")==0) { //if they chose to put in song
        Songs* songs = new Songs();
	cout << "Whats the title?";
	cin.get(songs -> takeTitle(), 10); //get the title
	cin.clear();
	cin.ignore(1000000, '\n');
	cout << "Whats the year?";
	cin >> *songs -> takeYear(); //get the year
	cin.clear();
	cin.ignore(1000000, '\n');
	cout << "What is the duration?";
	cin >> *songs -> takeDuration(); //get the duration
	cin.clear();
	cin.ignore(1000000, '\n');
	cout << "What is the publisher?";
	cin.get(songs -> takePublisher(), 20); //get the publisher
	cin.clear();
	cin.ignore(100000, '\n');
	cout << "What is the artist?";
	cin.get(songs -> takeArtist(), 20); //get the artist
	cin.clear();
	cin.ignore(100000, '\n');
	Med -> push_back(songs);
	    }
      else { //input doesn't match
	cout << "What?" << endl;
	cin.clear();
	cin.ignore(100000, '\n');
      }
    }


	
