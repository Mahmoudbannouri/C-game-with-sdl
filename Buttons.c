#include "Resource Menu/Header/Constantes.h"
#include "Resource Menu/Header/Buttons.h"

void initButMain(Buttons *B)
{
    //////////////////////////////
    B->Button1A = IMG_Load("Resource Menu/MainMenu/newgameON.png");
    B->Button1NA = IMG_Load("Resource Menu/MainMenu/newgameOFF.png");

    B->Button2A = IMG_Load("Resource Menu/MainMenu/settingsON.png");
    B->Button2NA = IMG_Load("Resource Menu/MainMenu/settingsOFF.png");

    B->Button3A = IMG_Load("Resource Menu/MainMenu/quitON.png");
    B->Button3NA = IMG_Load("Resource Menu/MainMenu/quitOFF.png");

    B->Button1_position.x = 430;
    B->Button1_position.y = 250;

    B->Button2_position.x = 430;
    B->Button2_position.y = 350;

    B->Button3_position.x = 430;
    B->Button3_position.y = 450;
}
void initButSet(Buttons *B)
{
    //////////////////////////////
    B->Option = IMG_Load("Resource Menu/Settings/Option.png");
    B->positionOption.x = 205;
    B->positionOption.y = 100;
    //////////////////////////////
    B->Moins = IMG_Load("Resource Menu/Settings/Moins.png");
    B->moins = IMG_Load("Resource Menu/Settings/moins.png");
    B->positionMoins.x = 260;
    B->positionMoins.y = 210;
    //////////////////////////////
    B->Plus = IMG_Load("Resource Menu/Settings/Plus.png");
    B->plus = IMG_Load("Resource Menu/Settings/plus.png");
    B->positionPlus.x = 610;
    B->positionPlus.y = 210;
    //////////////////////////////
    B->Normal = IMG_Load("Resource Menu/Settings/Normal.png");
    B->FullScreen = IMG_Load("Resource Menu/Settings/FullScreen.png");
    B->positionFullscreen.x = 410;
    B->positionFullscreen.y = 440;
    //////////////////////////////
    B->Quit = IMG_Load("Resource Menu/Settings/Quit.png");
    B->positionQuit.x = 445;
    B->positionQuit.y = 530;
}

void AfficherBut1(Buttons B, SDL_Surface *screen, int hover1, int Presses)
{
    if (Presses != 1)
    {
        if (hover1 == 1)
        {
            SDL_BlitSurface(B.Button1NA, NULL, screen, &B.Button1_position);
        }
        else if (hover1 == 0)
        {
            SDL_BlitSurface(B.Button1A, NULL, screen, &B.Button1_position);
        }
    }
    else if (hover1 != 0)
    {
        if (Presses != 1)
        {
            SDL_BlitSurface(B.Button1NA, NULL, screen, &B.Button1_position);
        }
        else if (Presses == 1)
        {
            SDL_BlitSurface(B.Button1A, NULL, screen, &B.Button1_position);
        }
    }
}

void AfficherBut2(Buttons B, SDL_Surface *screen, int hover2, int Presses)
{

    if (Presses != 2)
    {
        if (hover2 == 1)
        {
            SDL_BlitSurface(B.Button2NA, NULL, screen, &B.Button2_position);
        }
        else if (hover2 == 0)
        {
            SDL_BlitSurface(B.Button2A, NULL, screen, &B.Button2_position);
        }
    }
    else if (hover2 != 0)
    {
        if (Presses != 2)
        {
            SDL_BlitSurface(B.Button2NA, NULL, screen, &B.Button2_position);
        }
        else if (Presses == 2)
        {
            SDL_BlitSurface(B.Button2A, NULL, screen, &B.Button2_position);
        }
    }
}
void AfficherBut3(Buttons B, SDL_Surface *screen, int hover3, int Presses)
{
    if (Presses != 3)
    {
        if (hover3 == 1)
        {
            SDL_BlitSurface(B.Button3NA, NULL, screen, &B.Button3_position);
        }
        else if (hover3 == 0)
        {
            SDL_BlitSurface(B.Button3A, NULL, screen, &B.Button3_position);
        }
    }
    else if (hover3 != 0)
    {
        if (Presses != 3)
        {
            SDL_BlitSurface(B.Button3NA, NULL, screen, &B.Button3_position);
        }
        else if (Presses == 3)
        {
            SDL_BlitSurface(B.Button3A, NULL, screen, &B.Button3_position);
        }
    }
}

void AfficherButScreen(Buttons B, SDL_Surface *screen, int *Mode)
{
    if (*Mode == 0)
    {
        SDL_BlitSurface(B.Normal, NULL, screen, &B.positionFullscreen);
    }
    else
    {
        SDL_BlitSurface(B.FullScreen, NULL, screen, &B.positionFullscreen);
    }
}
void AfficherButPlus(Buttons B, SDL_Surface *screen)
{
    SDL_BlitSurface(B.plus, NULL, screen, &B.positionPlus);
}
void AfficherButMoins(Buttons B, SDL_Surface *screen)
{
    SDL_BlitSurface(B.moins, NULL, screen, &B.positionMoins);
}
void AfficherButOption(Buttons B, SDL_Surface *screen)
{
    SDL_BlitSurface(B.Option, NULL, screen, &B.positionOption);
}

void freeButMain(Buttons B)
{
    SDL_FreeSurface(B.Button1A);
    SDL_FreeSurface(B.Button1NA);
    SDL_FreeSurface(B.Button2A);
    SDL_FreeSurface(B.Button2NA);
    SDL_FreeSurface(B.Button3A);
    SDL_FreeSurface(B.Button3NA);
}
void freeButSet(Buttons B)
{
    SDL_FreeSurface(B.Option);
    SDL_FreeSurface(B.Moins);
    SDL_FreeSurface(B.moins);
    SDL_FreeSurface(B.Plus);
    SDL_FreeSurface(B.plus);
    SDL_FreeSurface(B.Normal);
    SDL_FreeSurface(B.FullScreen);
    SDL_FreeSurface(B.Quit);
}