#pragma once

#include <iostream>
#include <cmath>

const double Pi = 3.14159265358979;

class Point {
public:
  long double x; // rectangular coordinates
  long double y;
  long double r; /// polar coordinates
  long double theta;
  Point(long double x, long double y, char s);      // constructor
  Point operator+(const Point &); // overload addition operator
  Point operator-(const Point &); // overload subtraction operator
  Point operator*(const long double); // overload multiplication operator where right
                                 // operand is double
  Point operator/(const long double); // overload multiplication operator where right
                                 // operand is double
  Point operator+=(const Point &);
  bool operator==(const Point &);


  void setTheta(long double);
  long double thetaFromXY();
  void setPolar();
  void setRectangular();
  long double distFrom(const Point&);
};

std::ostream &operator<<(std::ostream &, const Point &p);
