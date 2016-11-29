#include "Point.h"

double Point::setTheta() {
  if (x == 0 && y == 0)
    return 0; /// check for special cases first
  if (x == 0 && y > 0)
    return Pi / 2;
  else if (x == 0 && y < 0)
    return -Pi / 2;
  else
    return x > 0 ? atan(y / x) : Pi + atan(y / x);
}

//    polar:    a:r, b:theta
// rectangular: a:x, b:y
//
Point::Point(double a, double b, char sys) {
  if (sys == 'r') {
    x = a;
    y = b;
    setPolar();
  } else if (sys == 'p') {
    r = a;
    theta = b;
    setRectangular();
  } else {
      std::cout << "Houston, we have a major problem!" << std::endl;
  }
}

void Point::setRectangular() {
    x = r * cos(theta);
    y = r * sin(theta);
}

void Point::setPolar() {
    r = sqrt(x * x + y * y);
    theta = setTheta();
}

Point Point::operator+(const Point &p) { 
    return Point(x + p.x, y + p.y, 'r'); 
}

Point Point::operator-(const Point &p) {
    return Point(x - p.x, y - p.x, 'r');
}


Point Point::operator*(const double m) {
    return Point(x * m, x * y, 'r');
}

Point Point::operator/(const double m) {
  if (m == 0)
    return *this;
  return Point(x / m, y / m, 'r');
}

Point Point::operator+=(const Point &p) {
    x += p.x;
    y += p.y;
    setPolar();
    return *this;
}

/// define overloaded insertion operator for Point
std::ostream &operator<<(std::ostream &os, const Point &p) {
  // os << '(' << p.x << ',' << p.y << ')';
  os << p.x << ',' << p.y;
  return os;
}
