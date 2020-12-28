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
extern Image run[8];
extern Image jump_bitmap;
extern ALLEGRO_SAMPLE *sample;
extern ALLEGRO_SAMPLE *walks;

extern int posx;
extern int posy;
extern int spriteDirection;

char collision_y(int dy, int time) {
    int i;
    for (i = 0; i < 350; i++) {
        if (block[i].x >= 355 && block[i].x <= 455 && block[i].y <= posy + 165 && block[i].y + 15 >= posy) {
            if (dy + time * 0.2 > 0) {
                printf("\n1");
                posy = block[i].y - 165;
            } else {
                posy = block[i].y + 50 + time * 0.22;
            }
            return 't';
        }

        if (block[i].x >= 355 && block[i].x <= 455 && block[i].y <= posy + 165 && block[i].y + 50 >= posy) {
            if (dy + time * 0.2 > 0){

                posy = block[i].y + 50 + time * 0.22;
            }
            return 'b';
        }
    }
    return false;
}

char collision_x() {
    int i;
    for (i = 0; i < 350; i++) {
        if (block[i].y >= posy && block[i].y <= posy + 160 && block[i].x <= 410 && block[i].x >= 345) {
            printf("\nr");
            return 'l'; // returns 'l' if x collision on left side of block
        }

        if (block[i].y >= posy && block[i].y <= posy + 160 && block[i].x <= 470 && block[i].x >= 400) {
            printf("\nl");
            return 'r'; // Returns 'r' if x collision on right side of a block
        }
    }
    return 'n'; // Returns 'n' if no x collision
}
