/// Traveller .h header file
#pragma once;
#include <cmath>


const double step = 0.01;
const double lakeRadius{1};
const double Pi{3.14159265358979};

class Point {
public:
  double x;
  double y;
  double r;
  double theta;
  Point(double r, double theta) : r(r), theta(theta) {
    x = r*cos(theta);
    y = r*sin(theta);
  }

  Point operator-(Point);
};
class Traveller {
public:
  Point currentLoc;
  double speed;
  double bearing{0};
  vector<Point> path;
  void updateLoc();
  void updateBearing(double);
  void updatePath();
  void printPath();
  bool onShore();
  Traveller(Point p, double s, double b);
}
