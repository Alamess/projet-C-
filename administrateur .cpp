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
        cout<<"departement :";
        out<< ad.departement <<endl ;
    return out;
}
administrateur ::~administrateur ()
{
    //dtor
}
istream& operator>>(istream&in  ,administrateur*p )
{

    in>>p->nom ;
    in>>p->prenom  ;
    in>>p->id  ;
    in>>p->age  ;
    in>>p->tel ;
    in>>p->statut ;
    in>>p->salaire ;
    in>>p->departement ;
    return in ;
}
ostream& operator<<(ostream& out ,administrateur* p)
{
    out <<p->prenom <<setw(10);
    out << p->nom <<setw(10);
    out << p->id <<setw(10);
    out<< p->age <<setw(10) ;
    out << p->tel <<setw(10);
    out <<p->statut << setw(10) ;
    out <<p->salaire<<setw(10) ;
    out<<p->departement<<setw(10) ;

    return out;
}
