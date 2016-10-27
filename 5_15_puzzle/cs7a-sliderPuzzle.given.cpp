#include <iostream>
#include <vector>

// Prototype descriptions (enter a prototype that fits.) 

// display() shows it on the console.  For example, if 
// board = {1, 2, 3, 4, 5, 16, 7, 8, 9, 10, 11, 12, 13, 14, 15, 6}
// then display shows
//  1  2  3  4  
//  5     7  8
//  9 10 11 12
// 13 14 15  6 

//shuffle() Use the \href{http://en.wikipedia.org/wiki/Fisher–Yates_shuffle}{Fisher-Yates} algorithm to shuffle.
//After shuffling the board, a call to the function display will produce a 
//shuffled board like this:
/* 14  5  4 11
   12  9  6  7
      13  8 10
   15  1  3  2 */

// 
//  1  2  3  4  
//  5  6  7  8
//  9 10 11 12
// 13 14 15   

class Board {
    public:
    	int size = 4; // The dimension of the square board
    	vector<int> tiles;
		void getMove(tiles);  // prompts the use to enter u, d, l, r 
							  // (or some other scheme)  	
    	void shuffle(tiles);
		void display(tiles);
		bool won(); //returns true if the game board is as below, otherwise false
		Board(); //	constructor
	};	
int main() 
{
// Initialize board with blank tiles in the lower right corner:
    // create a Board, b
    //game loop
	while(!b.won())
	{	
		// construct a board with size*size tiles
		getMove(board, size); // function calls – size is const int,
		display(board, size); // board is the address in memory of the
	}                          // first element of the array, board[]
}

//define display()

//define shuffle()

// define won()

// define getMove()
