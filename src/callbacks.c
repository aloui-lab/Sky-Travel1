#ifdef HAVE_CONFIG_H
#  include <config.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctionvols.h"
#endif



void
on_buttonAjouter_clicked (GtkWidget* objet_graphique,gpointer user_data)

{    
    GtkWidget *FenetreMenuAjout;
    GtkWidget *FenetreMenuAgent;
    FenetreMenuAgent=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(FenetreMenuAgent);
    FenetreMenuAjout=create_MenuAjout();
    gtk_widget_show(FenetreMenuAjout);
}

void
on_buttonRetour_clicked (GtkWidget* objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuAjout;
    GtkWidget *FenetreMenuAgent;
    FenetreMenuAjout=lookup_widget(objet_graphique,"MenuAjout");
    gtk_widget_destroy(FenetreMenuAjout);
    FenetreMenuAgent=create_MenuAgents();
    gtk_widget_show(FenetreMenuAgent);
    
}

void on_buttonAppliquer_clicked (GtkWidget* objet_graphique,gpointer user_data)
{

GtkWidget *JourDep;
GtkWidget *MoisDep;
GtkWidget *AnneeDep;
GtkWidget *ComboboxDestination;
GtkWidget *ComboboxDepart;
GtkWidget *ComboboxClass;
GtkWidget *PPrix;
GtkWidget *outputMsg;
char Depart[30],Destination[30],Class[30],Msg[30];
Date Dt;
int Prix,verif;
JourDep=lookup_widget(objet_graphique,"spinbuttonJourDepart");
MoisDep=lookup_widget(objet_graphique,"spinbuttonMois");
AnneeDep=lookup_widget(objet_graphique,"spinbuttonAnnee");
PPrix=lookup_widget(objet_graphique,"spinbuttonPrix");
ComboboxDestination=lookup_widget(objet_graphique,"comboboxDestination");
ComboboxDepart=lookup_widget(objet_graphique,"comboboxDepart");
ComboboxClass=lookup_widget(objet_graphique,"comboboxClass");
outputMsg=lookup_widget(objet_graphique,"labelMsg");

Dt.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourDep));
Dt.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisDep));
Dt.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeDep));
Prix=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(PPrix));

strcpy(Depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDepart)));
strcpy(Destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDestination)));
strcpy(Class,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxClass)));

verif= verifier(Depart,Destination);

switch(verif)
    
{
    case 0: strcpy(Msg,"Donnée invalide");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
    case 1:
    AjoutVol(Depart,Destination,Dt.Jour,Dt.Mois,Dt.Annee,Prix,Class);    
    strcpy(Msg,"Ajout Réussi");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
}
}

void on_buttonAfficher_clicked (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *treeviewVols;
treeviewVols=lookup_widget(objet_graphique,"treeviewListeVols");
AfficherVol(treeviewVols);
}

void on_buttonModifierVol_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    
    GtkWidget *FenetreMenuModifier;
    GtkWidget *FenetreMenuAgent;
    GtkWidget *Selection;
    GtkWidget *outputNotification;
    int test;
    char choix[30],Msg[30];
    Selection=lookup_widget(objet_graphique,"entrySelection");
    strcpy(choix,gtk_entry_get_text(GTK_ENTRY(Selection)));
    outputNotification=lookup_widget(objet_graphique,"labelNotification");
    test=verifier_selection(choix);
    if(test==0)
    {
    Volselectionner(choix);
    FenetreMenuAgent=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(FenetreMenuAgent);
    FenetreMenuModifier=create_MenuModifier();
    gtk_widget_show(FenetreMenuModifier);
    }
    else
    {
    strcpy(Msg,"Vols n'existe pas");
    gtk_label_set_text(GTK_LABEL(outputNotification),Msg);
    }

}
void
on_buttonRetourN_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    
    GtkWidget *FenetreMenuModifier;
    GtkWidget *FenetreMenuAgent;
    FenetreMenuModifier=lookup_widget(objet_graphique,"MenuModifier");
    gtk_widget_destroy(FenetreMenuModifier);
    FenetreMenuAgent=create_MenuAgents();
    gtk_widget_show(FenetreMenuAgent);
}

void
on_buttonModifierN_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *JourModif;
GtkWidget *MoisModif;
GtkWidget *AnneeModif;
GtkWidget *ComboboxDestinationModif;
GtkWidget *ComboboxDepartModif;
GtkWidget *ComboboxClassModif;
GtkWidget *PrixModif;
GtkWidget *outputMsg;

