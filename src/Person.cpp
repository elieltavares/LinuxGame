#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Person.h"

Person::Person(SDL_Renderer* passed_renderer,std::string FilePath,int person_x,int person_y)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init( IMG_INIT_PNG );

    renderer = passed_renderer;


    image =  IMG_Load(FilePath.c_str());

    person = SDL_CreateTextureFromSurface( renderer, image );
    SDL_FreeSurface( image );

    rect_x = person_x;
    rect_y = person_y;

    rect.x = rect_x;
    rect.y = rect_y;

    rect.w = 50;
    rect.h = 50;


    SDL_QueryTexture(person,NULL,NULL,&w,&h);

    crop.w = w/12;
    crop.h = h/8;
    crop.x = w/12;
    crop.y = 0*h/8;


    animation_gettick = SDL_GetTicks();
}

Person::~Person()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(person);
    SDL_Quit();
    IMG_Quit();
}
void Person::Draw()
{
    SDL_RenderCopy(renderer,person,&crop,&rect);
}
void Person::Animation(int inicio,int position,int num,int speed)
{

    Getticker = SDL_GetTicks();
if(animation_gettick+speed < Getticker)
{
    if(current < num)
    {
        current++;
    }
    else
    {
        current = inicio;
    }

    crop.w = w/12;
    crop.h = h/8;
    crop.x = current*w/12;
    crop.y = position*h/8;

    animation_gettick = SDL_GetTicks();
}

}




int Person::GetX()
{

    return rect.x;
}
int Person::GetY()
{

    return rect.y;
}
void Person::SetX(int x)
{
    rect_x = x;
    rect.x = rect_x;
}
void Person::SetY(int y)
{
    rect_y = y;
    rect.y = rect_y;
}

