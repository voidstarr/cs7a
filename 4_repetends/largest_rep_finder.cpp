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

 

  for (int i = 10000; i > 1; i--) {
    if (sequenceLength >= i) {
      break;
    }

    vector<int> foundRemainders(i);
    int value = 1;
    int position = 0;

    while (foundRemainders[value] == 0 && value != 0) {
      foundRemainders[value] = position;
      value *= 10;
      value %= i;
      position++;
    }

    if (position - foundRemainders[value] > sequenceLength) {
        num = i;
        sequenceLength = position - foundRemainders[value];
    }
  }
  cout << "number with the largest repetend is " << num << " and the length is " << sequenceLength << endl;
}
