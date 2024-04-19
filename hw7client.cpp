// CS311 YOSHII F23 hw7client.cpp

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Kayla Le
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph  and stack
#include "dgraph.h"
#include "stack.h"
#include <iostream>
#include <fstream>
#include <string>

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments. 
  dgraph D;//dgraph object
  stack S;  //stack object 
  int currentVisitNum = 1;//visit number used to store into a vertex
  char removedChar; //holder for removed char from stack
  char removedAdj;//holder for removed char from adjecent slist object
  slist adjOnes; //slist object

  D.fillTable(); //filling table

  D.displayGraph();//displaying table

  S.push('A'); //push A onto stack to start
  
  while(!S.isEmpty()){//while stack is not empty
    
      S.pop(removedChar);//remove a vertex from the stack

      cout << "Removed " << removedChar << " from stack\n";//display vertex name
   
        if(!D.isMarked(removedChar)){//if vertex is not marked 

           D.visit(currentVisitNum,removedChar);//marking vertex
    
           cout << "Visit " << removedChar << " as " << currentVisitNum << endl; //informing user
     
           adjOnes = D.findAdjacency(removedChar);//get adjacency list of vertex
   
      	          if(adjOnes.isEmpty())//if adjacency list is empty - inform user
        		 cout << "Deadend reached - backup\n";
       		else{
       		 cout << "...pushing ";
        	 adjOnes.displayAll();//displaying adjacency list
         
		//pushing  adjcent verticies of current vertex  onto stack 
 		   for(int i = 0; i < D.findOutDegree(removedChar);i++){//loop through adjaceny list
        	      adjOnes.deleteRear(removedAdj);//deleting from rear and storing removed char into removedAdj
           	       S.push(removedAdj);  //pushing removed adjcent vertex into stoack

                 }
         
               }
       currentVisitNum++; //updating visit number
       }
     else//inform user that a vertex has already been visited 
       cout << removedChar << " has been visited already - backup\n";
     
     S.displayAll();//displaying stack
   }
  D.displayGraph(); //displaying graph with visit numbers for all vertices
}
