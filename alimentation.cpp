#include "alimentation.h"

Alimentation::Alimentation(int a,int b ,int id_p,string nom_p,int nb_p):Service( a,b)
{


    id_plat=id_p;
    nom_plat=nom_p;
    nb_plat=nb_p;


 }
 void Alimentation::saisir()
 { Service::saisir();
    cout<<"donner id du plat"<<endl;
    cin>>id_plat;
    cout<<"donner nom du plat"<<endl;
    cin>>nom_plat;
    cout<<"donner nbre du plat"<<endl;
    cin>>nb_plat;
 }
 istream& operator>>(istream&in,Alimentation&s)
{
        Service*st =&s;
        in>>*st ;
    cout<<"donner id du plat"<<endl;
    cin>>s.id_plat;
    cout<<"donner nom du plat"<<endl;
    cin>>s.nom_plat;
    cout<<"donner nbre du plat"<<endl;
    cin>>s.nb_plat;
    return in ;
}

 void Alimentation::afficher() {
    Service::afficher();
    cout << "ID Plat : " << id_plat << endl;
    cout << "Nom Plat : " << nom_plat << endl;
    cout << "Nombre de plats : " << nb_plat << endl;
}
ostream& operator<<(ostream& out  ,Alimentation& a)
{Service *s=&a;
    out<<*s;
    cout << "ID Plat : " ;
    out<< a.id_plat << endl;
    cout << "Nom Plat : " ;
    out<< a.nom_plat << endl;
    cout << "Nombre de plats : " ;
    out<< a.nb_plat << endl;

}
Alimentation::~Alimentation(void)
{

}
