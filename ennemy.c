#include "Resource Entite/ennemy.h"
#include "Resource Perso/personnage.h"

void initEnnemi(Ennemi *E)
{
    int i;
    int j;
    char loadR[40];
    char loadL[40];

    E->Spike = NULL;

    E->Enemy[0][0] = NULL;
    E->Enemy[0][1] = NULL;
    E->Enemy[0][2] = NULL;
    E->Enemy[0][3] = NULL;
    E->Enemy[0][4] = NULL;
    E->Enemy[0][5] = NULL;

    E->Enemy[1][0] = NULL;
    E->Enemy[1][1] = NULL;
    E->Enemy[1][2] = NULL;
    E->Enemy[1][3] = NULL;
    E->Enemy[1][4] = NULL;
    E->Enemy[1][5] = NULL;

    for (j = 0; j < 6; j++)
    {
        sprintf(loadL, "Resource Entite/Lmouvment/L%d.png", j);
        E->Enemy[0][j] = IMG_Load(loadL);
    }

    for (i = 0; i < 6; i++)
    {
        sprintf(loadR, "Resource Entite/Rmouvment/R%d.png", i);
        E->Enemy[1][i] = IMG_Load(loadR);
    }

    E->Spike = IMG_Load("Resource Entite/Spike.png");
    E->posSpike.x = 1000;
    E->posSpike.y = 350;

    E->posEnemy.x = 400;
    E->posEnemy.y = 350;
    E->distance = 100;
    E->position_initiale = 100;
    E->num = 0;
    E->direction1 = 1;
}

void animerEnnemi(Ennemi *E)
{
    if (E->num < 5)
    {
        E->num++;
    }
    else
        E->num = 0;
}

void deplacer(Ennemi *E)
{
    if (E->direction1 % 2 == 1)
    {
        if (E->posEnemy.x < E->position_initiale + E->distance)
        {
            E->posEnemy.x += 1;
        }
        else
        { // E.dir=1;
            E->direction1++;
        }
    }
    else if (E->direction1 % 2 == 0)
    { // E.dir=0;
        if (E->posEnemy.x > E->position_initiale)
        {
            E->posEnemy.x -= 1;
        }
        else
        {
            E->direction1++;
        }
    }
}

void afficherEnnemi(Ennemi E, SDL_Surface *screen)
{
    SDL_BlitSurface(E.Enemy[E.direction1 % 2][E.num], NULL, screen, &E.posEnemy);
}

void afficherEnnemi2(Ennemi E, SDL_Surface *screen)
{
    SDL_BlitSurface(E.Spike, NULL, screen, &E.posSpike);
}

int collisionBB(personne p, Ennemi E)
{
    if ((p.position_perso.x + p.sprite[p.num]->w > E.posEnemy.x) && (p.position_perso.x < E.posEnemy.x))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int collisionBB2(personne p, Ennemi E)
{
    if ((p.position_perso.x + p.sprite[p.num]->w > E.posSpike.x) && (p.position_perso.x < E.posSpike.x))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void deplacerIA(Ennemi *e, SDL_Rect posperso)
{
    int dis = 200;
    if (posperso.x < e->posEnemy.x)
        e->direction = 1;
    else if (posperso.x + 100 > e->posEnemy.x)
        e->direction = 2;
    if (e->direction == 1)
    {
        if (((posperso.x + dis) > e->posEnemy.x) && ((e->posEnemy.x - posperso.x) > 100))
        {
            e->posEnemy.x -= 3;
        }
    }
    else if (e->direction == 2)
    {
        if (((posperso.x - e->posEnemy.x) < dis) && ((posperso.x - e->posEnemy.x) < 100))
        {
            e->posEnemy.x += 3;
        }
    }

    /*
    if (e->direction == 1)
    {
        e->direction1 = 0;
    }
    else
    {
        e->direction1 = 1;
    }
    */
    if (e->direction1 != (e->direction + 1) % 2)
    {
        e->direction1 = (e->direction + 1) % 2;
    }
}

void freeEnnemy(Ennemi E)
{
    int i;
    int j;
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 6; i++)
        {
            SDL_FreeSurface(E.Enemy[j][i]);
        }
    }
    SDL_FreeSurface(E.Spike);
}