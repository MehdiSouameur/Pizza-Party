#include "common.h"


void initSpring(char* line);
static void touch(Entity* other);
static void tick(void);
static SDL_Texture* spring[2];

void initSpring(char* line)
{
    Entity* e;

    e = malloc(sizeof(Entity));
    memset(e, 0, sizeof(Entity));
    stage.entityTail->next = e;
    stage.entityTail = e;

    sscanf(line, "%*s %f %f", &e->x, &e->y);
    e->health = 1;
    spring[0] = loadTexture("gfx/spring1.png");
    spring[1] = loadTexture("gfx/spring2.png");
    e->texture = spring[0];
    SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);

    e->touch = touch;
    e->tick = tick;

}

static void touch(Entity* other)
{
    //static int count = 30;

    if (self->health > 0 && other == player)
    {
        player->dy = -25;
        self->timer = self->count + 10;
    }
 
}
static void tick(void) {
    self->count++;

    if (self->count > self->timer) {
        self->texture = spring[0];
    }
    else if (self->count < self->timer)
    {
        self->texture = spring[1];
        self->y -= 5;
    }

}
