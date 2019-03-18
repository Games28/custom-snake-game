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
	gfx.FUp(loc.x *dimension, loc.y *dimension);
}

void Board::FelconDown(Location & loc)
{
	gfx.FDown(loc.x*dimension, loc.y*dimension);
}

void Board::FelconLeft(Location & loc)
{
	gfx.FLeft(loc.x*dimension, loc.y*dimension);
}

void Board::FelconRight(Location & loc)
{
	gfx.FRight(loc.x*dimension, loc.y*dimension);
}

int Board::Getwidth()
{
	return width;
}

int Board::Getheight()
{
	return height;
}
