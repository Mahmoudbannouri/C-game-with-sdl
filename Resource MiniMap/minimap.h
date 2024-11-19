#ifndef minimap_H
#define minimao_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct 
{SDL_Surface *map;
SDL_Surface  *minijoueur;
SDL_Rect positionmap;
SDL_Rect positionminijoueur;

}minimap;

/*typedef struct
{
char nomjeur[20];
int score;
}joueur;*/

void init_map (minimap *m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemp (int *temps,SDL_Surface *screen,TTF_Font *police);
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void meilleur( char nomfichier[], int *score, char nomjoueur[]);
void liberer(minimap *m);
#endif

