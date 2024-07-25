/**
* @file minimap.c
* @brief minimap lib
* @author voidprod
* @version 1.0
* @date Apr 01,2019

*/

#include "minimap.h"
#include "SDL_global_var.h"
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>

void Afficher_Minimap(SDL_Surface * ecran, SDL_Rect posplayer , SDL_Rect posEntite, SDL_Rect poskey1, SDL_Rect poskey2){
    SDL_Rect minimap = {SCREEN_WIDTH/2 - 200 ,SCREEN_HEIGHT / 2 + 270,400,200};
    SDL_Rect positionPlayer;
    SDL_Rect positionEntite;
    SDL_Rect positionKey1;
    SDL_Rect positionKey2;
    
    Uint32 black = SDL_MapRGB(ecran->format, 12, 12, 12);
    Uint32 red = SDL_MapRGB(ecran->format, 255, 12, 14);
    Uint32 purple = SDL_MapRGB(ecran->format, 128,0,128);
    Uint32 gold = SDL_MapRGB(ecran->format, 255,215,8);

    positionPlayer = makeItSmall(minimap,posplayer);
    positionEntite = makeItSmall(minimap,posEntite);
    positionKey2 = makeItSmall(minimap,poskey2);
    positionKey1 = makeItSmall(minimap,poskey1);

    SDL_FillRect(ecran, &minimap, black);
    SDL_FillRect(ecran, &positionEntite, red);
    SDL_FillRect(ecran, &positionPlayer, purple);
    SDL_FillRect(ecran,&positionKey1, gold);
    SDL_FillRect(ecran, &positionKey2, gold);

   
}

SDL_Rect makeItSmall(SDL_Rect minimap, SDL_Rect position){
    SDL_Rect smallPosition;
    smallPosition.x = minimap.x + 400 * position.x / 8000;
    smallPosition.y = minimap.y + 200 * position.y / 8000;
    smallPosition.h = 10;
    smallPosition.w = 10;

    return smallPosition;
}
