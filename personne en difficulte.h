#ifndef PERSONNE EN DIFFICULTE_H
#define PERSONNE EN DIFFICULTE_H
#include<iostream>
using namespace std;
#include<string>
#include"personne.h"

class personne_en_difficulte : public personne
{
protected :
    string diff ;
    public:
        personne_en_difficulte(personne_en_difficulte&) ;
        personne_en_difficulte(string="",string="" , int=0 , int=0, string="");
        void saisir () ;
        void afficher () ;
        friend istream& operator>>(istream&  ,personne_en_difficulte& ) ;
        friend ostream& operator<<(ostream& ,personne_en_difficulte& ) ;
        friend istream& operator>>(istream&  ,personne_en_difficulte* ) ;
        friend ostream& operator<<(ostream& ,personne_en_difficulte* ) ;

        virtual ~personne_en_difficulte();
        string getdiff(){return diff;} ;

};

#endif // PERSONNE EN DIFFICULTE_H
