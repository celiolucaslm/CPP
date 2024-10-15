#include "cartesien.hpp"
#include "polaire.hpp"

Cartesien::Cartesien(double x, double y): x(x), y(y) {}

Cartesien::Cartesien(Polaire& p) {
    this->x = p.getDistance() * std::cos(p.getAngle() * M_PI / 180);
    this->y = p.getDistance() * std::sin(p.getAngle() * M_PI / 180);
}

double Cartesien::getX() const {
    return x;
}
 
double Cartesien::getY() const {
    return y;
}

void Cartesien::setX(double x) {
    this->x = x;
}

void Cartesien::setY(double y) {
    this->y = y;
}

void Cartesien::afficher(std::ostream& o) const {
    o << "(x=" << this->x << ";y=" << this->y << ")";
}

void Cartesien::convertir(Cartesien& c) const {
    c.setX(this->x);
    c.setY(this->y);
}

void Cartesien::convertir(Polaire& p) const {
    p.setAngle((atan2(this->y, this->x) * 180 / M_PI));
    p.setDistance((hypot(this->x, this->y)));
}