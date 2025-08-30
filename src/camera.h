#pragma once
#include "entity.h"
#include "player.h"
#include "map.h"
#include "./sdl/properties.h"

typedef struct {
  float x, y, width, height;
} Camera;

extern Camera camera;
void init_camera(SDL_Renderer *renderer);