#ifndef _GETPIXEL_H_
#define _GETPIXEL_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

Uint32 getpixel(SDL_Surface *surface, int x, int y);
int is_black(int x,int y,SDL_Surface *i);

#endif
