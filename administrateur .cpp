#include "administrateur .h"

administrateur::administrateur(string a,string b , int c , int d , int e ,string f,float g) : employee(a,b,c,d,e,f,g)
{
    departement="administrateur" ;
}
void administrateur::saisir ()
{
    employee::saisir();
    departement="administrateur" ;
}
istream& operator>>(istream&in  ,administrateur&p )
{
    employee *pt=&p ;
    in>>*pt ;
    return in ;
}
void administrateur::afficher()
{
    employee::afficher() ;
    cout<<"departement : administrateur" <<endl ;
}
ostream& operator<<(ostream& out ,administrateur& ad)
{
        employee *e=&ad ;
        out<<*e ;
        out<<"departement : administrateur" <<endl ;
    return out;
}
administrateur ::~administrateur ()
{
    //dtor
}
