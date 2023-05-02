#include "service.h"
#include <string>
#include <iostream>

using namespace std;


Service::Service(int id_s,int desc)
{
    id_service=id_s;
    nbr_descrip=desc ;


}

Service::~Service()
{

}
 void Service::saisir() {
    cout << "Entrez l'ID du service : ";
    cin >> id_service;
    cout<<"entrer le nbre de description "<<endl ;
    cin>> nbr_descrip ;
    cout << "Entrez les descriptions du service : ";
    for(int i=0 ;i<nbr_descrip;i++)
    {
        string x ;
        cin>>x ;
        description.push_back(x) ;
    }
}
istream& operator>>(istream&in,Service&s)
{
    cout << "Entrez l'ID du service : ";
    in >> s.id_service;
    cout << "Entrez la description du service : ";
    in>> s.nbr_descrip ;
    cout << "Entrez les descriptions du service : ";
    for(int i=0 ;i<s.nbr_descrip;i++)
    {
        string x ;
        in>>x ;
        s.description.push_back(x) ;
    }

    return in ;
}

 void Service::afficher() {
    cout << "ID Service : " << id_service << endl;
     cout << "les descriptions du services : "<<endl;
    for(int i=0 ;i<nbr_descrip;i++)
    {
        cout<< description[i] ;
    }
}
ostream& operator<<(ostream& out  ,Service& serv)
{   cout << "ID Service : ";
    out<< serv.id_service << endl;
    cout << "les descriptions du services : "<<endl;
    for(int i=0 ;i<serv.nbr_descrip;i++)
    {
        out<< serv.description[i] ;
    }

    return out;
}
