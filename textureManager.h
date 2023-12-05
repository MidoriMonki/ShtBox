#include <SDL2/SDL.h>
#include "SDL_image.h"
#include "game.h"

class textureManager{
    public:
        static SDL_Texture* loadTexture(const char* fileName);
        static void draw(SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect destRect);
};