#ifndef H_POINT
#define H_POINT

#include <iostream>
#include <cmath>

class Point {
public:
  const double Pi = 3.14159265358979;
    
  double x; // rectangular coordinates
  double y;
  double r; /// polar coordinates
  double theta;
  Point(double x, double y);      // constructor
  Point operator+(const Point &); // overload addition operator
  Point operator-(const Point &); // overload subtraction operator
  Point operator*(const double); // overload multiplication operator where right
                                 // operand is double
  Point operator/(const double); // overload multiplication operator where right
                                 // operand is double
  Point operator+=(const Point &);
  double setTheta(double, double);
};

std::ostream &operator<<(std::ostream &, const Point &p);
#endif
