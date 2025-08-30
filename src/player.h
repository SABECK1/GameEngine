#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "entity.h"
#include "camera.h"

Entity init_player(SDL_Renderer* renderer);


typedef struct {
  float x;
  float y;
} Position;

typedef struct {
    float w, h;
} SpriteSize;

extern Position player_position;
extern SpriteSize player_sprite_size;