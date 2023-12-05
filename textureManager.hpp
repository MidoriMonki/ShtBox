#include <SDL2/SDL.h>

class textureManager{
    public:
        static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer renderer);
};