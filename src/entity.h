#pragma once
#include <SDL3/SDL.h>

#define MAX_ENTITIES 10

#define HANDLE_EVENTS_ENTITIES(entities, entities_count, event) \
  for (int i = 0; i < entities_count; i++) {    \
    entities[i].handle_events(event); \
  } 

#define QUIT_ENTITIES(entities, entities_count) \
  for (int i = 0; i < entities_count; i++) {    \
    entities[i].quit(); \
  } 

#define UPDATE_ENTITIES(entities, entities_count) \
  for (int i = 0; i < entities_count; i++) {    \
    entities[i].update(); \
  } 

#define RENDER_ENTITIES(entities, entities_count, renderer) \
  for (int i = 0; i < entities_count; i++) {    \
    entities[i].render(renderer); \
  } 


typedef struct {
  void (*quit)(void);
  void (*handle_events)(SDL_Event*);
  void (*update)(void);
  void (*render)(SDL_Renderer*);
} Entity;