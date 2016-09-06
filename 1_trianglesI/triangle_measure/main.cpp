/*
    Patrick Jacobs
    Assignment 1 - TriangleI
    TODO:
        spit out coordinates for final output
*/

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>

using namespace std;

float a, b, c, /// side lengths
      A, B, C; /// angle measures ... final values we want

float Ax, Ay, Bx, By, Cx, Cy; /// in case we need these

float distanceBetween (float x1, float x2, float y1, float y2) /// distance formula, yo!
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float toDegrees (float rad) { /// radian to degrees, yo!
    return rad * 180 / M_PI;
}

bool isTriangle(float x, float y, float z){
    return x + y > z && y + z > x && z + x > y;
}

int main()
{
    cout << "This program is designed to aid in the analysis of triangles." << endl;
    cout << "Would you like to specify the coordinates of a triangle (C),\nor the lengths of their sides(S) ? Enter ’C’ or ’S’:" << endl;
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
    C = toDegrees(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)));

    A = 180 - C - B;

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
The lengths of the sides are a = 2.828427, b = 4.000000, c= 2.828427
The angles are A = 45.000000, B = 90.000000, C = 45.000000
\**********************************************************************/
