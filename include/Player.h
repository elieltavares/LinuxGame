#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(SDL_Renderer* passed_renderer, SDL_Event* passed_event, std::string FilePath, int x, int y,SDL_Window* passed_window);
        ~Player();
        void Draw();
        void Update();
        int Cena();

    private:
    int ModoTela;

        int w;
        int h;

        SDL_Window* window;
        int cena;
        SDL_Renderer* renderer;
        SDL_Event* event;
        Person* player;

    bool ctrl;
    bool alt;
    bool enter;

        bool tecla_a;
        bool tecla_d;
        bool tecla_w;
        bool tecla_s;

        int velocidade;
};

#endif // PLAYER_H
