#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

class Nuage {

private:
    std::vector<Point *> nuage;

public:
    Nuage();
    int size() const;
    void ajouter(Point& p);
    using iterator = std::vector< Point *>::iterator;
    using const_iterator = std::vector< Point *>::const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    friend Cartesien barycentre(const Nuage& n);
    friend Polaire barycentre(const Polaire& p);

};

class BarycentreCartesien {
    public:
        Cartesien operator()(const Nuage& n) const;
};

class BarycentrePolaire {
    public:
        Polaire operator()(const Nuage& n) const;
};

#endif