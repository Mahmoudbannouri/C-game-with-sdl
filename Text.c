#include "Resource Menu/Header/Constantes.h"
#include "Resource Menu/Header/Text.h"

void initText(Text *t)
{
    t->position.x = 410;
    t->position.y = 35;
    t->textColor.r = 0;
    t->textColor.g = 0;
    t->textColor.b = 0;
    t->font = TTF_OpenFont("Resource Menu/Text/pol.ttf", 50);
}
void freeText(Text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}
void displayText(Text t, SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "Welcome", t.textColor);
    SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}