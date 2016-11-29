#include "Traveller.h"

Traveller::Traveller(Point p, double s, char k)
    : currentLoc(p), speed(s), kind(k) {}

void Traveller::updateLoc(Point p) { /// p is the location of the other
                                     /// Traveller
  if (kind == 'a') {
                    
  } else if (kind == 'z'){           
   
  } else {
    std::cout << "Houston, we don't know what we're tracking!" << std::endl;
  }
}

void Traveller::printPath(std::ofstream &of) {
  for (Point p : path){
  /// write code here
  }
}

bool Traveller::onShore() { return currentLoc.r >= lakeRadius; }
