#include "Traveller.h"

Traveller::Traveller(Point p, double s, char k)
    : currentLoc(p), speed(s), kind(k) {
  srand(time(0));
}

void Traveller::updateLoc(Point p) { /// p is the location of the other
                                     /// Traveller
  if (kind == 'a') {
    Point heading = ((currentLoc - p) / (currentLoc.distFrom(p))) *
                    speed; // div by dist between
    //std::cout << "aHeading : " << heading << std::endl
    //           << "currentLoc.distFrom(p):" << currentLoc.distFrom(p) << std::endl
    //           << "(currentLoc - p): " << (currentLoc - p) << std::endl;
    currentLoc += heading;
  } else if (kind == 'z') {
    double zTheta = currentLoc.theta;
    double aTheta = p.theta;

    std::cout << "z-theta: " << zTheta << " a-theta: " << aTheta << " z move: ";
    if (zTheta < aTheta && aTheta < zTheta + Pi) {
      currentLoc.setTheta(zTheta + speed);
      std::cout << "cc-wise" << std::endl;
    } else if (zTheta + Pi < aTheta && aTheta < zTheta + 2*Pi) {
      currentLoc.setTheta(zTheta - speed);
      std::cout << "c-wise" << std::endl;
    } else if (aTheta == zTheta ||
               aTheta == zTheta + Pi) {
      currentLoc.setTheta(zTheta + speed);
      std::cout << "cc-wise" << std::endl;
    } else {
      std::cout << "No zorkoid move..." << std::endl;
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
  // std::cout << "ast.currentLoc.r: " << currentLoc.r << std::endl;
  return currentLoc.r >= lakeRadius;
}
