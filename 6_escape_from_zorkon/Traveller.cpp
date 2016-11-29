#include "Traveller.h"

Traveller::Traveller(Point p, double s, char k)
    : currentLoc(p), speed(s), kind(k) {}

void Traveller::updateLoc(Point p) { /// p is the location of the other
                                     /// Traveller
  if (kind == 'a') { /// update astronaut
                     /// write code here
  } else {           /// update zorkoid
                     /// write code here
  }
}

void Traveller::printPath(std::ofstream &of) {
  for (Point p : path){
  /// write code here
  }
}

bool Traveller::onShore() { return currentLoc.r >= lakeRadius; }
