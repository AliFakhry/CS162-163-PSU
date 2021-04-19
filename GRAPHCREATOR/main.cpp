//
//  main.cpp
//  GraphCreater
//
//  Created by Ali Fakhry on 5/14/20.
//  Copyright © 2020 AliFakhry. All rights reserved.
//
// GRAPH CREATOR HAS MANY OPTIONS, INCLUDING PRINT, DELETE, ADD VERTEX AND EDGE, REMOVE VERTEX AND EDGE, AND CAN FIND THE SHORTEST PATH ASWELL!
// CITED ALL MY SOURCES INCLUDING ONLINE AND OTHERS!

#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <queue>
#include <cstring>
#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
//THOUGHT OF USING A STRUCT
struct vertex
{
  char * PLACEDNODEHERE;
  vector < vertex * > edges;
  vector < int > weight;
};
//WAS GOING TO USE NODES INITIALLY
class node {
  char* PLACEDNODEHERE;
  char* callPLACEDNODEHERE();
  vector<node*> connect;
  void setPLACEDNODEHERE(char*);
  vector<node*> getVect();
  void vectPush(node* toPush) {
    connect.push_back(toPush);
  }
  void vectErase(vector<node*>::const_iterator it)
    {
    connect.erase(it);
  }
};
//WAS GOING TO USE NODES INITIALLY

char* node::callPLACEDNODEHERE()
{
  return PLACEDNODEHERE;
}
//WAS GOING TO USE NODES INITIALLY

void node::setPLACEDNODEHERE(char* NODEATHISPOINT)
{
  PLACEDNODEHERE = NODEATHISPOINT;
}
//WAS GOING TO USE NODES INITIALLY

vector<node*> node::getVect()
{
  return connect;
}
void removeVertex(vector < vertex * > &NODEHERE, char * PLACEDNODEHERE);
void print(vector < vertex * > NODEHERE);
void find(vector < vertex * > NODEHERE, vertex * INITIAL, vertex * SECONDNEXT);
void addEdge(vector < vertex * > NODEHERE, char * INITIAL, char * SECONDNEXT);
void removeEdge(vector < vertex * > &NODEHERE, char * INITIAL, char * SECONDNEXT);


//HELP FOR ALGORITHUM
//CITATION:https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
//// A C++ progrNODEHERE for Dijkstra's single source shortest path algorithm.
//// The progrNODEHERE is for adjacency matrix representation of the graph
//
//#include <limits.h>
//#include <stdio.h>
//
//// Number of vertices in the graph
//#define V 9
//
//// A utility function to find the vertex with minimum distance value, from
//// the set of vertices not yet included in shortest path tree
//int minDistance(int dist[], bool sptSet[])
//{
//    // Initialize min value
//    int min = INT_MAX, min_index;
//
//    for (int v = 0; v < V; v++)
//        if (sptSet[v] == false && dist[v] <= min)
//            min = dist[v], min_index = v;
//
//    return min_index;
//}
//
//// A utility function to print the constructed distance array
//void printSolution(int dist[])
//{
//    printf("Vertex \t\t Distance from Source\n");
//    for (int i = 0; i < V; i++)
//        printf("%d \t\t %d\n", i, dist[i]);
//}
//
//// Function that implements Dijkstra's single source shortest path algorithm
//// for a graph represented using adjacency matrix representation
//void dijkstra(int graph[V][V], int src)
//{
//    int dist[V]; // The output array.  dist[i] will hold the shortest
//    // distance from src to i
//
//    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
//    // path tree or shortest distance from src to i is finalized
//
//    // Initialize all distances as INFINITE and stpSet[] as false
//    for (int i = 0; i < V; i++)
//        dist[i] = INT_MAX, sptSet[i] = false;
//
//    // Distance of source vertex from itself is always 0
//    dist[src] = 0;
//
//    // Find shortest path for all vertices
//    for (int count = 0; count < V - 1; count++) {
//        // Pick the minimum distance vertex from the set of vertices not
//        // yet processed. u is always equal to src in the INITIAL iteration.
//        int u = minDistance(dist, sptSet);
//
//        // Mark the picked vertex as processed
//        sptSet[u] = true;
//
//        // Update dist value of the adjacent vertices of the picked vertex.
//        for (int v = 0; v < V; v++)
//
//            // Update dist[v] only if is not in sptSet, there is an edge from
//            // u to v, and total weight of path from src to  v through u is
//            // smaller than current value of dist[v]
//            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
//                && dist[u] + graph[u][v] < dist[v])
//                dist[v] = dist[u] + graph[u][v];
//    }
//
//    // print the constructed distance array
//    printSolution(dist);
//}
//
// driver progrNODEHERE to test above function
//int main()
//{
//    /* Let us create the exNODEHEREple graph discussed above */
//    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
//
//    dijkstra(graph, 0);
//
//    return 0;
//}


