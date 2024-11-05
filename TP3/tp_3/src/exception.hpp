#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include "demangle.hpp" 

class ExceptionChaine : public std::exception {
public:
    ExceptionChaine(const std::string& type);
    virtual const char* what() const noexcept override;

private:
    std::string message;
};

#endif