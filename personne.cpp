#include "personne.h"
#include<iostream>

personne::personne(string h ,string c , int d ,int a) : nom(h) , prenom (c),id(d), age(a)
{
}
void personne::saisir()
{
    cout<<"saisir le nom de personne "<<endl ;
    cin>>nom ;
    cout<<"saisir le prenom de personne "<<endl ;
    cin>>prenom  ;
    cout<<"saisir id de personne "<<endl ;
    cin>>id  ;
    cout<<"saisir age de personne "<<endl ;
    cin>>age  ;
}
void personne::afficher()
{
    cout <<"prenom :"<< prenom <<endl;
    cout <<"nom :"<< nom <<endl;
    cout <<"id :"<< id <<endl;
    cout<<"age:"<< age <<endl ;
}

personne::~personne()
{
    //dtor
}
istream& operator>>(istream&in  ,personne&p )
{
    cout<<"saisir le nom de personne "<<endl ;
    in>>p.nom ;
    cout<<"saisir le prenom de personne "<<endl ;
    in>>p.prenom  ;
    cout<<"saisir id de personne "<<endl ;
    in>>p.id  ;
    cout<<"saisir age de personne "<<endl ;
    in>>p.age  ;
    return in ;
}
ostream& operator<<(ostream& out ,personne& p)
{
    out <<"prenom :"<<p.prenom <<endl;
    out <<"nom :"<< p.nom <<endl;
    out <<"id :"<< p.id <<endl;
    out<<"age:"<< p.age <<endl ;
    return out ;
}
