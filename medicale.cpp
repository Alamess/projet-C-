#include "medicale.h"
int medicale::nbr_alim=0 ;
vector<don_livree<Alimentation>> medicale::alim ;
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
    cout<<"departement :" ;
    out<< m.departement <<endl ;
}
 void medicale::ajouter_Alimen (don_livree<Alimentation> h)
{
    alim.push_back(h) ;
    nbr_alim+=1 ;
}
void medicale::afficher_Alimen()
{
    for (int i=0 ;i<nbr_alim;i++)
    {
        cout<< alim[i]<<endl ;
    }
}
istream& operator>>(istream&in  ,medicale*p )
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
ostream& operator<<(ostream& out ,medicale* p)
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



medicale::~medicale()
{
    //dtor
}
