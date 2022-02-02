#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>



// Ouvre simplement une fenêtre avec rien a l'intérieur

int main(int argc, char* argv[]){
	GtkWidget * FenetrePrincipal = NULL; // Crée un Widget
	gtk_init(&argc,&argv); // Initialise la librairie GTK
	FenetrePrincipal = gtk_window_new(GTK_WINDOW_TOPLEVEL); // On crée la fenêtre principal
	g_signal_connect(G_OBJECT(FenetrePrincipal), "delete-event",G_CALLBACK(gtk_main_quit),NULL); // Sur la fenetre principal on verifie la destruction de la fenetre et on execute la fonction gtk_main_quit. Le champ à null est l'argument de la fonction precedement appelé. 

	gtk_widget_show(FenetrePrincipal); // On affiche le widget Fenetre Principal
	gtk_main(); // Crée une boucle quasiment infinie.
	
	return EXIT_SUCCESS;

	return 0;
}
