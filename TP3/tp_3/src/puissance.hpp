#ifndef PUISSANCE_HPP
#define PUISSANCE_HPP

template <int N>
struct Puissance {
    static double valeur(double x) {
        return x * Puissance<N - 1>::valeur(x);
    }
};

// Caso base para N=0, onde qualquer número elevado a 0 é 1
template <>
struct Puissance<0> {
    static double valeur(double x) {
        return 1.0;
    }
};

#endif