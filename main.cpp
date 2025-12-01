#include <iostream>
#include "ecole.h"
#include "ecolePrivee.h"
#include <cstring>

using namespace std;

int main(){
    int tab1[6] = {20, 25, 30, 22, 18, 15};
    int tab2[6] = {10, 11, 12, 13, 14, 15};
    char* temp = new char[256];
    
    ecole *ptr = new ecole{"aschool", "Tunis", 25, tab1};
    ptr->view();
    cout << "\n-----------test operator char*-----------\n";
    strcpy(temp,ptr->operator char *());
    for (size_t i = 0 ; i < strlen(temp); i++){
        cout << temp[i];
    }
    
    ecole *ptr1 = new ecolePrivee{"Prive Excellence","Tunis",20,tab2,"Mr.Houssem",5000.5};
    cout << "\n-----------------------------------------\n";
    ptr1->view();
    cout << "\n-----------test operator char*-----------\n";
    strcpy(temp,ptr1->operator char *());
    for (size_t i = 0 ; i < strlen(temp); i++){
        cout << temp[i];
    }
    cout << "\n-----------------------------------------\n";
    
    cout<<"\n-------------test operator +-------------\n"<<endl;
    ecole *e3 = new ecole{*ptr+*ptr1};

    ++(*e3);
    (*e3)++;
    cout << "-----------------------------------------";
    e3->view();
    
    delete ptr;
    delete ptr1;
    delete e3;
    delete [] temp;

    return 0;
}