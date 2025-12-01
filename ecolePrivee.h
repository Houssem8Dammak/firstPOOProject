#ifndef ECOLEPRIVEE_H
#define ECOLEPRIVEE_H

#include "ecole.h"

class ecolePrivee: public ecole{
protected:
    char *gerant;
    float capital;
public:
    ecolePrivee(const char* nom,const char* adresse,int ne,int* eleve,const char *gerant, float capital);
    ecolePrivee(const ecolePrivee &source);
    virtual ~ecolePrivee();
    virtual operator char*() override;
    virtual void view()const override;
};

#endif