/*
 * Some code shamelessly ripped from
 * http://www.mathblog.dk/project-euler-26-find-the-value-of-d-1000-for-which-1d-contains-the-longest-recurring-cycle/
 * to examine the process of finding the largest repetend of 1/d where 1 < d <
 * 1000
 * */

#include <iostream>
#include <vector>

using namespace std;

int sequenceLength = 0;
int num = 0;

int main() {

 

  for (int i = 37; i > 1; i--) {
    if (sequenceLength >= i) {
      break;
    }

    vector<int> foundRemainders(i);
    int value = 144;
    int position = 0;

    while (foundRemainders[value] == 0 && value != 0) {
      foundRemainders[value] = position;
      value *= 10;
      value %= i;
      position++;
    }
    
    cout << "val: " << value << endl;
    cout << position << " - " << foundRemainders[value] << " > " << sequenceLength << endl;

    if (position - foundRemainders[value] > sequenceLength) {
        num = i;
        sequenceLength = position - foundRemainders[value];
    }
  }
  cout << "number with the largest repetend is " << num << " and the length is " << sequenceLength << endl;
}
