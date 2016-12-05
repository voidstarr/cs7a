#pragma once

#include <iostream>
#include <cmath>

const double Pi = 3.14159265358979;

class Point {
public:
  double x; // rectangular coordinates
  double y;
  double r; /// polar coordinates
  double theta;
  Point(double x, double y, char s);      // constructor
  Point operator+(const Point &); // overload addition operator
  Point operator-(const Point &); // overload subtraction operator
  Point operator*(const double); // overload multiplication operator where right
                                 // operand is double
  Point operator/(const double); // overload multiplication operator where right
                                 // operand is double
  Point operator+=(const Point &);
  bool operator==(const Point &);


  void setTheta(double);
  double thetaFromXY();
  void setPolar();
  void setRectangular();
  double distFrom(const Point&);
};

std::ostream &operator<<(std::ostream &, const Point &p);
