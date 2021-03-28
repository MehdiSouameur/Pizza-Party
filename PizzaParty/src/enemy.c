
#include "common.h"

static SDL_Texture* badguy;

static void tick(void);
static void touch(Entity* other);
static SDL_Texture* hurtpete[2];

void initEnemy(char *line)
{
	enemy = malloc(sizeof(Entity));
	memset(enemy, 0, sizeof(Entity));
	stage.entityTail->next = enemy;
	stage.entityTail = enemy;

	enemy->health = 1;


	badguy= loadTexture("gfx/Enemy01.png");
	//pete[1] = loadTexture("gfx/pete02.png");

	sscanf(line, "%*s %f %f %f", &enemy->x, &enemy->y, &enemy->count);
	
    enemy->texture = badguy;
	hurtpete[0] = loadTexture("gfx/hurtpete.png");
	hurtpete[1] = loadTexture("gfx/hurtpete2.png");
	SDL_QueryTexture(enemy->texture, NULL, NULL, &enemy->w, &enemy->h);
	enemy->tick = tick;
	enemy->touch = touch;
	//enemy->flags = EF_SOLID;
}


static void touch(Entity* other) {
	if (self->health > 0 && other == player && other->isOnGround) {
		player->health -= 1;
		player->x +=-20;
		player->texture = hurtpete[0];
		
	}
	if (self->health > 0 && other == player && (other->isOnGround == 0) ){
		self->health = 0;
		player->dy = -15;
	}
}
static void tick(void) {
	static int forwards = 0;
	static int backwards = 0;
	static int count = 0;
	if (forwards == 1) {
			self->dx = -3;
			count++;
	}
	else if (backwards == 1) {
		self->dx = 3;
		count--;
	}
	if (count == 0) {
		forwards = 1;
		backwards = 0;
	}
	if (count == self->count) {
		backwards = 1;
		forwards = 0;
	}

}
