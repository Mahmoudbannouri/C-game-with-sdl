#ifndef MUSIC
#define MUSIC

typedef struct
{
    Mix_Music *music;
    Mix_Chunk *bref;
} Music;

void initMus(Music *M, int *volume);
void freeMusic(Music M);
void volumeUp(int *niv_volume, int *volume);
void volumeDown(int *niv_volume, int *volume);

#endif /* MUSIC */
