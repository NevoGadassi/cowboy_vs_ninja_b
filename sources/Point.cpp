
#include "Point.hpp"
#include <iostream>
#include <math.h>
using namespace ariel;
using namespace std;


double Point :: distance (Point other) const {
    return sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
}


Point Point :: moveTowards (Point source, Point dest, double distance) {
    if (distance < 0) {
        throw std::invalid_argument("Distance is negative!");
    }
    if (source.distance(dest) <= distance) {
        return dest;
    }
    double x = source.getX()+ (dest.getX() - source.getX()) * (distance / source.distance(dest) );
    double y = source.getY()+ (dest.getY() - source.getY()) * (distance / source.distance(dest));

    return Point(x, y);

}

string Point :: toString () const {
    string info;
    info = "(" +  to_string(x) + ", " +  to_string(y) + ")";
    return info;
}
void Point :: print () const {
    cout << "(" << x << ", " << y << ")";
}