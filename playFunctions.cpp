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

void play(ALLEGRO_FONT *font){
        // move ball across screen using keyboard.
    int dx = 0;
    int dy = 0;
    int i;
    float time = 0;
    bool jump;
    bool walk = false;
    int frames = 0;
    int mouse_x;
    int mouse_y;

    int show_bbox = false;
	bool doexit = false;

    if (!font){
        al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        doexit = false;
    }

    while (!doexit) {

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            doexit = true;
        }

        // set direction if key pressed
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

            if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE){
                dy = -9;
            }
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_LEFT:
                case ALLEGRO_KEY_A:
                    dx = 3;
                    spriteDirection = 1;
                    walk = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                case ALLEGRO_KEY_D:
                    dx = -3;
                    spriteDirection = 0;
                    walk = true;
                    break;
            }
        }

        // display background and blocks
        if (ev.type == ALLEGRO_EVENT_TIMER) {
            posy += dy;

            switch (collision_x()) {
                case 'l':
                    jump = false;
                    if (dx < 0) {
                        posx += dx;
                    }
                    break;
                case 'r':
                    jump = false;
                    if (dx > 0) {
                        posx += dx;
                    }
                    break;
                default:
                    jump = true;
                    posx += dx;al_play_sample(walks, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                    break;
            }


            switch (collision_y(dy, time + 1)) {
                case 't':
                    jump = false;
                    dy = 0;
                    time = 0;
                    break;
                case 'b':
                    jump = true;
                    dy = 0;
                    time++;
                    posy += time * 0.22;
                    break;
                default:
                    jump = true;
                    time++;
                    posy += time * 0.22;
                    break;
            }

            if (posy >= 690) {
                printf("\nDeath by falling!");
                break;
            }

            frames++;

            if (frames >= 28) {
                frames = 0;
            }

            display_background(2);  // Prints background to screen

            display_structure(3);   // Prints blocks to screen

            display_character(jump, walk, frames / 4);    // Prints character to screen

            display_timer(font);    // Displays timer

            al_flip_display();  // Updates screen
        }
    }

    highscores(display_timer(font), font);
}

