#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "collisionparfaite.h"
#include "background.h"

/**
 *@file main.c
 *@brief testing program.
 *@author wided
 *@version 0.1
 *@date apr 24,2022
 *
 *testing program for background scrolling
 *
 */


int main(void)
{	
	int continuer=1;
	SDL_Surface *screen=NULL,*screen2;
	background ba,bm;
	Personne perso;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	screen=SDL_SetVideoMode(1360,765,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
		
	initialisation_back(&ba);//initback
	initBackMasque(&bm);//pour la collision parfaite
	

	initialiserperso(&perso);
	

	while (continuer)
	{		
		deplacer_perso(&perso,event);
		afficheBack(bm,screen);
 		collision(screen,&perso);
		SDL_PollEvent(&event);
     	switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			case SDLK_RIGHT:
			 
			if ( collisionparfaite(screen,perso)==10){
				//scrolling(&ba,2);	//scrollingymin;	
				scrolling(&bm,0);
			}
					
                        break;
                        case SDLK_LEFT:
                    
                       if ( collisionparfaite(screen,perso)==10){
				//scrolling(&ba,1);//scrolllingysar;
				scrolling(&bm,1);
			}			
		 
                        break;
			 case SDLK_UP:
			 
		  		if ( collisionparfaite(screen,perso)==10){
					//scrolling(&ba,4);	//scrollingymin;	
					scrolling(&bm,4);
				}			 
                        break;
 			 case SDLK_DOWN:
 			 
 		  		if ( collisionparfaite(screen,perso)==10){
					//scrolling(&ba,5);	//scrollingymin;	
					scrolling(&bm,5);
				}			 
                        break;
                          case SDLK_d:
                               if ( collisionparfaite(screen,perso)==10)
                                      scrolling(&ba,2);
                        break;
                           case SDLK_q:
                               if ( collisionparfaite(screen,perso)==10)
                                      scrolling(&ba,3);
                        break;
                           case SDLK_z:
                               if ( collisionparfaite(screen,perso)==10)
                                      scrolling(&ba,6);
                        break;
                           case SDLK_s:
                               if ( collisionparfaite(screen,perso)==10)
                                      scrolling(&ba,7);
                        break;


	
      		 }
      		 	
            break;
       

 	} 		animerBackground(&ba);	
			afficheBack2(ba,screen);
	
			afficher_perso(screen,perso);	
			SDL_Flip(screen);
			SDL_Delay(100);
	}

	
	SDL_Quit();

	return 1;
}
