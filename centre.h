#ifndef CENTRE_H
#define CENTRE_H
#include "livraison.h"
#include"sdf.h"
#include"medicale.h"
#include "administrateur .h"
#include"alimentation.h"
#include"hebergement.h"
#include <vector>
#include <typeinfo.h>
#include<fstream>
#include<iomanip>
#include<list>
#include<algorithm>
using namespace std;


class Centre
{ int id_centre;
  string nom_centre;
  string adresse_centre;
  float budget_centre;
  int nbre_total_en_diff;
  int nbr_dispo;
  int nbr_employe;
   vector<employee*> emp;
   list<don_livree<float>> livr;
   list<don_livree<float>>::iterator it ;
   vector<personne_en_difficulte*> pers;

    public:
      Centre(int=0,string="",string="" , float=0 , int=0,int=0,int=0,int=0);
        friend istream& operator>>(istream&  ,Centre& ) ;
        friend istream& operator>>(istream&  ,Centre* ) ;
        void ajouter_pers(personne_en_difficulte);
        void ajouter_emp(employee*) ;
        void recherche_pers(int ) ;
        void operator+(const don_livree<float>&) ;
        void ajouter_livraison(don_livree<float>);
        float calcul_budget();
        int supprimer_pers(int ) ;
        friend ostream& operator<<(ostream& ,Centre& ) ;
        friend ostream& operator<<(ostream& ,Centre* ) ;
        static void creer(fstream&) ;
        static void remplir(fstream&) ;
        static void afficher(fstream&) ;

        virtual ~Centre();

};

#endif // CENTRE_H
