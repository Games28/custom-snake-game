/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Direction.h"
#include "Titles.h"
#include "Cargo.h"
#include "Tiefighter.h"
#include "Stars.h"
#include <random>


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	Board brd;
	std::mt19937 rng;
	Snake snek;
	Location delta_loc{ 1,0 };
	Direction dir = Direction::RIGHT;
	static constexpr int maxRegularStars = 80;
	Stars Regularstars[maxRegularStars];
	static constexpr int maxBrightStars = 40;
	Stars Brightstars[maxBrightStars];
	int BrightStarresetMax = 100;
	int BrightStarCounter = 0;
	static constexpr int maxTie = 5;
	Tiefighter ties[maxTie];
	static constexpr int maxCargo = 10;
	Cargo cargos[maxCargo];
	int SnakeResetMax = 20;
	int Snakeresetcounter = 0;
	int headcounter = 0;
	int headreset = 20;
	bool GameIsOver = false;
	bool GameIsStarted = false;
	/********************************/
	/*  User Variables              */
	/********************************/
};