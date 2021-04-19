//NAME: ALI FAKHRY
//DATE: 20 NOVEMEBER 2019
//FUNCTION: PLAYER IS IN A DUNGEON, GET TO ROOM 15 AND GET ALL 5 KEYS. TIMED RACE!
//IMPLEMENTATION: Using c++'s map, and vector's for items and rooms.
#include <iostream>
#include "Room.h"
#include "Item.h"
#include <map>
#include <cstring>
#include <vector>
#include <chrono> 
#include <ctime>
using namespace std;
int main() {
vector <Room*>* room = new vector<Room*>();
 Room* ROOM1 = new Room();//Creates new room
 Room* ROOM2 = new Room();//Creates new room
 Room* ROOM3 = new Room();//Creates new room
 Room* ROOM4 = new Room();//Creates new room
 Room* ROOM5 = new Room();//Creates new room
 Room* ROOM6 = new Room();//Creates new room
 Room* ROOM7 = new Room();//Creates new room
 Room* ROOM8 = new Room();//Creates new room
 Room* ROOM9 = new Room();//Creates new room
 Room* ROOM10 = new Room();//Creates new room
 Room* ROOM11 = new Room();//Creates new room
 Room* ROOM12 = new Room();//Creates new room
 Room* ROOM13 = new Room();//Creates new room
 Room* ROOM14 = new Room();//Creates new room
 Room* ROOM15 = new Room();//Creates new room

 //create room1
 char* a = new char[10];
 strcpy (a , "Room ONE");
 ROOM1 -> setDes(a);
 char* a2 = new char[10];
 strcpy (a2, "ROOM1"); 
 ROOM1 -> setTitle(a2);
 map <char*, Room*>* m1 = new map<char*, Room*>;
 char* a1 = new char[10];
 strcpy (a1, "NORTH");
 m1 -> insert(pair<char*,Room*>(a1, ROOM2));
 ROOM1-> setMap(m1);
 room -> push_back(ROOM1);
 
 //create room2
 char* b = new char[10];
 strcpy (b, "Room TWO");
 ROOM2 -> setDes(b);
 map <char*, Room*>* m2 = new map<char*, Room*>;
 char* b1 = new char[10];
 strcpy (b1, "NORTH");
 m2 -> insert(pair<char*,Room*>(b1, ROOM3));
 char* b2 = new char[10];
 strcpy (b2, "SOUTH");
 m2 -> insert(pair<char*,Room*>(b2, ROOM1));
 ROOM2-> setMap(m2);
 room -> push_back(ROOM2);
 
 //create room3
 char* c = new char[10];
 strcpy (c, "Room THREE");
 ROOM3 -> setDes(c);
 map <char*, Room*>* m3 = new map<char*, Room*>;
 char* c1 = new char[10];
 strcpy (c1, "NORTH");
 m3 -> insert(pair<char*,Room*>(c1, ROOM4));
 char* c2 = new char[10];
 strcpy (c2, "SOUTH");
 m3 -> insert(pair<char*,Room*>(c2, ROOM2));
 ROOM3-> setMap(m3);
 room -> push_back(ROOM3);

 //create room4
 char* d = new char[10];
 strcpy (d, "Room FOUR");
 ROOM4 -> setDes(d);
 map <char*, Room*>* m4 = new map<char*, Room*>;
 char* d1 = new char[10];
 strcpy (d1, "NORTH");
 m4 -> insert(pair<char*,Room*>(d1, ROOM5));
 char* d2 = new char[10];
 strcpy (d2, "SOUTH");
 m4 -> insert(pair<char*,Room*>(d2, ROOM3));
 ROOM4-> setMap(m4);
 room -> push_back(ROOM4);
  
 //create room5
 char* e = new char[10];
 strcpy (e, "Room FIVE");
 ROOM5 -> setDes(e);
 map <char*, Room*>* m5 = new map<char*, Room*>;
 char* e1 = new char[10];
 strcpy (e1, "NORTH");
 m5 -> insert(pair<char*,Room*>(e1, ROOM6));
 char* e2 = new char[10];
 strcpy (e2, "SOUTH");
 m5 -> insert(pair<char*,Room*>(e2, ROOM4));
 ROOM5-> setMap(m5);
 room -> push_back(ROOM5);

 //create room6
 char* f = new char[10];
 strcpy (f, "Room SIX");
 ROOM6 -> setDes(f);
 map <char*, Room*>* m6 = new map<char*, Room*>;
 char* f1 = new char[10];
 strcpy (f1, "NORTH");
 m6 -> insert(pair<char*,Room*>(f1, ROOM7));
 char* f2 = new char[10];
 strcpy (f2, "SOUTH");
 m6 -> insert(pair<char*,Room*>(f2, ROOM5));
 ROOM6 -> setMap(m6);
 room -> push_back(ROOM6);

 //create room7
 char* g = new char[10];
 strcpy (g, "Room SEVEN");
 ROOM7 -> setDes(g);
 map <char*, Room*>* m7 = new map<char*, Room*>;
 char* g1 = new char[10];
 strcpy (g1, "NORTH");
 m7 -> insert(pair<char*,Room*>(g1, ROOM8));
 char* g2 = new char[10];
 strcpy (g2, "SOUTH");
 m7 -> insert(pair<char*,Room*>(g2, ROOM6));
 ROOM7 -> setMap(m7);
 room -> push_back(ROOM7);

 //create room8
 char* h = new char[10];
 strcpy (h, "Room EIGHT");
 ROOM8 -> setDes(h);
 map <char*, Room*>* m8 = new map<char*, Room*>;
 char* h1 = new char[10];
 strcpy (h1, "NORTH");
 m8 -> insert(pair<char*,Room*>(h1, ROOM9));
 char* h2 = new char[10];
 strcpy (h2, "SOUTH");
 m8 -> insert(pair<char*,Room*>(h2, ROOM7));
 ROOM8 -> setMap(m8);
 room -> push_back(ROOM8);
 
 //create room9
 char* i = new char[10];
 strcpy (i, "Room NINE");
 ROOM9 -> setDes(i);
 map <char*, Room*>* m9 = new map<char*, Room*>;
 char* i1 = new char[10];
 strcpy (i1, "NORTH");
 m9 -> insert(pair<char*,Room*>(i1, ROOM10));
 char* i2 = new char[10];
 strcpy (i2, "SOUTH");
 m9 -> insert(pair<char*,Room*>(i2, ROOM8));
 ROOM9 -> setMap(m9);
 room -> push_back(ROOM9);

 //create room10
 char* j = new char[10];
 strcpy (j, "Room TEN");
 ROOM10 -> setDes(j);
 map <char*, Room*>* m10 = new map<char*, Room*>;
 char* j1 = new char[10];
 strcpy (j1, "NORTH");
 m10 -> insert(pair<char*,Room*>(j1, ROOM11));
 char* j2 = new char[10];
 strcpy (j2, "SOUTH");
 m10 -> insert(pair<char*,Room*>(j2, ROOM9));
 ROOM10 -> setMap(m10);
 room -> push_back(ROOM10);

 //create room11
 char* k = new char[10];
 strcpy (k, "Room ELEVEN");
 ROOM11 -> setDes(k);
 map <char*, Room*>* m11 = new map<char*, Room*>;
 char* k1 = new char[10];
 strcpy (k1, "NORTH");
 m11 -> insert(pair<char*,Room*>(k1, ROOM12));
 char* k2 = new char[10];
 strcpy (k2, "SOUTH");
 m11 -> insert(pair<char*,Room*>(k2, ROOM10));
 ROOM11 -> setMap(m11);
 room -> push_back(ROOM11);
 
 //create room12
 char* l = new char[10];
 strcpy (l, "Room TWELVE");
 ROOM12 -> setDes(l);
 map <char*, Room*>* m12 = new map<char*, Room*>;
 char* l1 = new char[10];
 strcpy (l1, "NORTH");
 m12 -> insert(pair<char*,Room*>(l1, ROOM13));
 char* l2 = new char[10];
 strcpy (l2, "SOUTH");
 m12 -> insert(pair<char*,Room*>(l2, ROOM11));
 ROOM12 -> setMap(m12);
 room -> push_back(ROOM12);

 //create room13
 char* n = new char[10];
 strcpy(n, "Room THIRTEEN");
 ROOM13 -> setDes(n);
 map <char*, Room*>* m13 = new map<char*, Room*>;
 char* n1 = new char[10];
 strcpy (n1, "NORTH");
 m13 -> insert(pair<char*,Room*>(n1, ROOM14));
 char* n2 = new char[10];
 strcpy (n2, "SOUTH");
 m13 -> insert(pair<char*,Room*>(n2, ROOM12));
 ROOM13 -> setMap(m13);
 room -> push_back(ROOM13);

 //create room14
 char* o = new char[10];
 strcpy(o, "Room Fourteen");
 ROOM14 -> setDes(o);
 map <char*, Room*>* m14 = new map<char*, Room*>;
 char* o1 = new char[10];
 strcpy (o1, "NORTH");
 m14 ->insert(pair<char*,Room*>(o1, ROOM15));
 char* o2 = new char[10];
 strcpy (o2, "SOUTH");
 m14 -> insert(pair<char*,Room*>(o2, ROOM13));
 ROOM14 -> setMap(m14);
 room -> push_back(ROOM14);

 //create room15
 char* p = new char[10];
 strcpy(p, "FINISHED!");
 ROOM15 -> setDes(p);
 map <char*, Room*>* m15 = new map<char*, Room*>;
 char* p1 = new char[10];
 ROOM15 -> setMap(m15);
 room -> push_back(ROOM15);
 
 vector <Item*> items;//vector holds all items
 Item* KEY1 = new Item();//Creates new item
 Item* KEY2 = new Item();//Creates new item
 Item* KEY3 = new Item();//Creates new item
 Item* KEY4 = new Item();//Creates new item
 Item* KEY5 = new Item();//Creates new item

 //creates key1
 char* in1 = new char [10]; 
 strcpy(in1, "KEY1"); // pointer 
 KEY1 -> setName(in1);
 KEY1 -> setL(ROOM1);
 items.push_back(KEY1); 

 //create key2
 char* in2 = new char[10];
 strcpy(in2, "KEY2");
 KEY2 -> setName(in2);
 KEY2 -> setL(ROOM3);
 items.push_back(KEY2);
 
 //create key3
 char* in3 = new char[10];
 strcpy(in3, "KEY3");
 KEY3 -> setName(in3);
 KEY3 -> setL(ROOM5);
 items.push_back(KEY3);
 
 //create key4
 char* in4 = new char[10];
 strcpy(in4, "KEY4");
 KEY4 -> setName(in4);
 KEY4 -> setL(ROOM8);
 items.push_back(KEY4);
 
 //create key5
 char* in5 = new char[10];
 strcpy(in5, "KEY5");
 KEY5 -> setName(in5);
 KEY5 -> setL(ROOM10);
 items.push_back(KEY5);

 //initization of conditions
char input2[3];
bool playing = false;
 bool start = true;
int roomnum = 1;
Room* current = ROOM1;
bool onwards = true;
Room* Inv = new Room();
   cout << "WELCOME TO ZUUL" << endl;
   cout << "YOU ARE IN A DUNGEON!" <<endl;
   cout<< "A DRAGON IS CHASING YOU GET ALL THE KEYS AND GET TO THE END" <<endl;
   cout << "YOU HAVE TO PICK UP ALL THE ITEMS AND GO TO THE END!" << endl;
   cout << "THE KEYS ARE IN ROOM 1, ROOM 3, ROOM 5, ROOM 8, and ROOM 10!" << endl;
   cout << "COMMANDS ARE 'PICK' 'DROP' 'NORTH' 'SOUTH' 'EXITS' 'LOOK' 'QUIT' 'ROOMNUM' " <<endl;
   cout<< "THIS IS A TIMED RACE! GO AS FAST AS YOU CAN!" <<endl;
   cout << "SAY 'GO' TO START!" <<endl;
   cin.get(input2,10);
   cin.clear();
   cin.ignore(1000, '\n');
   if (strcmp(input2,"GO")==0) { //when they say go start the time
     cout << "TIMER STARTS! GO!" <<endl;
     playing = true;
   }
   while (playing == true) { 
     if (start == true) {
       unsigned int start = clock(); //start the time
     }
   onwards = true;
   char input[10];
   cin.get(input,10);
   cin.clear();
   cin.ignore(10000, '\n');
   if (strcmp(input, "EXITS")==0) {
   map<char*, Room*>* MAPSTUFF = current -> getMap();//map                                                                                                                                                                               
   cout << "THESE ARE THE DIRECTIONS: " << endl;
   for(map<char*,Room*>::iterator it = MAPSTUFF -> begin(); it != MAPSTUFF -> end(); ++it) {//Goes through the map                                                                                                                       
     cout << it -> first << endl; //Prints key of the map                                                                                                                                                                                
   }
   }
   else if (strcmp(input, "LOOK" )==0) {
     cout << "There is a " <<endl;
       for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) { //runs through the items
	 if ((*it) -> getL() == current) {//room print it out
	   cout << (*it) -> getName() << endl;
	 }
       }
   }

     else if (strcmp(input, "PICK")==0) {
       for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) {//runs through items
	 if ((*it) -> getL() == current) { //If it is in your room
	   cout << "CASE SENSITIVE!" <<endl;
	   cout << "Do you wish to pickup " << (*it) -> getName() << "(answer Y or N)" << endl;
	   char yesno; //holds answer
	   cin >> yesno;
	   if (yesno == 'Y') {
	     cin.ignore();
	     (*it) -> setL(Inv);
	   }
	 }
       }
     }
     else if (strcmp(input, "DROP") == 0) {// drop item
       cout << "You have: " << endl; //prints what you have
       for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) {//goes through items
	 if ((*it) -> getL() == Inv) {//if it is inventory room
	   cout << (*it) -> getName() << endl; //prints items in inv
	 }
       }
       cout << "Enter the Item you want to drop" << endl;
       char* itemdrop = new char [10];//pointer to hold item name
       cin.getline(itemdrop, 10);//enters input in pointer
       for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) {//runs through items
	 if ((*it) -> getL() == Inv && strcmp((*it) -> getName(), itemdrop) == 0) {//if it is in room  INV and matches name of item to drop
	   (*it) -> setL(current);//sets item in the current room
	   cout << " dropped" << endl;
	 }
       }
     }
     else if (strcmp(input, "NORTH") ==0 && roomnum <= 14) {//goes forward
       roomnum++;
       if (roomnum == 1) {
	 current = ROOM1;
       }
       else if (roomnum == 2) {
         current = ROOM2;
       }
       else if (roomnum == 3) {
         current = ROOM3;
       }
       else if (roomnum == 4) {
         current = ROOM4;
       }
       else if (roomnum == 5) {
         current = ROOM5;
       }
       else if (roomnum == 6) {
         current = ROOM6;
       }
       else if (roomnum == 7) {
         current = ROOM7;
       }
       else if (roomnum == 8) {
         current = ROOM8;
       }
       else if (roomnum == 9) {
         current = ROOM9;
       }
       else if (roomnum == 10) {
         current = ROOM10;
       }
       else if (roomnum == 11) {
         current = ROOM11;
       }
       else if (roomnum == 12) {
         current = ROOM12;
       }
       else if (roomnum == 13) {
         current = ROOM13;
       }
       else if (roomnum == 14) {
         current = ROOM14;
       }
       else  if (roomnum == 15) {
         current = ROOM15;
       }
       cout << "YOU ARE IN THIS ROOM " << roomnum <<endl;
     }
     else if (strcmp(input, "SOUTH") ==0 && roomnum >= 2) { //goes back
       roomnum--;
       if (roomnum == 1) {
         current = ROOM1;
       }
       else if (roomnum == 2) {
         current = ROOM2;
       }
       else if (roomnum == 3) {
         current = ROOM3;
       }
       else if (roomnum == 4) {
         current = ROOM4;
       }
       else if (roomnum == 5) {
         current = ROOM5;
       }
       else if (roomnum == 6) {
         current = ROOM6;
       }
       else if (roomnum == 7) {
         current = ROOM7;
       }
       else if (roomnum == 8) {
         current = ROOM8;
       }
       else if (roomnum == 9) {
         current = ROOM9;
       }
       else if (roomnum == 10) {
         current = ROOM10;
       }
       else if (roomnum == 11) {
         current = ROOM11;
       }
       else if (roomnum == 12) {
         current = ROOM12;
       }
       else if (roomnum == 13) {
         current = ROOM13;
       }
       else if (roomnum == 14) {
         current = ROOM14;
       }
       else  if (roomnum == 15) {
         current = ROOM15;
       }
       cout << "YOU ARE IN THIS ROOM " << roomnum <<endl;
     }
     else if (strcmp(input, "ROOMNUM") ==0) { //prints roomnum
       cout << roomnum <<endl;
     }
     if (roomnum == 15) { //winning condition
       int z1 =0;
       int z2 =0;
       int z3 = 0;
       int z4 =0;
       int z5 =0;
         cout << "YOU'RE IN THIS ROOM NUMBER:" << roomnum <<endl;
	 cout << "YOU NEED ALL 5 KEYS!" <<endl;
	 cout << "You have: " << endl; //prints what you have
      	 for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) {//goes through items
	 if ((*it) -> getL() == Inv) {//if it is inventory room
	 cout << (*it) -> getName() << endl; //prints items in inv
	for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) {//runs through items
	
	
	  if ((*it) -> getL() == Inv && strcmp((*it) -> getName(), "KEY1") == 0)
	    {
	      z1++;

	    }
	  else if ((*it) -> getL() == Inv && strcmp((*it) -> getName(), "KEY2") == 0)
	  {
	  z2++;

	  }
	  else if ((*it) -> getL() == Inv && strcmp((*it) -> getName(), "KEY3") == 0) 
	   {
	     z3++;
	   }
	  else if ((*it) -> getL() == Inv && strcmp((*it) -> getName(), "KEY4") == 0) 
	   {
	     z4++;
	   }
	  else if ((*it) -> getL() == Inv && strcmp((*it) -> getName(), "KEY5") == 0) {
              z5++; 
           }
	}
	 }

         }
     
	  if (z1 >=1 && z2 >= 1 && z3 >=1 && z4 >=1 && z5 >=1) {
	     //if you the if is true they win!
	   cout << "I see you picked up all the keys" <<endl;
	   cout << "GOOD JOB YOU FINISHED!" <<endl;
	   std::cout << "Time taken in millisecs: " << clock()-start <<endl;  //prints the amount of time it took to run the race
	   playing = false;
	  }
     }
     else if (strcmp(input, "QUIT") == 0) {//Ends program
       playing = false;//bool = false
     
       
     }
   
 }

   }

