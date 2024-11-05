#ifndef COSINUS_HPP
#define COSINUS_HPP

#include <factorielle.hpp>
#include <puissance.hpp>

template <int N>
struct Cosinus {
    static double valeur(double x) {
        return (N % 2 == 0 ? 1 : -1) * Puissance<2 * N>::valeur(x) / Factorielle<2 * N>::valeur + Cosinus<N - 1>::valeur(x);
    }
};

// Caso base para N=0
template <>
struct Cosinus<0> {
    static double valeur(double x) {
        return 1.0;
    }
};

template <int N>
struct Sinus {
    static double valeur(double x) {
        return (N % 2 == 0 ? 1 : -1) * Puissance<2 * N + 1>::valeur(x) / Factorielle<2 * N + 1>::valeur + Sinus<N - 1>::valeur(x);
    }
};

// Caso base para N=0
template <>
struct Sinus<0> {
    static double valeur(double x) {
        return x;
    }
};

#endif