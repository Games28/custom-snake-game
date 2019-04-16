#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::Drawcell(Location & loc)
{
	//gfx.DrawRectDim(loc.x *dimension + off_x, loc.y * dimension + off_y, dimension, dimension, c);

	gfx.Cargo(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::LineDraw(Location & loc)
{
	gfx.Drawbox(loc.x*dimension + off_x, loc.y*dimension+off_y, dimension + 7 , dimension + 7, col);

	
}



void Board::FelconUp(Location & loc)
{
	gfx.FUp(loc.x *dimension + off_x, loc.y * dimension + off_y);
}

void Board::FelconDown(Location & loc)
{
	gfx.FDown(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::FelconLeft(Location & loc)
{
	gfx.FLeft(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::FelconRight(Location & loc)
{
	gfx.FRight(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::TFighter(Location & loc)
{
	gfx.TieFighter(loc.x * dimension + off_x, loc.y * dimension + off_y);
}

void Board::Explode(Location & loc)
{
	gfx.Explosion(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

void Board::RegularStar(Location & loc)
{
	gfx.DrawDStar(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

void Board::BrightStar1(Location & loc)
{
	gfx.DrawBrightStar1(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

void Board::BrightStar2(Location & loc)
{
	gfx.DrawBrightStar2(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

bool Board::InsideBoard(const Location & loc) const
{
	return loc.x >= -1 && loc.x <= width -1 &&
		loc.y >= -1 && loc.y <= height -1 ;
}

void Board::DrawBoundry()
{
	/*const int top = y;
	const int left = x;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;
	//top
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	//left
	gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	//right
	gfx.DrawRect(right - borderWidth, top + borderWidth, right, bottom - borderWidth, borderColor);
	//bottom
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);*/
	
	
	gfx.DrawGrid(x + off_x, y + off_y, width, height, dimension, borderColor);
}

int Board::Getwidth()
{
	return width;
}

int Board::Getheight()
{
	return height;
}