int main() {
//initilization and starting
vector < vertex * > NODEHERE;
  while (true) {

      cout << endl;
      //chosing what one wants
       cout << "ENTER ADDEDGE." << endl; cout <<endl;cout << "ENTER REMOVEEDGE." << endl;cout <<endl; cout << "Enter PRINT." << endl; cout <<endl; cout << "ENTER REMOVEEDGE." << endl;cout <<endl; cout << "ENTER FIND." << endl; cout <<endl; cout << "ENTER QUIT." << endl;cout <<endl; cout << "ENTER ADDVERTEX." << endl; cout <<endl;

    char * input = new char[80];
      
    cin.getline(input, 80);
      
    if (strcmp(input, "PRINT") == 0) {
        


    print(NODEHERE);
        
    }
//      void addEdge(vector<node*>& graph, vector<edge*>& edgecont)
//     {
//        vector<node*>::const_iterator i;
//        vector<node*>::const_iterator j;
//        edge* newe = new edge();
//        cout << "ENTER THE INITIAL NODE" << endl;
//        char* INITIALnode = new char[80];
//        cin.getline(INITIALnode, 80);
//        bool flag = false;
//        for (i=graph.begin(); i!=graph.end(); ++i){
//          if(strcmp((*i) -> getPLACEDNODEHERE(), INITIALnode) == 0) {
//            newe -> INITIALp = (*i);
//            flag = true;
//            break;
//          }
//        }
//        if (flag == false){
//          cout << "The node you entered does not exist" << endl;
//          return;
//        }
//
//        cout << "Please enter the SECONDNEXT node" << endl;
//        char* SECONDNEXTnode = new char[80];
//        cin.getline(SECONDNEXTnode, 80);//gets the SECONDNEXT node PLACEDNODEHERE
//        flag = false;
//        for (j=graph.begin(); j!=graph.end(); ++j){
//          if(strcmp((*j) -> getPLACEDNODEHERE(), SECONDNEXTnode) == 0) {
//            newe -> SECONDNEXTp = (*j);//records SECONDNEXT node
//            (*i)-> vectPush(*j); //Add as a connection
//            flag = true;
//          }
//        }
//        if (flag == false){ //if node was not found
//          cout << "The node you entered does not exist" << endl;
//          return;
//        }
//
//        cout << "Please enter the weight" << endl; //takes edge weight
//        char* weightval = new char[80];
//        cin.getline(weightval, 80);
//        newe -> weight = weightval; //puts into the edge
//        edgecont.push_back(newe); //puts edge into vector
//      }
      //IF THEY WANT TO REMOVE AN EDGE
          else if (strcmp(input, "REMOVEEDGE") == 0) {

          char * INITAL = new char(); //INITILIZES
              
          char * SECONDNEXTNEXT = new char(); //INITILIZES
              
          cout << "INPUT INITIAL VERTEX:" << endl; //ASKS FOR THE INITIAL VERTEX
              cout << endl;
              
          cin.getline(INITAL, 20);
              
          cout << "INPUT THE SECONDNEXT VERTEXES NAME:" << endl; //INPUT THE SECOND VERTEX
              
              
          cin.getline(SECONDNEXTNEXT, 20);
              
          removeEdge(NODEHERE, INITAL, SECONDNEXTNEXT); //RUN REMOVE EDGE
              
            }
      //IF THEY WANT TO ADD AN EDGE
      else if (strcmp(input, "ADDEDGE") == 0)
      {

        char * INITAL = new char(); //INITILIZES
          
        char * SECONDNEXTNEXT = new char(); //INITILIZES
                  
        cout << "ENTER THE INITIAL VERTEX:"; //ASKS FOR THE INITIAL VERTEX
          
          cin.getline(INITAL, 20);
          
        cout << "ENTER THE SECONDNEXT VERTEX:"; //ASKS FOR THE SECOND VERTEX

        cin.getline(SECONDNEXTNEXT, 20); //GET THE LINE INPUt

        cout << endl;
          
          
          addEdge(NODEHERE, INITAL, SECONDNEXTNEXT); //RUN THE ADD EDGE FUNCTION
      
      }
      //IF THEY WANT TO ADD A VERTEX
                  else if (strcmp(input, "ADDVERTEX") == 0)
                  {
                      
                  char * PLACEDNODEHERE = new char();
                      
                  cout << "INPUT THE NAME OF THE VERTEX:"; //ASKS FOR THE VERTEX NAME
                      
                  cin.getline(PLACEDNODEHERE, 20);
                      
                  vertex * RUNNING = new vertex();
                      
                  RUNNING -> PLACEDNODEHERE = PLACEDNODEHERE;
                      
                  NODEHERE.push_back(RUNNING); //PUSH THE VERTEX BACK USING RUNNING
                      
                }
        
                    //IF THEY WANT TO REMOVE A VERTEX
                      else if (strcmp(input, "REMOVEVERTEX") == 0)
                    
                    {
                      char * PLACEDNODEHERE = new char();
                        
                      cout << "VERTEX: "; //ASKS FOR THE VERTEX
                        
                      cout <<endl;
                        
                      cin.getline(PLACEDNODEHERE, 20);

                      removeVertex(NODEHERE, PLACEDNODEHERE); //REMOVES THE VERTEX FUNCTION
                    }
      
                        
                          else if (strcmp(input, "FIND") == 0) //FIND THE VERTEX SHORTEST PATH
                          {
                         
                          char * INITIAL = new char(); //INITILIZES
                               
                          char * SECONDNEXT = new char(); //INITILIZES
                               
                          cout << "STARTING VERTEX: " << endl; //INIITAL VERTEX

                          cin.getline(INITIAL, 20);
                              
                          cout << "INPUT THE SECONDNEXT VERTEX: " << endl; //SECOND VERTEX
                               
                          cin.getline(SECONDNEXT, 20);
                      
                          vertex * INITIALV = NULL; //INITILIZES
                              
                          vertex * SECONDNEXTV = NULL; //INITILIZES

                          for (vector < vertex * > ::iterator it = NODEHERE.begin(); it != NODEHERE.end(); ++it)
                          {
                              
                            if (strcmp(( * it) -> PLACEDNODEHERE, INITIAL) == 0)
                                
                            {
                                
                              INITIALV = * it;   //INITILIZES
                                
                            }
                            else if (strcmp(( * it) -> PLACEDNODEHERE, SECONDNEXT) == 0)
                                
                            {
                                
                              SECONDNEXTV = * it;  //INITILIZES
                                
                            }
                          }
                          if (INITIALV != NULL && SECONDNEXTV != NULL)
                              
                          {
                              
                            find(NODEHERE, INITIALV, SECONDNEXTV); //RUNS THE FIND FUNCTION
                              
                          }
                          else
                          {
                              
                            cout << "DOESN'T EXIST" << endl;
                              
                          }
                              
                              
                        }
      
      //IF THEY WANT TO QUIT:
      
                          else if(strcmp(input, "QUIT") == 0){
                           exit(0);
                        
                      }
                          else {
                          
                          cout << endl;
                              
                          cout << "NOT A VALIDATED INPUT." << endl;
                        }
                      }
                }


    void print(vector < vertex * > v)
{
//    void print(vector<node*> graph) {
//      vector<node*>::const_iterator i;
//      vector<node*>::const_iterator j;
//      vector<node*>::const_iterator k;
//      vector<node*>::const_iterator l;
//      cout << "  ";
//      for(i=graph.begin(); i!=graph.end(); ++i){
//        cout << (*i)->PLACEDNODEHERE() << " ";
//      }
//      cout << endl;
//      for(i=graph.begin(); i!=graph.end(); ++i){
//        cout << (*i)->PLACEDNODEHERE() << " ";
//        for(j=graph.begin(); j!=graph.end(); ++j){
//          vector<node*> connect = (*j) -> getVect();
//          bool flag = false;
//          for(k=connect.begin(); k!=connect.end(); ++k){
//        for(l=graph.begin(); l!= graph.end(); ++l) {
//          if((*l) == (*k) && (*i) == (*l)) {
//            cout << "T";
//            flag = true;
//          }
//        }
//          }
//          if(flag == false) {
//          }
//          cout << " ";
//        }
//        cout << endl;
//      }
//
//    }
//    CREDITS TO SETHU EAPEN FOR THE PRINT FUNCTION, HIS WAS BETTER!
    
      cout << " ";
    //PRINTS THE ROW
        for (vector < vertex * > ::iterator it = v.begin(); it != v.end(); ++it)
        {
            
        cout << "      " << ( * it) -> PLACEDNODEHERE;
            
      }
    //CHECKS FOR CONNECTIONS
      for (vector < vertex * > ::iterator it = v.begin(); it != v.end(); ++it)
      {
        cout << endl;
          
        cout << ( * it) -> PLACEDNODEHERE;
          
        vector < vertex * > connect = ( * it) -> edges;
          
        vector < int > length = ( * it) -> weight;
         //SEES IF IT CAN BE PRINTED
        for (vector < vertex * > ::iterator ite = v.begin(); ite != v.end(); ++ite)
        {
          int count = 0;
            
          bool found = false;
            
          if (connect.empty())
              
          {
            
            cout << "      " << "0";
          }
          else
              
          {
            for (vector < vertex * > ::iterator iter = connect.begin(); iter != connect.end(); ++iter)
            {
              count++;
              if (( * iter) -> PLACEDNODEHERE == ( * ite) -> PLACEDNODEHERE)
                  
              {

                cout << "      " << length.at(count-1);
                  
                found = true;
              }
            }
              //IF IT IS FOUND PRINT
            if (!found)
            {
              cout << "      " << "0";
            }
          }
        }
      }
      cout << endl;

    }
