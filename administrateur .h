#ifndef ADMINISTRATEUR _H
#define ADMINISTRATEUR _H
#include "employee.h"

class administrateur: public employee
{
    string departement ;
    public:
        administrateur(string="",string="" , int=0 , int=0 , int=0 ,string="",float=0);
        void saisir () ;
        void afficher () ;

    friend istream& operator>>(istream&  ,administrateur& ) ;
    friend ostream& operator<<(ostream&  ,administrateur& );
        virtual ~administrateur ();


};

#endif // ADMINISTRATEUR _H
