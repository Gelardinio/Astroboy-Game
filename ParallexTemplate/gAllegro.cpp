/*****************************************************************************
 * Name:     Mr. Creelman                                                   *
 * Course:   ICS4U                                                           *
 * Date:     August 2016                                                     *
 *
   File     gAllegro.cpp	                                                *
 * Purpose: Initialize Allegro,                       *
 *	                                                                         *
 * *	                                                                    *
 * Revision History:                                                        *
 *	                                                                         *
 * Known Issues: Does more than it needs to,                               *
 *****************************************************************************/
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

// while global variables are discouraged, these variables are okay
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_FONT *arial;
extern ALLEGRO_EVENT_QUEUE *event_queue;

// initial all the allegro components
bool initializeAllegro(int width, int height, const char title[]) {

    const float FPS = 16;			// set frame rate
    ALLEGRO_COLOR background = al_map_rgb(255, 255, 255);       // make background white.

    // Initialize Allegro
	al_init();

	// initialize display
	display = al_create_display(width, height);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return false;
	}
	al_set_window_title(display, title);

   	// Initialize keyboard routines
	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
     	return false;
   	}

	// need to add image processor
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return false;
	}

	//  setup timer
	timer = al_create_timer(1.0 / FPS);
   	if (!timer) {
   		al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
    }


    // Add fonts
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon

    arial = al_load_ttf_font("C:/Windows/Fonts/arial.ttf", 16, 0);
    if (!arial){
       al_show_native_message_box(display, "Error", "Error", "Could not load arial.ttf",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       return false;
    }

    // Initialize primative add on, needed to draw shapes
 	if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return false;
	}

	// Install mouse
 	if (!al_install_mouse()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to install mouse!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return false;
	}

	// set up event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
      	return false;
	}

	// event sources trigger events to check for in our main loop
	al_register_event_source(event_queue, al_get_display_event_source(display));    // look for close box
// 	al_register_event_source(event_queue, al_get_keyboard_event_source());          // look for keystrokes
    al_register_event_source(event_queue, al_get_timer_event_source(timer));	    // register timer events

	al_clear_to_color(background);

	al_flip_display();
	al_start_timer(timer);
	return true;
}

