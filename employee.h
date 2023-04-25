#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
using namespace std;
#include<string>
#include"personne.h"

class employee : public personne
{
protected :
    int tel ;
    string statut ;
    float salaire ;
    public:
        employee(string="",string="" , int=0 , int=0 , int=0 ,string="",float=0);
        virtual void afficher ()= 0;
        virtual void saisir ()= 0 ;
        friend istream& operator>>(istream&  ,employee& ) ;
        friend ostream& operator<<(ostream&  ,employee& );
        virtual ~employee();

};

#endif // EMPLOYEE_H
