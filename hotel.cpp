istream& operator>>(istream &ci,hotel& X)
{
    ci>>X.nr_c2;
    ci>>X.nr_c4;
    ci>>X.nr_confpro;
    ci>>X.nr_confmes;
    ci>>X.cap_rest;
    ci>>X.cap_confpro;
    ci>>X.cap_confmes;
    for(int i=1; i<=X.nr_c4; i++)
    {
        incapere A(4,i);
        (X.cam_tot).insert(A);
    }
    for(int i=X.nr_c4+1; i<=X.nr_c2+X.nr_c4; i++)
    {
        incapere A(2,i);
        (X.cam_tot).insert(A);
    }
    for(int i=1; i<=X.nr_confpro; i++)
    {
        incapere A(X.cap_confpro,i);
        (X.confpro_tot).insert(A);
    }
    for(int i=1; i<=X.nr_confmes; i++)
    {
        incapere A(X.cap_confmes,i);
        (X.confmes_tot).insert(A);
    }

}
int hotel::capacit(set<incapere> X)
{
    int number=0;
    for(set<incapere>::iterator it=X.begin(); it!=X.end(); it++)
        number+=it->capacit();
    return number;
}
bool hotel::anul_rez(int cnp)
{
    if(rez[cnp].camere.size()!=0)
    {
        vector<cerere>::iterator it;
        for(it=cereri.begin(); it!=cereri.end(); it++)
            if(it->get_cnp()==cnp)
                break;
        cereri.erase(it,it);
        set<incapere> Xcam,Xpro,Xmes;
        for(int i=0; i<rez[cnp].camere.size(); i++)
            Xcam.insert(rez[cnp].camere[i]);
        for(int i=0; i<rez[cnp].cpro.size(); i++)
            Xpro.insert(rez[cnp].cpro[i]);
        for(int i=0; i<rez[cnp].cmes.size(); i++)
            Xmes.insert(rez[cnp].cmes[i]);
        for(int i=rez[cnp].st_date; i<=rez[cnp].sf_date; i++)
        {
            zile_rest[i]+=rez[cnp].nr_rest;
            zile_cam[i]=dif(zile_cam[i],Xcam);
            zile_confpro[i]=dif(zile_confpro[i],Xpro);
            zile_confmes[i]=dif(zile_confmes[i],Xmes);
        }
        cereri.erase(it,it+1);
        rez.erase(cnp);
        return 1;
    }
    else
        return 0;
}
set<incapere>hotel:: dif(set<incapere> X1,set<incapere> X2)
{
    set<incapere> X3;
    for(set<incapere>::iterator it=X1.begin(); it!=X1.end(); it++)
        if(X2.find(*it)==X2.end())
            X3.insert(*it);
    return X3;
}

