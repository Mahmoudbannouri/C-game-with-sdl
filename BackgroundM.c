#include "Resource Menu/Header/Constantes.h"
#include "Resource Menu/Header/Background.h"

void initBackMain(Background *Back)
{
    Back->back[0] = IMG_Load("Resource Menu/MainMenu/background.jpg");
    // Back->back[1] = IMG_Load("Resource Menu/MainMenu/Background2.jpg");
    Back->positionBack.x = 0;
    Back->positionBack.y = 0;
    Back->positionBack.w = SCREEN_W;
    Back->positionBack.h = SCREEN_H;
}
void initBackNGame(Background *Back)
{
    Back->back[1] = IMG_Load("Resource Menu/NewGame/NewGame.jpg");
    Back->positionBack.x = 0;
    Back->positionBack.y = 0;
    Back->positionBack.w = SCREEN_W;
    Back->positionBack.h = SCREEN_H;
}
void initBackSet(Background *Back)
{
    Back->back[2] = IMG_Load("Resource Menu/Settings/Settings.jpg");
    Back->positionBack.x = 0;
    Back->positionBack.y = 0;
    Back->positionBack.w = SCREEN_W;
    Back->positionBack.h = SCREEN_H;
}

void AfficherMain1(Background Main, SDL_Surface *screen)
{
    SDL_BlitSurface(Main.back[0], NULL, screen, &Main.positionBack);
}
/*
void AfficherMain2(Background Main, SDL_Surface *screen)
{
    SDL_BlitSurface(Main.back[1], NULL, screen, &Main.positionBack);
}*/

void AfficherNGame(Background NGame, SDL_Surface *screen)
{
    SDL_BlitSurface(NGame.back[1], NULL, screen, &NGame.positionBack);
}

void AfficherSet(Background Set, SDL_Surface *screen)
{
    SDL_BlitSurface(Set.back[2], NULL, screen, &Set.positionBack);
}

void freeBackMain(Background Back)
{
    SDL_FreeSurface(Back.back[0]);
}
void freeBackNGame(Background Back)
{

    SDL_FreeSurface(Back.back[1]);
}
void freeBackSet(Background Back)
{

    SDL_FreeSurface(Back.back[2]);
}
/////

void AfficherMain(Background Main, SDL_Surface *screen)
{
    SDL_BlitSurface(Main.back[0], NULL, screen, &Main.positionBack);
}
