incapere::incapere(int a=0,int b=0)
{
    capacitate=a;
    loc=0;
    nr=b;
}
bool incapere::adaug(string a)
{
    if(loc<capacitate)
    {
        viz.push_back(a);
        ++loc;
        return 1;
    }
    return 0;
}
ostream& operator<<(ostream &co,const incapere& X)
{
    co<<X.nr<<endl;
    co<<"Persoanele care stau in camera:"<<X.nr<<" sunt:"<<endl;
    for(int i=0; i<(X.viz).size(); i++)
        co<<(X.viz)[i]<<' ';
    return co;
}
bool incapere::operator<(const incapere& X)const
{
    return(nr<X.nr);
}
bool incapere::operator==(const incapere& X)const
{
    return (nr==X.nr);
}
