#ifndef MEDICALE_H
#define MEDICALE_H
#include "employee.h"

class medicale : public employee
{
    static vector<don_livree<Alimentation>> alim ;
    static int nbr_alim ;
    string departement ;
    public:
        medicale(string="",string="" , int=0 , int=0 , int=0 ,string="",float=0);
        void saisir () ;
        void afficher () ;
        string getdepartement(){return departement;};
        static void ajouter_Alimen (don_livree<Alimentation>) ;
        static void afficher_Alimen() ;
        friend istream& operator>>(istream&  ,medicale& ) ;
        friend ostream& operator<<(ostream&  ,medicale& );
        friend istream& operator>>(istream&  ,medicale* ) ;
        friend ostream& operator<<(ostream&  ,medicale* );
        static vector<don_livree<Alimentation>> getalim(){return alim ;} ;
        static int getnbr_alim(){return nbr_alim ;} ;
        virtual ~medicale();

};

#endif // MEDICALE_H
