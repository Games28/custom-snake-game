#include "Cargo.h"

void Cargo::container(std::mt19937 & rng, Board & brd, Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Cargo::Respawn(std::mt19937 & rng, Board & brd, Snake & snake)
{
	std::uniform_int_distribution<int> xdist(0, brd.Getwidth() - 1);
	std::uniform_int_distribution<int> ydist(0, brd.Getheight() - 1);

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

void Cargo::PickUp(const Location & Floc, const Board & Fbrd)
{
	const int FelconRight = Floc.x + Fbrd.Getwidth;
	const int FelconBottom = Floc.y + Fbrd.Getheight;
	const int CRight = loc.x + width;
	const int CBottom = loc.y + height;

	if (FelconRight >= loc.x &&
		FelconBottom >= loc.y &&
		CRight >= Floc.x &&
		CBottom >= Floc.y)
	{
		isCollected = true;
	}
}

bool Cargo::IsPickedUp(const Location & Floc,const Board & Fbrd)
{
	const int FelconRight = Floc.x + Fbrd.Getwidth;
	const int FelconBottom = Floc.y + Fbrd.Getheight;
	const int CRight = loc.x + width;
	const int CBottom = loc.y + height;

	return FelconRight >= loc.x &&
		FelconBottom >= loc.y &&
		CRight >= Floc.x &&
		CBottom >= Floc.y;
}
