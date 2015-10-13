#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Person.h"
#include <string>
#include "Player.h"

Player::Player(SDL_Renderer* passed_renderer, SDL_Event* passed_event, std::string FilePath, int x, int y,SDL_Window* passed_window)
{
    window = passed_window;
    //IMG_Init( IMG_INIT_PNG );
    SDL_Init(SDL_INIT_EVERYTHING);
    velocidade = 1;
    event = passed_event;
    tecla_a = false;
    tecla_d = false;
    tecla_w = false;
    tecla_s = false;
    renderer = passed_renderer;
    player = new Person(renderer,FilePath.c_str(),x,y);

    ctrl = false;
    alt = false;
    enter = false;
    ModoTela = 0;



//SDL_GetWindowSize(window,&w,&h);


}

Player::~Player()
{
    SDL_Quit();
    IMG_Quit();
}
int Player::Cena()
{
    return cena;
}
void Player::Update()
{

        if(tecla_a)
        {
            player->SetX(player->GetX()-velocidade);
            player->Animation(0,1,2,150);
        }
        if(tecla_d)
        {
            player->SetX(player->GetX()+velocidade);
            player->Animation(0,2,2,150);
        }
        if(tecla_w)
        {
            player->SetY(player->GetY()-velocidade);
            player->Animation(0,3,2,150);
        }
        if(tecla_s)
        {
            player->SetY(player->GetY()+velocidade);
            player->Animation(0,0,2,150);
        }

        switch(event->type)
        {
            case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_a:
                        tecla_a = true;
                        break;
                    case SDLK_d:
                        tecla_d = true;
                        break;
                    case SDLK_w:
                        tecla_w = true;
                        break;
                    case SDLK_s:
                        tecla_s = true;
                        break;
                    case SDLK_F12:

                        break;
                    case SDLK_LCTRL:
                        ctrl = true;
                        break;
                    case SDLK_LALT:
                        alt = true;
                        break;
                    case SDLK_RETURN:
                        enter = true;
                        //SDL_MaximizeWindow()
                        break;
                    case SDLK_ESCAPE:
                        //cena = 0;
                        SDL_Quit();
                        break;

                }
            break;
            case SDL_KEYUP:
                switch(event->key.keysym.sym)
                {
                    case SDLK_a:
                        tecla_a = false;
                        break;
                    case SDLK_d:
                        tecla_d = false;
                        break;
                    case SDLK_w:
                        tecla_w = false;
                        break;
                    case SDLK_s:
                        tecla_s = false;
                        break;
                    case SDLK_LCTRL:
                        ctrl = false;
                        break;
                    case SDLK_LALT:
                        alt = false;
                        break;
                    case SDLK_RETURN:
                        enter = false;
                        //SDL_MaximizeWindow()


                        break;

                }
            break;



}



            //SDL_MaximizeWindow(window);
            //SDL_SetWindowDisplayMode(window,SDL_WINDOW_FULLSCREEN);
            /*if(ModoTela == 1)
            {
                SDL_SetWindowFullscreen(window, SDL_TRUE);
            }
*/
            /*SDL_Quit();
            IMG_Quit();*/



        /*if(ctrl && alt && enter)
        {

        SDL_GetWindowSize(window,&w,&h);
            //SDL_Delay(200);
             if(w == 800)
            {

                SDL_SetWindowFullscreen(window, SDL_TRUE | SDL_WINDOW_FULLSCREEN_DESKTOP);
                //SDL_SetWindowSize(window,1366,768);
                //ModoTela = 0;
                //SDL_GetWindowSize(window,&w,&h);
            }
            else
            {
                SDL_SetWindowFullscreen(window, SDL_FALSE);
                SDL_SetWindowSize(window,800,640);
                //ModoTela = 1;
                //SDL_GetWindowSize(window,&w,&h);

            }


        }*/


        if(player->GetY() < 1)
        {
            tecla_w = false;
        }

}
void Player::Draw()
{
    player->Draw();
}

