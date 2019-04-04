#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
// #define INCLUDE_SDL_IMAGE

// #include <iostream>
// #include "SDL_include.h"
#include "Component.h"
#include "Rect.h"
#include <vector>

class GameObject {
private:
  bool isDead;
  std::vector<Component *> components;

public:
  Rect box;

  GameObject();
  ~GameObject();
  void Update(float dt);
  void Render();
  bool IsDead();
  void RequestDelete();
  void AddComponent(Component *cpt);
  void RemoveComponent(Component *cpt);
  Component *GetComponent(std::string type);
};

#endif
