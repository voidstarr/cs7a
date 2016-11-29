#include "Point.h"
#include "Traveller.h"
#include <fstream>
using namespace std;

const int maxSteps = 2000;
const double fasterFactor = 4.0;

int main() {
  int steps{0};     // count how many times you've moved
  Point east(1, 0); /// starting point of zorkoid
  cout << "\neast = " << east;
  Point origin(0, 0);                     /// starting point of astronaut
  Traveller astronaut(origin, step, 'a'); /// construct astronaut
  cout << "\nastronaut starts at " << astronaut.currentLoc;
  Traveller zorkoid(east, fasterFactor * step, 'z'); /// construct zorkoid
  ofstream ofa("aPath.txt"), ofz("zPath.txt");
  while (!astronaut.onShore() && steps < maxSteps) {
    /// update  zorkoid 's position (note  that it must be on  shore) and  path
    /// write code here
    /// update  spaceman 's bearing
    cout << "\nzorkoid is at " << zorkoid.currentLoc;
    /// update  spaceman 's position  and  path
    /// write code here
    ///...
    cout << "\nastronaut is at " << astronaut.currentLoc;
    ++steps;
    // cin.get();
  }
  /// write code here
}
