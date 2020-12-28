#include <stdio.h>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "functions.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;

extern Image background1[7], background2[6];
extern Image character;
extern Image sprite;
extern Image block[350];
extern Image jump_bitmap;
extern Image run[8];
extern ALLEGRO_SAMPLE *sample;
extern ALLEGRO_SAMPLE *walks;

extern int posx;
extern int posy;
extern int spriteDirection;

int initialize_allegro(){

    // Initialize Allegro
    al_init();

    al_install_audio();
    al_init_acodec_addon();

    al_reserve_samples(1);

    sample = al_load_sample("fr.wav");

    walks = al_load_sample("boi.wav");

    // initialize display
    display = al_create_display(800, 690);
    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // Adding a display title
    al_set_window_title(display, "Emet Behrendt and Gerald Liu Summative Project");

    // Initialize keyboard routines
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // Image Processer setup
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error","Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // Timer setup
    timer = al_create_timer(1.0 / 58);
    if (!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // set up event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    if (!al_init_font_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize font addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if (!al_init_ttf_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize ttf addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

     if (!al_install_mouse()){
        al_show_native_message_box(display, "Error", "Error",
        "Failed to initialize mouse!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
     }

    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_start_timer(timer);

    return 0;
}
