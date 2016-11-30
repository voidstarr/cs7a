#include "Traveller.h"

Traveller::Traveller(Point p, double s, char k)
    : currentLoc(p), speed(s), kind(k) {
        srand(time(0));
    }

void Traveller::updateLoc(Point p) { /// p is the location of the other
                                     /// Traveller
  if (kind == 'a') {
    Point heading = ((currentLoc - p) / (currentLoc.distFrom(p))) * speed; // div by dist between
    //std::cout << "heading : " << heading << std::endl;
    currentLoc += heading;
  } else if (kind == 'z') {
   if (p.theta > currentLoc.theta && p.theta < currentLoc.theta + Pi) {
       currentLoc.theta += speed;
   } else if (p.theta + Pi < currentLoc.theta && p.theta > currentLoc.theta) {
       currentLoc.theta += -1*speed;
   } else if (p.theta == currentLoc.theta || p.theta + Pi == currentLoc.theta) {
    if (rand() % 2 + 1 == 1) {
       currentLoc.theta += -1*speed;
    } else {
       currentLoc.theta += speed;
    }
   }
   currentLoc.setRectangular();
  } else {
    std::cout << "Houston, we don't know what we're tracking!" << std::endl;
  }
  path.push_back(currentLoc);
}

void Traveller::printPath(std::ofstream &of) {
  for (Point p : path) {
    of << p << std::endl;
  }
}

bool Traveller::onShore() { 
    //std::cout << "ast.currentLoc.r: " << currentLoc.r << std::endl;
    return currentLoc.r >= lakeRadius; 
}
