
#include "Resource Perso/personnage.h"

void initperso(personne *p)
{
  // CHARGEMENT DES RESSOURCES LIEES A NOTRE HERO
  char Fichier[50];
  int i;
  for (i = 0; i < 20; i++)
  {
    sprintf(Fichier, "Resource Perso/image/sprite%d.png", i);
    p->sprite[i] = IMG_Load(Fichier);
  }

  p->Vie[0] = IMG_Load("Resource Perso/image/v4.png");
  p->Vie[1] = IMG_Load("Resource Perso/image/v3.png");
  p->Vie[2] = IMG_Load("Resource Perso/image/v2.png");
  p->Vie[3] = IMG_Load("Resource Perso/image/v1.png");

  p->position_vie.x = 5;
  p->position_vie.y = 8;
  // INITIALISATIONS DES POSITIONS DU SCORE ET LE NIVEAU
  p->TEXTE[0].position.x = 850;
  p->TEXTE[0].position.y = 5;
  p->TEXTE[1].position.x = 850;
  p->TEXTE[1].position.y = 30;

  p->etatHub = 3; // CE QUI EQUIVAUT A UNE VIE DE NIVEAU 3 AU DEMARRAGE
  p->score = 0;
  p->level = 1; // A INCREMENTER A LA FIN DE CHAQUE LEVEL

  // INITIALISATIONS DES VARIABLES NECESSAIRE POUR POSITIONNER LE PERSO SUR LE SOL AINSI QUE LE SAUT
  p->etat = ETAT_SOL;
  p->vx = p->vy = 0;
  p->x = 50;
  p->y = 350;
  // INITIALISATIONS DES VARIABLES INDISPENSABLES AU DEPLACEMENT
  p->dx = 0;
  p->vitesse = 0.3;
  p->acceleration = 0;
  // VARIABLES NECESSAIRE
  p->deplacement = -1;
  p->num = 1;
  p->direction = -1;
}

void afficherperso(personne *p, SDL_Surface *screen)
{
  char score[20], level[20];

  TTF_Font *police = NULL;
  SDL_Color couleur = {250, 250, 250};
  police = TTF_OpenFont("Resource Perso/GenBasB.ttf", 30);

  sprintf(score, "SCORE:%d", p->score);
  sprintf(level, "LEVEL:%d", p->level);

  p->TEXTE[0].texte = TTF_RenderText_Blended(police, score, couleur);
  p->TEXTE[1].texte = TTF_RenderText_Blended(police, level, couleur);

  SDL_BlitSurface(p->TEXTE[0].texte, NULL, screen, &p->TEXTE[0].position);
  SDL_BlitSurface(p->TEXTE[1].texte, NULL, screen, &p->TEXTE[1].position);
  SDL_BlitSurface(p->sprite[p->num], NULL, screen, &(p->position_perso));
  SDL_BlitSurface(p->Vie[p->etatHub], NULL, screen, &(p->position_vie));
  TTF_CloseFont(police);

  FILE *f;
  f = fopen("Resource Perso/Score.txt", "w");
  fprintf(f, " %d \n ", p->score);

  fclose(f);
}

void Saute(personne *p, float impulsion)
{
  p->vy = -impulsion;
  p->etat = ETAT_AIR;
}
void deplacerperso(personne *p, Uint32 dt)
{
  p->dx = (0.5 * p->acceleration) * dt * dt + (p->vitesse) * dt; // CALCUL DE LA DISTANCE ENGENDRE

  if (p->deplacement == 1 && p->x < 1300)
  {
    p->x += (p->dx);
    (p->score) += -0.000001 * ((dt) / (p->dx) - 0.000001) + 2;
  }
  else if (p->deplacement == 0 && p->x > 50)
  {
    p->x -= (p->dx);
  }
}

void animerperso(personne *p)
{
  if (p->direction == 0)
  {
    if (p->num >= 5)
      p->num = 1;
    else
      p->num++;
  }
  else if (p->direction == 1)
  {
    if (p->num == 10 || p->num < 6 || p->num > 11)
      p->num = 6;
    else
      p->num++;
  }
  else if (p->direction == 2)
  {
    if (p->num == 13 || p->num < 11 || p->num > 14)
      p->num = 11;
    else
      p->num++;
  }
  else if (p->direction == 3)
  {

    p->num = 16;
  }
  else if (p->direction == 4)
  {

    p->num = 17;
  }
  else
  {
    if (p->num == 15 || p->num < 14 || p->num > 16)
      p->num = 14;
    else
      p->num++;
  }
}

void Updateperso(personne *p, Uint8 *keys)
{
  float impulsion = 6;
  float factgravite = 0.5;
  float factsautmaintenu = 3;

  if (p->etat == ETAT_AIR && (keys[SDLK_UP] || keys[SDLK_z]))
  {
    factgravite /= factsautmaintenu;
  }
  p->vy += factgravite;

  if (p->y > 380)
  {
    p->y = 380;
    if (p->vy > 0)
      p->vy = 0.0f;
    p->etat = ETAT_SOL;
  }

  p->x += p->vx;
  p->y += p->vy;

  p->position_perso.x = p->x;
  p->position_perso.y = p->y;
}

