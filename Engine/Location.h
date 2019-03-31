#pragma once

class Location
{
public:
	void Add(const Location& loc)
	{
		x += loc.x;
		y += loc.y;
	}
	bool operator == (const Location& rhs) const
	{
		return x == rhs.x && y == rhs.x;
	}
	int x;
	int y;
};
