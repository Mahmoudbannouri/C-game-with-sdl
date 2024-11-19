
#include "Resource Menu/Header/Constantes.h"
#include "Resource Menu/Header/Music.h"
#include "Resource Menu/Header/Text.h"
#include "Resource Menu/Header/Buttons.h"
#include "Resource Menu/Header/Menu.h"
#include "Resource Menu/Header/Background.h"

int main(int argc, char *args[])
{
    /////////////////////////////

    SDL_Surface *screen = NULL;
    SDL_Event event;
    int continuer = 3;
    int hover1 = 1;
    int hover2 = 1;
    int hover3 = 1;
    int Presses = 5;
    int Mode = 0;
    int i, j;
    int volume = 128;
    int niv_volume = 1;
    Buttons B;
    Text t;
    Music M;
    Background Main;
    /////////////////////////////
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Game Menu", NULL);
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    /////////////////////////////
    initMus(&M, &volume);
    /////////////////////////////
    initButMain(&B);
    /////////////////////////////
    initBackMain(&Main);
    initText(&t);
    /////////////////////////////

    SDL_EnableKeyRepeat(0, 0);
    while (continuer)
    {

        AfficherMain(Main, screen);
        displayText(t, screen);
        AfficherBut1(B, screen, hover1, Presses);
        AfficherBut2(B, screen, hover2, Presses);
        AfficherBut3(B, screen, hover3, Presses);
        SDL_Flip(screen);
        hover1 = 1;
        hover2 = 1;
        hover3 = 1;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_j:
                Mix_PlayChannel(-1, M.bref, 0);
                NewGame(screen, &Mode);
                break;
            case SDLK_s:
                Mix_PlayChannel(-1, M.bref, 0);
                Settings(screen, &Mode, &niv_volume, &volume);
                break;
            case SDLK_UP:
                Presses = Presses % 3 - 1;
                if (Presses == 0)
                    Presses = 3;
                if (Presses == -1)
                    Presses = 2;

                SDL_Delay(100);
                break;
            case SDLK_DOWN:
                Presses = Presses % 3 + 1;

                SDL_Delay(100);
                break;
            case SDLK_SPACE:
                switch (Presses)
                {
                case 1:
                    NewGame(screen, &Mode);
                    break;
                case 2:
                    Settings(screen, &Mode, &niv_volume, &volume);
                    break;
                case 3:
                    continuer = 0;
                    break;
                }
                break;
            }
            break;

        case SDL_MOUSEMOTION:
            if (event.motion.x > 430 && event.motion.x < 580 && event.motion.y > 250 && event.motion.y < 291)
            {
                hover1 = 0;
                Presses = 5;
                Mix_FadeInChannel(-1, M.bref, 0, 0);
            }
            else if (event.motion.x > 430 && event.motion.x < 580 && event.motion.y > 350 && event.motion.y < 391)
            {
                hover2 = 0;
                Presses = 5;
                Mix_FadeInChannel(-1, M.bref, 0, 0);
            }
            else if (event.motion.x > 430 && event.motion.x < 580 && event.motion.y > 450 && event.motion.y < 491)
            {
                hover3 = 0;
                Presses = 5;
                Mix_FadeInChannel(-1, M.bref, 0, 0);
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (event.button.x > 430 && event.button.x < 580 && event.button.y > 250 && event.button.y < 291)
                {
                    NewGame(screen, &Mode);
                }
                else if (event.button.x > 430 && event.button.x < 580 && event.button.y > 350 && event.button.y < 391)
                {
                    Settings(screen, &Mode, &niv_volume, &volume);
                }
                else if (event.button.x > 430 && event.button.x < 580 && event.button.y > 450 && event.button.y < 491)
                {
                    continuer = 0;
                    break;
                }
            }
            break;
        }
    }
    freeBackMain(Main);
    freeButMain(B);
    freeText(t);
    freeMusic(M);
    TTF_CloseFont(t.font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
