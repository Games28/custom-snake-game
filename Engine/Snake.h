#pragma once
#include "Board.h"
#include "Direction.h"
#include"Keyboard.h"

class Snake
{

private:
	class Segment
	{
	public:
		void Inithead(const Location& in_loc);
		void Initbody();
		void Draw(Board& brd);
		void HDrawup(Board& brd);
		void HDrawDown(Board& brd);
		void HDrawLeft(Board& brd);
		void HDrawRight(Board& brd);
		void DrawHead(Board& brd, Direction dir);
		void Moveby(const Location& delta_loc);
		void follow(Segment& next);
	private:
		
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);
	void moveby(const Location& delta_loc);
	
	void DirectionUpdate(Direction& in_dir);
	void Draw(Board& brd);
	void Grow();
	
private:
	static constexpr Color headColor = Colors::Green;
	static constexpr Color BodyColor = Colors::Blue;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	int counter = 0;
	int counterReset = 20;
	Direction dir;
	//Keyboard kbd;

};

