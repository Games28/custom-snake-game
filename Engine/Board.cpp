#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::Drawcell(Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x *dimension, loc.y * dimension, dimension, dimension, c);
}

void Board::FelconUp(Location & loc)
{
	gfx.FUp(loc.x, loc.y);
}

void Board::FelconDown(Location & loc)
{
	gfx.FDown(loc.x, loc.y);
}

void Board::FelconLeft(Location & loc)
{
	gfx.FLeft(loc.x, loc.y);
}

void Board::FelconRight(Location & loc)
{
	gfx.FRight(loc.x, loc.y);
}

int Board::Getwidth()
{
	return width;
}

int Board::Getheight()
{
	return height;
}
