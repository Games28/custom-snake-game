#include "Stars.h"



void Stars::StarSet(std::mt19937 & rng, Board & brd)
{
	std::uniform_int_distribution<int> xdist(0, brd.Getwidth() - 1);
	std::uniform_int_distribution<int> ydist(0, brd.Getheight() - 1);

	loc.x = xdist(rng);
	loc.y = ydist(rng);
}

void Stars::DrawBrightStar1(Board & brd)
{
	brd.BrightStar1(loc);
}

void Stars::DrawBrightStar2(Board & brd)
{
	brd.BrightStar2(loc);
}

void Stars::DrawDStar(Board & brd)
{
	brd.RegularStar(loc);
}

