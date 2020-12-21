/*
        Add header here
*/
// Motion Parallax
// http://nifty.stanford.edu/2019/dicken-motion-parallax/specification.html
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <windows.h>

#define SKY         al_map_rgb(0x87, 0xce, 0xfa)

using namespace std;

ALLEGRO_DISPLAY *display;
ALLEGRO_TIMER *timer;
ALLEGRO_FONT *arial;
ALLEGRO_EVENT_QUEUE *event_queue;

int initializeAllegro(int width, int height, const char title[]);
void displaySky();
void displayGrass();
void displayFarMountain();
void displayNearMountains();
void displayBirds();

const int screenWidth = 800;
const int screenHeight = 700;

int j;

int main() {

    srand(time(0));

    ALLEGRO_EVENT event;

    if (! initializeAllegro(screenWidth, screenHeight, "Your name Motion Parallax")) {
        printf("Allegro failed to initialize\n");
        return 1;
    }

    bool done = false;

    while (!done) {
       al_wait_for_event(event_queue, &event);

       if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
           done = true;
       }
       else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
           ALLEGRO_KEYBOARD_STATE key_state;
           al_get_keyboard_state(&key_state);
           if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
               done = true;
        }
        else if (event.type == ALLEGRO_EVENT_TIMER) {
            displaySky();
            al_draw_text(arial, al_map_rgb(255, 100, 100), 5, 5, 0, "Gerald Liu: Making the birds go away REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
            displayFarMountain();
            displayNearMountains();
            displayGrass();
            displayBirds();
            al_flip_display();
            j += 10;
        }

    }
    // end of main loop
    return 0;
}

void displaySky() {
    int i;
    i = rand() % 500 + 1;
    al_clear_to_color(SKY);
    al_draw_filled_circle(200,200,200, al_map_rgb(255, 255, 0));
}


void displayGrass() {
     al_draw_filled_rectangle(0, screenHeight-150,  screenWidth, screenHeight, al_map_rgb(0,200,0));
}

void displayNearMountains() {
    int i = rand() % 230 + 200;
    al_draw_filled_triangle(50, 700, 700, 558, 200, 300, al_map_rgb(230, 230, 230));
}

void displayFarMountain() {
   int i = rand() % 230 + 200;
   al_draw_filled_triangle(300, 550, 500, 558, 500, 150, al_map_rgb(240, 240, 240));
}

// five birds flying across screen
void displayBirds() {
    float x1 = 100, y1 = 100;

        for (int i=0; i<5; i++) {
            x1 += 100 + j;
            al_draw_line(x1+i*25, y1+24, x1+i*25+50, y1-15, al_map_rgb(0,0,0), 3);
            al_draw_line(x1+i*25, y1+24, x1+i*25-50, y1-15, al_map_rgb(0,0,0), 3);
        }

        if (x1 > 800) {
            x1 = 100;
        }
}


