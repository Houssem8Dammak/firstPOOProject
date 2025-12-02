#include <iostream>
#include "ecole.h"
#include "ecolePrivee.h"
#include <cstring>

using namespace std;

int main(){
    int tab1[6] = {20, 25, 30, 22, 18, 15};
    int tab2[6] = {10, 11, 12, 13, 14, 15};
    char* temp = new char[256];
    
    ecole *e1 = new ecole{"aschool", "Tunis", 25, tab1};
    e1->view();
    cout << "\n-----------test operator char*-----------\n";
    strcpy(temp,e1->operator char *());
    for (size_t i = 0 ; i < strlen(temp); i++){
        cout << temp[i];
    }
    
    ecole *e2 = new ecolePrivee{"Prive Excellence","Tunis",20,tab2,"Mr.Houssem",5000.5};
    cout << "\n-----------------------------------------\n";
    e2->view();
    cout << "\n-----------test operator char*-----------\n";
    strcpy(temp,e2->operator char *());
    for (size_t i = 0 ; i < strlen(temp); i++){
        cout << temp[i];
    }
    cout << "\n-----------------------------------------\n";
    
    cout<<"\n-------------test operator +-------------\n"<<endl;
    ecole *e3 = new ecole{*e1+*e2};

    ++(*e3);
    (*e3)++;
    cout << "-----------------------------------------";
    e3->view();
    cout << "\n-----------------------------------------\n";
    
    try{
        ecole *e4 = new ecole{"aschool", "Tunis", -25, tab1};
    }
    catch(const negativeProfessorCount &ex){
        cout << ex.what() << endl;
    }

    cout << "\n-----------------------------------------\n";
    
    try{
        int tab3[6] = {20, 25, 30, -22, 18, 15};
        ecole *e5 = new ecole{"aschool", "Tunis", 25, tab3};
    }catch(const negativeClasse &ex){
        cout << ex.what() << endl;
    }


    delete e1;
    delete e2;
    delete e3;
    delete [] temp;

    return 0;
}