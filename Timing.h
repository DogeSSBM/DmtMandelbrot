#pragma once
#define FPS		60
#define TPF		(1000/FPS)

static inline
Ticks getTicks(void)
{
	return SDL_GetTicks();
}

static inline
Ticks secondsToTicks(const uint sec)
{
	return sec*TPF*FPS;
}

static inline
Ticks timeIn(const uint sec)
{
	return getTicks()+secondsToTicks(sec);
}
