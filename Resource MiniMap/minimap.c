#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include <SDL/SDL.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void init_map (minimap *m)
{ m -> map = IMG_Load("minimap2.png");
  m-> minijoueur = IMG_Load("playermap.png");
  m->positionmap.x =250;
  m->positionmap.y =115;
  m->positionminijoueur.x =250;
  m->positionminijoueur.y =85;
}

void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  posJoueurABS.x = 0;
  posJoueurABS.y = 0;
  posJoueurABS.x = posJoueur.x + camera.x;
  posJoueurABS.y = posJoueur.y + camera.y;
  m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+250;
  m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)+85;
}


void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}


void affichertemp (int *temps,SDL_Surface *screen,TTF_Font *police)
{
SDL_Surface *chrono = NULL;
SDL_Rect positionChrono;
SDL_Color couleur = {0,0,0};

int min=0,sec=0;
char texteChrono [10] = "";

positionChrono.x = 250;
positionChrono.y = 50;
(*temps)=SDL_GetTicks();
(*temps)/=1000;
min=((*temps)/60);
sec=(*temps) - (60*min);

sprintf(texteChrono,"%02d:%02d",min,sec);

chrono = TTF_RenderText_Solid(police,texteChrono,couleur);
SDL_BlitSurface(chrono,NULL,screen,&positionChrono);
}



void sauvegarder( int score, char nomjoueur[], char nomfichier[])
{

FILE* fichier = NULL ;
fichier=fopen("nomficher.txt","a+");

if(fichier!=NULL)
{
fprintf(fichier,"  %s :%d \n",nomjoueur,score);
fclose(fichier);
}
}

void meilleur( char nomfichier[], int *score, char nomjoueur[])
{

int auxs=0;
int scord=0;
char aux_nom[30];

FILE *fichier;

fichier=fopen("nomfichier.txt","r+");

if(fichier!=NULL)
{
while(fscanf(fichier,"%s %d",nomjoueur,&scord)!=EOF)
{
if(scord>auxs)
{
*score=scord;
strcpy(nomjoueur,aux_nom);
}
}

fclose(fichier);
}
}

void liberer(minimap *m)
{
SDL_FreeSurface(m->minijoueur);
SDL_FreeSurface(m->map);
}
