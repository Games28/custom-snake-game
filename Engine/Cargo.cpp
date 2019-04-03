#include "Cargo.h"

void Cargo::container(std::mt19937 & rng, Board & brd, Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Cargo::Respawn(std::mt19937 & rng, Board & brd, Snake & snake)
{
	std::uniform_int_distribution<int> xdist(0, brd.Getwidth() - 10);
	std::uniform_int_distribution<int> ydist(0, brd.Getheight() - 10);

	Location newLoc;
	do
	{
		newLoc.x = xdist(rng);
		newLoc.y = ydist(rng);
	} while (snake.InsideTrail(newLoc));
	loc = newLoc;
}

void Cargo::Draw(Board & brd)
{
	brd.Drawcell(loc);
}


Location & Cargo::getLocation()
{
	return loc;
}

