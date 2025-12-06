#include "ecolePrivee.h"
#include <cstring>

ecolePrivee::ecolePrivee(
    const char* nom = nullptr,
    const char* adresse = nullptr,
    int ne = 0,
    int* eleve = nullptr,
    const char *gerant = nullptr,
    float capital = 0.0
): ecole(nom,adresse,ne,eleve), gerant{nullptr}, capital{0.0}
{
    if(gerant){
        this->gerant = new char[std::strlen(gerant)+1];
        std::strcpy(this->gerant ,gerant);
    }
    if (capital)
        this->capital = capital;
}

ecolePrivee::ecolePrivee(const ecolePrivee &source): ecole(source){
    if(source.gerant){
        this->gerant = new char[std::strlen(source.gerant)+1];
        std::strcpy(this->gerant ,source.gerant);
    }
    if (capital)
        this->capital = source.capital;
}

ecolePrivee::~ecolePrivee(){
    if(gerant)
    delete [] gerant;
}

ecolePrivee::operator char*(){
    char* p = new char[256];
    p = ecole::operator char *();

    sprintf(p,"%s:%s:%.2f",p,gerant,capital);

    return p;
}

void ecolePrivee::view() const{
    std::cout << std::endl;
    std::cout << "le nom de cet ecole privee est: " << this->nom << std::endl;
    std::cout << "l'addresse de cet ecole privee est: " << this->adresse << std::endl;
    std::cout << "le nombre d'enseignant de cet ecole privee est: " << this->ne << std::endl;
    std::cout << "le gerant de cet ecole privee est: " << this->gerant << std::endl;
    std::cout << "le capital de cet ecole privee est: " << this->capital << std::endl;
    std::cout << std::endl;
    for (int i = 0 ; i < 6 ; i++ ){
        if (i >= 1)
            std::cout << "le nombre des eleves du " << i+1 <<"eme niveau est: " << *(eleve+i) << std::endl;
        else
            std::cout << "le nombre des eleves du " << i+1 <<" er niveau est: " << *(eleve+i) << std::endl;

    }

}

