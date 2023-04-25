#include "livraison.h"

livraison::livraison() : don_livree(),type_livraison(""),date_livraison(""),id_livraison(0)
{
    //ctor
}
istream& operator>>(istream&in,livraison&l)
{
    cout<<"saisir l'id de livraison "<<endl ;
    in>>l.id_livraison ;
    cout<<"saisir type de livraison "<<endl ;
    in>>l.type_livraison ;
    cout<<"saisir date de livraison "<<endl ;
    in>>l.date_livraison ;
    cout<<"saisir don a livree "<<endl ;
    in>>l.don_livree ;
    return in ;
}
ostream& operator<<(ostream& out  ,livraison& l)
{
    out<<"id de livraison est"<<l.id_livraison<<endl ;
    out<<"type de livraison est"<<l.type_livraison<<endl ;
    out<<"la date de livraison est"<<l.date_livraison<<endl ;
    out<<"don a livree est" ;
    out<<l.don_livree ;
    return out;
}

livraison::~livraison()
{
    //dtor
}
