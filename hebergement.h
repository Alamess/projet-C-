#ifndef HEBERGEMENT_H
#define HEBERGEMENT_H
#include "service.h"
#include <string>
#include <iostream>




class Hebergement: public Service
{int id_Hebergement;
      string date_debut;
      string date_fin;
      string type_heb;
    public:

        Hebergement(int=0,int=0,int=0,string="",string="",string="");
        void afficher();
        friend ostream& operator<<(ostream&,Hebergement& );
        friend istream& operator>>(istream&,Hebergement&) ;
        void saisir();
        virtual ~Hebergement();
};

#endif // HEBERGEMENT_H
