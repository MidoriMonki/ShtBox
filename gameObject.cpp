#include "gameObject.h"
#include "textureManager.h"

gameObject::gameObject(const char* textureSheet, int x, int y){
    objTexture = textureManager::loadTexture(textureSheet);

    xPos = x;
    yPos = y;
}


void gameObject::update(){
    xPos++;
    yPos++;

    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
}

void gameObject::render(){
    SDL_RenderCopy(game::renderer, objTexture, &srcRect, &destRect);
    //textureManager::draw(objTexture, srcRect, destRect);
}