#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>


int main(int argc, char ** argv){
	
	GtkWidget * fenetre_principal = NULL;
	
	gtk_init(&argc, &argv);
	
	fenetre_principal =  gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(fenetre_principal), "TT Industries");
	g_signal_connect(G_OBJECT(fenetre_principal),"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	

	gtk_widget_show(fenetre_principal);
	
	gtk_main();	
	return EXIT_SUCCESS;	
}
