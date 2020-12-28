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

int display_timer(ALLEGRO_FONT *font) {
    static int frame;
    static char time[10];
    frame++;

    if ((frame / 60) % 60 < 10) {
        sprintf(time, "0%d:0%d", (frame / 3480), (frame / 58) % 60);
    } else {
        sprintf(time, "0%d:%d", (frame / 3480), (frame / 58) % 60);
    }

    // Prints time to screen
    al_draw_text(font, text_colour, 10, 10, ALLEGRO_ALIGN_LEFT, time);

    return frame;
}

void display_structure(int level) {
    int i, j;
    if (level == 1) {
        for (i = 0; i < 13; i++) {
            block[i].x = 2.5 * posx + 64 * i;
            block[i].y = 627;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 13; i < 20; i++) {
            block[i].x = 2.5 * posx + 64 * i;
            block[i].y = 627 - (i - 13) * 64;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 20; i < 27; i++) {
            block[i].x = 2.5 * posx + 64 * i;
            block[i].y = 243;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }


        for (i = 27; i < 32; i++) {
            block[i].x = 2.5 * posx + 64 * (i - 20);
            block[i].y = 300;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (j = 0; j < 8; j++) {
            for (i = 32; i < 38; i++) {
                block[i].x = 2.5 * posx + 64 * (i - 21) + (j + 3) * 64;
                block[i].y = 627 - (i - 32) * 64;
                al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
           }
        }

        for (j = 0; j < 5; j++) {
            for (i = 32; i < (37 - j); i++) {
               block[i].x = 2.5 * posx + 64 * (i - 10 + j);
                block[i].y = 627 - (i - 32) * 64;
                al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
            }
        }

        for (j = 0; j < 4; j++) {
            for (i = 37 + (j * 7); i < 44 + (j * 7); i++) {
                block[i].x = 2.5 * posx + 64 * (37 - 10 + 4 + j);
                block[i].y = 627 - (i - (j * 7) - 37) * 64;
                al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
            }
        }

        for (j = 0; j < 4; j++) {
            for (i = 65 + (j * 7); i < 72 + (j * 7); i++) {
                block[i].x = 2.5 * posx + 64 * (37 - 10 + 19 + j);
                block[i].y = 627 - (i - (j * 7) - 65) * 64;
                al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
            }
        }

        for (i = 93; i < 100; i++) {
            block[i].x = 2.5 * posx + 64 * (37 + i - 93);
            block[i].y = 627 - 64 * 3;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 100; i < 103; i++) {
            block[i].x = 2.5 * posx + 64 * (54 + i - 100);
            block[i].y = 627 - 64;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 103; i < 106; i++) {
            block[i].x = 2.5 * posx + 64 * (60 + i - 103);
            block[i].y = 627 - 64 * 4;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 106; i < 109; i++) {
            block[i].x = 2.5 * posx + 64 * (66 + i - 106);
            block[i].y = 627 - 64 * 7;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 109; i < 117; i++) {
            block[i].x = 2.5 * posx + 64 * (70 + i - 109);
            block[i].y = 627 - 64;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 117; i < 121; i++) {
            block[i].x = 2.5 * posx + 64 * (81 + i - 117);
            block[i].y = 627 - 64 * 4;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 121; i < 122; i++) {
            block[i].x = 2.5 * posx + 64 * (90 + i - 121);
            block[i].y = 627 - 64 * 7;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 122; i < 123; i++) {
            block[i].x = 2.5 * posx + 64 * (97 + i - 122);
            block[i].y = 627 - 64 * 2;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 123; i < 145; i++) {
            block[i].x = 2.5 * posx + 64 * (104 + i - 123);
            block[i].y = 627;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }



    } else if (level == 2) {

        for (i = 0; i < 5; i++) {
            block[i].x = 2.5 * posx + 64 * (4 * i) + 832;
            block[i].y = 627 - 64 * i;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 5; i < 9; i++) {
            block[i].x = 2.5 * posx + 64 * i + 768 + 832;
            block[i].y = 627 - 64 * 4;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (j = 0; j < 4; j++) {
            for (i = 9 + (j *5); i < 14 + (j *5); i++) {
                block[i].x = 2.5 * posx + 64 * (i - j * 5) + 448 + 832;
                block[i].y = 627 - 64 * j;
                al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
            }
        }

        for (i = 116; i < 122; i++) {
            block[i].x = 2.5 * posx + 64 * 22 + 832 + (64 * (i - 116));
            block[i].y = 627 - 64;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 29; i < 36; i++) {
            block[i].x = 2.5 * posx + 64 * 29 + 832;
            block[i].y = 627 - 64 * (i - 29);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 39; i < 48; i++) {
            block[i].x = 2.5 * posx + 64 * 34 + 832;
            block[i].y = 627 - 64 * (i - 39);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 48; i < 54; i++) {
            block[i].x = 2.5 * posx + 64 * 39 + 832;
            block[i].y = 627 - 64 * (i - 48);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 54; i < 57; i++) {
            block[i].x = 2.5 * posx + 64 * 44 + 832;
            block[i].y = 627 - 64 * (i - 54);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 70; i < 80; i++) {
            block[i].x = 2.5 * posx + 64 * (48 + i - 70) + 832;
            block[i].y = 627 - 64 * (5);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

         for (i = 80; i < 95; i++) {
            block[i].x = 2.5 * posx - 5120 + 64 * i;
            block[i].y = 627;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 95; i < 115; i++) {
            block[i].x = 2.5 * posx + 64 * (48 + i - 95) + 832 + (20 * 64);
            block[i].y = 627;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 115; i < 116; i++) {
            block[i].x = 2.5 * posx + 64 * (48 + i - 115) + 832 + (15 * 64);
            block[i].y = 627 - (4 * 64);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }



    } else if  (level == 3) {

        for (i = 0; i < 55; i++) {
            block[i].x = 2.5 * posx + 64 * i;
            block[i].y = 627;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 55; i < 57; i++) {
            block[i].x = 2.5 * posx + 64 * (i - 55 + 8);
            block[i].y = 627 - 64;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

         for (i = 57; i < 62; i++) {
            block[i].x = 2.5 * posx + 64 * (9 * (i - 57)) + 896;
            block[i].y = 627 - 64 * (i - 56 + 3);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 62; i < 67; i++) {
            block[i].x = 2.5 * posx + 64 * (9 * (i - 62)) + 3456;
            block[i].y = 627 - 64 * (8) + 64 * (i - 62);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 67; i < 71; i++) {
            block[i].x = 2.5 * posx + 64 * (i - 67) + 6912 - (64 * 5) - 320;
            block[i].y = 627 - 64 * (4 + i - 67);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 71; i < 78; i++) {
            block[i].x = 2.5 * posx + 64 * (i - 71 + 4) + 6912 - (64 * 5) - 320;
            block[i].y = 627 - 64 * (7);
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

        for (i = 78; i < 97; i++) {
            block[i].x = 2.5 * posx + 64 * (i - 80 + 21) + 6912 - 320;
            block[i].y = 627;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

         for (i = 97; i < 98; i++) {
            block[i].x = 2.5 * posx + 64 * (i - 90 + 5) + 6912 - 320;
            block[i].y = 627 - 64 * 3;
            al_draw_bitmap(block[i].bitmap, block[i].x, block[i].y, 0);
        }

    }

}

void display_character(bool jump, bool walk, int frame) {
    if (jump) {
        al_draw_bitmap(jump_bitmap.bitmap, 345, posy, spriteDirection);
    } else if (walk) {
        al_draw_bitmap(run[frame].bitmap, 345, posy, spriteDirection);
    } else {
        al_draw_bitmap(character.bitmap, 345, posy, spriteDirection);
    }
}

void display_background(int level){
    if (level == 1) {
        for (int i = 0; i < 5; i++){
            al_draw_bitmap(background1[0].bitmap, posx + (i * 1229), 0, 0);
            al_draw_bitmap(background1[1].bitmap, posx * 1.05 + (i * 1229), 0, 0);
            al_draw_bitmap(background1[2].bitmap, posx * 1.1 + (i * 1229), 0, 0);
            al_draw_bitmap(background1[3].bitmap, posx * 1.2 + (i * 1229), 0, 0);
            al_draw_bitmap(background1[4].bitmap, posx * 1.3 + (i * 1229), 0, 0);
            al_draw_bitmap(background1[5].bitmap, posx * 1.5 + (i * 1229), 0, 0);
            al_draw_bitmap(background1[6].bitmap, posx * 1.7 + (i * 1229), 0, 0);
        }

    } else if (level == 2) {
        for (int i = 0; i < 5; i++) {
            al_draw_bitmap(background2[0].bitmap, posx * 0.5 + (i * 1229), 0, 0);
            al_draw_bitmap(background2[1].bitmap, posx * 0.7 + (i * 1229), 0, 0);
            al_draw_bitmap(background2[2].bitmap, posx * 1 + (i * 1229), 0, 0);
            al_draw_bitmap(background2[3].bitmap, posx * 1.2 + (i * 1229), 0, 0);
            al_draw_bitmap(background2[4].bitmap, posx * 1.4 + (i * 1229), 0, 0);
            al_draw_bitmap(background2[5].bitmap, posx * 1.5 + (i * 1229), 0, 0);
        }

    } else if (level = 3) {
        // Code for level 3 background
    }

}
