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
    nbr_service=l ;

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
    cout<<"Donner le nombre de services :"<<endl ;
    in>>c.nbr_service ;
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

    cout<<"remplir tableau service "<<endl ;

    for (int i=0 ;i<c.nbr_employe;i++)
    {
        string x ;
        Service* q ;
        cout<<"alimentaire ou hebergement ? " <<endl ;
        cin >>x ;
        if(x=="alimentaire")
            q=new Alimentation ;
        else
            q=new Hebergement ;
        q->saisir() ;
        c.serv.push_back(q);
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
int Centre::recherche_pers(int id)
{
        for (int i=0;i<nbr_employe;i++)
        {
            if(id==emp[i]->getid())
            {
                emp[i]->afficher() ;
                return 1 ;
            }
        }


        for (int i=0;i<nbre_total_en_diff;i++)
        {
            if(id==pers[i]->getid())
            {
                pers[i]->afficher() ;
                return 1 ;
            }
        }

    cout<<"il n'y a pas ce personne "<<endl ;
}
 void Centre::ajouter_livraison(livraison h)
 {
     livr.push_back(h) ;
 }
 void Centre::operator+(const livraison& l)
 {
     livr.push_back(l) ;
 }
 float Centre::calcul_budget()
 {
     float s=0 ;
     for (int i=0;i< livr.size();i++)
     {
        s=s+livr[i].getdonmonnaie() ;
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
    cout<<"Donner le nombre de services :"<<endl ;
    out<<c.nbr_service ;
    for(int i=0;i<c.nbre_total_en_diff;i++)
    {
        c.pers[i]->afficher() ;
    }
    cout << "Afficher tableau employee"<<endl ;
    for(int i=0;i<c.nbr_employe ;i++)
    {
        c.emp[i]->afficher() ;
    }

    cout<<"Afficher tableau service "<<endl ;

    for (int i=0 ;i<c.nbr_employe;i++)
    {
       c.serv[i]->afficher();
    }
    cout<<"Afficher tableau don "<<endl ;

    for (int i=0 ;i<c.livr.size();i++)
    {
       out<<c.livr[i];
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
    cout<<"id_centre :"<<endl ;
    in>>c->id_centre ;
    cout<<"nom_centre :"<<endl ;
    in>>c->nom_centre ;
    cout<<"Donner l adresse du centre"<<endl ;
    in>>c->adresse_centre ;
    cout<<"nbre des personnes en difficultes"<<endl ;
    in>>c->nbre_total_en_diff;
    cout<<"nombre de place disponible :"<<endl ;
    in>>c->nbr_dispo ;
    cout<<"Donner le nombre d'employers"<<endl ;
    in>>c->nbr_employe ;
    cout<<"Donner le nombre de services :"<<endl ;
    in>>c->nbr_service ;
    for(int i=0;i<c->nbre_total_en_diff;i++)
    {
        personne_en_difficulte s ;
        personne_en_difficulte*q ;
        cin>>s ;
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
        c->pers.push_back(q) ;
    }
    for(int i=0;i<c->nbre_total_en_diff;i++)
    {
        in>>*(c->pers[i]) ;
    }
    cout << "remplir tableau employee"<<endl ;
    for(int i=0;i<c->nbr_employe ;i++)
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
        c->emp.push_back(q) ;
    }

    cout<<"remplir tableau service "<<endl ;

    for (int i=0 ;i<c->nbr_employe;i++)
    {
        string x ;
        Service* q ;
        cout<<"alimentaire ou hebergement ? " <<endl ;
        cin >>x ;
        if(x=="alimentaire")
            q=new Alimentation ;
        else
            q=new Hebergement ;
        q->saisir() ;
        c->serv.push_back(q);
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
    cout<<"id_centre :"<<endl ;
    out<<c->id_centre<<setw(10) ;
    cout<<"nom_centre :"<<endl ;
    out<<c->nom_centre<<setw(10) ;
    cout<<"Donner l adresse du centre"<<endl ;
    out<<c->adresse_centre <<setw(10);
    cout<<"nbre des personnes en difficultes"<<endl ;
    out<<c->nbre_total_en_diff<<setw(10);
    cout<<"nombre de place disponible :"<<endl ;
    out<<c->nbr_dispo<<setw(10) ;
    cout<<"Donner le nombre d'employers"<<endl ;
    out<<c->nbr_employe<<setw(10) ;
    cout<<"Donner le nombre de services :"<<endl ;
    out<<c->nbr_service<<setw(10) ;
    for(int i=0;i<c->nbre_total_en_diff;i++)
    {
        out<<*(c->pers[i])<<setw(10);
    }
    cout << "Afficher tableau employee"<<endl ;
    for(int i=0;i<c->nbr_employe ;i++)
    {
        out<<*(c->emp[i])<<setw(10) ;
    }

    cout<<"Afficher tableau service "<<endl ;

    for (int i=0 ;i<c->nbr_employe;i++)
    {
      out<< *(c->serv[i])<<setw(10);
    }
    cout<<"Afficher tableau don "<<endl ;

    for (int i=0 ;i<c->livr.size();i++)
    {
       out<<c->livr[i]<<setw(10);
    }
    return out ;
}
