#include "game.h"
#include "SDL_image.h"

class gameObject{
    public:
        gameObject(const char* textureSheet, int x, int y);
        ~gameObject();

        void update();
        void render();

    private:
        int xPos;
        int yPos;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;

};
