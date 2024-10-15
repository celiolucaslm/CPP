#include "nuage.hpp"
    
Nuage::Nuage() {}
 
int Nuage::size() const {
    return nuage.size();
}

void Nuage::ajouter(Point& p) {
    nuage.push_back(&p);
}

Nuage::iterator Nuage::begin() {
    return nuage.begin();
} 

Nuage::iterator Nuage::end() {
    return nuage.end();
} 

Nuage::const_iterator Nuage::begin() const {
    return nuage.begin();
}

Nuage::const_iterator Nuage::end() const {
    return nuage.end();
}

Cartesien barycentre(const Nuage& n) {
    double sumX = 0.0;
    double sumY = 0.0;
    int count = 0;

    for(const auto& point : n.nuage) {
        Cartesien* c = dynamic_cast<Cartesien*>(point);
        sumX += c->getX();
        sumY += c->getY();
        count++;
    }

    if(count == 0) {
        return Cartesien(0, 0);
    }

    return Cartesien(sumX / count, sumY / count);
}

Cartesien BarycentreCartesien::operator()(const Nuage& n) const {
    return barycentre(n);
} 

Polaire BarycentrePolaire::operator()(const Nuage& n) const {
    Cartesien c = barycentre(n);
    return Polaire(c);
} 