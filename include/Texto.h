#ifndef TEXTO_H
#define TEXTO_H
#include <SDL2/SDL_ttf.h>

class Texto
{
    public:
        //void SetCor(Uint8 r,Uint8 g,Uint8 b);
        Texto(SDL_Renderer* passed_renderer,int x,int y,std::string Texto,std::string FontPath,int tamanho);
        ~Texto();
        void Draw();
        void Update(SDL_Window* passed_window);
    private:

        int w;
        int h;

        SDL_Window* window;
        SDL_Renderer* gRenderer;
    SDL_Rect rect;
        SDL_Texture* mTexture;
        TTF_Font* gFont;
        SDL_Surface* textSurface;
        SDL_Color textColor;

        /*Uint8 R;
        Uint8 G;
        Uint8 B;*/

};

#endif // TEXTO_H
