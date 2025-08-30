#include "player.h"

static SDL_FRect sprite_portion = {18, 16, 13, 16};
const char* PATH_PLAYER_TEXTURE = "./assets/Char_Sprites/char_spritesheet.png";
static SDL_Texture* player_texture = NULL;
static int move_speed = 50;

SpriteSize player_sprite_size = {13, 16};
Position player_position = {0,0};

static void quit()
{
};

static void handle_events(SDL_Event* event)
{
};

static void update(float delta_time) {
  const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

  if (keyboard_state[SDL_SCANCODE_W]) {
    player_position.y -= 1 * delta_time * move_speed;
  }

  if (keyboard_state[SDL_SCANCODE_S]) {
    player_position.y += 1 * delta_time * move_speed;
  }

  if (keyboard_state[SDL_SCANCODE_A]) {
    player_position.x -= 1 * delta_time * move_speed;
  }

  if (keyboard_state[SDL_SCANCODE_D]) {
    player_position.x += 1 * delta_time * move_speed;
  }

  // Keep player within bounds of the map using half the sprite size for centering
  if (player_position.x < player_sprite_size.w / 2) player_position.x = player_sprite_size.w / 2;
  if (player_position.y < player_sprite_size.h / 2) player_position.y = player_sprite_size.h / 2;
}

static void render(SDL_Renderer* renderer) {
  float final_x = camera.width / 2 - player_sprite_size.w / 2;
  float final_y = camera.height / 2 - player_sprite_size.h / 2;

  if (camera.x <= 0) final_x = player_position.x - player_sprite_size.w / 2;
  if (camera.y <= 0) final_y = player_position.y - player_sprite_size.h / 2;

  if (camera.x + camera.width >= 420) final_x = player_position.x - (420 - camera.width) - player_sprite_size.w / 2;
  if (camera.y + camera.height >= 240) final_y = player_position.y - (240 - camera.height) - player_sprite_size.h / 2;

  SDL_FRect player_rect = {
    final_x,
    final_y,
    player_sprite_size.w,
    player_sprite_size.h
  };

  SDL_RenderTexture(renderer, player_texture, &sprite_portion, &player_rect);
}



Entity init_player(SDL_Renderer* renderer)
{
    player_texture = IMG_LoadTexture(renderer, PATH_PLAYER_TEXTURE);
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

    Entity player = {
        .quit = quit,
        .handle_events = handle_events,
        .update = update,
        .render = render,
    };

    create_entity(player);
};