void addEdge(vector < vertex * > NODEHERE, char * INITIAL, char * SECONDNEXT)
{
    
  int weight;

  cout << "WEIGHT";
            
  cin >> weight;
      
  cin.get();
    
  vertex * INITIALV = NULL;
    
  vertex * SECONDNEXTV = NULL;
    //CHECKS IF THE VERTEXES EXIST

  for (vector < vertex * > ::iterator it = NODEHERE.begin(); it != NODEHERE.end(); ++it)
  {
      
    if (strcmp(( * it) -> PLACEDNODEHERE, INITIAL) == 0)
    {
        //INITIALIZE
      INITIALV = * it;
        
    }
      else if (strcmp(( * it) -> PLACEDNODEHERE, SECONDNEXT) == 0)
      {
          //INITILIE
      SECONDNEXTV = * it;
    }
      
  }
    
    //IF IT DOESN'T EQUAL NULL
  if (INITIALV != NULL && SECONDNEXTV != NULL)
      
  {
      //PUSH SECOND
    INITIALV -> edges.push_back(SECONDNEXTV);
      //PUSH WEIGHT
    INITIALV -> weight.push_back(weight);
      
  }
    
}
//METHOD TO REMOVE THE VERTEX
void removeVertex(vector < vertex * > & NODEHERE, char * PLACEDNODEHERE)
{
      vertex * temp = NULL;

      for (vector < vertex * > ::iterator it = NODEHERE.begin(); it != NODEHERE.end(); ++it)
          {
            if (strcmp(( * it) -> PLACEDNODEHERE, PLACEDNODEHERE) == 0)
                {
                  cout << "vertex found";
                    
                  temp = * it;
                    
                  NODEHERE.erase(it);
                    
                  break;
                }
          
        }
    //RUNS THE FOR LOOP ACROSS THE "NODES" UNTIL THE END
        for (vector < vertex * > ::iterator it = NODEHERE.begin(); it != NODEHERE.end(); ++it)
            {
              vector < vertex * > vEdges = ( * it) -> edges;
                
              vector < int > vWeight = ( * it) -> weight;
                
              int count = 0;
                
              cout << (*it)->PLACEDNODEHERE << ", ";
            
                //RUNS THROUGH THE EDGES
          for (vector < vertex * > ::iterator it2 = vEdges.begin(); it2 != vEdges.end(); ++it2)
          {
                count++;
                  
                cout << (*it2)->PLACEDNODEHERE;
                  
                    if (( * it2) == temp)
                    {
                        
                      vEdges.erase(it2);
                        
                      vWeight.erase(vWeight.begin() + (count - 1));
                        
                      ( * it) -> edges = vEdges;
                        
                      ( * it) -> weight = vWeight;
                        
                      break;
                    }
                      
                  }
            
        }

}

