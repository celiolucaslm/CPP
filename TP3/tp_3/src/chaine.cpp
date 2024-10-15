#include "chaine.hpp"

ExceptionChaine::ExceptionChaine(const std::string& type) {
    message = "Conversion en chaine impossible pour '" + demangle(type) + "'";
}

const char* ExceptionChaine::what() const noexcept {
    return message.c_str();
}