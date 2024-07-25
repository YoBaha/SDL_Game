#include "bg.h"
void init_bg(bg *bg)
{
bg->pos.x=0;
bg->pos.y=0;
bg->pos_entite.x=-1000;
bg->pos_entite.y=20;
char ch[50];
bg->entite = IMG_Load("entite.png");
bg->background = IMG_Load("bg3.png");
bg->m = IMG_Load("masque.png");//test bg m n
bg->pos.w=bg->background->w;
bg->pos.h=bg->background->h;
bg->pos_entite.w=bg->entite->w;
bg->pos_entite.h=bg->entite->h;
}
void scrolling(bg *bg,int d,int pas)
{//scroll v h 
if(d==1) bg->pos.x+=pas;
if(d==2) bg->pos.y+=pas;
}
void bg_in_borders(bg *bg,SDL_Surface *screen) 
{//borders lim
if(bg->pos.x>0) bg->pos.x=0;
if(bg->pos.y>0) bg->pos.y=0;
if(screen->w-bg->pos.x>bg->pos.w) bg->pos.x=screen->w-bg->pos.w;
if(screen->h-bg->pos.y>bg->pos.h) bg->pos.y=screen->h-bg->pos.h;
}
void afficher_bg(bg bg,SDL_Surface *screen)
{
SDL_BlitSurface(bg.background,NULL,screen,&bg.pos);
SDL_BlitSurface(bg.entite,NULL,screen,&bg.pos_entite);
}
void animation_entite(bg* bg,SDL_Surface *screen)
{
bg->pos_entite.x+=10;
if(bg->pos_entite.x>2*screen->w) if(rand()%70==1) bg->pos_entite.x=-300;
}

void animation_start(bg bg,SDL_Surface *screen)
{
//bg l to up
SDL_Rect pos;pos.x=screen->w+1000;pos.y=0;
SDL_Delay(500);
while(pos.x>10)
{
SDL_BlitSurface(bg.background,NULL,screen,&pos);
pos.x-=10;SDL_Flip(screen);
}
}

void musique()
{
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
   Mix_Music *musique; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
   Mix_PlayMusic(musique, -1);//-1:boucle infinie
}





