//
// Created by afik on 1/10/19.
//

#ifndef SECONDPROJECT_POINT_H
#define SECONDPROJECT_POINT_H

#include <math.h>

class Point {
    int x;
    int y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }


    int getX() const {
        return this->x;
    }

    int getY() const {
        return this->y;
    }

    bool operator==(const Point &point) const {
        if (this->x == point.x && this->y == point.y) {
            return true;
        }
        return false;
    }

    double getDistance(const Point* p) {
        return sqrt(pow(this->x - p->getX(), 2) +
             pow(this->y - p->getY(), 2));
    }
};
#endif //SECONDPROJECT_POINT_H
