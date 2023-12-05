#pragma once
#include "components.h"
#include "transformComponent.h"

class SpriteComponent : public Component{
    private:
        TransformComponent* transform;
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;

    public:
        //~SpriteComponent(){}
        SpriteComponent() = default;
        SpriteComponent(const char* path){
            texture = textureManager::loadTexture(path);
        }

        void init() override{
            
            transform = &entity->getComponent<TransformComponent>();
            /*
            srcRect.x = srcRect.y = 0;
            srcRect.w = srcRect.h = 32;
            destRect.x = 200;
            destRect.y = 200;
            destRect.w = destRect.h = 32;
            */
            srcRect.x = srcRect.y = 0;
            srcRect.w = destRect.w = 32;
            srcRect.h = destRect.h = 32;
            destRect.x = destRect.y = 0;
        }

        void update() override{
            destRect.x = (int)transform->position.x;
            destRect.y = (int)transform->position.y;
        }

        void draw() override{
            textureManager::draw(texture, srcRect, destRect);
        }

};