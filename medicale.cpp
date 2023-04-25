#include "medicale.h"

medicale::medicale(string a,string b , int c , int d , int e ,string f,float g) : employee(a,b,c,d,e,f,g)
{
    departement="medicale" ;
}
void medicale::saisir ()
{
    employee::saisir();
    departement="medicale" ;
}
istream& operator>>(istream&in  ,medicale&p )
{
    employee *pt=&p ;
    in>>*pt ;
    return in ;
}
void medicale::afficher()
{
    employee::afficher() ;
    cout<<"departement : medicale" <<endl ;
}
ostream& operator<<(ostream& out ,medicale& m)
{
    employee *e=&m;
    out<<*e;
    out<<"departement : medicale" <<endl ;
    return out;
}


medicale::~medicale()
{
    //dtor
}
