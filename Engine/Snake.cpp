#include "Snake.h"

void Snake::Segment::Inithead(const Location & in_loc)
{
	loc = in_loc;
	//c = Snake::headColor;
	
}

void Snake::Segment::Initbody()
{
	c = Snake::BodyColor;
}

void Snake::Segment::Draw(Board & brd)
{
	brd.Drawcell(loc, c);
}

/*void Snake::Segment::HDrawup(Board & brd)
{
	brd.FelconUp(loc);
}

void Snake::Segment::HDrawDown(Board & brd)
{
	brd.FelconDown(loc);
}

void Snake::Segment::HDrawLeft(Board & brd)
{
	brd.FelconLeft(loc);
}*/

void Snake::Segment::HDrawRight(Board & brd)
{
	brd.FelconRight(loc);
}

void Snake::Segment::DrawHead(Board & brd, Direction dir)
{
	if (dir == Direction::UP)
	{
		brd.FelconUp(loc);
	}
	else if (dir == Direction::DOWN)
	{
		brd.FelconDown(loc);
	}
	else if (dir == Direction::LEFT)
	{
		brd.FelconLeft(loc);
	}
	else if (dir == Direction::RIGHT)
	{
		brd.FelconRight(loc);
	}
}

void Snake::Segment::Moveby(const Location & delta_loc)
{
	loc.Add(delta_loc);
}

void Snake::Segment::follow(Segment & next)
{
	loc = next.loc;
}

Snake::Snake(const Location & loc)
{
	segments[0].Inithead(loc);
}

void Snake::moveby(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].follow(segments[i-1]);
	}
	segments[0].Moveby(delta_loc);
}



void Snake::DirectionUpdate(Board& brd,Direction& dir) // get an kbd error
{
	segments[0].DrawHead(brd,dir);
	
}



void Snake::Draw(Board & brd)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
segments[0].HDrawRight(brd);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		
		segments[nSegments].Initbody();
		nSegments++;
		
	}
}
