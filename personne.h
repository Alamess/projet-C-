#ifndef PERSONNE_H
#define PERSONNE_H
#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
#include<string>
class personne
{
    protected:
        static map<int,string> m ;
        string nom ;
        string prenom ;
        int id ;
        int age ;
    public:
        personne(string="",string="" , int=0 , int=0);
        virtual void afficher ()= 0;
        virtual void saisir ()= 0 ;
        virtual ~personne();
        string getnom(){return nom ;};
        string getprenom(){return prenom ;};
        int getid(){return id ;};
        int getage(){return age ;};
        friend istream& operator>>(istream&  ,personne& ) ;
        friend ostream& operator<<(ostream&  ,personne& ) ;
        static void afficher_map();
        static void ajouter_map(personne*) ;
        static void rechercher_personne(int) ;
};

#endif // PERSONNE_H
