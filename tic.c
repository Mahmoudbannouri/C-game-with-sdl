#include <stdio.h>
#include <stdlib.h>
#include "Resource Menu/Header/tic.h"

void initialisertic(tic *t)
{
    int i;
    for (i = 0; i < 9; i++)
        t->tabsuivi[i] = 0;

    t->boxes = SDL_LoadBMP("Resource MiniMap/fond.bmp");
    t->xs = SDL_LoadBMP("Resource MiniMap/xs.bmp");
    t->os = SDL_LoadBMP("Resource MiniMap/os.bmp");
    t->joueur = 1;
    t->tour = 0;
    t->font = TTF_OpenFont("Resource MiniMap/comic.ttf", 40);
    t->couleur.r = 0;
    t->couleur.g = 0;
    t->couleur.b = 0;
    t->postxt.x = 0;
    t->postxt.y = 0;
}

void affichertic(tic t, SDL_Surface *ecran)
{
    int i;
    SDL_BlitSurface(t.boxes, NULL, ecran, NULL);
    for (i = 0; i < 9; i++)
    {
        t.pos.x = 190 * (i % 3);
        t.pos.y = 190 * (i / 3);
        switch (t.tabsuivi[i])
        {
        case -1:
            SDL_BlitSurface(t.xs, NULL, ecran, &t.pos);
            break;
        case 1:
            SDL_BlitSurface(t.os, NULL, ecran, &t.pos);
            break;
        }
    }
}

void Resultat(tic t, SDL_Surface *ecran)
{
    
    char msg[20];
    switch (atilganer(t.tabsuivi))
    {
    case 0:
        strcpy(msg, "NULL");
        break;
    case 1:
        strcpy(msg, "you lost");
        break;
    case -1:
        strcpy(msg, "you win");
    }

    SDL_BlitSurface(TTF_RenderText_Solid(t.font, msg, t.couleur), NULL, ecran, &t.postxt);
    SDL_Flip(ecran);
    SDL_Delay(4000);
}

void liberertic(tic t)
{
    SDL_FreeSurface(t.boxes);
    SDL_FreeSurface(t.xs);
    SDL_FreeSurface(t.os);
}

int atilganer(int tabsuivi[])
{
    
    int lignes_gagnantes[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    int i;
    for (i = 0; i < 8; ++i)
        if (tabsuivi[lignes_gagnantes[i][0]] != 0 &&
            tabsuivi[lignes_gagnantes[i][0]] == tabsuivi[lignes_gagnantes[i][1]] &&
            tabsuivi[lignes_gagnantes[i][0]] == tabsuivi[lignes_gagnantes[i][2]])
            return tabsuivi[lignes_gagnantes[i][2]];
    return 0;
}

int minimax(int tabsuivi[], int joueur)
{
    int gagnant = atilganer(tabsuivi);
    if (gagnant != 0)
        return gagnant * joueur;
    int coup = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; ++i)
    {
        if (tabsuivi[i] == 0)
        {
            tabsuivi[i] = joueur;
            int mmscore = -minimax(tabsuivi, joueur * -1);
            if (mmscore > score)
            {
                score = mmscore;
                coup = i;
            }
            tabsuivi[i] = 0;
        }
    }
    if (coup == -1)
        return 0;
    return score;
}

void calcul_coup(int tabsuivi[])
{
    int coup = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; ++i)
    {
        if (tabsuivi[i] == 0)
        {
            tabsuivi[i] = 1;
            int mmscore = -minimax(tabsuivi, -1);
            tabsuivi[i] = 0;
            if (mmscore > score)
            {
                score = mmscore;
                coup = i;
            }
        }
    }
    tabsuivi[coup] = 1;
}
