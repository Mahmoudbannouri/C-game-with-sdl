menu:main.o Menu.o Music.o tic.o Text.o Buttons.o BackgroundM.o ennemy.o minimap.o background.o collisionparfaite.o EnigmeSF.o personnage.o enigme.o
	gcc main.o Menu.o Music.o tic.o minimap.o Text.o Buttons.o BackgroundM.o ennemy.o background.o collisionparfaite.o EnigmeSF.o personnage.o enigme.o -o menu -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -g
Menu.o:Menu.c
	gcc -c Menu.c -g
Music.o:Music.c
	gcc -c Music.c -g
Text.o:Text.c
	gcc -c Text.c -g
Buttons.o:Buttons.c
	gcc -c Buttons.c -g
BackgroundM.o:BackgroundM.c
	gcc -c BackgroundM.c -g
ennemy.o:ennemy.c
	gcc -c ennemy.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
background.o: background.c 
	gcc -c background.c -g
collisionparfaite.o:collisionparfaite.c 
	gcc -c collisionparfaite.c -g
EnigmeSF.o:EnigmeSF.c 
	gcc -c EnigmeSF.c -g
personnage.o:personnage.c 
	gcc -c personnage.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
tic.o:tic.c
	gcc -c tic.c -g
