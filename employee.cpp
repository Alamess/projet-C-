#include "employee.h"

employee::employee(string a,string b , int c , int d , int e ,string f,float g) : personne(a,b,c,d)
{
tel=e ;
statut=f ;
salaire=g ;
}
void employee::saisir()
{
    cout<<"saisir un employee"<<endl ;
    personne::saisir() ;
    string msg="le numero doit comporter 8 chiffres" ;
    try{

    cout<<"saisir la tel d'employee "<<endl ;
    cin >> tel ;
    if ((tel>99999999)||(tel<10000000)) throw (msg);
    }
    catch(string m)
    {
        cout<<"erreur"<<m<<endl;
    }
    cout<<"saisir statut d'employee "<<endl ;
    cin >> statut ;
    cout<<"saisir salaire d'employee "<<endl ;
    cin >> salaire ;

}
istream& operator>>(istream&in  ,employee&p )
{
    cout<<"saisir un employee"<<endl ;
    personne *pt=&p ;
    in>>*pt ;
    string msg="le numero doit comporter 8 chiffres" ;
     try{
    cout<<"saisir la tel d'employee(8 chiffres) "<<endl ;
    in >> p.tel ;
    if ((p.tel>99999999)||(p.tel<10000000)) throw (msg);
    }
    catch(string m)
    {
        cout<<"erreur"<<m<<endl;
    }
    cout<<"saisir statut d'employee "<<endl ;
    in >> p.statut ;
    cout<<"saisir salaire d'employee "<<endl ;
    in >> p.salaire ;
    return in ;
}
void employee::afficher()
{
    cout<<"employee "<<endl ;
    personne::afficher() ;
    cout <<"tel  :"<< tel <<endl;
    cout << "statut :"<<statut << endl ;
    cout << "salaire : "<<salaire<<endl ;
}
ostream& operator<<(ostream& out ,employee& e)
{
    out<<"employee "<<endl ;
    personne *p=&e;
    out<<*p;
    out <<"tel  :"<< e.tel <<endl;
    out << "statut :"<<e.statut << endl ;
    out << "salaire : "<<e.salaire<<endl ;
    return out;
}

employee::~employee()
{
    //dtor
}
