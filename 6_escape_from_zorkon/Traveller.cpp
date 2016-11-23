#include "Traveller.h"

Point::operator-(const Point& p){
    double xtmp = x - p.x;
    double ytmp = y - p.y;

    double rtmp = sqrt((xtmp*xtmp) + (ytmp*ytmp));
    double ttmp;
    if (xtmp == 0 && ytmp > 0)
        ttmp = Pi/2;
    else if (xtmp == 0 && ytmp < 0)
        ttmp = -1*Pi/2;
    else
        ttmp = (xtmp > 0) ? atan(xtmp/ytmp) : Pi+atan(xtmp/ytmp);


    
    return Point(rtmp,ttmp);
}

Traveller::Traveller(Point p, double s, double b)
    : currentLoc(p), speed(s), bearing(b) {}

void Traveller::updateLoc(Point p) { currentLoc = p; }

bool Traveller::onShore() {
  return currentLoc.x * currentLoc.x + currentLoc.y * currentLoc.y >=
         lakeRadius * lakeRadius;
}

void updateLoc() {}

void updateBearing(double b) { bearing = d; }

void updatePath() {}

void printPath() {}
