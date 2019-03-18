#pragma once

#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void Drawcell(Location& loc, Color c);
	void FelconUp(Location& loc);
	void FelconDown(Location& loc);
	void FelconLeft(Location& loc);
	void FelconRight(Location& loc);
	int Getwidth();
	int Getheight();
private:
	static constexpr int dimension = 20;
	static constexpr int width = 10;
	static constexpr int height = 10;
	Graphics& gfx;
};