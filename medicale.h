#ifndef MEDICALE_H
#define MEDICALE_H
#include "employee.h"

class medicale : public employee
{
    string departement ;
    public:
        medicale(string="",string="" , int=0 , int=0 , int=0 ,string="",float=0);
        void saisir () ;
        void afficher () ;
        friend istream& operator>>(istream&  ,medicale& ) ;
        friend ostream& operator<<(ostream&  ,medicale& );
        virtual ~medicale();

};

#endif // MEDICALE_H
