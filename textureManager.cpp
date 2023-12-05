#include "textureManager.h"

SDL_Texture* textureManager::loadTexture(const char* texture){
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* meow = SDL_CreateTextureFromSurface(game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return meow;
}

void textureManager::draw(SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect destRect){
    //SDL_RenderCopy(game::renderer, tex, &srcRect, &destRect);
    SDL_RenderCopy(game::renderer, tex, NULL, &destRect);
}