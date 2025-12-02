#ifndef NEGATIVEPROFESSORCOUNT_H
#define NEGATIVEPROFESSORCOUNT_H

#include <exception>

class negativeProfessorCount: public std::exception{
    public:
    negativeProfessorCount() noexcept = default;
    ~negativeProfessorCount() = default;
    virtual const char* what() const noexcept{
        return "on n'accepte pas un nombre negatif des professeurs. ";
    }
};


#endif