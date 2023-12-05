#include "game.h"

class map{
    public:
        map();
        ~map();

        void loadMap(int arr[20][25]);
        void drawMap();

    private:
        SDL_Rect srcRect, destRect;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        int mapArray[20][25];

};