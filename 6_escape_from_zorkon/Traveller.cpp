#include "Traveller.h"

Traveller::Traveller(Point p, double s, char k)
    : currentLoc(p), speed(s), kind(k) {
  srand(time(0));
}

void Traveller::updateLoc(Point p) { /// p is the location of the other
                                     /// Traveller
  if (kind == 'a') {
    //Point heading = ((currentLoc - p) / (currentLoc.distFrom(p))) *
    //                speed; // div by dist between
    //std::cout << "unit vector : " << heading / speed << std::endl
    //          << "(|A - Z|):" << currentLoc.distFrom(p) << std::endl
    //          << "(A - Z): " << (currentLoc - p) << std::endl;
    //currentLoc += heading;
    

    /// Basic astronaut movement w/ explicit calculations
    // works(ish?)
    double vect_x = currentLoc.x - p.x;
    double vect_y = currentLoc.y - p.y;
    double d = sqrt(vect_x*vect_x + vect_y*vect_y);
    double unit_x = vect_x / d;
    double unit_y = vect_y / d;
    
    double step_x = unit_x * speed;
    double step_y = unit_y * speed;

    currentLoc.x += step_x;
    currentLoc.y += step_y;
   
    currentLoc.setPolar();
 
  } else if (kind == 'z') {
    long double zTheta = currentLoc.theta;
    long double aTheta = p.theta;
    
    long double currx = currentLoc.x;
    long double curry = currentLoc.y;
    
    bool aboveLine = p.y > p.x * tan(zTheta);
    bool onLine = p.y == p.x * tan(zTheta);
    bool zyPos = currentLoc.y > 0;
    bool zxPos = currentLoc.x > 0;
    //METHOD A:
    //bool cw = (!aboveLine && !zxPos && !zyPos) ||
    //          (!aboveLine && zxPos && !zyPos) ||
    //          (aboveLine && !zxPos && zyPos) || 
    //          (aboveLine && zxPos && zyPos);
    
    //METHOD B:
    //bool cw = rand() % 2;;

    //METHOD C1:
    //bool cw = (!aboveLine && !zxPos && !zyPos) ||
    //          (!aboveLine && zxPos && !zyPos) ||
    //          (aboveLine && !zxPos && zyPos) || 
    //          (aboveLine && zxPos && zyPos) ||
    //          onLine;

    //METHOD C2:
    //bool cw = (!aboveLine && !zxPos && !zyPos) ||
    //          (!aboveLine && zxPos && !zyPos) ||
    //          (aboveLine && !zxPos && zyPos) ||
    //          (aboveLine && zxPos && zyPos);
    //if (onLine)
    //    cw = false;

    //METHOD C3:
    bool cw = (!aboveLine && !zxPos && !zyPos) ||
              (!aboveLine && zxPos && !zyPos) ||
              (aboveLine && !zxPos && zyPos) ||
              (aboveLine && zxPos && zyPos);
    
    std::cout << "cw: " << (cw ? "true" : "false") << std::endl 
              << "aboveLine: " << (aboveLine ? "true" : "false") << std::endl
              << "zxPos: " << (zxPos ? "true" : "false") << std::endl
              << "zyPos: " << (zyPos ? "true" : "false") << std::endl;

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
