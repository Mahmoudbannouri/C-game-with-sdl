#ifndef ENIGMESF
#define ENIGMESF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
    SDL_Rect pos;
    SDL_Surface *spritesheet;
    SDL_Rect clips[6];
    int cliploaded;
} animation;

typedef struct
{
    SDL_Surface *img[3];
    SDL_Rect p;
    int reponsevrai;
    int reponsejoueur;
    int num_enigme;
    animation anim;
} enigme;

void init_enigme(enigme *e, char *nomfichier);
void generate_afficher(int *alea);
void afficherEnigme(enigme e, SDL_Surface *screen);
int resolution(int *running, int *run);
void afficher_resultat(SDL_Surface *screen, int s, int r, enigme *en);
void animer(enigme *e);

#endif /* ENIGMESF */
