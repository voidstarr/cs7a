#include "Traveller.h"

const int maxSteps = 1000;
int main() {
  int steps{0};
  const double Pi{3.14159265358979};
  Point east(1, 0);
  Point origin(0, 0);
  Traveller spaceman(origin, step, 0);
  Traveller zorkoid(east, 4 * step, Pi);
  while (!spaceman.onshore()) {
    // update zorkoid ’s position ( note that it must be on shore ) and path
    // update spaceman ’s bearing
    // update spaceman ’s position and path
    // // ...
  }
}
