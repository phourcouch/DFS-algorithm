//CS311 Yoshii F23 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW7 dgraph
// Name: Kayla Le
// File Type: dgraph impleatnion file dgraph.cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

//PURPOSE: initizlizes the table entries and countUsed to 0
//no paramters 
dgraph::dgraph(){
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
// - need a loop
for(int i =0; i< SIZE;i++){//loop until max size
 Gtable[i].vertexName = ' ';//initalizing vertexname to blank
 Gtable[i].visit = 0;//initalizing vertex visit number to 0
}
 // initialize countUsed to be 0
 countUsed = 0;
}

//PURPSOE: delete all nodes of slist in table
//no paramerters 
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

//PURPOSE: reads a specified input file to fill the table
//no parameters
void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
  string fname;//file name
  cout << "Enter a file name: ";
  cin >> fname;//get user's input
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
  char x;//holder for adjacent vertexs

  // the rest is in HW6-help
 while(fin >> Gtable[countUsed].vertexName){//loop while  there is a name to read
     fin >> Gtable[countUsed].outDegree;//get outdegree of vertex
     
    for(int i = 0;i<Gtable[countUsed].outDegree;i++){//loop number of outdegress
        fin >> x;//get adjecent vertex
        Gtable[countUsed].adjacentOnes.addRear(x);//add vertex to rear of slist
     }
    countUsed++;//update countUsed - number of vertex in table
   }

}


//PURPOSE: display table content in a table format - displaying total # of edges
//no paramenters
void dgraph::displayGraph() // be sure to display
// you will have to use a linked list function displayAll. 
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top (you have to sum it up)
    int TotalEdges = 0;//holder for total of edges
 
  for(int i  = 0; i < countUsed; i++)//loop for amount of vertex in graph
  {
    TotalEdges += Gtable[i].outDegree;//add the current vertex out degree to total edges
  } 

  cout << "\nThe number of edges is: " << TotalEdges << endl;//print out total  edges 

  cout << "Name Out Visit   Adj \n--------------------------\n";
  
  for(int i = 0; i < countUsed;i++){//loop through graph
//printing out the Name, outDegree, and visit number of vertex
   cout << Gtable[i].vertexName << "    " << Gtable[i].outDegree
   << "\t " <<  Gtable[i].visit << "\t ";
    Gtable[i].adjacentOnes.displayAll();//priting out adjacent vertexs (slist)
  cout  << endl;
  } 
} 


//PURPOSE: convert given vertex to a slot number
//PARA: a vertex given from client
int dgraph:: convertChartoInt(char V){ return (V - 'A');}//formula for slot number

//PURPOSE: return the out degree of given vertex 
//PARE: given vertex from client
int dgraph::findOutDegree(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
 
 int charIndex = convertChartoInt(V);//convert char to slot number 
 
 if(charIndex > (countUsed-1) || charIndex < 0)//if charIndex is not  the range of 0-(countUsed-1) then  throw an exception
    throw BadVertex();
 else{
    return Gtable[charIndex].outDegree;//returing outdegree of given char
  }
}


//PURPOSE: return the linked list of adjacent vertices of the given vertex 
//PARA: a char given from client 

slist dgraph::findAdjacency(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
  
 int charIndex = convertChartoInt(V);//formula -- make a fucntion

 if(charIndex >(countUsed-1) || charIndex < 0)//if charIndex isnt  in the range of 0-(countUsed-1) throw an exceptiom
    throw BadVertex();
 else{
    return Gtable[charIndex].adjacentOnes;//returing slist of adjacent vertexs  of given char
  }
 
   
}

//PURPOSE: store given number into given vertex
//PARAMETE: a number and char given from client
void dgraph::visit(int num, char V){
   
  int charIndex = convertChartoInt(V);//get slot of given char

  Gtable[charIndex].visit = num;//stored given visit number into the given char

} 
//PURPOSE: return true if a given vertx was already visited 
//PARAMETER: given char from client 
bool dgraph::isMarked(char V){

   int charIndex = convertChartoInt(V);//get slot of given char
 
  if(Gtable[charIndex].visit != 0)//if char has  been visited return true otherwise return  false
  return true;
 else 
  return false;
}
