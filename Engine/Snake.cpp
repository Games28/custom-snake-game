#include "Snake.h"

void Snake::Segment::Inithead(const Location & in_loc)
{
	loc = in_loc;
	
	
}

void Snake::Segment::Initbody()
{
	c = Snake::BodyColor;
}

void Snake::Segment::Draw(Board & brd)
{
	brd.Drawcell(loc);
}

void Snake::Segment::HDrawup(Board & brd)
{
	brd.FelconUp(loc);
	//brd.LineDraw(loc);
}

void Snake::Segment::HDrawDown(Board & brd)
{
	brd.FelconDown(loc);
	//brd.LineDraw(loc);
}

void Snake::Segment::HDrawLeft(Board & brd)
{
	brd.FelconLeft(loc);
	//brd.LineDraw(loc);
}

void Snake::Segment::HDrawRight(Board & brd)
{
	brd.FelconRight(loc);
	//brd.LineDraw(loc);
}


void Snake::Segment::Moveby(const Location & delta_loc)
{
	loc.Add(delta_loc);
}

void Snake::Segment::follow(Segment & next)
{
	loc = next.loc;
}

const Location & Snake::Segment::GetLocation() const
{
	return loc;
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



void Snake::DirectionUpdate(Direction& in_dir) 
{
	dir = in_dir;
	
}



void Snake::Draw(Board & brd)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
	if (dir == Direction::UP)
	{
		segments[0].HDrawup(brd);
  } 
	else if (dir == Direction::DOWN)
	{
		segments[0].HDrawDown(brd);
	}
	else if (dir == Direction::LEFT)
	{
		segments[0].HDrawLeft(brd);
	}
	else if (dir == Direction::RIGHT)
	{
		segments[0].HDrawRight(brd);
	}
	else {
		segments[0].HDrawRight(brd);
	}
	
}

Location Snake::GetnextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

bool Snake::InsideTrialExceptEnd(const Location & target) const
{
	for (int i = 0; i < nSegments - 1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::InsideTrail(const Location & target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void Snake::Grow()
{
	
	if (nSegments < nSegmentsMax)
	{
		
		segments[nSegments].Initbody();
		nSegments++;
		
	}
}
