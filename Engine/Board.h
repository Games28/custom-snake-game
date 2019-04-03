#pragma once

#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void Drawcell(Location& loc);
	void FelconUp(Location& loc);
	void FelconDown(Location& loc);
	void FelconLeft(Location& loc);
	void FelconRight(Location& loc);
	void TFighter(Location& loc);
	void Explode(Location& loc);
	void RegularStar(Location& loc);
	void BrightStar1(Location& loc);
	void BrightStar2(Location& loc);
	bool InsideBoard(const Location& loc) const;
	void DrawBoundry();
	int Getwidth();
	int Getheight();
private:
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int x = 20;
	static constexpr int y = 20;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr Color borderColor = Colors::Yellow;
	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;
	Graphics& gfx;
};