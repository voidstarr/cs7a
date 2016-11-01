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
    	bool forfeit = false;
        int holeAt = 0;
        int size = 4; // The dimension of the square board
    	int sqrSize = size*size;
        vector<int> tiles; 
        vector<int> winState;
		
        void getMove();
        void moveHole(int holeShift, bool horizShift);
        void shuffle();
        void display();
		bool won(); //returns true if the game board is as below, otherwise false
        Board(int s=4); //	constructor
};

int main() {
    srand(time(0));
    Board b;
    
    b.shuffle();
    b.display();
	
    time_t startTime = time(0);

    while(!b.won()) {	
		b.getMove();
        b.display(); 
    }


    if (b.forfeit){
        cout << "You forfeit. ";
    } else {
        cout << "You win. ";
    }

    double duration = difftime(time(0), startTime);

    cout << endl << "Game time: " << duration << " seconds." << endl;

}

Board::Board(int s) : size(s) {
    // DONE: Initialize board with blank tiles in the lower right corner:
    for (int i = 1; i <= sqrSize; i++){
        tiles.push_back(i);
        winState.push_back(i);
    }
    
}

void Board::moveHole(int holeShift, bool horizShift) {
    if (horizShift) {
        int row = holeAt / size;
        if (holeShift >= size*row && holeShift < size*(row+1)) {
            tiles[holeAt] = tiles[holeShift];
            tiles[holeShift] = sqrSize;
            holeAt = holeShift;
        }
    } else if (holeShift >= 0 && holeShift < sqrSize) {
        tiles[holeAt] = tiles[holeShift];
        tiles[holeShift] = sqrSize;
        holeAt = holeShift;
    }
}

void Board::getMove() {
    // DONE: prompts the use to enter u, d, l, r or some other scheme
    // DONE: find some way to do this cleaner?
    // this mess could be quite a bit prettier if we used a 2d array
    // instead of vector<int>
    cout << "Enter u(up), d(down), l(left), r(right) or f(forfeit)" << endl 
         << ">> ";
    char nMove;
    cin >> nMove;
    switch (nMove) {
        case 'u':
        case 'U':
            moveHole(holeAt - size, false);
            break;
        case 'd':
        case 'D':
            moveHole(holeAt + size, false);
            break;
        case 'l':
        case 'L':
            moveHole(holeAt - 1, true);
            break;
        case 'r':
        case 'R':
            moveHole(holeAt + 1, true);
            break;
        case 'f':
        case 'F':
            forfeit = true;
            break;
    }
    cout << endl;
}

void Board::display() {
    //TODO: pretty display() function
   /*cout << "-----------------" << endl 
        << "|  ";*/
   int tsize = tiles.size();
   for (int i = 0; i < tsize; i++) {
       if (tiles[i] == sqrSize) cout << "  ";
       else cout << tiles[i];
       
       if((i+1)%size==0) cout << endl;
       else if ((tiles[i]) < 10) cout << "  ";
       else if ((tiles[i]) >= 10) cout << " ";
       //else cout << " ";
   }
   cout << endl; 
}

void Board::shuffle() {
    int tsize = tiles.size();
    int tmp = 0;
    for (int i = 0; i < tsize; i++) {
       unsigned int j = (rand() % tsize) ;
       tmp = tiles[i];
       tiles[i] = tiles[j];
       tiles[j] = tmp;
//        cout << " itiles[" << i << "] = " << tiles[j] << " jtiles[" << j << "] = " << tiles[i] << endl;
    }
    for (int i = 0; i < tsize; i++) {
        if (tiles[i] == sqrSize) {
            holeAt = i;
            break;
        }
    }
}

bool Board::won() {
    // DONE: write win condition
    return forfeit ||  tiles == winState;
}
