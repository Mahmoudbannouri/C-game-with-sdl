#ifndef BACKGROUND
#define BACKGROUND

typedef struct
{
    SDL_Surface *back[3];
    SDL_Rect positionBack;
} Background;

//////////////////////////////
void initBackMain(Background *Back);
void initBackNGame(Background *Back);
void initBackSet(Background *Back);

//////////////////////////////
void AfficherMain1(Background Main, SDL_Surface *screen);
// void AfficherMain2(Background Main, SDL_Surface *screen);
void AfficherNGame(Background NGame, SDL_Surface *screen);
void AfficherSet(Background Set, SDL_Surface *screen);

//////////////////////////////
void freeBackMain(Background Back);
void freeBackNGame(Background Back);
void freeBackSet(Background Back);

///
void AfficherMain(Background Main, SDL_Surface *screen);

#endif /* BACKGROUND */
