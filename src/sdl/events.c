#include "events.h"

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    AppState* state = (AppState*) appstate;
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }

    HANDLE_EVENTS_ENTITIES(entities, entities_count, event);

    return SDL_APP_CONTINUE;
};
