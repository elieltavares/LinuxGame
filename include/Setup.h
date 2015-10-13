#ifndef SETUP_H
#define SETUP_H


class Setup
{
    public:
        Setup();
        ~Setup();
        void Inicio();
        void Fim();

        SDL_Renderer* Get_Renderer();
        SDL_Event* Get_Event();
        SDL_Window* Get_Window();
        void Update();

        int W();
        int H();

    private:
        int Window_w;
        int Window_h;

        int w;
        int h;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event* event;


};

#endif // SETUP_H
