#ifndef SERVICE_H
#define SERVICE_H
#include <string>
#include <iostream>

using namespace std;

class Service
{
    protected:
    int id_service;
    string description;
    public:
       virtual void saisir()=0;
       friend istream& operator>>(istream&,Service&) ;
        friend ostream& operator <<(ostream&,Service&);
        Service(int=0,string="");
        virtual void afficher()=0;
        virtual ~Service();
};
#endif
