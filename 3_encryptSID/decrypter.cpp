/*
    Patrick Jacobs
    Assignment 3 - student id encrypter
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

uint64_t stringToNumber(string);

int main () {
    string crypted_id = "YOURIDHERE";
    uint64_t id = stringToNumber(crypted_id);

    cout << "Here's that cheeseburger you ordered: crypted_id("
         << crypted_id << ") : id(" << id << ")" << endl;
}

uint64_t stringToNumber(string str) {
    uint64_t id = 0;
    int j = 0;
    for (int i = str.size()-1; i >= 0; i--, j++) {
        id += uint64_t(pow(26,j)) * (uint64_t(str[i]) - 65);
        //cout << i << " " <<str[i] << " : " << str[i] - 65 << " pow: " << pow(26,j) << endl;
    }
    //cout << id << endl;
    return uint64_t(sqrt(id));
}
