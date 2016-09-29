/*
 * Patrick Jacobs - a program to encrypt and decrypt a student id number
 * */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

uint64_t stringToNumber(string);
string numberToString(uint64_t);
/// Write a function that takes a string (perhaps an encoded student number)
/// and converts it back to the student number.  Remember to take the square root first.

/// remember to change id

int main() {
    uint64_t id,id_from_string;
    id = -1; //put your id here
    if (id < 0) {
        cout << endl << "you forgot to change the id variable" << endl;
        return -1;
    }
    id *= id;
    string idstr = numberToString(id); 
    cout << endl << "Here's a string from the SID\n" << id << ": " << idstr << endl;
    /// Enter code here to compute the square of you student number .

    id_from_string = stringToNumber(idstr);

    cout << endl << "Here's an uint64_t from that string: " << endl << id_from_string << " : " << idstr << endl << ".... and it's square root : " << uint64_t(sqrt(id_from_string)) << endl;

}

uint64_t stringToNumber(string str) {
    uint64_t id = 0;
    int j = 0;
    for (int i = str.size()-1; i >= 0; i--, j++) {
        id += uint64_t(pow(26,j)) * (uint64_t(str[i]) - 65);
        //cout << i << " " <<str[i] << " : " << str[i] - 65 << " pow: " << pow(26,j) << endl;
    }
        //cout << id << endl;
    return id;
}

string numberToString(uint64_t x) {
    string idstr;
    while(x) {
        idstr = char(65+x%26)+idstr;
        //cout << "" << endl;
        x /= 26;
    }
    return idstr;
}
