#include "quit.h"

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    AppState* state = (AppState*) appstate;
    QUIT_ENTITIES(entities, entities_count);
    SDL_DestroyRenderer(state->renderer);
    state->renderer = NULL;
    SDL_DestroyWindow(state->window);
    state->window = NULL;
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
};