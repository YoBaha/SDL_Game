#ifndef _BG_H_
#define _BG_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "getpixel.h"
typedef struct{
SDL_Rect pos;
SDL_Rect pos_entite;
SDL_Surface *entite;
SDL_Surface *background;
SDL_Surface *m;//masque test m pas
}bg;

void init_bg(bg *bg);
void afficher_bg(bg bg,SDL_Surface *screen);
void anim_bg(bg *bg);
void scrolling(bg *bg,int d,int pas);
void bg_in_borders(bg *bg,SDL_Surface *screen);
void animation_entite(bg* bg,SDL_Surface *screen);
void animation_start(bg bg,SDL_Surface *screen);
void musique();

#endif
