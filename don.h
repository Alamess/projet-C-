#ifndef DON_H
#define DON_H
#include"benevole.h"

template<typename T>
class Don
{
protected :
    int id_don;
    T monnaie ;
    benevole donneur ;
public:
    Don();
    T getmonnaie() { return monnaie ;} ;
    template<typename a>
    friend ostream& operator<< (ostream&, Don<a>&);
    template<typename a>
    friend istream& operator>> (istream&, Don<a>&);
    bool operator<(const Don<T>&) ;
};
template<typename T>

Don<T>::Don(): donneur(),id_don(),monnaie()
{
}
template<typename T>
ostream& operator<< (ostream& out, Don<T>&d)
{
    cout<<"id don est : ";
    out<<d.id_don<<endl ;
    cout<<"monnaie est : ";
    out<<d.monnaie<<endl ;
    cout<<"le donneur est : "<<d.donneur<<endl ;

    return out;
}
template<typename T>

istream& operator>> (istream& in, Don<T> &d)
{
    cout<<"saisir l'id de don :"<<endl ;
    in>>d.id_don ;
    cout<<"saisir monnaie : "<<endl ;
    in>> d.monnaie ;
    cout<<"saisir donneur : "<<endl ;
    in>> d.donneur ;
    return in ;
}
template<typename T>
bool Don<T>::operator<(const Don<T>&p)
{
    if(monnaie<p.monnaie) return 1 ;
    else return 0 ;
}
#endif // DON_H
