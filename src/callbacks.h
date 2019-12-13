#include <gtk/gtk.h>


void
on_buttonAppliquer_clicked (GtkWidget*objet_graphique,gpointer user_data);

void
on_buttonAjouter_clicked (GtkWidget *objet_graphique,gpointer user_data);

void
on_buttonRetour_clicked (GtkWidget*objet_graphique,gpointer user_data);

void 
on_buttonAfficher_clicked (GtkWidget*objet_graphique,gpointer user_data);


void 
on_buttonModifierN_clicked(GtkWidget*objet_graphique,gpointer user_data);

void 
on_buttonModifierVol_clicked(GtkWidget *objet_graphique,gpointer user_data);

void
on_buttonRetourN_clicked(GtkWidget *objet_graphique,gpointer user_data);

void
on_buttonModifierN_clicked(GtkWidget *objet_graphique,gpointer user_data);



void
on_buttonGestionVols_clicked (GtkWidget *objet_graphique,gpointer user_data);

void
on_buttonReservationVols_clicked(GtkWidget *objet_graphique,gpointer user_data);


void
on_buttonRetourP_clicked(GtkWidget *objet_graphique,gpointer user_data);

void
on_buttonRetourMP_clicked(GtkWidget *objet_graphique,gpointer user_data);

void
on_buttonSupprimerVols_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercher_clicked(GtkWidget *objet_graphique,gpointer user_data);

void
on_refresh_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);
