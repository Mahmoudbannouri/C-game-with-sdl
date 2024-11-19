#ifndef COLLISIONPARFAITE
#define COLLISIONPARFAITE

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "../Resource Perso/personnage.h"

SDL_Color getpixel(SDL_Surface *psurface, int x, int y);
int collisionparfaite(SDL_Surface *psurface, personne S);
void collision(SDL_Surface *psurface, personne *S);
#endif /* COLLISIONPARFAITE */
