#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"

//to build this shit: g++ -std=c++11 moew.cpp game.cpp map.cpp gameObject.cpp textureManager.cpp -o play -I include -L lib -l SDL2_image -l SDL2-2.0.0
// to go back a file->  "../fileName",    and to enter a file-> "fileName/otherFileName"

game* theGame= nullptr;

int main(/*int argc, char *argv[]*/){
    
    const int fps = 60;
    const int frameDelay = 1000/fps;

    Uint32 frameStart;
    int frameTime;

    theGame= new game();
    theGame->init("meow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while(theGame->running()){

        frameStart = SDL_GetTicks();
        
        theGame->handleEvents();
        theGame->update();
        theGame->render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }

    theGame->clean();

    /*SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 120, 200, 50, 255);
    SDL_Event event;
    SDL_PollEvent(&event);
    
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);
    */

    return 0;
}