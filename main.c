
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "interface.h"
#include "support.h"
//#include "fonctions.h"
int
main (int argc, char *argv[])
{
  GtkWidget *window3;
 // wtkWidget *window2;
  
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");


  window3 = create_window3();
  gtk_widget_show (window3);


  gtk_main ();
  return 0;
}
