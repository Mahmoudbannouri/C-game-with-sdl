#ifndef TEXT
#define TEXT

typedef struct
{
    SDL_Rect position;
    TTF_Font *font;
    SDL_Surface *surfaceTexte;
    SDL_Color textColor;
    char texte[50];
} Text;

//////////////////////////////
void initText(Text *t);
void freeText(Text A);
void displayText(Text t, SDL_Surface *screen);

#endif /* TEXT */
