//
// Created by afik on 1/10/19.
//

#ifndef SECONDPROJECT_POINT_H
#define SECONDPROJECT_POINT_H
class Point {
    int x;
    int y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }
};
#endif //SECONDPROJECT_POINT_H
