#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Setup.h"

Setup::Setup()
{
    Window_w = 800;
    Window_h = 640;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Return",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,Window_w,Window_h,SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP );
    //SDL_SetWindowMaximumSize()
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    event = new SDL_Event();
}
void Setup::Update()
{
    SDL_GetWindowSize(window,&w,&h);
}
Setup::~Setup()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete event;
    SDL_Quit();

}
void Setup::Inicio()
{
        SDL_PollEvent(event);

        SDL_RenderClear(renderer);

}
void Setup::Fim()
{
        SDL_RenderPresent(renderer);

}
SDL_Renderer* Setup::Get_Renderer()
{
    return renderer;
}


SDL_Event* Setup::Get_Event()
{
    return event;
}
SDL_Window* Setup::Get_Window()
{
    return window;
}
int Setup::W()
{
    return w;
}
int Setup::H()
{
    return h;
}
