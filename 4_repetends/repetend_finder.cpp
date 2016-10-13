
// Code to search for a repetend in the decimal form of a rational number .
// precondition : a quotient and a divisor , both positive integers .
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

#include <iostream>
#include <vector>

using namespace std;

uint64_t dividend, divisor, remainder;
vector<short> decimalDigs;

void printQuotient(int);

bool findRepetend();

void calculateQuotient();

int main() {
  cout << "\nEnter the dividend and divisor of the rational number "
       << " whose repetend we seek :\n";

  cin >> dividend >> divisor;

  calculateQuotient();
  cout << "\nHere are the digits of the quotient computed : ";
  printQuotient(-1);
  findRepetend();
  return 0;
}

void printQuotient(int digits) {
  if (digits < 0)
    digits = decimalDigs.size();
  for (uint64_t i = 0; i < decimalDigs.size(); i++)
    cout << decimalDigs[i];
  cout << endl;
}

void calculateQuotient() {
  // let's skip all those unneeded values before the repetend
  short skip = 0;
  int div = divisor;
  while ((div /= 10) > 10) {
    // cout << "div: " << div << endl;
    skip++;
  }
  // cout << "skip: " << skip << endl;
  // build our vector of quotient digits
  for (uint64_t i = 0; i < divisor * 4; i++) {
    remainder = dividend % divisor;
    dividend = 10 * remainder;
    if (skip <= 0) {
      decimalDigs.push_back(dividend / divisor);
    } else {
      skip--;
    }
  }
}

bool findRepetend() {
  // I find this for-loop solution the most elegant
  // do a little dance
  for (int n = 1; n < divisor; n++) {
    // make a little love
    for (int i = 0; decimalDigs[i] == decimalDigs[i + n]; i++) {
      // cout << "d[" << i << "]("<<decimalDigs[i]<<") == d[" << i << " + " << n
      // << "](" << decimalDigs[i+n] << ")" << endl;
      if (i > divisor * 2) {
        // get down tonight
        cout << "Found repetend." << endl;
        printQuotient(n);
        return true;
      }
    }
  }
  cout << "No repetend found." << endl;
  return false;
}
