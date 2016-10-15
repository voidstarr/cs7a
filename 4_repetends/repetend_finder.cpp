
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
//    "    : http://pari.math.u-bordeaux.fr/
//    "    : http://seanelvidge.com/2011/12/recurring-decimals-something-on-the-repetend/
//    "    : http://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/
//    "    : http://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printQuotient(int, vector<short>);

int findRepetend(int, vector<short>);

vector<short> calculateQuotient(int, int);

void intervalCase();

void potentialRepCase();

void enterWait();

int main() {
  int response = -1;
  do {
    cout << endl << endl
         << "==============================_______================================" << endl 
         << "||                   Choose an option:                             ||" << endl
         << "|| 1) Find largest repetend in a given interval: [1,n]             ||" << endl
         << "|| 2) Find the potential repetend for a given dividend and divisor ||" << endl
         << "|| 3) Quit                    _______                              ||" << endl
         << "==============================       ================================" << endl
         << ">> ";

    if (!(cin >> response)) {
      cin.clear(); //clear bad input flag
      response = -1;
    }

    switch (response) {
      case 1:
        intervalCase();
        break; 
      case 2:
        potentialRepCase();
        break;
      case 3:
        return 0;
        break;
      default:
        cout << "Invalid response." << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
        break;
        
    }
    enterWait();
  } while (response != 3);
  return 0;
}

void enterWait() {
  cin.ignore();
  cout << "Press the enter key to continue.";
  cin.ignore();
}

void printQuotient(int digits, vector<short> v) {
  if (digits < 0)
    digits = v.size();
  for (uint64_t i = 0; i < digits; i++)
    cout << v[i];
  cout << endl;
}

vector<short> calculateQuotient(int divisor, int dividend) {
  vector<short> quotient;
  int remainder = 0;
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
      quotient.push_back(dividend / divisor);
    } else {
      skip--;
    }
  }
  return quotient;
}

int findRepetend(int divisor, vector<short> quotient) {
  // I find this for-loop solution the most elegant
  // do a little dance
  for (int n = 1; n < divisor; n++) {
    // make a little love
    for (int i = 0; quotient[i] == quotient[i + n]; i++) {
       //cout << "d[" << i << "]("<< quotient[i]<<") == d[" << i << " + " << n
       //<< "](" << quotient[i+n] << ")" << endl;
      if (i > divisor * 2) {
        // get down tonight
        return n;
      }
    }
  }
  //we couldn't dance, love or get down
  return -1;
}

void potentialRepCase() {
  cout << endl << "Enter the dividend and divisor of the rational number"
       << " whose repetend we seek:" << endl;

  int dividend{0}, divisor{0};

  cin >> dividend >> divisor;


  vector<short> quotientDigits = calculateQuotient(divisor, dividend);

  //cout << "\nHere are the digits of the quotient computed : ";
  //printQuotient(-1, quotientDigits);

  int result = findRepetend(divisor, quotientDigits);

  cout <<  endl;

  if (result > 0){
    cout << "Repetend found:" << endl;
    printQuotient(result, quotientDigits);
  } else {
    cout << "No repetend found." << endl;
  }
}

void intervalCase() {
  //cout << "not done yet" << endl;

  int largestLength{0};
  int largestDividend{0};
  vector<short> largestQuotient;

  cout << endl << "Enter the integer n for the interval [1,n] in which we will find the divisor" << endl
       <<"with the largest repetend when divided into 1." << endl;

  int upperBound{0};

  cin >> upperBound;

  for (int i = upperBound; i > 1; i--){
    vector<short> quotientDigits = calculateQuotient(i, 1);

    int result = findRepetend(i, quotientDigits);

    if (result > 0 && result > largestLength) {
     largestLength = result;
     largestDividend = i;
     largestQuotient = quotientDigits;
     // cout << "Repetend found:" << i << " " << result << endl;
     // printQuotient(result, quotientDigits);
    }
  }

  cout << "The dividend of 1/n with longest repetend: " << largestDividend << " with length: " << largestLength << endl
       << endl;
  printQuotient(largestLength, largestQuotient); 

}
