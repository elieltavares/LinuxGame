#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Texto.h"
/*void Texto::SetCor(Uint8 r,Uint8 g,Uint8 b)
{
    R = r;
    G = g;
    B = b;

    //textColor = { r, g, b};
}*/

Texto::Texto(SDL_Renderer* passed_renderer,int x,int y,std::string Texto,std::string FontPath,int tamanho)
{
    TTF_Init();
    gRenderer = passed_renderer;
    gFont =TTF_OpenFont(FontPath.c_str(), tamanho);
    textColor.r = 255;
    textColor.g = 255;
    textColor.b = 255;
    textSurface = TTF_RenderText_Solid( gFont, Texto.c_str(), textColor );
    mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );

    rect.x = x;
    rect.y = y;
    rect.w = 100;
    rect.h = 50;
}

Texto::~Texto()
{
    TTF_CloseFont(gFont);
    SDL_DestroyTexture(mTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_FreeSurface(textSurface);
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
}
void Texto::Update(SDL_Window* passed_window)
{
    window = passed_window;
    SDL_GetWindowSize(window,&w,&h);

    if(w > 800)
    {
        rect.x = w/2.2;
    }
    else
    {
        rect.x = w/2.0;
    }


}
void Texto::Draw()
{
    SDL_RenderCopy(gRenderer,mTexture,NULL,&rect);
}
