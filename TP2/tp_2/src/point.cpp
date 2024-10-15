#include "point.hpp"

Point::Point() {} 

std::ostream& operator<<(std::ostream& s, const Point& p) {
    p.afficher(s);

    return s;
} 