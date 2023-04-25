#include <iostream>
#include"centre.h"
using namespace std;

int main()
{
    Centre c ;
    int choix;
    while(1)
    {

    cout<<"\t\t\t\t************************************"<<endl;
    cout<<"\t\t\t\t\t\ *\n\t\t\t\t 1- initialiser le centre    \n\t\t\t\t\t\ *\n\t\t\t\t 2- afficher le centre  \n\t\t\t\t\t\ *\n\t\t\t\t  3- chercher personne    \n\t\t\t\t\t\ *\n\t\t\t\t 4- ajouter un employee \n\t\t\t\t\t\ *\n\t\t\t\t 5-ajouter personne en difficulte \n\t\t\t\t\t\ *\n\t\t\t\t  6-ajouter une livraison \n\t\t\t\t\t\ *\n\t\t\t\t 7-supprimer personne \n\t\t\t\t\t\ *\n\t\t\t\t 8- budget   \n\t\t\t\t\t\ *\n\t\t\t\t  0- Exit\t\t\t"<<endl;
    cout<<"\t\t\t\t************************************\n"<<endl;

cout<<"-----> "<<endl;
cin>>choix ;
if (choix==1)
{
    cin>>c ;
}
else if (choix==2){
    cout<<c ;
  }
else if (choix==3){
       int id,v ;
       cout<<"id: " ;
       cin>>id ;
       v=c.recherche_pers(id);

    }
else if (choix==4){
            string y ;
            cout<< "admin ou medical ?"<<endl ;
            cin >>y;
            if(y=="admin")
            {
                employee*e ;
                e=new administrateur ;
                cin>>*e ;
                c.ajouter_emp(e) ;
            }
            else
            {
                employee*e ;
                 e=new medicale ;
                cin>>*e ;
                c.ajouter_emp(e) ;
            }
}
else if (choix==5){
                personne_en_difficulte p ;
                cin>>p ;
                c.ajouter_pers(p) ;
}
else if (choix==6){
        livraison l ;
        cin>> l ;
        c+l ;
}
else if (choix==7){
        int id1 ;
        cin>>id1 ;
        c.supprimer_pers(id1) ;
}
else if (choix==8){
        float s ;
        s=c.calcul_budget() ;
        cout<<"budget :"<<s<<endl ;
}

 else if (choix==0){
    fstream f ;

    Centre::creer(f) ;
    f.seekg(0) ;
    Centre k ;
    cin>>k ;
    f<<&k ;
    }
else if(choix==10)
        exit(0) ;

}
    return 0;
}
