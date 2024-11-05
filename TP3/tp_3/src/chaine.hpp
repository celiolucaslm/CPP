#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include "exception.hpp"
#include <tuple>
#include <utility>

// Declarações antecipadas para garantir que as sobrecargas sejam resolvidas corretamente
template <typename T>
std::string chaine(const T& x);

// Especialização para std::string
template <>
std::string chaine(const std::string& str) {
    return str;
}

// Especialização para int
template <>
std::string chaine(const int& x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

// Especialização para double
template <>
std::string chaine(const double& x) {
    return std::to_string(x);
}

// Sobrecarga para tuplas com tipos variados
template <typename... Args>
std::string chaine(const std::tuple<Args...>& t);  // Declaração antecipada para tupla

// Função auxiliar para lidar com tuplas, com chamada recursiva para `chaine`
template <typename Tuple, std::size_t... Is>
std::string chaine_tuple_impl(const Tuple& t, std::index_sequence<Is...>) {
    std::ostringstream oss;
    ((oss << chaine(std::get<Is>(t)) << " "), ...);
    return oss.str();
}

// Definição da sobrecarga para tuplas com tipos variados
template <typename... Args>
std::string chaine(const std::tuple<Args...>& t) {
    return chaine_tuple_impl(t, std::make_index_sequence<sizeof...(Args)>());
}

// Versão genérica da função para outros tipos
template <typename T>
std::string chaine(const T& x) {
    throw ExceptionChaine(typeid(x).name());
}

// Variadic template para múltiplos argumentos
template <typename... Args>
std::string chaine(const Args&... args) {
    std::ostringstream oss;
    ((oss << chaine(args) << " "), ...);
    return oss.str();
}

#endif