#pragma once
#include <SDL3/SDL.h>

#define MAX_ENTITIES 10

#define HANDLE_EVENTS_ENTITIES(entities, entities_count, event) \
  for (int i = 0; i < entities_count; i++) {    \
    if (!entities[i].handle_events) continue; \
    entities[i].handle_events(event); \
  } 

#define QUIT_ENTITIES(entities, entities_count) \
  for (int i = 0; i < entities_count; i++) {    \
    if (!entities[i].quit) continue; \
    entities[i].quit(); \
  } 

#define UPDATE_ENTITIES(entities, entities_count, delta_time) \
  for (int i = 0; i < entities_count; i++) {    \
      if (!entities[i].update) continue; \
    entities[i].update(delta_time); \
  } 

#define RENDER_ENTITIES(entities, entities_count, renderer) \
  for (int i = 0; i < entities_count; i++) {    \
    if (!entities[i].render) continue; \
    entities[i].render(renderer); \
  } 


typedef struct {
  void (*quit)(void);
  void (*handle_events)(SDL_Event*);
  void (*update)(float);
  void (*render)(SDL_Renderer*);
} Entity;

extern Entity entities[MAX_ENTITIES];
extern int entities_count;