#ifndef BUTTONS
#define BUTTONS

typedef struct
{
    SDL_Surface *Button1A;
    SDL_Surface *Button1NA;
    SDL_Surface *Button2A;
    SDL_Surface *Button2NA;
    SDL_Surface *Button3A;
    SDL_Surface *Button3NA;

    SDL_Rect Button1_position;
    SDL_Rect Button2_position;
    SDL_Rect Button3_position;

    SDL_Surface *Option;
    SDL_Rect positionOption;

    SDL_Surface *Plus;
    SDL_Surface *plus;
    SDL_Rect positionPlus;

    SDL_Surface *Moins;
    SDL_Surface *moins;
    SDL_Rect positionMoins;

    SDL_Surface *Normal;
    SDL_Surface *FullScreen;
    SDL_Rect positionFullscreen;

    SDL_Surface *Quit;
    SDL_Rect positionQuit;
} Buttons;

//////////////////////////////
void initButMain(Buttons *B);
void initButSet(Buttons *B);

//////////////////////////////
void freeButMain(Buttons B);
void freeButSet(Buttons B);
//////////////////////////////
void AfficherBut1(Buttons B, SDL_Surface *screen, int hover1, int Presses);
void AfficherBut2(Buttons B, SDL_Surface *screen, int hover2, int Presses);
void AfficherBut3(Buttons B, SDL_Surface *screen, int hover3, int Presses);

//////////////////////////////
void AfficherButScreen(Buttons B, SDL_Surface *screen, int *Mode);
void AfficherButQuit(Buttons B, SDL_Surface *screen);
void AfficherButPlus(Buttons B, SDL_Surface *screen);
void AfficherButMoins(Buttons B, SDL_Surface *screen);
void AfficherButOption(Buttons B, SDL_Surface *screen);

#endif /* BUTTONS */
