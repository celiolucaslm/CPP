#ifndef FACTORIELLE_HPP
#define FACTORIELLE_HPP

template <int N>
struct Factorielle {
    static const unsigned long valeur = N * Factorielle<N - 1>::valeur;
};

// Especialização do template Factorielle para o caso base
template <>
struct Factorielle<0> {
    static const unsigned long valeur = 1;
};

#endif