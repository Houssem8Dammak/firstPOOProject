#include "ecole.h"
using namespace std;
ecole::ecole(
    const char *nom = nullptr,
    const char *adresse = nullptr,
    int ne = 0,
    int *eleve = nullptr
): nom{nullptr}, adresse{nullptr}, ne{0}, eleve{nullptr}
{
    if (nom){
        this->nom = new char[strlen(nom) + 1];
        strcpy(this->nom, nom);
    }

    if (adresse){
        this->adresse = new char[strlen(adresse) + 1];
        strcpy(this->adresse, adresse);
    }
    if (ne > 0){
        this->ne = ne;
    }

    this->eleve = new int[6];
    if (eleve){
        for (int i = 0; i < 6; i++){
            this->eleve[i] = eleve[i];
        }
    }
}
ecole::ecole(const ecole &source): nom{nullptr}, adresse{nullptr}, ne{0}, eleve{nullptr}{
    if (source.nom){
        this->nom = new char[strlen(source.nom) + 1];
        strcpy(this->nom, source.nom);
    }

    if (source.adresse){
        this->adresse = new char[strlen(source.adresse) + 1];
        strcpy(this->adresse, source.adresse);
    }

    if (source.ne > 0){
        this->ne = source.ne;
    }

    this->eleve = new int[6];
    if (source.eleve){
        for (int i = 0; i < 6; i++){
            this->eleve[i] = source.eleve[i];
        }
    }
}
ecole::~ecole(){
    if (nom){
        delete[] nom;
    }

    if (adresse){
        delete[] adresse;
    }

    if (eleve){
        delete[] eleve;
    }
}

char *ecole::get_nom()const{
    return nom;
}

int ecole::get_eleve_niveau(int niveau)const{
    if (niveau >= 1 || niveau <= 6)
        return *(eleve + niveau - 1);
    else
        return 0;
}

ecole &ecole::operator++(){
    this->ne++;
    return *this;
}

ecole ecole::operator++(int asba){
    ecole temp {*this};
    this->ne +=1;
    return temp;
}

ecole ecole::operator+(ecole &fusionEcole){
    char *nameBuffer = new char[100];
    cout << "tapez le nom de la nouveau ecole: ";
    cin >> nameBuffer;

    char *adrBuffer = new char[100];
    cout << "tapez l'adresse de la nouveau ecole: ";
    cin >> adrBuffer;


    int newNe = this->ne + fusionEcole.ne;

    int *newEleve = new int[6];
    for(int i = 0; i < 6 ; i++){
        *(newEleve+i) = *(this->eleve+i) + *(fusionEcole.eleve+i);
    }

    ecole newEcole{nameBuffer,adrBuffer,newNe,newEleve};

    if (nameBuffer)
        delete[] nameBuffer;
    if (adrBuffer)
        delete [] adrBuffer;
    if(newEleve)
        delete [] newEleve;

    return newEcole;
}

ecole::operator char*(){
    char* p = new char[256];
    sprintf(p,"%s:%s:%d:",nom,adresse,ne);

    char *temp = new char[20];
    for (int i = 0 ; i < 5 ; i++){
        sprintf(temp,"%d/",this->eleve[i]);
        p = strcat(p,temp);
    }
    sprintf(temp,"%d",this->eleve[5]);
    p = strcat(p,temp);
    
    delete [] temp;

    return p;

}

void ecole::view() const{
    cout << endl;
    cout << "le nom de cet ecole est: " << this->nom << endl;
    cout << "l'addresse de cet ecole est: " << this->adresse << endl;
    cout << "le nombre d'enseignant de cet ecole est: " << this->ne << endl;
    cout << endl;
    for (int i = 0 ; i < 6 ; i++ ){
        if (i >= 1)
            cout << "le nombre des eleves du " << i+1 <<"eme niveau est: " << *(eleve+i) << endl;
        else
            cout << "le nombre des eleves du " << i+1 <<" er niveau est: " << *(eleve+i) << endl;

    }
}
