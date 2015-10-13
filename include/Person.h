#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    public:
        Person(SDL_Renderer* passed_renderer,std::string FilePath,int person_x,int person_y);
        ~Person();
        void Draw();

        int GetX();
        int GetY();

        void SetX(int x);
        void SetY(int y);

        void Animation(int inicio,int position,int num,int speed);

    private:
        int Getticker;
        SDL_Surface* image;
        SDL_Texture* person;
        SDL_Renderer* renderer;
        SDL_Rect rect;
        SDL_Rect crop;
        int w;
        int h;

        int rect_x;
        int rect_y;

        int current;

        int animation_gettick;
};

#endif // PERSON_H
