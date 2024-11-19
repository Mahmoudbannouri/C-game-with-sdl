#include "Resource Menu/Header/Constantes.h"
#include "Resource Menu/Header/Music.h"

void initMus(Music *M, int *volume)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic(*volume / 2);
    M->music = Mix_LoadMUS("Resource Menu/Musica/son.mp3");
    Mix_PlayMusic(M->music, -1);
    M->bref = Mix_LoadWAV("Resource Menu/Musica/click.wav");
}

void freeMusic(Music M)
{
    Mix_FreeMusic(M.music);
    Mix_FreeChunk(M.bref);
    Mix_CloseAudio();
    Mix_Quit();
}

void volumeUp(int *niv_volume, int *volume)
{
    if (*niv_volume == 5)
    {
        *niv_volume = 6;
        *volume = 16;
        Mix_VolumeMusic(*volume);
    }
    else if (*niv_volume == 6)
    {
        *niv_volume = 7;
        *volume = *volume * 2;
        Mix_VolumeMusic(*volume);
    }
    else if (*niv_volume == 7)
    {
        *niv_volume = 8;
        *volume = *volume * 2;
        Mix_VolumeMusic(*volume);
    }
    else if (*niv_volume == 8)
    {
        *niv_volume = 1;
        *volume = *volume * 2;
        Mix_VolumeMusic(*volume);
    }
}

void volumeDown(int *niv_volume, int *volume)
{
    if (*niv_volume == 1)
    {
        *niv_volume = 2;
        Mix_VolumeMusic(*volume / 2);
        *volume = *volume / 2;
    }
    else if (*niv_volume == 2)
    {
        *niv_volume = 3;
        Mix_VolumeMusic(*volume / 2);
        *volume = *volume / 2;
    }
    else if (*niv_volume == 3)
    {
        *niv_volume = 4;
        Mix_VolumeMusic(*volume / 2);
        *volume = *volume / 2;
    }
    else if (*niv_volume == 4)
    {
        *niv_volume = 5;
        Mix_VolumeMusic(0);
        *volume = 0;
    }
}