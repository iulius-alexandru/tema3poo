#include <fstream>
#include <iostream>
#include "incapere.h"
#include "rezerv.h"
#include "hotel.h"
#include<vector>
#include <stdbool.h>
#include<string>
#include <map>
#include <set>
using namespace std;
ifstream f("date_hotel.txt");
int main()
{
    hotel& h=hotel::get_instant();
    f>>h;
    h.descarca_bd();
    int x=1;
    cout<<"Vreti sa faceti o rezervare , sa anulati o rezervare sau sa vedeti o rezervare?"<<'\n';
    while(x)
    {
        cout<<"Scrieti:\n0 pentru anulare\n1 pentru rezervare\n2 pentru vedere rezervare:"<<'\n';
        int alg;
        cout<<"Introduceti alegerea:";
        cin>>alg;
        switch(alg)
        {
        case 0:
        {
            cout<<"Introduceti cnp-ul:";
            int cnp;
            cin>>cnp;
            if(h.anul_rez(cnp))
                cout<<"Rezervarea a fost anulata cu succes\n";
            else
                cout<<"Nu erati rezervat\n";
            break;
        }
        case 1:
        {
            cerere X;
            cout<<"numarul de persoane:";
            int a;
            cin>>a;
            X.add_nrpers(a);
            cout<<"numele persoanelor:";
            X.add_pers();
            cout<<"numarul persoanelor la restaurant:";
            cin>>a;
            X.add_nrrest(a);
            cout<<"numarul de zile:";
            cin>>a;
            X.add_nrzile(a);
            cout<<"cnp-ul de rezervarea:";
            cin>>a;
            X.add_cnp(a);
            bool b;
            cout<<"conferinte cu proiector:";
            cin>>b;
            X.add_confpro(b);
            cout<<"conferinte cu scena:";
            cin>>b;
            X.add_confmes(b);
            if(h.ad_rez(X))
                cout<<"Rezervarea s-a facut cu succes!\n";
        }
        break;
        case 2:
        {
            cout<<"Introduceti cnp:";
            int a;
            cin>>a;
            cout<<h.afis_rezerv(a);
            break;
        }

        }
        cout<<"Scrieti:\n0 Pentru terminarea actiunilor\n1 pentru continuare\n";
        cout<<"Introduceti:";
        cin>>x;
    }
    cout<<"\nMultumim ca ati ales hotelul nostru!";
    h.incarca_bd();


    return 0;
}
