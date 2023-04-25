#ifndef DON_H
#define DON_H
#include"benevole.h"

class Don
{
    int id_don ;
    float monnaie ;
    benevole donneur ;
    public:
        Don();
        friend istream& operator>>(istream&,Don&) ;
        friend ostream& operator<<(ostream&  ,Don& );
        float getmonnaie() {return monnaie;} ;
        virtual ~Don();

    protected:

    private:
};

#endif // DON_H
