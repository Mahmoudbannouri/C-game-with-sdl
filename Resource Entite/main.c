#include "ennemy.h"

int main(int argc, char const *argv[])
{
    SDL_Surface *screen = NULL;
    SDL_Surface *back = NULL;
    SDL_Rect posBack;
    SDL_Event event;
    Ennemi E;
    personne p;
    int die = 0;

    int done = 1;
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    initEnnemi(&E);
    back = IMG_Load("backg.png");
    posBack.x = 0;
    posBack.y = 0;

    while (done)
    {
        SDL_BlitSurface(back, NULL, screen, &posBack);
        afficherEnnemi(E, screen);
        animerEnnemi(&E);
        deplacer(&E);
        deplacerIA(&E, p.position_perso);
        SDL_Flip(screen);
        SDL_Delay(10);
        die = collisionBB(p, E);
        printf("%d\n", E.num);
        if (die == 1)
        {
            // condition du colision
        }

        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            done = 0;
            break;
        }
    }
    SDL_FreeSurface(back);
    freeEnnemy(E);
    SDL_Quit();
    return 0;
}
