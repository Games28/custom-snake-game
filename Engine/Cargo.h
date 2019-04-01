#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Cargo
{
public:
	void container(std::mt19937& rng, Board& brd, Snake& snake);
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake);
	void Draw(Board& brd);
	void PickUp(const Location& Floc,const Board& Fbrd);
	bool IsPickedUp(const Location& Floc,const Board& Fbrd);
private:
	Location loc;
	static constexpr int width = 20;
	static constexpr int height = 20;
	bool isCollected = false;
};
