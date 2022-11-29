#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "mov.h"

#define SPRITE 48
#define FPS 60

int main(){
   /*Gestione Frame #1*/
   int frameDelay = 1000/FPS;
   Uint32 frameStart;
   int frameTime;
   const Uint8 *key = SDL_GetKeyboardState(NULL);

   SDL_Window *w;
   SDL_Renderer *r;
   SDL_Texture *p1, *lv0, *scala;
   SDL_Rect a, b, c;
   SDL_Event e;

   SDL_Init(SDL_INIT_EVERYTHING);

   a.x = 80, a.y = 470;
   a.w = SPRITE, a.h = SPRITE;

   b.x = b.y = 0;
   b.w = 3200, b.h = 600;

   c.x = 1230, c.y = 460;
   c.w = SPRITE, c.h = 96;

   w = SDL_CreateWindow(
   "Demo",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
   800, 600, SDL_WINDOW_OPENGL);

   r = SDL_CreateRenderer(
   w, -1, SDL_RENDERER_ACCELERATED);

   p1 = IMG_LoadTexture(r, "texture/p1.png");
   lv0 = IMG_LoadTexture(r, "texture/lv0.png");
   scala = IMG_LoadTexture(r, "texture/scala.png");

   SDL_SetRenderDrawColor(r, 255, 255, 255, 255);

   while(1){
      SDL_PollEvent(&e);

      if(e.type == SDL_QUIT)
         break;
      else if(e.key.keysym.sym == SDLK_ESCAPE)
         break;

      mov(key, &a);

      if(a.x > 400){
         a.x = 400;
         b.x -= 10;
         SDL_Delay(5);
      }
      else if(a.x < 0){
         a.x = 0;
         b.x += 10;
         SDL_Delay(5);
      }

      /*Gestione Frame #2*/
      frameStart = SDL_GetTicks();
      frameTime = SDL_GetTicks() - frameStart;
      if(frameDelay > frameTime){
         SDL_Delay(frameDelay - frameTime);
      }

      SDL_RenderClear(r);
      SDL_RenderCopy(r, lv0, NULL, &b);
      SDL_RenderCopy(r, p1, NULL, &a);
      SDL_RenderCopy(r, scala, NULL, &c);    
      SDL_RenderPresent(r);

      //printf("b.x: %4d\ta.y: %4d\n", b.x, a.y);
   }

   SDL_DestroyWindow(w);
   SDL_DestroyRenderer(r);
   SDL_Quit();
   return 0;
}

