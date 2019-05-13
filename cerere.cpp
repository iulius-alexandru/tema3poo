istream& operator>>(istream& ci,cerere &X)
{
    ci>>X.nr_pers;
    int p=X.nr_pers;
    X.pers.resize(0);
    while(p)
    {
        string a;
        ci>>a;
        (X.pers).push_back(a);
        --p;
    }
    ci>>X.nr_rest;
    ci>>X.nr_zile;
    ci>>X.cnp_sef;
    ci>>X.confpro;
    ci>>X.confmes;
    return ci;

}
ostream& operator<<(ostream& co,const cerere& X)
{
    co<<X.nr_pers<<endl;
    for(int i=0; i<X.pers.size(); i++)
        co<<(X.pers)[i]<<' ';
    co<<endl;
    co<<X.nr_rest<<endl;
    co<<X.nr_zile<<endl;
    co<<X.cnp_sef<<endl;
    co<<X.confpro<<endl;
    co<<X.confmes<<endl;
    return co;
}

int cerere::get_cnp()
{
    return cnp_sef;
}
bool cerere::get_confmes()
{
    return confmes;
}
bool cerere::get_confpro()
{
    return confpro;
}
bool cerere::operator<(const cerere& X)const
{
    return (cnp_sef<X.cnp_sef);
}
bool cerere::operator==(const cerere& X)const
{
    return (cnp_sef==X.cnp_sef);
}
int cerere::get_nrzile()
{
    return nr_zile;
}
int cerere::get_nrpers()
{
    return nr_pers;
}
int cerere::get_nrrest()
{
    return nr_rest;
}
void cerere::add_pers()
{
    string a;
    for(int i=1; i<=nr_pers; i++)
    {
        cin>>a;
        pers.push_back(a);
    }
}
