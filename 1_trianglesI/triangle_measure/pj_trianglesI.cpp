/*
    Patrick Jacobs
    Assignment 1 - TriangleI
    "This program is designed to aid in the analysis of triangles."
*/

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>

using namespace std;



const double M_PI = 3.1415926535897932384626433832795;

/***********************************************************
50/50
Patrick,

1.  It turns out M_PI is not standard with all compilers.  I had to add the definition above.
2.  I generally avoid pow(x,2) when x*x will do.
3.  Nice use of boolean function.

Here's my output:
--------------------------------------------------------------

This program is designed to aid in the analysis of triangles.
Would you like to specify the coordinates of a triangle (C),
or the lengths of their sides(S) ? Enter ΓÇÖCΓÇÖ or ΓÇÖSΓÇÖ:
C
Enter the x coordinate of point A:
0 0
Enter the y coordinate of point A:
Enter the x coordinate of point B:
5 0
Enter the y coordinate of point B:
Enter the x coordinate of point C:
3.2 2.4
Enter the y coordinate of point C:
The values of coordinates are A(0.000000, 0.000000) B(5.000000, 0.000000) C(3.200000, 2.400000)
The lengths of the sides are a = 3.000000, b = 4.000000, c = 5.000000
The angles are A = 36.869900, B = 53.130100, C = 90.000000

--------------------------------------------------------------
This program is designed to aid in the analysis of triangles.
Would you like to specify the coordinates of a triangle (C),
or the lengths of their sides(S) ? Enter ΓÇÖCΓÇÖ or ΓÇÖSΓÇÖ:
S
Enter the length of side a:
1 2 4
Enter the length of side b:
Enter the length of side c:
Those side lengths do not form a triangle.

--------------------------------------------------------------
This program is designed to aid in the analysis of triangles.
Would you like to specify the coordinates of a triangle (C),
or the lengths of their sides(S) ? Enter ΓÇÖCΓÇÖ or ΓÇÖSΓÇÖ:
S
Enter the length of side a:
7 5 3
Enter the length of side b:
Enter the length of side c:
The values of coordinates are A(0.000000, 0.000000) B(3.000000, 0.000000) C(-2.500000, 4.330127)
The lengths of the sides are a = 7.000000, b = 5.000000, c = 3.000000
The angles are A = 120.000000, B = 38.213211, C = 21.786789

--------------------------------------------------------------
-gh
*************************************************************/

float a, b, c, /// side lengths
    A, B, C;   /// angle measures ... final values we want

float Ax, Ay, Bx, By, Cx, Cy; /// in case we need these

float distanceBetween(float x1, float x2, float y1,
                      float y2) /// distance formula, yo!
{
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float toDegrees(float rad) { /// radian to degrees, yo!
  return rad * 180 / M_PI;
}

float toRadians(float deg) { /// degrees to radians, yo!
  return deg * M_PI / 180;
}

bool isTriangle(float x, float y, float z) {
  return x + y > z && y + z > x && z + x > y;
}

int main() {
  cout << "This program is designed to aid in the analysis of triangles.\n"
       << "Would you like to specify the coordinates of a triangle (C),\n"
       << "or the lengths of their sides(S) ? Enter ’C’ or ’S’:" << endl;
  char response = '?';
  cin >> response;
  if (response == 'C' || response == 'c') {
    /// we're going to receive coordinates of points that make up the triangle.
    cout << "Enter the x coordinate of point A:" << endl;
    cin >> Ax;
    cout << "Enter the y coordinate of point A:" << endl;
    cin >> Ay;
    cout << "Enter the x coordinate of point B:" << endl;
    cin >> Bx;
    cout << "Enter the y coordinate of point B:" << endl;
    cin >> By;
    cout << "Enter the x coordinate of point C:" << endl;
    cin >> Cx;
    cout << "Enter the y coordinate of point C:" << endl;
    cin >> Cy;
    /// calculate side lengths
    a = distanceBetween(Cx, Bx, Cy, By);
    b = distanceBetween(Ax, Cx, Ay, Cy);
    c = distanceBetween(Ax, Bx, Ay, By);

  } else if (response == 'S' || response == 's') {
    cout << "Enter the length of side a:" << endl;
    cin >> a;
    cout << "Enter the length of side b:" << endl;
    cin >> b;
    cout << "Enter the length of side c:" << endl;
    cin >> c;
  } else {
    cout << "Try again! 'S' or 'C' next time..." << endl;
    return -1;
  }

  if (!isTriangle(a, b, c)) {
    cout << "Those side lengths do not form a triangle.\n";
    return -1;
  }

  B = toDegrees(acos((pow(a, 2) - pow(b, 2) + pow(c, 2)) / (2 * a * c)));
  /// who needs optimization when I've got performance!1!one!?
  C = toDegrees(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)));

  A = 180 - C - B;

  if (response == 'S' || response == 's') {
    Ax = 0;
    Ay = 0;
    Bx = c;
    By = 0;
    Cx = b * cos(toRadians(A));
    Cy = b * sin(toRadians(A));
  }


  /// used printf for performance over using law of sins.
  /// see https://stackoverflow.com/questions/2872543/printf-vs-cout-in-c
  printf("The values of coordinates are A(%f, %f) B(%f, %f) C(%f, %f)\n", Ax,
         Ay, Bx, By, Cx, Cy);
  printf("The lengths of the sides are a = %f, b = %f, c = %f\n", a, b, c);
  printf("The angles are A = %f, B = %f, C = %f\n", A, B, C);

  return 0;
}

/************************:OUTPUT:********************************\
This program is designed to aid in the analysis of triangles.
Would you like to specify the coordinates of a triangle (C),
or the lengths of their sides(S) ? Enter ’C’ or ’S’:
c
Enter the x coordinate of point A:
0
Enter the y coordinate of point A:
0
Enter the x coordinate of point B:
2
Enter the y coordinate of point B:
2
Enter the x coordinate of point C:
4
Enter the y coordinate of point C:
0
The values of coordinates are A(0.000000, 0.000000) B(2.000000, 2.000000)
C(4.000000, 0.000000)
The lengths of the sides are a = 2.828427, b = 4.000000, c = 2.828427
The angles are A = 45.000000, B = 90.000000, C = 45.000000

This program is designed to aid in the analysis of triangles.
Would you like to specify the coordinates of a triangle (C),
or the lengths of their sides(S) ? Enter ’C’ or ’S’:
s
Enter the length of side a:
3
Enter the length of side b:
5
Enter the length of side c:
4
b: 5 A: 36.8699 toRad(A): 0.643501 sin(toRad(A): 0.6
The values of coordinates are A(0.000000, 0.000000) B(4.000000, 0.000000)
C(4.000000, 3.000000)
The lengths of the sides are a = 3.000000, b = 5.000000, c = 4.000000
The angles are A = 36.869904, B = 90.000000, C = 53.130100
\**********************************************************************/
