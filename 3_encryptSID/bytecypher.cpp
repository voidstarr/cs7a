/// G. Hagopian - A program to encrypt student number

#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>

using namespace std;

string numberToString(uint64_t);
uint64_t random64bit();
/// Write a function that takes a string (perhaps an encoded student number)
/// and converts it back to the student number.  Remember to take the square root first.

int main() {
    srand(time(0));
    uint64_t id;
    id = 508026;
    id *= id;
    string idstr = numberToString(id);
    //string idstr;
    cout << "\nHere's a string from the random number\n" << id << ": " << idstr << endl;
    /// Enter code here to compute the square of you student number .
}



string numberToString(uint64_t x) {
    string idstr;
    while(x) {
        idstr = char(65+x%26)+idstr;
        x /= 26;
    }
    return idstr;
}

uint64_t random64bit() {
    uint64_t randNum = rand(); // two byte random number
    for(int i = 0; i < 3; ++i) {
        randNum = (randNum << 16) + rand();
        cout << endl << bitset<64>(randNum);
    }
    return randNum;
}
