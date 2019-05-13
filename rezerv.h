#pragma once
#include "cerere.h"
#include "incapere.h"
#include <vector>
class hotel;
class rezerv:public cerere
{
private:
    friend class hotel;
    int st_date,sf_date;
    vector<incapere>camere;
    vector<incapere>cpro;
    vector<incapere>cmes;
public:
    friend ostream& operator<<(ostream& co,const rezerv&);
    void add_st(int);
    void add_sf(int);
    void add_camere(incapere);
    void add_confpro(incapere);
    void add_confmes(incapere);
    rezerv(int a,int b);
    int get_st();
    int get_sf();

};
#include "rezerv.cpp"
