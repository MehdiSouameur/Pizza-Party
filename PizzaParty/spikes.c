#include "common.h"

static void touch(Entity* other);
static SDL_Texture* spiketext;
static SDL_Texture* hurtpete;

void initSpikes(char *line)
{   
	Entity* e;

	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;

	sscanf(line, "%*s %f %f", &e->x, &e->y);

	e->health = 1;

	e->texture = loadTexture("gfx/spike.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->touch = touch;
}

static void touch(Entity* other) {
	if (self->health > 0 && other == player && (player->texture != hurtpete)){
		player->health -= 1;
        player->dy = -20;
		player->texture = hurtpete;
	}
}
