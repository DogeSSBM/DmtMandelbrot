#include "Includes.h"
const Length window = {800, 600};



typedef struct {
	Ticks frozenUntil;
	Coord pos;
	uint health;
}Ship;

Coord playerMove(const Coord currentPos)
{
	const bool dir[4] = {
		keyState(SDL_SCANCODE_W) || keyState(SDL_SCANCODE_UP),
		keyState(SDL_SCANCODE_D) || keyState(SDL_SCANCODE_RIGHT),
		keyState(SDL_SCANCODE_S) || keyState(SDL_SCANCODE_DOWN),
		keyState(SDL_SCANCODE_A) || keyState(SDL_SCANCODE_LEFT)
	};
	Coord ret = currentPos;
	for(uint i = 0; i < 4; i++){
		if(dir[i] && !dir[dirINV(i)]){
			ret = coordClamp(coordShift(ret, i, 2), (Range){0,window.x}, (Range){0,window.y});
		}
	}
	return ret;
}

void playerDraw(const Ship player)
{
	setRGB(255*(player.health/10.0f), 0, 255*(10.0f-(player.health/10.0f)));
	fillCircleCoord(player.pos, 8);
}

int main(int argc, char *argv[])
{
	init(window);
	setFontSize(48);

	Ship player = {
		.frozenUntil =
		.pos = coordDiv(window, 2),
		.health = 10
	};

	while(true){
		Ticks frameStart = getTicks();
		clear();

		player.pos = playerMove(player.pos);
		playerDraw(player);

		draw();
		events(frameStart + TPF);
	}
	return EXIT_SUCCESS;
}
