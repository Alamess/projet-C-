#include "centre.h"
Centre::Centre(int a,string b,string c , float s , int e,int f,int g ,int l)
{
    id_centre = a ;
    nom_centre=b ;
    adresse_centre=c ;
    budget_centre=s ;
    nbre_total_en_diff = e ;
    nbr_dispo = f ;
    nbr_employe= g ;
}
istream& operator>>(istream& in ,Centre& c)
{
    cout<<"id_centre :"<<endl ;
    in>>c.id_centre ;
    cout<<"nom_centre :"<<endl ;
    in>>c.nom_centre ;
    cout<<"Donner l adresse du centre"<<endl ;
    in>>c.adresse_centre ;
    cout<<"nbre des personnes en difficultes"<<endl ;
    in>>c.nbre_total_en_diff;
    cout<<"nombre de place disponible :"<<endl ;
    in>>c.nbr_dispo ;
    cout<<"Donner le nombre d'employers"<<endl ;
    in>>c.nbr_employe ;
    for(int i=0;i<c.nbre_total_en_diff;i++)
    {
        personne_en_difficulte s ;
        personne_en_difficulte*q ;
        in>>s ;
        if ((s.getdiff())=="sdf")
            {
                long x;
                string y ;
                cout<<"duree :"<<endl ;
                cin>>x ;
                cout<<"motif :"<<endl ;
                cin>>y ;
                q = new sdf (s.getnom(),s.getprenom(),s.getid(),s.getage(),x,y) ;

            }
        else q= new personne_en_difficulte (s) ;
        c.pers.push_back(q) ;
    }
    cout << "remplir tableau employee"<<endl ;
    for(int i=0;i<c.nbr_employe ;i++)
    {
        string x ;
        employee*q ;
        cout << "administrateur ou medicale ?"<< endl ;
        cin>>x ;
        if(x=="administrateur")
        {
            q=new administrateur ;
        }
        else
        {
            q= new medicale ;
        }
        in>>*q ;
        c.emp.push_back(q) ;
    }
    return in ;
}
void Centre::ajouter_emp(employee* p)
{
    if (typeid(*p)==typeid(administrateur))
    {   employee*q ;
        q=new administrateur(static_cast<const administrateur& >(*p)) ;
        emp.push_back(q) ;

    }
    else if (typeid(*p)==typeid(medicale))
    {   employee*q ;
        q=new medicale(static_cast<const medicale& >(*p)) ;
        emp.push_back(q) ;
    }
    nbr_employe+=1 ;
    }
void Centre::ajouter_pers(personne_en_difficulte s)
{
    if(nbr_dispo!=0)
    {
        personne_en_difficulte*q ;
        if ((s.getdiff())=="sdf")
            {
                long x;
                string y ;
                cout<<"duree :"<<endl ;
                cin>>x ;
                cout<<"motif :"<<endl ;
                cin>>y ;
                q = new sdf (s.getnom(),s.getprenom(),s.getid(),s.getage(),x,y) ;

            }
        else q= new personne_en_difficulte (s) ;
        pers.push_back(q) ;
        nbr_dispo=nbr_dispo-1 ;
        nbre_total_en_diff +=1 ;
    }
    else
        cout<<"il n'y a pas de disponibilite"<<endl ;

}
void Centre::recherche_pers(int id)
{
        personne::rechercher_personne(id) ;
}
 void Centre::ajouter_livraison(don_livree<float> h)
 {
     livr.push_back(h) ;
 }
 void Centre::operator+(const don_livree<float>& l)
 {
     livr.push_back(l) ;
 }
 float Centre::calcul_budget()
 {
     float s=0 ;
     for ( it=livr.begin() ;it!=livr.end();it++)
     {
        s=s+it->getmonnaie() ;
     }
     return s ;
 }
int Centre :: supprimer_pers(int id)
{
        for (int i=0;i<nbr_employe;i++)
        {
            if(id==emp[i]->getid())
            {
                emp.erase(emp.begin()+i);
                nbr_employe-=1;
                return 1 ;

            }
        }


        for (int i=0;i<nbre_total_en_diff;i++)
        {
            if(id==pers[i]->getid())
            {
                pers.erase(pers.begin()+i);
                nbr_dispo+=1;
                nbre_total_en_diff-=1;
                return 1 ;
            }
        }
}

