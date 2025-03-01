//
// Program ini dibuat untuk bersenang senang bukan untuk serius maupun niru niru wkwk
//

#include <gtk/gtk.h>

// Fungsi untuk menampilkan pesan pada dialog
static void show_message(GtkWindow *parent, const char *message) {
    // Membuat message dialog dengan parent
    GtkWidget *dialog = gtk_message_dialog_new(parent,
                                                 GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                                 GTK_MESSAGE_INFO,
                                                 GTK_BUTTONS_OK,
                                                 "%s", message);
    // Setelah tombol dialog ditekan, dialog akan dihancurkan
    g_signal_connect(dialog, "response", G_CALLBACK(gtk_window_destroy), NULL);
    gtk_window_present(GTK_WINDOW(dialog));
}

// Callback untuk tombol ditekan
static void on_button_clicked(GtkButton *button, gpointer user_data) {
    // Mengambil window utama sebagai parent dialog
    GtkWindow *window = GTK_WINDOW(gtk_widget_get_root(GTK_WIDGET(button)));
    const char *message = (const char *)user_data;
    show_message(window, message);
}

// Fungsi yang dipanggil saat aplikasi diaktifkan
static void activate(GtkApplication *app, gpointer user_data) {
    // Membuat jendela utama
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hack Ramadhan 2025 1445H");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    // Membuat grid sebagai container utama
    GtkWidget *grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);

    // Label judul dengan markup
    GtkWidget *label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), "<span font_desc='15' weight='bold'>HACK RAMADHAN 2025 - Hijriah</span>");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);

    // Membuat checkbox
    const char *options[] = {
        "Fast Time", "Auto Buka", "Auto Sahur", "Hack Pahala", "Anti Haus",
        "Anti Lapar", "Auto Khatam", "Hack Amal", "Anti Nafsu", "Anti Ngantuk"
    };
    GtkWidget *check_buttons[8];
    for (int i = 0; i < 8; i++) {
        check_buttons[i] = gtk_check_button_new_with_label(options[i]);
        gtk_grid_attach(GTK_GRID(grid), check_buttons[i], i % 2, (i / 2) + 1, 1, 1);
    }

    // Entry untuk Nama dan Kota
    GtkWidget *entry_name = gtk_entry_new();
    GtkWidget *entry_city = gtk_entry_new();
    GtkWidget *label_name = gtk_label_new("Nama");
    GtkWidget *label_city = gtk_label_new("Kota");
    gtk_grid_attach(GTK_GRID(grid), label_name, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_name, 1, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_city, 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_city, 1, 6, 1, 1);

    // Tombol utama
    GtkWidget *button_go = gtk_button_new_with_label("GO HACK");
    GtkWidget *button_trial = gtk_button_new_with_label("TRIAL");
    GtkWidget *button_created = gtk_button_new_with_label("CREATED");

    gtk_grid_attach(GTK_GRID(grid), button_go, 0, 7, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button_created, 0, 8, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_trial, 1, 8, 1, 1);

    // Menambahkan event handler untuk tombol
    g_signal_connect(button_go, "clicked", G_CALLBACK(on_button_clicked),
                     "Selamat! Anda telah berhasil 'menghack' Ramadhan.");
    g_signal_connect(button_trial, "clicked", G_CALLBACK(on_button_clicked),
                     "Trial mode: Fitur dibatasi.");
    g_signal_connect(button_created, "clicked", G_CALLBACK(on_button_clicked),
                     "Dibuat oleh Archana Berry.");

    // Menampilkan window utama
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    // Membuat GtkApplication
    GtkApplication *app;
    int status;
    app = gtk_application_new("com.archanaberry.github.hackramadhan", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Menjalankan aplikasi
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
