#include "don.h"
#include"benevole.h"

Don::Don( ): donneur()
{
    id_don=0 ;
    monnaie=0 ;

}
istream& operator>>(istream&in,Don&d)
{
    cout<<"saisir l'id de don : "<<endl ;
    in>>d.id_don ;
    cout<<"saisir monnaie : "<<endl ;
    in>> d.monnaie ;
    cout<<"saisir donneur : "<<endl ;
    in>> d.donneur ;
    return in ;
}
ostream& operator<<(ostream& out ,Don& d)
{
    out<<"id don est : "<<d.id_don<<endl ;
    out<<"monnaie est : "<<d.monnaie<<endl ;
    out<<"le donneur est : "<<d.donneur ;

    return out;
}
Don::~Don()
{
    //dtor
}
