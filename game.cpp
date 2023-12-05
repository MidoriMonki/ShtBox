#include "game.h"
#include "textureManager.h"
#include "map.h"
#include "Components/components.h"

map* theMap;
SDL_Renderer* game::renderer = nullptr;
SDL_Event game::event;

Manager manager;
auto& newPlayer(manager.addEntity());

game::game(){

}

game::~game(){

}

void game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen){
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"Subsystems Initialised!..."<<std::endl;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        if (window){
            std::cout<<"Window created"<<std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 105, 105, 255, 255);
            std::cout<<"Renderer created"<<std::endl;
        }

        isRunning = true;
    }

    theMap = new map();
    newPlayer.addComponent<TransformComponent>();
    newPlayer.addComponent<KeyInputComponent>();
    newPlayer.addComponent<SpriteComponent>("assets/player.png");
}

void game::handleEvents(){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void game::update(){    
    manager.refresh();
    manager.update(); 
    //newPlayer.getComponent<TransformComponent>().position.Add(Vector2D(1, 1));
    /*std::cout << newPlayer.getComponent<PositionComponent>().x() << std::endl;
    std::cout << newPlayer.getComponent<SpriteComponent>().meow << std::endl;*/
}

void game::render(){
    SDL_RenderClear(renderer);
    theMap->drawMap();
    manager.draw();
    //newPlayer.getComponent<SpriteComponent>().draw();
    //player->render();
    SDL_RenderPresent(renderer);
}

void game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game cleaned"<<std::endl;
}
