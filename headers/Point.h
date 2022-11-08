#ifndef LAB4_POINT_H
#define LAB4_POINT_H
#include <cstdio>
struct Point {
    size_t x, y;

    Point() : x(0), y(0) {};

    Point(size_t x, size_t y) : x(x), y(y) {};
};

#endif //LAB4_POINT_H
