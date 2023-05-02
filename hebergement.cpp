#include "hebergement.h"

  Hebergement::Hebergement(int a,string b,int id_h,string date_d,string date_f,string type_h,string des): Service( a,b)
 {

    id_Hebergement=id_h;
    date_debut=date_d;
    date_fin=date_f;
    description=des;
    type_heb=type_h;

 }
void Hebergement::saisir()
{ Service::saisir();
    cout<<"donner id du hebergement"<<endl;
    cin>>id_Hebergement;
    cout<<"donner date de debut"<<endl;
    cin>>date_debut;
    cout<<"donner date de fin"<<endl;
    cin>>date_fin;
    cout<<"donner la decription"<<endl;
    cin>>description;
    cout<<"donner le type d hebergement"<<endl;
    cin>>type_heb;
}
 istream& operator>>(istream&in,Hebergement&s)
 {
     Service*st =&s;
    in>>*st ;
    cout<<"donner id du hebergement"<<endl;
    in>>s.id_Hebergement;
    cout<<"donner date de debut"<<endl;
    in>>s.date_debut;
    cout<<"donner date de fin"<<endl;
    in>>s.date_fin;
    cout<<"donner la decription"<<endl;
    in>>s.description;
    cout<<"donner le type d hebergement"<<endl;
    in>>s.type_heb;
    return in ;
 }
void Hebergement::afficher() {
    Service::afficher(); // appel de la méthode afficher de la classe de base
    cout << "ID Hebergement : " << id_Hebergement << endl;
    cout << "Date début : " << date_debut << endl;
    cout << "Date fin : " << date_fin << endl;
    cout << "Type d'hébergement : " << type_heb << endl;
    cout << "Description : " << description << endl;
}
ostream& operator<<(ostream& out  ,Hebergement& h)
{
    Service *s=&h;
    out<<*s;       // appel de la méthode afficher de la classe de base
    cout << "ID Hebergement : ";
    out<< h.id_Hebergement << endl;
    cout << "Date début : ";
    out<< h.date_debut << endl;
    cout << "Date fin : ";
    out<< h.date_fin << endl;
    cout << "Type d'hébergement : ";
    out<< h.type_heb << endl;
    cout << "Description : ";
    out<< h.description << endl;
    return out;
}
Hebergement::~Hebergement(void)
{
    //dtor
}
