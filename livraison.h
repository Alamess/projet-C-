#ifndef LIVRAISON_H
#define LIVRAISON_H
#include"don.h"

class livraison
{
    int id_livraison ;
    string date_livraison ;
    Don don_livree ;
    string type_livraison ;
    public:
        livraison();
        friend istream& operator>>(istream&,livraison&) ;
        friend ostream& operator<<(ostream& ,livraison&);
        virtual ~livraison();
        float getdonmonnaie(){return don_livree.getmonnaie();};

};

#endif // LIVRAISON_H