//OLD CODE NOT GOOD!

//vector<node*> delEdge(vector<node*>& graph, vector<edge*>& edgecont) {
//vector<edge*>::const_iterator X;
//vector<node*>::const_iterator Y;
//vector<node*>::const_iterator Z;
//cout << "INPUT THE NODE YOU WANT" << endl;
//cin.getline(firstnode, 80);
// cout << "ENTER THE NODE" << endl;
//char* secondnode = new char[80];
//cin.getline(secondnode, 80);
//for(X=edgecont.begin(); X!=edgecont.end(); ++X) {
//  if((*k) -> firstp -> getName() != NULL) {
//    if(strcmp((*k) -> firstp -> getName(), firstnode) == 0 || strcmp((*k) -> secondp -> getName(), secondnode) == 0) {
//  edgecont.erase(k);
//  break;
//    }
//  }
//}
//cout<< "I" << endl;
//for(i=graph.begin(); i!=graph.end(); ++i) {
//  if(strcmp((*Z) -> getName(), firstnode) == 0) {
//    vector<node*> connect = (*i) -> getVect();
//    cout << "a" << endl;
//  for(j=connect.begin(); j!=connect.end(); ++j) {
//    cout << (*Z) -> getName();
//    if((*j) != NULL && strcmp((*j) -> getName(), secondnode) == 0) {
//      connect.erase(Z);
//    }
//  }
//  }
//}
//return V;
//REMOVES THE EDGE
void removeEdge(vector < vertex * > &NODEHERE, char * INITIAL, char * SECONDNEXT) {
//MAKE SURE IT EXISTS
    vertex * INITIALV = NULL;
    
    vertex * SECONDNEXTV = NULL;
    for (vector < vertex * > ::iterator it = NODEHERE.begin(); it != NODEHERE.end(); ++it)
    {
      if (strcmp(( * it) -> PLACEDNODEHERE, INITIAL) == 0)
      {
        INITIALV = * it;
      }
      else if (strcmp(( * it) -> PLACEDNODEHERE, SECONDNEXT) == 0)
      {
        SECONDNEXTV = * it;
      }
    }
//GO THROUGH THE EDGES AND DELETE EDGE AND THE WEIGHTS THROUGH
    vector < vertex * > fEdges = INITIALV -> edges;
    
    vector < int > fWeights = INITIALV -> weight;
    
    int count = 0;
    
    for (vector < vertex * > ::iterator it = fEdges.begin(); it != fEdges.end(); ++it)
    {
      count++;
      if (( * it) == SECONDNEXTV)
      {
          //ERASE IT
          
        fEdges.erase(it);
          
        fWeights.erase(fWeights.begin() + (count - 1));
          
        INITIALV -> edges = fEdges;
          
        INITIALV -> weight = fWeights;
          
          //IT IS FINISHED BREAK/RETURN
        
          //return;
        break;
      }
    }

  }
    bool contains(vector < vertex * > NODEHERE, vertex * ver)
    {
      if (std::find(NODEHERE.begin(), NODEHERE.end(), ver) != NODEHERE.end())
      {
        return true;
      }
      return false;
    }

