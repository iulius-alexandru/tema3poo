rezerv::rezerv(int a=0,int b=0)
{
    st_date=a;
    sf_date=b;
}
void rezerv::add_sf(int a)
{
    sf_date=a;
}
void rezerv::add_st(int a)
{
    st_date=a;
}
void rezerv::add_confmes(incapere A)
{
    cmes.push_back(A);
}
void rezerv::add_confpro(incapere B)
{
    cpro.push_back(B);
}
void rezerv::add_camere(incapere A)
{
    camere.push_back(A);
}
int rezerv::get_st()
{
    return st_date;
}
int rezerv::get_sf()
{
    return sf_date;
}
ostream& operator<<(ostream &co,const rezerv& X)
{
    co<<"Sunteti cazati in intervalul:"<<X.st_date<<"->"<<X.sf_date<<endl;
    co<<"In camerele:"<<endl;
    for(int i=0; i<(X.camere).size(); ++i)
        co<<X.camere[i]<<endl;
    return co;
}
