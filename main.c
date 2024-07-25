#include "bg.h"

int mouvement_horizontal(){
Uint8 *keystate = SDL_GetKeyState(NULL);
if ( keystate[SDLK_RIGHT] )
return -5;
if ( keystate[SDLK_LEFT] )
return 5;
}
int mouvement_vertical(){
Uint8 *keystate = SDL_GetKeyState(NULL);
if ( keystate[SDLK_DOWN] )
return -5;
if ( keystate[SDLK_UP] )
return 5;
}

void quit(int *q)
{
Uint8 *keystate = SDL_GetKeyState(NULL);
if ( keystate[SDLK_ESCAPE] ) (*q)=1;
}

void main()
{
bg bg;
init_bg(&bg);
SDL_Init(SDL_INIT_EVERYTHING);
srand( time( NULL ) );
SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);
SDL_WM_SetCaption("SUPER TOUNSI !!!  ", NULL);
SDL_Surface *screen =SDL_SetVideoMode(1000,800,32,SDL_SWSURFACE);
int q=0;
animation_start(bg,screen);
musique();
while(q==0)
{
SDL_PumpEvents();
quit(&q);
scrolling(&bg,2,mouvement_vertical());
scrolling(&bg,1,mouvement_horizontal());
bg_in_borders(&bg,screen);
afficher_bg(bg,screen);
animation_entite(&bg,screen);
SDL_Flip(screen);
}
}



