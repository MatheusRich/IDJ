#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "State.h"

class Game {
private:
  static Game* instance;
  SDL_Window* window;
  SDL_Renderer* renderer;
  State* state;

  Game(std:string title, int width, int height);

public:
  ~Game();
  void Run();
  SDL_Renderer* GetRenderer();
  State& GetState();
  static Game& GetInstance();  
};

#endif