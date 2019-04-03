#pragma once
#include "Graphics.h"

class Titles
{
public:
	static void StartImage(int x, int y, Graphics& gfx);
	static void EndImage(int x, int y, Graphics& gfx);
	static void Explosion(int x, int y, Graphics& gfx);
	static void Screentitle(int x, int y, Graphics& gfx);
};
