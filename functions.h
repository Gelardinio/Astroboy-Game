#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#define text_colour al_map_rgb(0xdd, 0xdd, 0xdd)
#define BACKGROUND al_map_rgb(0x09, 0x31, 0x45)

struct Image {
    ALLEGRO_BITMAP *bitmap;               // picture
    int x, y;                             // position on screen
    int bbRight, bbLeft, bbTop, bbBottom; // boundary box
};

struct Player {
    char name[10];
    int score;
    char headline[20];
};

void display_background(int level);
void play(ALLEGRO_FONT *font);
bool imageIndex();
bool loadBitmap(Image &image, const char *filename);
int initialize_allegro();
void display_structure(int level);
void display_character(bool jump, bool walk, int frame);

char collision_y(int dy, int time);
char collision_x();

int display_timer(ALLEGRO_FONT *font);

void highscores(int score, ALLEGRO_FONT *font);
void mainmenu(ALLEGRO_FONT *font);




