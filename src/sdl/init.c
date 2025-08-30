#include "init.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    AppState *state = SDL_malloc(sizeof(AppState));
    *appstate = state;

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer(GAME_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0, &state->window, &state->renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    init_camera(state->renderer);
    init_map(state->renderer);
    init_player(state->renderer);

    SDL_SetRenderLogicalPresentation(state->renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    
    return SDL_APP_CONTINUE;
};