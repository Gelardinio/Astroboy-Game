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


void mainmenu(ALLEGRO_FONT *font) {

    al_clear_to_color(BACKGROUND);
    al_draw_text(font, text_colour, 385, 270, ALLEGRO_ALIGN_LEFT, "Play");
    al_draw_text(font, text_colour, 345, 320, ALLEGRO_ALIGN_LEFT, "How to Play");
    al_draw_text(font, text_colour, 370, 370, ALLEGRO_ALIGN_LEFT, "Credits");
    al_flip_display();


    int mouse_x;
    int mouse_y;
    bool play = false;

    while(!play) {

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {

            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            if (ev.mouse.button & 1){
                if (380 < mouse_x && 435 > mouse_x && 240 < mouse_y && 290 > mouse_y) {
                    printf("play");
                    break;
                }
            }
        }
    }
}


void highscores(int frame, ALLEGRO_FONT *font) {

    static Player player;
    static Player old[10];
    int i, j;
    int place;
    char headline[30];

    player.score = frame;

    if ((frame / 58) % 60 < 10) {
        sprintf(player.headline, "0%d:0%d", (frame / 3480), (frame / 58) % 60);
    } else {
        sprintf(player.headline, "0%d:%d", (frame / 3480), (frame / 58) % 60);
    }

    al_clear_to_color(BACKGROUND);

    FILE *fptr;
    fptr = fopen("highscore.txt", "r"); // Opens file where high scores are stored

    al_draw_text(font, text_colour, 500, 50, ALLEGRO_ALIGN_LEFT, "Highscores:");


    for (i = 0; i < 10; i++) {
        fscanf(fptr, "%s %d", old[i].name, &old[i].score);
        if ((old[i].score / 58) % 60 < 10) {
            sprintf(old[i].headline, "0%d:0%d", (old[i].score / 3480), (old[i].score / 58) % 60);
        } else {
            sprintf(old[i].headline, "0%d:%d", (old[i].score / 3480), (old[i].score / 58) % 60);
        }
        sprintf(headline, "%d. %3s %s", i + 1, old[i].name, old[i].headline);
        al_draw_text(font, text_colour, 500, (i * 50) + 120, ALLEGRO_ALIGN_LEFT, headline);
    }


    bool higher = false;



    fclose(fptr);

    //printf("\nEnter the first 3 letters of your name");

    al_draw_text(font, text_colour, 10, 300, ALLEGRO_ALIGN_LEFT, player.headline);

    al_flip_display();
}





