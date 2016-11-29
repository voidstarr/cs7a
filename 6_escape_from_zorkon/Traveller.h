#ifndef H_TRAVELLER
#define H_TRAVELLER

#include "Point.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>


const double step = 0.01; // determines speed
const double lakeRadius{1};

class Traveller {
public:
  char kind;         //'a' for "astronaut" and 'z' for "zorkoid"
  Point currentLoc;  // Where's Waldo?
  double speed;      // Generally a small number, but zorkoid goes faster
  double bearing{0}; // direction the Traveller is headed (maybe not useful?)
  std::vector<Point> path;    // history of locations
  void updateLoc(Point);      // engine for moving, depends on 'kind'
  void updateBearing(double); // not sure this is useful yet
  void updatePath();          // could be built into updateLoc()
  void printPath(std::ofstream &);
  bool onShore();                          /// is r >= lakeRadius?
  Traveller(Point p, double s, char kind); // constructor
};

#endif
