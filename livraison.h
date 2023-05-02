#ifndef LIVRAISON_H
#define LIVRAISON_H
#include"don.h"
template<typename T>
class don_livree :public Don<T>
{
    string date_livraison ;
    string type_livraison ;
    public:
        don_livree();
        template<typename a>
        friend istream& operator>>(istream&,don_livree<a>&) ;
        template<typename a >
        friend ostream& operator<<(ostream& ,don_livree<a>&);

};
template <typename T >
don_livree<T>::don_livree(): Don<T>() ,date_livraison()
{
    type_livraison = typeid(T).name() ;
}
template <typename T >

istream& operator>>(istream&in,don_livree<T>&l)
{
    Don<T>* q=&l ;
    in>>*q ;
    cout<<"saisir date de don_livree "<<endl ;
    in>>l.date_livraison ;
    return in ;
}
template <typename T >
ostream& operator<<(ostream& out  ,don_livree<T>& l)
{
    cout<<"id don est : ";
    out<<l.id_don<<endl ;
    cout<<"monnaie est : ";
    out<<l.monnaie<<endl ;
    cout<<"le donneur est : ";
    out<<l.donneur<<endl ;
    cout<<"type de don_livree est";
    out<<l.type_livraison<<endl ;
    cout<<"la date de don_livree est";
    out<<l.date_livraison<<endl ;
    return out;
}


#endif // LIVRAISON_H