void hotel::redim(int n)
{
    zile_cam.resize(n);
    zile_confmes.resize(n);
    zile_confpro.resize(n);
    zile_rest.resize(n,cap_rest);
}
bool hotel::test_rest(int z1,int z2,int nr_pers)
{
    for(int i=z1; i<=z2; i++)
    {
        if(zile_rest[i]<nr_pers)
            return 0;
    }
    return 1;
}
void hotel::ocup_rest(int z1,int z2,int nr_pers)
{
    for(int i=z1; i<=z2; i++)
        zile_rest[i]=zile_rest[i]-nr_pers;
}
set<incapere> hotel::cam_disp(int z1,int z2)
{
    set<incapere>X1,X2;
    for(int i=z1; i<=z2; i++)
        X2.insert(zile_cam[i].begin(),zile_cam[i].end());
    X1=dif(cam_tot,X2);
    return X1;
}
bool hotel::test_camere(int z1,int z2,int nr_pers)
{
    set<incapere>  X1=cam_disp(z1,z2);
    if(nr_pers>capacit(X1))
        return 0;
    return 1;
}
void hotel::ocup_camere(int z1,int z2,set<incapere> X)
{
    for(int i=z1; i<=z2; i++)
        zile_cam[i].insert(X.begin(),X.end());
}
set<incapere> hotel::confpro_disp(int z1,int z2)
{
    set<incapere>X1,X2;
    for(int i=z1; i<=z2; i++)
        X2.insert(zile_confpro[i].begin(),zile_confpro[i].end());
    for(set<incapere>::iterator it=confpro_tot.begin(); it!=confpro_tot.end(); it++)
        if(X2.find(*it)==X2.end())
            X1.insert(*it);
    return X1;
}
bool hotel::test_confpro(int z1,int z2,int nr_pers)
{
    set<incapere>  X1=confpro_disp(z1,z2);
    if(nr_pers>capacit(X1))
        return 0;
    return 1;
}
void hotel::ocup_confpro(int z1,int z2,set<incapere>X)
{
    for(int i=z1; i<=z2; i++)
        zile_confpro[i].insert(X.begin(),X.end());
}
set<incapere> hotel::confmes_disp(int z1,int z2)
{
    set<incapere>X1,X2;
    for(int i=z1; i<=z2; i++)
        X2.insert(zile_confmes[i].begin(),zile_confmes[i].end());
    for(set<incapere>::iterator it=confmes_tot.begin(); it!=confmes_tot.end(); it++)
        if(X2.find(*it)==X2.end())
            X1.insert(*it);
    return X1;
}
bool hotel::test_confmes(int z1,int z2,int nr_pers)
{
    set<incapere> X1=confmes_disp(z1,z2);
    if(nr_pers>capacit(X1))
        return 0;
    return 1;
}
void hotel::ocup_confmes(int z1,int z2,set<incapere> X)
{
    for(int i=z1; i<=z2; i++)
        zile_confmes[i].insert(X.begin(),X.end());
}
bool hotel::ad_rez(cerere X)
{
    cereri.push_back(X);
    if(rez[X.cnp_sef].pers.size()!=0)
    {
        cout<<"Mai aveti o rezervare facuta la hotelul nostru!\n";
        return 0;
    }
    else
    {
        int caz=0;
        int zi=0;
        if((X.nr_rest<=cap_rest)&&(X.nr_pers*X.confmes<=cap_confmes)&&(X.nr_pers*X.confpro<=cap_confpro)&&(X.nr_pers<=capacit(cam_tot)))
        {
            while(caz==0)
            {
                if(zi+X.get_nrzile()>zile_cam.size())
                    redim(zi+X.get_nrzile());
                if(test_camere(zi,zi+X.get_nrzile()-1,X.get_nrpers()))
                    if(test_confmes(zi,zi+X.get_nrzile()-1,X.get_nrpers()*X.get_confmes()))
                        if(test_confpro(zi,zi+X.get_nrzile()-1,X.get_nrpers()*X.get_confpro()))
                            if(test_rest(zi,zi+X.get_nrzile()-1,X.get_nrrest()))
                            {
                                caz=1;
                                ocup_rest(zi,zi+X.get_nrzile()-1,X.get_nrrest());
                                rez[X.get_cnp()].add_st(zi);
                                rez[X.get_cnp()].add_sf(zi+X.get_nrzile()-1);
                                rez[X.get_cnp()].add_nrrest(X.get_nrrest());
                                int p=0;
                                set<incapere> cam=cam_disp(zi,zi+X.get_nrzile()-1),camere_ocup;
                                set<incapere>::iterator it=cam.begin();
                                incapere camera(it->capacit(),it->get_nr());
                                while(p<X.get_nrpers())
                                {
                                    if(camera.adaug(X.pers[p]))
                                        ++p;
                                    else
                                    {
                                        camere_ocup.insert(camera);
                                        rez[X.get_cnp()].add_camere(camera);
                                        cam.erase(*it);
                                        it=cam.begin();
                                        camera.reset_loc();
                                        camera.add_capacitate(it->capacit());
                                        camera.add_nr(it->get_nr());
                                    }
                                }
                                if(camera.nr_pers_cam())
                                {
                                    camere_ocup.insert(camera);
                                    rez[X.get_cnp()].add_camere(camera);
                                    cam.erase(it);
                                }
                                ocup_camere(zi,zi+X.get_nrzile()-1,camere_ocup);
                                if(X.get_confpro())
                                {
                                    set<incapere> conf1=confpro_disp(zi,zi+X.get_nrzile()-1),conf1_ocup;
                                    int p=1,n=X.nr_pers/cap_confpro;
                                    while(p<=n)
                                    {
                                        set<incapere>::iterator t=conf1.begin();
                                        rez[X.get_cnp()].add_confpro(*t);
                                        conf1_ocup.insert(*t);
                                        conf1.erase(*t);
                                        ++p;
                                    }
                                    if(X.nr_pers%cap_confpro)
                                    {
                                        set<incapere>::iterator t=conf1.begin();
                                        rez[X.get_cnp()].add_confpro(*t);
                                        conf1_ocup.insert(*t);
                                        conf1.erase(*t);
                                    }
                                    ocup_confpro(zi,zi+X.get_nrzile()-1,conf1_ocup);
                                }
                                if(X.get_confmes())
                                {
                                    set<incapere> conf2=confmes_disp(zi,zi+X.get_nrzile()-1),conf2_ocup;
                                    int p=1,n=X.nr_pers/cap_confmes;
                                    while(p<=n)
                                    {
                                        set<incapere>::iterator t =conf2.begin();
                                        rez[X.get_cnp()].add_confmes(*t);
                                        conf2_ocup.insert(*t);
                                        conf2.erase(*t);
                                        ++p;
                                    }
                                    if(X.nr_pers%cap_confmes)
                                    {
                                        set<incapere>::iterator t=conf2.begin();
                                        conf2_ocup.insert(*t);
                                        rez[X.get_cnp()].add_confmes(*t);
                                        conf2.erase(*t);
                                    }
                                    ocup_confmes(zi,zi+X.get_nrzile()-1,conf2_ocup);
                                }

                            }
                ++zi;

            }
         return 1;
        }
      cout<<"Ne pare rau, hotelul nostru nu are capacitate de a sustine cerintele dumneavoastra!\n";
    return 0;
    }

}

void hotel::descarca_bd()
{
    ifstream f("rezervari_save.txt");
    cerere X;
    while(f>>X)
        ad_rez(X);
}
void hotel::incarca_bd()
{
    ofstream g("rezervari_save.txt");
    for(int i=0; i<cereri.size(); i++)
        g<<cereri[i]<<'\n';
}
