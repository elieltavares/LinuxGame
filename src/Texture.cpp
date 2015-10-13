#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Texture.h"

Texture::Texture(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h)
{
    renderer = passed_renderer;
    image = IMG_LoadTexture(renderer,FilePath.c_str());

    //SDL_QueryTexture(image,NULL,NULL,&background_w,&background_h);
    passed_w = w;
    passed_h = h;

    rect.x = x;
    rect.y = y;
    rect.w = passed_w;
    rect.h = passed_h;
}
void Texture::Update(SDL_Window* passed_window)
{
    window = passed_window;
    SDL_GetWindowSize(window,&passed_w,&passed_h);
    rect.w = passed_w;
    rect.h = passed_h;
}
void Texture::UpdateX(SDL_Window* passed_window)
{
    window = passed_window;
    SDL_GetWindowSize(window,&passed_w,&passed_h);
    rect.x = passed_w/2.5;
}

Texture::~Texture()
{
    SDL_DestroyTexture(image);
}
void Texture::Draw()
{
    SDL_RenderCopy(renderer,image,NULL,&rect);
}
