#ifndef ALIMENTATION_H
#define ALIMENTATION_H
#include "service.h"
#include <iostream>

class Alimentation: public Service
{
        int id_plat;
        string nom_plat;
        int nb_plat;

    public:

        Alimentation(int=0,string="",string="",int=0,int=0,string="",int=0);
        void afficher();
        void saisir();
        friend istream& operator>>(istream&,Alimentation&) ;
        friend ostream& operator<<(ostream&,Alimentation& );
        virtual ~Alimentation();

    protected:

    private:
};

#endif // ALIMENTATION_H
