#include "Point.h"
#include "Traveller.h"
#include <fstream>
using namespace std;

const int maxSteps = 2000;
const double fasterFactor = 4.0;
const double step = 0.01;

int main() {
  int steps{0};     // count how many times you've moved
  Point east(1, 0, 'r'); /// starting point of zorkoid
  cout << "east = " << east << endl;
  Point origin(0, 0, 'r');                     /// starting point of astronaut
  Traveller astronaut(origin, step, 'a'); /// construct astronaut
  cout << "astronaut starts at " << astronaut.currentLoc << endl;
  Traveller zorkoid(east, fasterFactor * step, 'z'); /// construct zorkoid
  ofstream ofa("aPath.txt"), ofz("zPath.txt");
  while (!astronaut.onShore() && steps < maxSteps) {
    zorkoid.updateLoc(astronaut.currentLoc);
    cout << "zorkoid is at " << zorkoid.currentLoc << endl;
    
    astronaut.updateLoc(zorkoid.currentLoc);
    cout << "astronaut is at " << astronaut.currentLoc << endl;
    ++steps;
    if (astronaut.currentLoc == zorkoid.currentLoc){
        cout << "astronaut was eaten, oh well." << endl;
        break;
    }
  }
  /// write code here
}
