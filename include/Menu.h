#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu(SDL_Renderer* passed_renderer,SDL_Event* passed_event,SDL_Window* passed_window);
        ~Menu();

        void Update();
        void Draw();
        int GetCena();

        bool GetFechar();
        void SetFechar(bool x);
        void SetCena(int passed_cena);
    private:

        int w;
        int h;

        bool fechar;

        bool houver_play;
        bool houver_carregar;
        bool houver_opcao;
        bool houver_sair;

        int cena;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event* event;

        Texture* Menu_Fundo;
        Texture* Menu_borda;
        Texture* Menu_centro;
        Texture* Menu_houver_play;
        Texture* Menu_houver_carregar;
        Texture* Menu_houver_opcao;
        Texture* Menu_houver_sair;




        /**** Menus ****/
    Texto* menu_button_play;

    Texto* menu_button_carregar;
    Texto* menu_button_opacao;
    Texto* menu_button_sair;
};

#endif // MENU_H
