#include "personne en difficulte.h"
personne_en_difficulte::personne_en_difficulte(personne_en_difficulte&w)
{
    nom=w.nom ;
    id=w.id ;
    age=w.age ;
    diff=w.diff ;
    prenom=w.prenom ;
}

personne_en_difficulte::personne_en_difficulte(string h ,string c , int d ,int a,string l): personne(h,c,d,a)
{
    diff=l ;
}
void personne_en_difficulte::saisir()
{
    cout<<"saisir un personne en difficulte"<<endl ;
    personne::saisir() ;
    cout<<"saisir la difficulte de personne "<<endl ;
    cin >> diff ;

}
 istream& operator>>(istream&in  ,personne_en_difficulte&p )
{
    personne *pt=&p ;
    cout<<"saisir un personne en difficulte"<<endl ;
    in>>*pt ;
    cout<<"saisir la difficulte de personne "<<endl ;
    in >> p.diff ;
    return in ;

}
ostream& operator<<(ostream& out ,personne_en_difficulte& p)
{
    cout<<"personne en diff "<<endl ;
    personne *pt=&p ;
    out<< *pt ;
    out <<"difficulte :"<< p.diff <<endl;
    return out ;
}
void personne_en_difficulte::afficher()
{
    cout<<"personne en diff "<<endl ;

    personne::afficher() ;
    cout <<"difficulte :"<< diff <<endl;
}

personne_en_difficulte::~personne_en_difficulte()
{
    //dtor
}
