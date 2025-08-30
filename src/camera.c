#include "camera.h"
Camera camera = {0, 0, LOGICAL_WIDTH, LOGICAL_HEIGHT};

static void update(float delta_time) {
  camera.x = player_position.x - camera.width / 2;
  camera.y = player_position.y - camera.height / 2;

  if (camera.x < 0) camera.x = 0;
  if (camera.y < 0) camera.y = 0;

  if (camera.x + camera.width > 420) camera.x = 420 - camera.width;
  if (camera.y + camera.height > 240) camera.y = 240 - camera.height;
}

void init_camera(SDL_Renderer *renderer)
{

    create_entity((Entity){
        .update = update,
    });
};