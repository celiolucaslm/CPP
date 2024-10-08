#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include "cartesien.hpp"
#include "polaire.hpp"

template <typename PointType> 
class Nuage {

private:
    std::vector<PointType> points;

public:
    void ajouter(const PointType& point);
    int size() const;
    using iterator = typename std::vector<PointType>::iterator;
    using const_iterator = typename std::vector<PointType>::const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    template <typename T>
    friend T barycentre_v1(const Nuage<T>& n);
};

// Implementing the template

template <typename PointType>
void Nuage<PointType>::ajouter(const PointType& point) {
    points.push_back(point);
}

template <typename PointType>
int Nuage<PointType>::size() const {
    return points.size();
}

template <typename PointType>
typename Nuage<PointType>::iterator Nuage<PointType>::begin() {
    return points.begin();
}

template <typename PointType>
typename Nuage<PointType>::iterator Nuage<PointType>::end() {
    return points.end();
}

template <typename PointType>
typename Nuage<PointType>::const_iterator Nuage<PointType>::begin() const {
    return points.begin();
}

template <typename PointType>
typename Nuage<PointType>::const_iterator Nuage<PointType>::end() const {
    return points.end();
}

template <typename PointType>
PointType barycentre_v1(const Nuage<PointType>& n) {
    double sumX = 0.0;
    double sumY = 0.0;
    int count = 0;

    for(const auto& point : n.points) {
	const Cartesien* c = dynamic_cast<const Cartesien*>(&point);
        sumX += c->getX();
        sumY += c->getY();
        count++;
    }

    if(count == 0) {
        return Cartesien(0, 0);
    }

    return Cartesien(sumX / count, sumY / count);
}

#endif