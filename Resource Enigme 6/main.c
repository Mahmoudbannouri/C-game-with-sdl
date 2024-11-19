#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "header.h"

int main()
{
    SDL_Surface *screen;
    enigme e;
    e.num_enigme = -1;
    int s, r = 0, run = 1, running = 1, alea;
    char image[30] = "";
    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    while (run)
    {
        int prevt = SDL_GetTicks();
        init_enigme(&e, "enigme.txt");
        afficherEnigme(e, screen);

        running = 1, r = 0;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:

            run = 0;
            break;
        }

        int time = 0;
        r = 0;
        do
        {
            time = (SDL_GetTicks() - prevt) / 1000;
            SDL_BlitSurface(e.anim.spritesheet, &e.anim.clips[e.anim.cliploaded], screen, &e.anim.pos);
            SDL_Flip(screen);
            printf("%d\n", time);

            switch (time)
            {
            case 5:
                animer(&e);
                break;

            case 10:
                animer(&e);
                break;

            case 15:
                animer(&e);
                break;

            case 20:
                animer(&e);
                break;

            case 25:
                animer(&e);
                break;

            case 30:
                animer(&e);
                break;
            }
            r = resolution(&running, &run);

        } while (time <= 30 && (r > 3 || r < 1) && running != 0);
        afficher_resultat(screen, e.reponsevrai, r, &e);

        while (running)
        {

            SDL_WaitEvent(&event);
            switch (event.type)
            {

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    running = 0;
                    break;

                case SDLK_SPACE:
                    running = 0;
                    break;
                }
                break;

            case SDL_QUIT:
                running = 0;
                run = 0;
                break;
            }
        }
    }

    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}
