#include "Tiefighter.h"

void Tiefighter::tiefighter(std::mt19937 & rng, Board & brd, Snake & snake)
{
	Respawn( rng, brd, snake);
}

void Tiefighter::Respawn(std::mt19937 & rng, Board & brd, Snake & snake)
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

void Tiefighter::Draw(Board & brd)
{
	brd.TFighter(loc);
}

void Tiefighter::DrawExplode(Board & brd)
{
	brd.Explode(loc);
}

void Tiefighter::WatchOut(std::mt19937 & rng, Board & brd, Cargo & cargo)
{
	std::uniform_int_distribution<int> xdist(0, brd.Getwidth() - 1);
	std::uniform_int_distribution<int> ydist(0, brd.Getheight() - 1);
	Location newLoc;
	do
	{
		newLoc.x = xdist(rng);
		newLoc.y = ydist(rng);
	} while (loc == cargo.getLocation());
	loc = newLoc;
}

bool Tiefighter::Collision(const Location & target) const
{
	if (loc == target)
	{
		return true;
	}
	else {
		return false;
	}
}

const Location & Tiefighter::GetLocation()
{
	return loc;
}
