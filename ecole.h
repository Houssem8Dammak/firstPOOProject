#ifndef ECOLE_H
#define ECOLE_H

#include <iostream>
#include <cstring>

using namespace std;

class ecole{
    protected:
        char* nom;
        char* adresse;
        int ne;
        int *eleve;
    public:
        ecole(const char* nom,const char* adresse,int ne,int* eleve);
        ecole(const ecole& e);
        virtual ~ecole();
        char* get_nom()const;
        int get_eleve_niveau(int niveau) const;
        ecole &operator++();
        ecole operator++(int);
        ecole operator+(ecole &fusionEcole);
        virtual operator char*();
        virtual void view()const;
};



#endif