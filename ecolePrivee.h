#ifndef ECOLEPRIVEE_H
#define ECOLEPRIVEE_H

#include "ecole.h"

class ecolePrivee : public ecole
{
protected:
    char *gerant;
    float capital;

public:
    ecolePrivee(const char* nom = nullptr,const char* adresse = nullptr,int ne = 0,int* eleve = nullptr,const char *gerant = nullptr,float capital = 0.0);
    ecolePrivee(const ecolePrivee &source);
    virtual ~ecolePrivee();
    virtual operator char *() override;
    virtual void view() const override;
};

#endif