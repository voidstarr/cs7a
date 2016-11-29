#include "Point.h"

double Point::setTheta(double xin, double yin) {
  if (xin == 0 && yin == 0)
    return 0; /// check for special cases first
  if (xin == 0 && yin > 0)
    return Pi / 2;
  else if (xin == 0 && yin < 0)
    return -Pi / 2;
  else
    return x > 0 ? atan(y / x) : Pi + atan(y / x);
}

Point::Point(double xin, double yin) : x(xin), y(yin) {
  r = sqrt(x * x + y * y);
  theta = setTheta(x, y);
}

Point Point::operator+(const Point &p) { return Point(x + p.x, y + p.y); }

Point Point::operator-(const Point &p) {
  /// write code here
}

Point Point::operator*(const double m) {
  /// write code here
}

Point Point::operator/(const double m) {
  if (m == 0)
    return *this;
  /// write code here
}

Point Point::operator+=(const Point &p) {
  /// write code here
}

/// define overloaded insertion operator for Point
std::ostream &operator<<(std::ostream &os, const Point &p) {
  // os << '(' << p.x << ',' << p.y << ')';
  os << p.x << ',' << p.y;
  return os;
}
