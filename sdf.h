#ifndef SDF_H
#define SDF_H
#include<iostream>
using namespace std;
#include<string>
#include "personne en difficulte.h"


class sdf : public personne_en_difficulte
{
    long duree ;
    string motif ;
    public:
        sdf(string="",string="" , int=0 , int=0,long=0 ,string="");
        void saisir () ;
        void afficher () ;
        virtual ~sdf();
        void Setduree(long x){duree=x ;};
        void Setmotif(string x){motif=x ;};
        friend istream& operator>>(istream&  ,sdf&);
        friend ostream& operator<<(ostream&  ,sdf& );
};

#endif // SDF_H
