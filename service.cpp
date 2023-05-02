#include "service.h"
#include <string>
#include <iostream>

using namespace std;


Service::Service(int id_s,string desc)
{
    id_service=id_s;
    description=desc;


}

Service::~Service()
{

}



 void Service::saisir() {
    cout << "Entrez l'ID du service : ";
    cin >> id_service;
    cout << "Entrez la description du service : ";
    cin>>description ;
}
istream& operator>>(istream&in,Service&s)
{
    cout << "Entrez l'ID du service : ";
    in >> s.id_service;
    cout << "Entrez la description du service : ";
    in>>s.description ;
    return in ;
}

 void Service::afficher() {
    cout << "ID Service : " << id_service << endl;
    cout << "Description : " << description << endl;
}
ostream& operator<<(ostream& out  ,Service& serv)
{   cout << "ID Service : ";
    out<< serv.id_service << endl;
    cout << "Description : ";
    out<< serv.description << endl;
    return out;
}
