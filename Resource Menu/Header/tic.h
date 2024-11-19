#ifndef ENTETE_H_INCLUDED
#define ENTETE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
int joueur;
SDL_Surface * boxes,*xs,*os;
int tabsuivi[9];
SDL_Rect pos;
int tour;
TTF_Font *font;
SDL_Color couleur;
SDL_Rect postxt;
}tic;
//
void initialisertic(tic *t);

void affichertic(tic t,SDL_Surface *ecran ) ;

int atilganer(int tabsuivi[]);

int minimax(int tabsuivi[],int joueur);

void calcul_coup(int tabsuivi[]);

void Resultat (tic t,SDL_Surface* ecran);

void liberertic(tic t);

#endif // ENTETE_H_INCLUDED
