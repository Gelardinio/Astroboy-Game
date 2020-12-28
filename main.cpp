/*****************************************************************************
 *    Name:     Emet Behrendt and Gerlad Liu                                 *
 *    Date:     xxxx due date...                                             *
 *                                                                           *
 *    Purpose: Example 6 - Use a timer, set a frame rate                     *
 *                                                                           *
 *    Usage:   Use arrows keys to change direction of sprite                 *
 *                                                                           *
 *    Revision History: Started on 16/04/18                                  *
 *                                                                           *
 *    Known Issues: N/A                                                      *
 *                                                                           *
 *****************************************************************************/

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

ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_TIMER *timer = nullptr;
ALLEGRO_SAMPLE *sample = NULL;
ALLEGRO_SAMPLE *walks = NULL;

Image background1[7], background2[6];
Image character;
Image sprite;
Image block[350];
Image run[8];
Image jump_bitmap;

int posx = 0;
int posy = 300;
int spriteDirection = 0;

int main(int argc, char *argv[]){
    // Initializes allegro
    initialize_allegro();

    // Loads all images
    if (!imageIndex()){
        return 1;
    }

    ALLEGRO_FONT *font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 36, 0);

    mainmenu(font);

    play(font);

    al_rest(10);

    al_destroy_display(display);

    return 0;
}

