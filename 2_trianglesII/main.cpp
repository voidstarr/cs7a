/*
    Patrick Jacobs
    Assignment 2 - TriangleII
    TODO:
      case 2 needs WORK
      test all switch paths thoroughly
      spit out coordinates
*/

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>

using namespace std;

float a, b, c, /// side lengths
    A, B, C;   /// angle measures ... final values we want

float Ax, Ay, Bx, By, Cx, Cy; /// in case we need these

float distanceBetween(float x1, float x2, float y1,
                      float y2) { /// distance formula, yo!
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float toDegrees(float rad) { /// radian to degrees, yo!
  return rad * 180 / M_PI;
}

float toRadians(float deg) { /// radian to degrees, yo!
  return deg * M_PI / 180;
}

int main() {
  int choice = -1;
  do {
    cout << "This program is designed to aid in the analysis of triangles."
         << "\nPlease select the number for the given information you have for "
            "your triangle:"
         << "\n1. Three vertices."
         << "\n2. Three edge lengths."
         << "\n3. Two edges and the included angle."
         << "\n4. Two angles and the included edge."
         << "\n5. Two angles and the side opposite the first angle."
         << "\n";

    cin >> choice;
    if (choice < 1 || choice > 5)
      cout << "\nThat’s not a good choice, try again: ";
  } while (choice < 0 ||
           choice > 5); /// keep prompting until legal choice selected

  switch (choice) {
  case 1:
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

    B = toDegrees(acos((pow(a, 2) - pow(b, 2) + pow(c, 2)) / (2 * a * c)));
    C = toDegrees(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)));
    A = 180 - C - B;

    break;
  case 2: /// TODO: NEEDS WORK
    cout << "Enter the length of side a:" << endl;
    cin >> a;
    cout << "Enter the length of side b:" << endl;
    cin >> b;
    cout << "Enter the length of side c:" << endl;
    cin >> c;

    B = toDegrees(acos((pow(a, 2) - pow(b, 2) + pow(c, 2)) / (2 * a * c)));
    C = toDegrees(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)));
    A = 180 - C - B;
    break;
  case 3:
    cout << "Enter the length of side b:" << endl;
    cin >> b;
    cout << "Enter the length of side c:" << endl;
    cin >> c;
    cout << "Enter the measure of angle A:" << endl;
    cin >> A;

    a = sqrt(pow(b, 2) + pow(c, 2) - (2 * b * c * cos(toRadians(A))));

    B = toDegrees(acos((pow(a, 2) - pow(b, 2) + pow(c, 2)) / (2 * a * c)));
    C = 180 - A - B;

    break;
  case 4:
    cout << "Enter the measure of angle A:" << endl;
    cin >> A;
    cout << "Enter the measure of angle B:" << endl;
    cin >> B;
    cout << "Enter the length of side c:" << endl;
    cin >> c;

    C = 180 - A - B;

    b = c * sin(toRadians(B)) / sin(toRadians(C));
    a = c * sin(toRadians(A)) / sin(toRadians(C));

    break;
  case 5:
    cout << "Enter the length of side a:" << endl;
    cin >> a;
    cout << "Enter the length of side b:" << endl;
    cin >> b;
    cout << "Enter the measure of angle A:" << endl;
    cin >> A;

    if (a > b) {
      B = toDegrees(asin(a * sin(toRadians(A) / b)));
      C = 180 - A - B;
      c = b * sin(toRadians(C)) / sin(toRadians(b));
    } else {
      float h = b * sin(toRadians(A));
      if (h > a) {
        cout << "No triangles exist for those values!" << endl;
        return 0;
      } else if (h < a && a < b) {
        B = toDegrees(asin(b * sin(toRadians(A)) / a));
        C = 180 - A - B;
        c = b * sin(toRadians(C)) / sin(toRadians(b));

        float Bprime = 180 - B;
        float Cprime = 180 - Bprime - A;
        float cprime = b * sin(toRadians(Cprime)) / sin(toRadians(b));
        cout << "First triangle:" << endl;
        printf("The lengths of the sides are a = %f, b = %f, c' = %f\n", a, b,
               cprime);
        printf("The angles are A = %f, B' = %f, C' = %f\n", A, Bprime, Cprime);
        cout << "Second triangle" << endl;
      }
    }
    break;
  }

  printf("The lengths of the sides are a = %f, b = %f, c = %f\n", a, b, c);
  printf("The angles are A = %f, B = %f, C = %f\n", A, B, C);

  return 0;
}
