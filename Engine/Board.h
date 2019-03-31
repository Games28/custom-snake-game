#pragma once

#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void Drawcell(Location& loc,Color c);
	void FelconUp(Location& loc);
	void FelconDown(Location& loc);
	void FelconLeft(Location& loc);
	void FelconRight(Location& loc);
	bool InsideBoard(const Location& loc) const;
	int Getwidth();
	int Getheight();
private:
	static constexpr int dimension = 24;
	static constexpr int width = 35;
	static constexpr int height = 25;
	Graphics& gfx;
};