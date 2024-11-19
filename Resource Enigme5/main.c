
#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"

int main()
{

	SDL_Surface *ecran;
	// SDL_Surface *porte[14];

	// SDL_Rect port;

	SDL_Event event;
	Enigme e;
	int boucle = 1;
	int scene = 1;
	Init_Enigme(&e, "Resource Enigme5/questions.txt", "Resource Enigme5/reponses.txt", "Resource Enigme5/vraireponses.txt");

	int Game;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Echec d'initialisation de SDL.\n");
		return 1;
	}
	// SDL_WM_SetIcon(IMG_Load("img/cursor.png"), NULL);
	printf("Bonjour le monde, SDL est initialisé avec succès.\n");
	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	while (boucle == 1)
	{

		boucle = Play_Enigme(&e, ecran, &Game);
	}

	if (Game)
	{
		printf("you win!!!");
		// animerEnigme(porte, &port, ecran);
	}
	else if (!Game)
	{
		// animerEnigmee(porte, &port, ecran);
		printf("you lost!!! %d ", Game);
	}

	// Free_Enigme(&e);
	SDL_Quit();
	exit(0);
	return EXIT_SUCCESS;
	return 0;
}
