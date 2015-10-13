#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Setup.h"
#include "Texture.h"
#include "Person.h"
#include "Texto.h"
#include "Menu.h"
#include "Player.h"

int main(int arvc,char* argv[])
{

    Setup* setup = new Setup();
/**** Backgrounds ****/
int w;
int h;

    setup->Update();
 SDL_GetWindowSize(setup->Get_Window(),&w,&h);

//int* teste_w = &w;
//int* teste_h = &h;

    Texture* background = new Texture(setup->Get_Renderer(),"data/mapa/mapa.png",0,0,setup->W(),setup->H());

/**** Personagems ****/
    Player* Eric = new Player(setup->Get_Renderer(),setup->Get_Event(),"data/person/Actor1.png",200,200,setup->Get_Window());
/**** Menu ****/
    Menu* menu = new Menu(setup->Get_Renderer(),setup->Get_Event(),setup->Get_Window());
menu->SetCena(Eric->Cena());
menu->SetFechar(false);
menu->SetCena(0);

    while(!menu->GetFechar())
    {
        setup->Update();
        background->Update(setup->Get_Window());
        if(setup->Get_Event()->type == SDL_QUIT)
        {
            menu->SetFechar(true);
        }
/******* Mouse *******/
        menu->Update();
        Eric->Update();

/******* Mouse  fim *******/
        //std::cout << player->GetX() <<" "<< player->GetY()<<std::endl;
        setup->Inicio();
            if(menu->GetCena() == 0)
            {
                menu->Draw();
            }
            if(menu->GetCena() == 1)
            {
                background->Draw();
                Eric->Draw();

            }
        setup->Fim();
    }
    return 0;
}



