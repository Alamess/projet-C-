#include "sdf.h"
sdf::sdf(string h ,string c , int d ,int a,long k,string e): personne_en_difficulte(h,c,d,a)
{
    diff="sdf" ;
    duree=k;
    motif =e ;
}
void sdf::saisir()
{
    personne::saisir() ;
    diff="sdf" ;
    cout<<"saisir la duree "<<endl ;
    cin >> duree ;
     cout<<"saisir la motif "<<endl ;
    cin >> motif ;

}
 istream& operator>>(istream&in  ,sdf&p )
{
    personne *pt=&p ;
    in>>*pt ;
    cout<<"saisir la duree "<<endl ;
    in >> p.duree ;
     cout<<"saisir la motif "<<endl ;
    in >>p.motif ;
    return in ;

}
void sdf::afficher()
{
    personne_en_difficulte::afficher() ;
    cout <<"duree:"<< duree <<endl;
    cout <<"motif:"<< motif <<endl;
}

ostream& operator<<(ostream& out ,sdf& s)
{
    personne_en_difficulte *p=&s ;
    out<< *p ;
    cout <<"duree:";
    out<< s.duree <<endl;
    cout <<"motif:";
    out<< s.motif <<endl;
    return out;
}



sdf::~sdf()
{
    //dtor
}
