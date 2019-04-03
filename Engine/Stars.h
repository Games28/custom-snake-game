#pragma once
#include "Graphics.h"
#include "Board.h"
#include <random>

class Stars
{
public:
	void StarSet(std::mt19937& rng, Board& brd);
	void DrawBrightStar1(Board& brd);
	void DrawBrightStar2(Board& brd);
	void DrawDStar(Board& brd);
private:
	Location loc;

};