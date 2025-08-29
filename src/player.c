#include "player.h"

static SDL_FRect sprite_portion = {18, 16, 13, 16};
const char* PATH_PLAYER_TEXTURE = "./assets/Char_Sprites/char_spritesheet.png";
static SDL_Texture* player_texture = NULL;
static int move_speed = 50;

typedef struct {
  float x;
  float y;
} Position;

Position position = {255, 255};

static void quit()
{
};

static void handle_events(SDL_Event* event)
{
};

static void update(float delta_time) {
  const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

  if (keyboard_state[SDL_SCANCODE_W]) {
    position.y -= 1 * delta_time * move_speed;
  }

  if (keyboard_state[SDL_SCANCODE_S]) {
    position.y += 1 * delta_time * move_speed;
  }

  if (keyboard_state[SDL_SCANCODE_A]) {
    position.x -= 1 * delta_time * move_speed;
  }

  if (keyboard_state[SDL_SCANCODE_D]) {
    position.x += 1 * delta_time * move_speed;
  }
}

static void render(SDL_Renderer* renderer)
{
    SDL_FRect player_position = {position.x, position.y, 15, 18};
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
    SDL_RenderTexture(renderer, player_texture, &sprite_portion, &player_position);
};

Entity init_player(SDL_Renderer* renderer)
{
    player_texture = IMG_LoadTexture(renderer, PATH_PLAYER_TEXTURE);

    Entity player = {
        .quit = quit,
        .handle_events = handle_events,
        .update = update,
        .render = render,
    };

    return player;
};