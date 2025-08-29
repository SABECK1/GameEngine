#include "player.h"

static SDL_FRect sprite_portion = {18, 16, 13, 16};
static SDL_FRect sprite_position = {255, 255, 13, 16};
const char* PATH_PLAYER_TEXTURE = "./assets/Char_Sprites/char_spritesheet.png";
static SDL_Texture* player_texture = NULL;

static void quit()
{
};

static void handle_events(SDL_Event* event)
{
};

static void update()
{
};

static void render(SDL_Renderer* renderer)
{
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
    SDL_RenderTexture(renderer, player_texture, &sprite_portion, &sprite_position);
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