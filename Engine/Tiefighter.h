#pragma once
#include "Snake.h"
#include "Board.h"
#include "Cargo.h"
#include <random>

class Tiefighter
{
public:
	void tiefighter(std::mt19937& rng, Board& brd, Snake& snake);
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake);
	void Draw(Board& brd);
	void DrawExplode(Board& brd);
	void WatchOut(std::mt19937& rng, Board& brd, Cargo& cargo);
	bool Collision(const Location& target) const;
	const Location& GetLocation();
private:
	Location loc;
};
