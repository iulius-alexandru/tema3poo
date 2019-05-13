#pragma once
#include "incapere.h"
#include "cerere.h"
#include "rezerv.h"
#include <istream>
#include <ostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
class hotel
{
private:
    int nr_c2,nr_c4,cap_rest,nr_confpro,nr_confmes,cap_confpro,cap_confmes;
    set<incapere>cam_tot;
    set<incapere>confpro_tot;
    set<incapere>confmes_tot;
    vector< set<incapere> >zile_cam;
    vector< set<incapere> >zile_confpro;
    vector< set<incapere> >zile_confmes;
    vector<int>zile_rest;
    map<int,rezerv>rez;
    static hotel h;
    hotel() {}
    vector<cerere>cereri;
public:
    static hotel& get_instant()
    {
        return h;
    }
    rezerv afis_rezerv(int n)
    {
        return rez[n];
    }
    friend istream& operator>>(istream&,hotel&);
    int capacit(set<incapere>);
    bool anul_rez(int);
    set<incapere> cam_disp(int,int);
    bool test_camere(int,int,int);
    void ocup_camere(int,int,set<incapere>);
    set<incapere> confpro_disp(int,int);
    bool test_confpro(int,int,int);
    void ocup_confpro(int,int,set<incapere>);
    set<incapere> confmes_disp(int,int);
    bool test_confmes(int,int,int);
    void ocup_confmes(int,int,set<incapere>);
    bool test_rest(int,int,int);
    void ocup_rest(int,int,int);
    void redim(int);
    bool ad_rez(cerere);
    void incarca_bd();
    void descarca_bd();
    set<incapere> dif(set<incapere>,set<incapere>);
};
hotel hotel::h;
#include "hotel.cpp"
