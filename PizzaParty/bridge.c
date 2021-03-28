#include "common.h"

static void touch(Entity* other);
static void tick(void);

void initBridge(char* line)
{
	Entity* e;

	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;

	Entity* d;

	d = malloc(sizeof(Entity));
	memset(d, 0, sizeof(Entity));
	stage.entityTail->next = d;
	stage.entityTail = d;

	sscanf(line, "%*s %f %f", &e->x, &e->y);
	sscanf(line, "%*s %f %f", &d->x, &d->y);

	e->health = 1;
	d->health = 1;
	d->y -= 1;
	e->timer = 0;
	e->texture = loadTexture("gfx/bridge.png");
	d->texture = loadTexture("gfx/debugbridge.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	SDL_QueryTexture(d->texture, NULL, NULL, &d->w, &d->h);
	e->flags =  EF_SOLID + EF_WEIGHTLESS;
	d->flags = EF_WEIGHTLESS;
	d->touch = touch;
	e->tick = tick;
}

static void touch(Entity* other)
{   
	if (self->health > 0 && other == player) {
	  player->bridge += 1;
	}
	
}

static void tick(void) {
	if (player->bridge != 0) {
		self->dy = 1;
	}
}