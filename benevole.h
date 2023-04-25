#ifndef BENEVOLE_H
#define BENEVOLE_H
#include "personne.h"

class benevole : public personne
{
    int num_tel ;
    int disponibilite ;
    public:
        benevole(string="",string="" , int=0 , int=0,int=0,int=0);
        void saisir () ;
        void afficher () ;
        friend istream& operator>>(istream&  ,benevole& ) ;
        friend ostream& operator<<(ostream&  ,benevole& );
        virtual ~benevole();
};

#endif // BENEVOLE_H
