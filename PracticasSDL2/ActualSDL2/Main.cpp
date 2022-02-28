#include<SDL2/SDL.h>
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window;
    window = SDL_CreateWindow("Hola",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                300, //Window width
                                100, //Window height
                                SDL_WINDOW_RESIZABLE);
    if( window == NULL) {
        cout << "Error al crear la ventana" << endl 
        << SDL_GetError();
        return 1;
    }
    SDL_Delay(5000);

    SDL_DestroyWindow( window );

    SDL_Quit();
    return 1;
}