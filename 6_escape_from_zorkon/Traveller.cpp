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
    std::cout << "unit vector : " << heading / speed << std::endl
              << "(|A - Z|):" << currentLoc.distFrom(p) << std::endl
              << "(A - Z): " << (currentLoc - p) << std::endl;
    currentLoc += heading;
  } else if (kind == 'z') {
    long double zTheta = currentLoc.theta;
    long double aTheta = p.theta;
    bool aboveLine = p.y > p.x * tan(zTheta);
    bool zyPos = currentLoc.y > 0;
    bool zxPos = currentLoc.x > 0;
    bool cw = (!aboveLine && !zxPos && !zyPos) ||
              (!aboveLine && zxPos && !zyPos) ||
              (aboveLine && !zxPos && zyPos) || 
              (aboveLine && zxPos && zyPos);

    if (cw) {
      currentLoc.setTheta(zTheta - speed);
    } else {
      currentLoc.setTheta(zTheta + speed);
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
