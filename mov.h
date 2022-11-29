void mov(const Uint8 *key, SDL_Rect *a){
   if(key[SDL_SCANCODE_D]){
      a->x += 10;
      SDL_Delay(5);
   }
   else if(key[SDL_SCANCODE_A]){
      a->x -= 10;
      SDL_Delay(5);
   }
}
