#include <iostream>
#include <vector>
#include <random>
#include <ctime>
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

using namespace std;

class Board {
    public:
    	int size = 4; // The dimension of the square board
    	vector<int> tiles;
		
        void getMove();
        void shuffle();
        void display();
		bool won(); //returns true if the game board is as below, otherwise false
        Board(int s=4); //	constructor
};

int main() {
    srand(time(0));
    Board b;
    //game loop
	while(!b.won()) {	
		b.getMove();
        b.display(); 
    }
}

Board::Board(int s) : size(s) {
    // TODO: Initialize board with blank tiles in the lower right corner:
    int sqrSize = (size*size) - 1;
    for (int i = 0; i < sqrSize; i++)
        tiles.push_back(i+1);
}

void Board::getMove() {
    // TODO: prompts the use to enter u, d, l, r or some other scheme
}

void Board::display() {
   for (int i = 0; i < tiles.size(); i++) {
       if (tiles[i] == 16) cout << " ";
       else cout << tiles[i];

       if(i%size==0) cout << endl;
       else cout << " ";
   } 
}

void Board::shuffle() {
    int tsize = tiles.size();
    int tmp = 0;
    for (int i = tsize; i > 0; i--){
       int j = rand() % tsize;
       tmp = tiles[i];
       tiles[i] = tiles[j];
       tiles[j] = tmp;
    }
}

bool Board::won() {
    return false;
}
