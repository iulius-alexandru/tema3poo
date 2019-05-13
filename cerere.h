#pragma once
#include<istream>
#include<ostream>
#include<vector>
#include "string.h"
using namespace std;
class hotel;
class cerere
{
private:
    bool confpro,confmes;
    friend class hotel;
protected:
    int nr_rest,nr_pers,nr_zile;
    int cnp_sef;
public:
    vector<string>pers;
    friend istream& operator>>(istream&,cerere&);
    friend ostream& operator<<(ostream&,const cerere&);
    cerere(int n=0)
    {
        cnp_sef=n;
    }
    bool get_confpro();
    int get_nrzile();
    void add_cnp(int a)
    {
        cnp_sef=a;
    }
    void add_nrrest(int a)
    {
        nr_rest=a;
    }
    void add_nrpers(int a)
    {
        nr_pers=a;
    }
    void add_nrzile(int a)
    {
        nr_zile=a;
    }
    void add_confpro(bool a)
    {
        confpro=a;
    }
    void add_confmes(bool a)
    {
        confmes=a;
    }
    void add_pers();
    int get_nrpers();
    int get_nrrest();
    bool get_confmes();
    int get_cnp();
    bool operator<(const cerere&)const;
    bool operator==(const cerere&)const;
};
#include "cerere.cpp"
