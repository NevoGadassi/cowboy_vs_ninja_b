
#ifndef POINT_H
#define POINT_H
#include <string>

namespace ariel {
    class Point {
    private:
        double x;
        double y;

    public:

        Point (double pointx = 0, double pointy = 0) : x(pointx), y(pointy) {}

        double distance (Point other) const;
        static Point moveTowards (Point source, Point dest, double dist);
        double& getX ()  { return this->x; }
        double& getY ()  { return this->y; }

         std :: string toString () const;
         void print () const;
    };
}

#endif 