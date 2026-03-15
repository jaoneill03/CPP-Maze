// Implementation of Maze class
// By Joshua O'Neill

#include "Maze.h"
#include "DisjointSet.h"
#include <cstdlib>
#include <ctime>
using namespace std;



Maze::Maze(int rows, int cols)
{
    numRows = rows;
    numColumns = cols;
    int numCells = rows * cols;
    mazeWalls = new CellWalls[numCells];
    mazeWalls[numCells - 1].east = false;
}


Maze &Maze::operator=(const Maze &rhs)
{
    if (this != &rhs)
    {
        delete [] mazeWalls;
        this->copy(rhs);
    }
    return *this;
}




void Maze::generateMaze()
{
   int numCells = numRows * numColumns;
    DisjointSet mySet(numCells);
    bool mazeComplete = false;
    //cout << numCells <<endl;



     while(!mazeComplete){
        int cell = rand() % numCells;//random cell
        int direction = rand() % 4;// random direction
        int neighbor = chooseNeighbor(cell, direction);//finds neighboring cell


        //checks if neighbor is within the maze walls and not already in same set as cell
        if(neighbor >= 0 && neighbor <  numCells && mySet.find(cell) != mySet.find(neighbor)){

            if(neighbor == cell -1){
                mazeWalls[neighbor].east = false; // left
            }else if(neighbor == cell + 1){
                mazeWalls[cell].east = false; // right
            }else if(neighbor == cell - numColumns){
                mazeWalls[neighbor].south = false; // up
            }else if(neighbor == cell + numColumns){
                mazeWalls[cell].south = false; // down
            }

            mazeComplete = mySet.doUnion(cell, neighbor);

        }

    }
    
}

int Maze :: chooseNeighbor(int cell, int& direction){

   

    switch (direction) {
    case 0: // left
        if (cell % numColumns == 0)
            direction = 2; 
        break;
    case 1: // down
        if (cell >= numColumns * (numRows - 1))
            direction = 3; 
        break;
    case 2: // right
        if ((cell + 1) % numColumns == 0)
            direction = 0; 
        break;
    case 3: // up
        if (cell < numColumns)
            direction = 1; 
        break;
}

int neighbor = cell;
if (direction == 0)
    neighbor = cell - 1; // left
else if (direction == 1)
    neighbor = cell + numColumns; // down
else if (direction == 2)
    neighbor = cell + 1; // right
else if (direction == 3)
    neighbor = cell - numColumns; // up

return neighbor;








}

void Maze::print(ostream &outputStream)
{
    // print the top row of walls
    for (int i = 0; i < numColumns; i++)
        outputStream << " _";
    outputStream << '\n';
    for (int i = 0; i < numRows; i++)
    {
        int cellbase = i * numColumns;
        // print west wall (except at entrance)
        if (i == 0)
            outputStream << ' ';
        else
            outputStream << '|';
        for (int j = 0; j < numColumns; j++)
        {
            if (mazeWalls[cellbase + j].south)
                outputStream << '_';
            else
                outputStream << ' ';
            if (mazeWalls[cellbase + j].east)
                outputStream << '|';
            else
                outputStream << ' ';
        }
        outputStream << '\n';
    }
}

void Maze::copy(const Maze &orig)
{
    this->numRows = orig.numRows;
    this->numColumns = orig.numColumns;
    int numCells = numRows * numColumns;
    mazeWalls = new CellWalls[numCells];
    for (int i = 0; i < numCells; i++)
    {
        this->mazeWalls[i] = orig.mazeWalls[i];
    }
}



