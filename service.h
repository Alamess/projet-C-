#ifndef SERVICE_H
#define SERVICE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Service
{
    protected:
    int id_service;
    int nbr_descrip ;
     vector<string> description;
    public:
       virtual void saisir()=0;
       friend istream& operator>>(istream&,Service&) ;
        friend ostream& operator <<(ostream&,Service&);
        Service(int=0,int=0);
        virtual void afficher()=0;
        virtual ~Service();
};
#endif