char DepartM[30],DestinationM[30],ClassM[30],Msg[30],choix[30],chjour[30],chmois[30],channee[30],chprix[30];
Date Dt;
int PrixM,verif;
FILE *g;
JourModif=lookup_widget(objet_graphique,"spinbuttonJoursM");
MoisModif=lookup_widget(objet_graphique,"spinbuttonMoisM");
AnneeModif=lookup_widget(objet_graphique,"spinbuttonAnneeM");
PrixModif=lookup_widget(objet_graphique,"spinbutton1");
ComboboxDestinationModif=lookup_widget(objet_graphique,"comboboxDestinationM");
ComboboxDepartModif=lookup_widget(objet_graphique,"comboboxDepartM");
ComboboxClassModif=lookup_widget(objet_graphique,"comboboxClassM");
outputMsg=lookup_widget(objet_graphique,"labelMsgM");

Dt.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourModif));
Dt.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisModif));
Dt.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeModif));
PrixM=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(PrixModif));
sprintf(chjour,"%d",Dt.Jour);
sprintf(chmois,"%d",Dt.Mois);
sprintf(channee,"%d",Dt.Annee);
sprintf(chprix,"%d",PrixM);
g=fopen("volselectionner.txt","r");
if(g!=NULL)
 {
while(fscanf(g,"%s\n",choix)!=EOF);
fclose(g);
 }
strcpy(DepartM,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDepartModif)));
strcpy(DestinationM,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDestinationModif)));
strcpy(ClassM,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxClassModif)));
verif= verifier(DepartM,DestinationM);
switch(verif)
{
    case 0: strcpy(Msg,"Donnée invalide");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
    case 1:
    modifier(choix,DepartM,DestinationM,chjour,chmois,channee,chprix,ClassM);    
    strcpy(Msg,"Modification Réussi");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
}

}



void
on_buttonGestionVols_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuPrincipale;
    GtkWidget *FenetreMenuAgents;
    FenetreMenuPrincipale=lookup_widget(objet_graphique,"MenuPrincipale");
    gtk_widget_destroy(FenetreMenuPrincipale);
    FenetreMenuAgents=create_MenuAgents();
    gtk_widget_show(FenetreMenuAgents);

}


void
on_buttonReservationVols_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    
GtkWidget *FenetreMenuPrincipale;
GtkWidget *FenetreMenuReservation;
FenetreMenuPrincipale=lookup_widget(objet_graphique,"MenuPrincipale");
gtk_widget_destroy(FenetreMenuPrincipale);
FenetreMenuReservation=create_MenuResrvation();
gtk_widget_show(FenetreMenuReservation); 

}


void
on_buttonRetourP_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuPrincipale;
    GtkWidget *FenetreMenuAgents;
    FenetreMenuAgents=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(FenetreMenuAgents);
    FenetreMenuPrincipale=create_MenuPrincipale();
    gtk_widget_show(FenetreMenuPrincipale);
}


void
on_buttonRetourMP_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *FenetreMenuPrincipale;
GtkWidget *FenetreMenuReservation;
FenetreMenuReservation=lookup_widget(objet_graphique,"MenuResrvation");
gtk_widget_destroy(FenetreMenuReservation);
FenetreMenuPrincipale=create_MenuPrincipale();
gtk_widget_show(FenetreMenuPrincipale); 
}


void
on_buttonSupprimerVols_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *input1;
        GtkWidget *MenuAgents;
        GtkWidget *treeview;
        
        input1=lookup_widget(button,"entrySelection");
        
        SupprimerVol(gtk_entry_get_text(GTK_ENTRY(input1)));
         MenuAgents=lookup_widget(button,"MenuAgents");
        MenuAgents=create_MenuAgents();   
        gtk_widget_show (MenuAgents);
        treeview=lookup_widget(MenuAgents,"treeviewListeVols");
        AfficherVol(treeview);
        MenuAgents = lookup_widget(button,"MenuAgents");
        gtk_widget_destroy(MenuAgents);

}



void
on_buttonRechercher_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
char IdVols[20];
GtkWidget *input20;
GtkWidget *treeview1;
input20=lookup_widget(objet_graphique,"entryrech");
strcpy(IdVols,gtk_entry_get_text(GTK_ENTRY(input20)));

treeview1 = lookup_widget(objet_graphique,"treeviewListeVols");
AfficherVolrecherche(treeview1,IdVols);
}


void
on_refresh_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *MenuAgents;
    MenuAgents=create_MenuAgents();
    gtk_widget_show(MenuAgents);
    MenuAgents=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(MenuAgents);
}

