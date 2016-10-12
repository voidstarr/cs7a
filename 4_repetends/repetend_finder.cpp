
//Code to search for a repetend in the decimal form of a rational number .
//precondition : a quotient and a divisor , both positive integers .
// postcondition : an array containing the sequence of decimal digits in
// the quotient , the length of the repetend and a sequence of repetend digits .
/*
Enter the dividend and divisor of the rational number whose repetend we seek :
1 17
Here are the digits of the quotient computed :
005882352941176470588235294117647058823529411764705882
352941176470588235294117647058823529411764705882352941
1764705882352941176470588235294117647058823529
4117647058823529411764705882352941176470588235
The repetend is of length 16
The digits of the repetend are
4117647058823529 
*/

// research: http://mathforum.org/library/drmath/view/67018.html
//           http://pari.math.u-bordeaux.fr/
//           http://seanelvidge.com/2011/12/recurring-decimals-something-on-the-repetend/
//           http://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/

#define QUOTIENT_LENGTH 20000
#define MAX_REPETEND_LENGTH 20000

#include <iostream>
#include <vector>

using namespace std;

void printQuotient(int);

vector<short> decimalDigs;

int main () {
    uint64_t dividend, divisor, quotient, remainder;
    cout << "\nEnter the dividend and divisor of the rational number "
         << " whose repetend we seek :\n";
    
    cin >> dividend >> divisor;
    
    for (uint64_t i = 0; i < QUOTIENT_LENGTH; i++) {
        //decimalDigs.push_back(dividend / divisor);
        remainder = dividend % divisor;
        dividend = 10 * remainder;
        decimalDigs.push_back(dividend / divisor);
    }
    
    cout << "\nHere are the digits of the quotient computed : ";
    printQuotient(QUOTIENT_LENGTH);
    // Write code to detect the repetend and its length here
/*    
    uint64_t n = 1;

    while (n < MAX_REPETEND_LENGTH) {
        uint64_t i = 0;
        while (decimalDigs[i] == decimalDigs[i + n]) {
            i++;
            if (i > MAX_REPETEND_LENGTH) {
                cout << "Found repetend." << endl;
                printQuotient(n);
                return 0;
            }
        }
        n++;
    }

    cout << "No repetend found." << endl;
*/


    // I find this for-loop solution the most elegant 
    for (int n = 1; n < MAX_REPETEND_LENGTH; n++) {
        for (int i = 0; decimalDigs[i] == decimalDigs[i + n]; i++) {
            if (i > MAX_REPETEND_LENGTH) {
                cout << "Found repetend." << endl;
                printQuotient(n);
                return 0;
            }
        }
    }

    cout << "No repetend found." << endl;
   
    return 0;
}

void printQuotient(int digits) {
    for (uint64_t i = 0; i < digits; i++)
        cout << decimalDigs[i];
    cout << endl;
}
