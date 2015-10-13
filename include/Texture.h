#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

class Texture
{
    public:
        Texture(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h);
        ~Texture();
        void Draw();
        void Update(SDL_Window* passed_window);
        void UpdateX(SDL_Window* passed_window);
    private:
        int passed_w;
        int passed_h;
        SDL_Window* window;
        //SDL_Window* window;
        SDL_Texture* image;
        SDL_Rect rect;
        SDL_Renderer* renderer;

        int background_w;
        int background_h;
};

#endif // TEXTURE_H
