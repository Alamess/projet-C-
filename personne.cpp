#include "personne.h"
#include<iostream>
map<int,string> personne::m;
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
    personne::ajouter_map(&p) ;
    return in ;
}
ostream& operator<<(ostream& out ,personne& p)
{
    cout <<"prenom :";
    out<<p.prenom <<endl;
    cout <<"nom :" ;
    out<< p.nom <<endl;
    cout <<"id :";
    out<< p.id <<endl;
    cout<<"age:";
    out<< p.age <<endl ;
    return out ;
}

void personne::afficher_map()
{
    for(auto it = m.begin(); it != m.end(); ++it) {
        cout << "ID : " << it->first << ", Nom : " << it->second << endl;
    }
}
void personne::rechercher_personne(int id)
{
        map<int,string>::iterator it ;
        it= m.find(id) ;
        if(it!=m.end())
        {
            cout << "ID : " << it->first << ", Nom : " << it->second << endl;
        }
        else cout<<"aucun personne de cette id " <<endl ;
}

void personne::ajouter_map(personne*p)
{
    m[p->getid()]=p->getnom();
}
