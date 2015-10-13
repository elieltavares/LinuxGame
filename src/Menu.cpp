#include <SDL2/SDL.h>
#include "Texture.h"
#include "Texto.h"
#include <iostream>
#include "Menu.h"

Menu::Menu(SDL_Renderer* passed_renderer,SDL_Event* passed_event,SDL_Window* passed_window)
{
SDL_Init(SDL_INIT_EVERYTHING);
    houver_play = false;
    houver_carregar = false;
    houver_opcao = false;
    houver_sair = false;

    window = passed_window;


        SDL_GetWindowSize(window,&w,&h);



    cena = 0;
    event = passed_event;
    renderer = passed_renderer;
    /**** background ****/
    Menu_Fundo = new Texture(renderer,"data/texturas/menu/DemonCastle.png",0,0,w,h);
    Menu_borda = new Texture(renderer,"data/texturas/menu/Dragons.png",0,0,w,h);
    Menu_centro = new Texture(renderer,"data/texturas/menu/menu_black.png",w/2.5,200,250,300);
    Menu_houver_play = new Texture(renderer,"data/texturas/menu/menu_houver_play.png",w/2.2,200,250,300);
    Menu_houver_carregar = new Texture(renderer,"data/texturas/menu/menu_houver_carregar.png",w/2.2,200,250,300);
    Menu_houver_opcao = new Texture(renderer,"data/texturas/menu/menu_houver_opcao.png",w/2.2,200,250,300);
    Menu_houver_sair = new Texture(renderer,"data/texturas/menu/menu_houver_sair.png",w/2.2,200,250,300);
    /**** Menus ****/
    menu_button_play = new Texto(renderer,w/2.2,250,"Play","data/fontes/VLGothic.ttf",25);

    menu_button_carregar = new Texto(renderer,w/2.2,300,"Carregar","data/fontes/VLGothic.ttf",25);
    menu_button_opacao = new Texto(renderer,w/2.2,350,"Opcao","data/fontes/VLGothic.ttf",25);
    menu_button_sair = new Texto(renderer,w/2.2,400,"Sair","data/fontes/VLGothic.ttf",25);
}

Menu::~Menu()
{
    SDL_Quit();
}
void Menu::Update()
{
    Menu_Fundo->Update(window);
    Menu_borda->Update(window);

    Menu_centro->UpdateX(window);
    Menu_houver_play->UpdateX(window);
    Menu_houver_carregar->UpdateX(window);
    Menu_houver_opcao->UpdateX(window);
    Menu_houver_sair->UpdateX(window);

    menu_button_play->Update(window);
    menu_button_carregar->Update(window);
    menu_button_opacao->Update(window);
    menu_button_sair->Update(window);

    SDL_GetWindowSize(window,&w,&h);
if( event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONUP )
    {
        int mouseX, mouseY;
        SDL_GetMouseState( &mouseX, &mouseY );

                if(mouseX>330 && mouseX<430 && mouseY > 250 && mouseY < 290)
                {
                   // menu_button_play->SetCor(255,255,255);
                    //menu_button_carregar->SetCor(255,255,255);
                    //menu_button_opacao->SetCor(255,255,255);
                }
/**** Houver Play ****/
                if(mouseX>w/2.2 && mouseX<w/1.8 && mouseY > 250 && mouseY < 290)
                {
                    houver_play = true;
                }
                else
                {
                    houver_play = false;
                }
/**** Houver Carregar ****/
                if(mouseX>w/2.2 && mouseX<w/1.8 && mouseY > 291 && mouseY < 340)
                {
                    houver_carregar = true;
                }
                else
                {
                    houver_carregar = false;
                }
/**** Houver Opcao ****/
                if(mouseX>w/2.2 && mouseX<w/1.8 && mouseY > 341 && mouseY < 390)
                {
                    houver_opcao = true;
                }
                else
                {
                    houver_opcao = false;
                }
/**** Houver Sair ****/
                if(mouseX>w/2.2 && mouseX<w/1.8 && mouseY > 391 && mouseY < 440)
                {
                    houver_sair = true;
                }
                else
                {
                    houver_sair = false;
                }


        std::cout<< mouseX << " "<< mouseY<<std::endl;

         switch( event->type )
            {
                case SDL_MOUSEMOTION:

                break;

                case SDL_MOUSEBUTTONDOWN:
                if(mouseX>w/2.2 && mouseX<w/1.8 && mouseY > 250 && mouseY < 290)
                {
                    cena = 1;
                    //player->Animation(0,1,2,0);
                }
                else if(mouseX>w/2.2 && mouseX<w/1.8 && mouseY > 391 && mouseY < 440)
                {
                    //return 0;
                    //SDL_Quit();
                    fechar = true;
                }



                break;

                /*case SDL_MOUSEBUTTONUP:
                cena = 0;
                break;*/


            }




    }

}
void Menu::Draw()
{
            Menu_Fundo->Draw();

            Menu_borda->Draw();
            Menu_centro->Draw();


            menu_button_play->Draw();
            menu_button_carregar->Draw();
            menu_button_opacao->Draw();
            menu_button_sair->Draw();


            if(houver_play == true)
            {
                Menu_houver_play->Draw();
            }
            if(houver_carregar == true)
            {
                Menu_houver_carregar->Draw();
            }
            if(houver_opcao == true)
            {
                Menu_houver_opcao->Draw();
            }
            if(houver_sair == true)
            {
                Menu_houver_sair->Draw();
            }
}
int Menu::GetCena()
{
    return cena;
}
void Menu::SetCena(int passed_cena)
{
    cena = passed_cena ;
}
bool Menu::GetFechar()
{
    return fechar;
}
void Menu::SetFechar(bool x)
{
    fechar = x;
}
