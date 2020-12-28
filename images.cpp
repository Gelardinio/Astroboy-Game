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

bool loadBitmap(Image &image, const char *filename) {
    image.bitmap = al_load_bitmap(filename);
    if (image.bitmap == nullptr) {
        al_show_native_message_box(display, "Error", filename, "Could not load ", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
    }
    return true;
}

bool imageIndex(){
    int i;
    for (i = 0; i < 7; i++) {
        Image background1[i];
    }

    char background1File[7][30] = {
    "background1/layer1.png",
    "background1/layer2.png",
    "background1/layer3.png",
    "background1/layer4.png",
    "background1/layer5.png",
    "background1/layer6.png",
    "background1/layer7.png"};

    for (i = 0; i < 7; i++) {
        if (!loadBitmap(background1[i], background1File[i])) {
            return false;
        }
    }

    char background2File[6][30] = {
    "background2/layer1.png",
    "background2/layer2.png",
    "background2/layer3.png",
    "background2/layer4.png",
    "background2/layer5.png",
    "background2/layer6.png"};

    for (i = 0; i < 7; i++) {
        if (!loadBitmap(background2[i], background2File[i])) {
            return false;
        }
    }

    if (!loadBitmap(character, "Character/idle.png")) {
        return false;
    }

    if (!loadBitmap(sprite, "Sprites/firesp.png")) {
        return false;
    }

    for (i = 0; i < 150; i++) {
        if (!loadBitmap(block[i], "Sprites/block.png")) {
            return false;
        }
        block[i].x = -10;
        block[i].y = -10;
    }

    if (!loadBitmap(jump_bitmap, "Character/jump.png")) {
        return false;
    }

    if (!loadBitmap(run[0], "Character/Run/Run__000.png")) {
        return false;
    }

    if (!loadBitmap(run[1], "Character/Run/Run__001.png")) {
        return false;
    }

    if (!loadBitmap(run[2], "Character/Run/Run__002.png")) {
        return false;
    }

    if (!loadBitmap(run[3], "Character/Run/Run__003.png")) {
        return false;
    }

    if (!loadBitmap(run[4], "Character/Run/Run__004.png")) {
        return false;
    }

    if (!loadBitmap(run[5], "Character/Run/Run__005.png")) {
        return false;
    }

    if (!loadBitmap(run[6], "Character/Run/Run__006.png")) {
        return false;
    }

    if (!loadBitmap(run[7], "Character/Run/Run__007.png")) {
        return false;
    }

    // Returns true is all images were loaded successfully
    return true;
}

