#include "../game.h"
#include "components.h"

class KeyInputComponent: public Component{
    private:

    public:
        TransformComponent* transform;

        void init() override{
            transform = &entity->getComponent<TransformComponent>();
        }

        void update() override{
            if(game::event.type == SDL_KEYDOWN){
                switch(game::event.key.keysym.sym){
                    case SDLK_w:
                        transform->velocity.y = -1;
                        break;
                    case SDLK_a:
                        transform->velocity.x = -1;
                        break;
                    case SDLK_s:
                        transform->velocity.y = 1;
                        break;
                    case SDLK_d:
                        transform->velocity.x = 1;
                        break;
                    default:
                        break;
                }
            }
            if(game::event.type == SDL_KEYUP){
                switch(game::event.key.keysym.sym){
                    case SDLK_w:
                        transform->velocity.y = 0;
                        break;
                    case SDLK_a:
                        transform->velocity.x = 0;
                        break;
                    case SDLK_s:
                        transform->velocity.y = 0;
                        break;
                    case SDLK_d:
                        transform->velocity.x = 0;
                        break;
                    default:
                        break;
                }
            }
        }
};
