#pragma once
#include <istream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;
class incapere
{
protected:
    int nr;
    int loc;
    int capacitate;
    vector<string>viz;
public:
    incapere(int,int);
    int capacit()const
    {
        return capacitate;
    }
    int nr_pers_cam()
    {
        return loc;
    }
    int get_nr()const
    {
        return nr;
    }
    void reset_loc()
    {
        loc=0;
        viz.resize(0);
    }
    void add_capacitate(int a)
    {
        capacitate=a;
    }
    void add_nr(int a)
    {
        nr=a;
    }
    bool adaug(string); //adaugam omul a
    friend ostream& operator<<(ostream &,const incapere&);
    bool operator<(const incapere&)const;
    bool operator==(const incapere&)const;
};
#include "incapere.cpp"
