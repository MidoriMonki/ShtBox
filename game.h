#pragma once
/*
#ifndef GAME_HPP
#define GAME_HPP
*/
#include <SDL2/SDL.h>
#include <iostream>
#include "SDL_image.h"

class game{

    public:
        game();
        ~game();
        void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();

        static SDL_Renderer* renderer;
        static SDL_Event event;

        bool running() { return isRunning; }

    private:
        bool isRunning;
        SDL_Window* window;
};
/*
#endif
*/
