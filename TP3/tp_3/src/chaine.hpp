#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <exception>
#include "demangle.hpp" 

class ExceptionChaine : public std::exception {
public:
    ExceptionChaine(const std::string& type);
    virtual const char* what() const noexcept override;

private:
    std::string message;
};

template <typename T>
std::string chaine(const T& x) {
    
    throw ExceptionChaine(typeid(x).name());

    return "";
}

/* template <typename T1, typename T2>
std::string chaine(const std::pair<T1, T2>& p) {
    std::ostringstream oss;
    
    try {
        oss << "(" << p.first << ", " << p.second << ")";
    } catch (...) {
        throw ExceptionChaine(typeid(p).name());
    }

    return oss.str();
}
 */
#endif