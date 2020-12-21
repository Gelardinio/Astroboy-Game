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



 //691 x 1229



#include <stdio.h>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

const float FPS = 60;
const int SCREEN_W = 800;       // screen width
const int SCREEN_H = 690;       // screen height

int posx = 0;
int posy = 525;
int spriteDirection = 0;
int mobDirection = 0;
int mobx = 0;
int moby = 525;

ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_TIMER *timer = nullptr;

struct Image {
    ALLEGRO_BITMAP *bitmap;               // picture
    int x, y;                             // position on screen
    int bbRight, bbLeft, bbTop, bbBottom; // boundary box
};
Image background1[7], background2[6];
Image character;
Image sprite;

void display_background(int level);
void play();
bool imageIndex();
bool loadBitmap(Image &image, const char *filename);
int initialize_allegro();

int main(int argc, char *argv[]){
    // Initializes allegro
    initialize_allegro();

    // Loads all images
    if (!imageIndex()){
        return 1;
    }

    play();

    return 0;
}

void display_background(int level){
    if (level == 1) {
        al_draw_bitmap(background1[0].bitmap, posx, 0, 0);
        al_draw_bitmap(background1[0].bitmap, posx + 1229, 0, 0);

        al_draw_bitmap(background1[1].bitmap, posx * 1.05, 0, 0);
        al_draw_bitmap(background1[1].bitmap, posx * 1.05 + 1229, 0, 0);

        al_draw_bitmap(background1[2].bitmap, posx * 1.1, 0, 0);
        al_draw_bitmap(background1[2].bitmap, posx * 1.1 + 1229, 0, 0);

        al_draw_bitmap(background1[3].bitmap, posx * 1.2, 0, 0);
        al_draw_bitmap(background1[3].bitmap, posx * 1.2 + 1229, 0, 0);

        al_draw_bitmap(background1[4].bitmap, posx * 1.3, 0, 0);
        al_draw_bitmap(background1[4].bitmap, posx * 1.3 + 1229, 0, 0);

        al_draw_bitmap(background1[5].bitmap, posx * 1.5, 0, 0);
        al_draw_bitmap(background1[5].bitmap, posx * 1.5 + 1229, 0, 0);

        al_draw_bitmap(background1[6].bitmap, posx * 1.7, 0, 0);
        al_draw_bitmap(background1[6].bitmap, posx * 1.7 + 1229, 0, 0);

    } else if (level == 2) {

        al_draw_bitmap(background2[0].bitmap, posx * 0.5, 0, 0);
        al_draw_bitmap(background2[0].bitmap, posx * 0.5 + 1229, 0, 0);

        al_draw_bitmap(background2[1].bitmap, posx * 0.7, 0, 0);
        al_draw_bitmap(background2[1].bitmap, posx * 0.7 + 1229, 0, 0);

        al_draw_bitmap(background2[2].bitmap, posx * 1, 0, 0);
        al_draw_bitmap(background2[2].bitmap, posx * 1 + 1229, 0, 0);

        al_draw_bitmap(background2[3].bitmap, posx * 1.2, 0, 0);
        al_draw_bitmap(background2[3].bitmap, posx * 1.2 + 1229, 0, 0);

        al_draw_bitmap(background2[4].bitmap, posx * 1.4, 0, 0);
        al_draw_bitmap(background2[4].bitmap, posx * 1.4 + 1229, 0, 0);

        al_draw_bitmap(background2[5].bitmap, posx * 1.5, 0, 0);
        al_draw_bitmap(background2[5].bitmap, posx * 1.5 + 1229, 0, 0);

    } else if (level = 3) {
        // Code for level 3 background
    }

}

void play(){
        // move ball across screen using keyboard.
    int dx = 0;
    int dy = 0;

    ALLEGRO_BITMAP *frame[10];

    frame[0] = al_load_bitmap("character/jump/Jump__000.png");
    frame[1] = al_load_bitmap("Jump__001.png");
    frame[2] = al_load_bitmap("Jump__002.png");
    frame[3] = al_load_bitmap("Jump__003.png");
    frame[4] = al_load_bitmap("Jump__004.png");
    frame[5] = al_load_bitmap("Jump__005.png");
    frame[6] = al_load_bitmap("Jump__006.png");
    frame[7] = al_load_bitmap("Jump__007.png");
    frame[8] = al_load_bitmap("Jump__008.png");
    frame[9] = al_load_bitmap("Jump__009.png");

    bool doexit = false;

    while (!doexit) {

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            doexit = true;
        }

        // set direction if key pressed
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

            if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE){
                dy = -6;
                    al_draw_bitmap(frame[0], dx, dy, 0);
            }
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_LEFT:
                case ALLEGRO_KEY_A:
                    dx = 2;
                    dy = 0;
                    spriteDirection = 1;
                    break;
                case ALLEGRO_KEY_RIGHT:
                case ALLEGRO_KEY_D:
                    dx = -2;
                    dy = 0;
                    spriteDirection = 0;
                    break;
            }
        }

        // move ball and display for each frame.
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {

            if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE){
                dy = 0;
            }
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_LEFT:
                case ALLEGRO_KEY_A:
                    dx = 0;
                    dy = 0;
                    break;
                case ALLEGRO_KEY_RIGHT:
                case ALLEGRO_KEY_D:
                    dx = 0;
                    dy = 0;
                    break;
            }
        }

            // move ball and display for each frame.
        if (ev.type == ALLEGRO_EVENT_TIMER) {
            posx += dx;
            posy += dy;

            if (posy <= 525){
                posy += 3;
            }

            if (mobx < 300) {
                mobx++;
            }

            display_background(2);
            al_draw_bitmap(character.bitmap, 345, posy, spriteDirection);
            al_draw_bitmap(sprite.bitmap, mobx, 622, mobDirection);
            al_flip_display();
        }

    }

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




    // Returns true is all images were loaded successfully
    return true;
}

bool loadBitmap(Image &image, const char *filename) {
    image.bitmap = al_load_bitmap(filename);
    if (image.bitmap == nullptr) {
        al_show_native_message_box(display, "Error", filename, "Could not load ", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
    }
    return true;
}

int initialize_allegro(){

    // Initialize Allegro
    al_init();

    // initialize display
    display = al_create_display(SCREEN_W, SCREEN_H);
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
        al_show_native_message_box(display, "Error", "Error",
        "Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // Timer setup
    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // set up event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    return 0;
}

