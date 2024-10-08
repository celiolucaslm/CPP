#include "polaire.hpp"
#include "cartesien.hpp"

Polaire::Polaire(double a, double d): a(a), d(d) {}

Polaire::Polaire(Cartesien c) {
    this->a = atan2(c.getY(), c.getX()) * 180 / M_PI;
    this->d = hypot(c.getX(), c.getY());
}

double Polaire::getAngle() const {
    return a;
}
 
double Polaire::getDistance() const {
    return d;
}

void Polaire::setAngle(double a) {
    this->a = a;
}
     
void Polaire::setDistance(double d) {
    this->d = d;
}

void Polaire::afficher(std::ostream& o) const {
    o << "(a=" << this->a << ";d=" << this->d << ")";
}

void Polaire::convertir(Cartesien& c) const {
    c.setX((this->d * std::cos(this->a * M_PI / 180)));
    c.setY((this->d * std::sin(this->a * M_PI / 180)));
}

void Polaire::convertir(Polaire& p) const {
    p.setAngle(this->a);
    p.setDistance(this->d);
}