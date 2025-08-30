#include "entity.h"
Entity entities[MAX_ENTITIES];
int entities_count = 0;

void create_entity(Entity entity) {
  if (entities_count < MAX_ENTITIES) {
    entities[entities_count++] = entity;
  }
  else {
    SDL_Log("Max entities reached!");
  }
}

void destroy_entity(int index) {
  if (index < 0 || index >= entities_count) {
    SDL_Log("Invalid entity index!");
    return;
  }

  entities[index].quit();
  // Shift entities to fill the gap
  for (int i = index; i < entities_count - 1; i++) {
    entities[i] = entities[i + 1];
  }
  entities_count--;
}

void swap_entities(int index1, int index2) {
  if (index1 < 0 || index1 >= entities_count || index2 < 0 || index2 >= entities_count) {
    SDL_Log("Invalid entity index!");
    return;
  }

  Entity temp = entities[index1];
  entities[index1] = entities[index2];
  entities[index2] = temp;
}