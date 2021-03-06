/*
 * Patrick Jacobs
 * Assignment 5 - 14-15 game 
 * (able to be any size square)
 * pass Board an integer at time of instantiation
 * (second line of main() ) to adjust side length
 * */

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Board {
    public:
    	bool forfeited = false;
        int holeAt = 0;
        int size = 4; // The dimension of the square board
    	int sqrSize = size*size;
        vector<int> tiles; 
        vector<int> winState;
        vector<char> moves;

        void getMove();
        void moveHole(int holeShift, bool horizShift, char move);
        void shuffle();
        void display();
        void setForfeited(bool f);
        bool hasForfeited();
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


    if (b.hasForfeited()){
        cout << "You forfeit. ";
    } else {
        cout << "You win. ";
    }

    double duration = difftime(time(0), startTime);

    cout << endl << "Game time: " << duration << " seconds." << endl;
    
    int movesTaken = b.moves.size();
    
    cout << "Moves taken: " << movesTaken << endl;
    for (int i = 0; i < movesTaken; i++) {
        cout <<  b.moves[i];
        if (i < movesTaken - 1)
            cout << ",";
    }
    cout << endl;

}

Board::Board(int s) : size(s) {
    // DONE: Initialize board with blank tiles in the lower right corner:
    for (int i = 1; i <= sqrSize; i++){
        tiles.push_back(i);
        winState.push_back(i);
    }
    
}

bool Board::hasForfeited(){
    return forfeited;
}

void Board::setForfeited(bool f){
    forfeited = f;
}

void Board::moveHole(int holeShift, bool horizShift, char move) {
    if (horizShift) {
        int row = holeAt / size;
        if (holeShift >= size*row && holeShift < size*(row+1)) {
            tiles[holeAt] = tiles[holeShift];
            tiles[holeShift] = sqrSize;
            holeAt = holeShift;
            moves.push_back(move);
        }
    } else if (holeShift >= 0 && holeShift < sqrSize) {
        tiles[holeAt] = tiles[holeShift];
        tiles[holeShift] = sqrSize;
        holeAt = holeShift;
        moves.push_back(move);
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
            moveHole(holeAt - size, false, nMove);
            break;
        case 'd':
        case 'D':
            moveHole(holeAt + size, false, nMove);
            break;
        case 'l':
        case 'L':
            moveHole(holeAt - 1, true, nMove);
            break;
        case 'r':
        case 'R':
            moveHole(holeAt + 1, true, nMove);
            break;
        case 'f':
        case 'F':
            setForfeited(true);
            break;
    }
    cout << endl;
}

void Board::display() {
   int tsize = tiles.size();
   cout << "\t\t";
   for (int i = 0; i < tsize; i++) {
       if (tiles[i] == sqrSize) cout << "  ";
       else cout << tiles[i];
       
       if((i+1)%size==0) cout << endl << "\t\t";
       else if ((tiles[i]) < 10) cout << "  ";
       else if ((tiles[i]) >= 10) cout << " ";
       //else cout << " ";
   }
   cout << endl; 
}

void Board::shuffle() {
    int tsize = tiles.size();
    for (int i = 0; i < tsize; i++) {
        unsigned int j = (rand() % tsize) ;
        swap(tiles[i], tiles[j]);
        if(tiles[i] == sqrSize)
            holeAt = i;
        else if (tiles[j] == sqrSize)
            holeAt = j;
        //    cout << " itiles[" << i << "] = " << tiles[j] << " jtiles[" << j << "] = " << tiles[i] << endl;
    }
}

bool Board::won() {
    // DONE: write win condition
    return hasForfeited() ||  tiles == winState;
}
