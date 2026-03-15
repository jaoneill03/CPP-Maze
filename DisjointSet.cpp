// DisjointSet implementation using union by size and path compression
// By Mary Elaine Califf and Joshua O'Neill

#include "DisjointSet.h"
#include <iostream>

DisjointSet::DisjointSet(int numObjects)
{
    //to do
    numValues = numObjects;
    theArray.resize(numValues,-1);
}

//recursive method to find the item -- does path compression on the way out of the recursion
int DisjointSet::find(int objectIndex)
{  
    // to do -- see assignment instructions for details
    if(theArray[objectIndex] < 0){
        return objectIndex;
    }else{
        return theArray[objectIndex] = find(theArray[objectIndex]);
    }
}

bool DisjointSet::doUnion(int objIndex1, int objIndex2)
{
    // to do -- see assignment instructions for details
    int root1 = find(objIndex1);
    int root2 = find(objIndex2);
    int temp;


    if(root1 == root2){
        return false;
    }
    
    if(theArray[root1] <= theArray[root2]){
        theArray[root1] += theArray[root2];
        theArray[root2] = root1; 
        temp = root1;
    }else{
        theArray[root2] += theArray[root1];
        theArray[root1] = root2; 
        temp = root2;
    }

    if(theArray[temp] == -numValues){
        return true;
    }

    return false;



}

void DisjointSet::printArrayValues(std::ostream &outputStream)
{
    for (int i = 0; i < numValues; i++)
    {
        outputStream << theArray[i] << " ";
    }
    outputStream << std::endl;
}
