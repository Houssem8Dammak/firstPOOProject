#ifndef NEGATIVECLASSE_H
#define NEGATIVECLASSE_H

#include <exception>

class negativeClasse: public std::exception{
    public:
    negativeClasse() noexcept = default;
    ~negativeClasse() = default;
    virtual const char* what() const noexcept{
        return "il \' y a un niveau qui a un nombre neagtif des eleves. ";
    }
};


#endif