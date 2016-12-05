#include "Point.h"

double Point::thetaFromXY() {
  //std::cout << "Point::thetaFromXY(): " << std::endl
  //          << "R(" << x << ", " << y << ") " << std::endl
  //          << "atan(y/x): " << atan(y/x) << std::endl;
  if (x == 0 && y == 0)
    return 0; /// check for special cases first
  if (x == 0)
    return y > 0 ? Pi/2 : -Pi/2;
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

void Point::setTheta(double nTheta) {
    if (nTheta == 0)
        theta = nTheta;
    theta = (nTheta > 0) ? nTheta : nTheta + 2*Pi;
    setRectangular();
}

void Point::setRectangular() {
    std::cout << "Point::setRectangular(): ";
    x = r * cos(theta);
    std::cout << "x:" << x << " r:" << r << " cos(theta):" << cos(theta);
    y = r * sin(theta);
    std::cout << " y:" << y << " r:" << r << " sin(theta):" << sin(theta) << std::endl;
}

void Point::setPolar() {
    r = sqrt(x * x + y * y);
    setTheta(thetaFromXY());
}

double Point::distFrom(const Point &p) {
    return sqrt(pow(x - p.x,2) + pow(y - p.y,2));
}

Point Point::operator+(const Point &p) { 
    return Point(x + p.x, y + p.y, 'r'); 
}

Point Point::operator-(const Point &p) {
    return Point(x - p.x, y - p.x, 'r');
}


Point Point::operator*(const double m) {
    return Point(x * m, x * m, 'r');
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

bool Point::operator==(const Point &p) {
    return x == p.x && y == p.y;
}

/// define overloaded insertion operator for Point
std::ostream &operator<<(std::ostream &os, const Point &p) {
  // os << '(' << p.x << ',' << p.y << ')';
  os << p.x << ',' << p.y;
  return os;
}
