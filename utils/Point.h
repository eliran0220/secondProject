#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <unordered_set>

/**
 * Point class
 */
class Point {
    int x;
    int y;
public:
    /**
     * Function name: Point
     * The function operation: constructor
     * @param x given x
     * @param y given y
     */
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    /**
     * Function name: getX
     * The function operation: returns x value
     * @return int
     */
    int getX() const {
        return this->x;
    }

    /**
     * Function name: getY
     * The function operation: returns y value
     * @return int
     */
    int getY() const {
        return this->y;
    }

    /**
     * Function name: operator==
     * The function operation: returns true if this point
     * and the given point are equal, else false
     * @param point given point
     * @return bool
     */
    bool operator==(const Point &point) const {
        if (this->x == point.x && this->y == point.y) {
            return true;
        }
        return false;
    }

    /**
     * Function name: getDistance
     * The function operation: returns the distance between this point
     * and the given point using the known distance forumla
     * @param p given point
     * @return double
     */
    double getDistance(const Point *p) {
        return sqrt(pow(this->x - p->getX(), 2) +
                    pow(this->y - p->getY(), 2));
    }
};

/**
 * namespace std
 */
namespace std {
    template<>
    struct hash<Point *> {
        /**
         * Function name: operator
         * The function operation: a hash function,which for every
         * x position and y position, it pows(2) them and does | operation
         * on them
         * @param point given point
         * @return hash value
         */
        size_t operator()(const Point *point) const {
            size_t rowHash = hash<int>()(point->getX());
            size_t colHash = hash<int>()(point->getY());
            return rowHash ^ colHash;
        }
    };
}

#endif