ostream& operator<<(ostream& out ,Centre& c)
{
    cout<<"id_centre :" ;
    out<<c.id_centre<<endl ;
    cout<<"nom_centre :" ;
    out<<c.nom_centre <<endl;
    cout<<"Donner l adresse du centre" ;
    out<<c.adresse_centre <<endl;
    cout<<"nbre des personnes en difficultes" ;
    out<<c.nbre_total_en_diff<<endl;
    cout<<"nombre de place disponible :" ;
    out<<c.nbr_dispo <<endl;
    cout<<"Donner le nombre d'employers" ;
    out<<c.nbr_employe <<endl;
    for(int i=0;i<c.nbre_total_en_diff;i++)
    {
        c.pers[i]->afficher() ;
    }
    cout << "Afficher tableau employee"<<endl ;
    for(int i=0;i<c.nbr_employe ;i++)
    {
        string h ;
        out<<*(c.emp[i]) ;
    }

    cout<<"Afficher tableau don liquide "<<endl ;

    for ( c.it=c.livr.begin() ;c.it!=c.livr.end();c.it++)
    {
        c.livr.sort();
       out<<*(c.it)<<endl;
    }
    cout<<"Afficher tableau don d'Hebergement "<<endl ;
     for(int i=0 ; i<employee::getnbr_Heber();i++)
     {
         out<<employee::getserv()[i]<<endl ;
     }
     cout<<"Afficher tableau don d'Alimentation "<<endl ;
     for(int i=0 ; i<medicale::getnbr_alim();i++)
     {
         out<<medicale::getalim()[i]<<endl ;
     }
     return out ;
}
Centre::~Centre()
{
    //dtor
}
istream& operator>>(istream&in ,Centre*c )
{
    in.seekg(0) ;
    in>>c->id_centre ;
    in>>c->nom_centre ;
    in>>c->adresse_centre ;
    in>>c->nbre_total_en_diff;
    in>>c->nbr_dispo ;
    in>>c->nbr_employe ;
    for(int i=0;i<c->nbre_total_en_diff;i++)
    {
        in>>*(c->pers[i]) ;
    }
    for(int i=0;i<c->nbr_employe ;i++)
    {
        in>>*(c->emp[i]);
    }
     for(int i=0 ; i<employee::getnbr_Heber();i++)
     {
         in>>employee::getserv()[i] ;
     }
     for(int i=0 ; i<medicale::getnbr_alim();i++)
     {
         in>>medicale::getalim()[i] ;
     }
    return in ;

}
void Centre::creer(fstream&f)
{
    f.open("d:\\projet.txt",ios::in | ios::out | ios::trunc) ;
    if(!f.is_open()) exit ;
}
void Centre::remplir(fstream&f)
{
    Centre c ;
    cout <<"ecrire le donner de centre "<<endl ;
    cin >> c ;
    f<<c<<endl ;
}
void Centre::afficher(fstream&f)
{
    Centre c ;
    f.seekg(0) ;
    f>>c ;
    cout<<c<<endl ;
}
ostream& operator<<(ostream& out ,Centre*c)
{
    out<<c->id_centre<<setw(10) ;
    out<<c->nom_centre<<setw(10) ;
    out<<c->adresse_centre <<setw(10);
    out<<c->nbre_total_en_diff<<setw(10);
    out<<c->nbr_dispo<<setw(10) ;
    out<<c->nbr_employe<<setw(10) ;
    for(int i=0;i<c->nbre_total_en_diff;i++)
    {
        out<<*(c->pers[i])<<setw(10);
    }
    for(int i=0;i<c->nbr_employe ;i++)
    {
        out<<*(c->emp[i])<<setw(10) ;
    }
    for ( c->it=c->livr.begin() ;c->it!=c->livr.end();c->it++)
    {
        c->livr.sort();
       out<<*(c->it)<<setw(10);
    }
     for(int i=0 ; i<employee::getnbr_Heber();i++)
     {
         out<<employee::getserv()[i]<<setw(10) ;
     }
     for(int i=0 ; i<medicale::getnbr_alim();i++)
     {
         out<<medicale::getalim()[i]<<setw(10) ;
     }
    return out ;
}

