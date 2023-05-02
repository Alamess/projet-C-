#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
using namespace std;
#include<string>
#include"personne.h"
#include <vector>
#include"livraison.h"
#include"hebergement.h"
#include"alimentation.h"
class employee : public personne
{
protected :
    static vector<don_livree<Hebergement>> Serv ;
    int tel ;
    static int nbr_Heber ;
    string statut ;
    float salaire ;

    public:
        employee(string="",string="" , int=0 , int=0 , int=0 ,string="",float=0);
        virtual void afficher ()=0;
        virtual void saisir ()=0 ;
        friend istream& operator>>(istream&  ,employee& ) ;
        friend ostream& operator<<(ostream&  ,employee& );
        virtual ~employee();
        static void ajouter_Heberg (don_livree<Hebergement>) ;
        static void afficher_Heberg () ;
        static int getnbr_Heber (){return nbr_Heber;};
        static vector<don_livree<Hebergement>> getserv(){return Serv ;};
};

#endif // EMPLOYEE_H
