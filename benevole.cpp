#include "benevole.h"

benevole::benevole(string h ,string c , int d ,int a,int l,int f): personne(h,c,d,a)
{
  num_tel=l ;
  disponibilite=f ;
}
void benevole::saisir()
{
    cout<<"saisir un benevole"<<endl ;
    personne::saisir() ;
    cout<<"saisir numero de telephone "<<endl ;
    cin >> num_tel ;
    cout<<"saisir la disponibilite "<<endl ;
    cin >> disponibilite ;

}
istream& operator>>(istream&in  ,benevole&p )
{
    personne *pt=&p ;
    cout<<"saisir un benevole"<<endl ;
    in>>*pt ;
    cout<<"saisir numero de telephone "<<endl ;
    in >> p.num_tel ;
    cout<<"saisir la disponibilite "<<endl ;
    in >> p.disponibilite ;
    return in ;

}
void benevole::afficher()
{
    cout<<"benevole "<<endl ;

    personne::afficher() ;
    cout <<"numero de telephone :"<< num_tel <<endl;
    cout <<"disponibilite :"<< disponibilite <<endl;

}
ostream& operator<<(ostream& out ,benevole& b)
{
    cout<<"benevole "<<endl ;

    personne *p=&b;
    out<<*p; ;
    cout <<"numero de telephone :";
    out<< b.num_tel <<endl;
    cout <<"disponibilite :";
    out<< b.disponibilite <<endl;
    return out;
}

benevole::~benevole()
{
    //dtor
}