//FIND METHOD USING THE ALGORITHUM:
//- MAKES SURE TO STORE the path
//- STORES THE TEMP PATH
//- SETS SHORTEST PATH
//- FINDS THE LENGTHS
void find(vector < vertex * > NODEHERE, vertex * start, vertex * end) {

//INITILIZE
  vector < vector < vertex * >> paths;
    
  vector < vertex * > UPDATEPATH;
    
  vector < vertex * > sptSet;
    
  vector < int > length;
    
  vector < vertex * > con;
    
  vector < vertex * > c;
    
  c.push_back(start);
    
  paths.push_back(c);
    
  sptSet.push_back(start);
    
  length.push_back(0);
    //INITILIZE
    int INITIALONE2;
      
    int LOWESTNODE;
      
    bool STILLGOING = true;
    STILLGOING = false;
      
    bool found;
    
    //INITILIZE

  vertex * current;
    
  vertex * next;
    
  vertex * previous;
    
    //INITILIZE

  int currentLength;
    
  int INITIALONE;
    
//RUNS A WHILE LOOP
    
    //DOES IT EXIST
    while (!STILLGOING)
    {
    found = false;
        
    STILLGOING = true;
        
    INITIALONE = 0;
        
    LOWESTNODE = std::numeric_limits < int > ::max();
        
        //RUNS THROUGH AND CHANGES THE CURRENT LENGTH
        
    for (vector < vertex * > ::iterator it = sptSet.begin(); it != sptSet.end(); ++it)
    {
      INITIALONE++;
        
      current = ( * it);
        
      currentLength = length.at(INITIALONE - 1);
        
      con = current -> edges;
        
      INITIALONE2 = 0;
        
        //IF THERE IS ANY MORE VERTEXES GO THROUGH AND CHECK
      if (!con.empty())
      {
          
        STILLGOING = false;
          
        for (vector < vertex * > ::iterator it2 = con.begin(); it2 != con.end(); ++it2)
        {
          INITIALONE2++;
            
          if (!contains(sptSet, ( * it2)))
          {

              if ((currentLength + current -> weight.at(INITIALONE2 - 1)) < LOWESTNODE)
              {
                  
              LOWESTNODE = currentLength + current -> weight.at(INITIALONE2 - 1);
                  
              next = ( * it2);
                  
              previous = current;
                  //IT HAS BEEN FOUND
              found = true;
            }
          }
        }
      }
    }
    if (STILLGOING || !found)
    {
        //THERE HAS BEEN NO PATH FOUND!
      cout << "NO PATH." << endl;
        
      return;
    }
        
        
    for (vector < vector < vertex * >> ::iterator it = paths.begin(); it != paths.end(); ++it) {

      c = ( * it);
        //IF EQUALS PREVIOUS
      if (c.back() == previous)
      {
          //UPDATE THE PATH
          
        UPDATEPATH = ( * it);
          
        UPDATEPATH.push_back(next);
          
        paths.push_back(UPDATEPATH);
          
        length.push_back(LOWESTNODE);
          
        sptSet.push_back(next);
          
        break;
      }
    }
    for(vector<vertex*>::iterator it = UPDATEPATH.begin(); it!=UPDATEPATH.end(); ++it)
    {

    bool exist = false;
        
    for(vector<vertex*>::iterator it1 = NODEHERE.begin(); it1!=NODEHERE.end(); ++it1)
    {
        if(strcmp((*it)->PLACEDNODEHERE, (*it1)->PLACEDNODEHERE)==0)
        {
                exist = true;
            
                break;
        }
    }
    if(!exist)
    {
        cout << "NO PATH" << endl;
        return;
    }
    
    }
    if //PRINT OUT THE ROUTE AND THE LENGTH
        (next == end)
    {
      cout << "THE SHORTEST PATH IS: ";//SHOWS THE SHORTEST PATH
        
    vector < vertex * > ::iterator it = UPDATEPATH.begin();
        
     while( it != UPDATEPATH.end())
      {
        cout << ( * it) -> PLACEDNODEHERE << "  ";
        ++it;
      }
     
      cout << "THE TOTAL WEIGHT:" << LOWESTNODE << endl; //PRINTS THE TOTAL WEIGHT
        
      return;
        
    }
  }
}

