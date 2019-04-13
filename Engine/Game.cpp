/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek({ 2,2 })
{
	for (int i = 0; i < maxCargo; i++)
	{
		cargos[i].container(rng, brd, snek);
	}
	for (int i = 0; i < maxTie; i++)
	{
		ties[i].tiefighter(rng, brd, snek);
	}
	for (int i = 0; i < maxRegularStars; i++)
	{
		Regularstars[i].StarSet(rng, brd);
	}
	for (int i = 0; i < maxBrightStars; i++)
	{
		Brightstars[i].StarSet(rng, brd);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (GameIsStarted)
	{
		if (!GameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0,-1 };
				dir = Direction::UP;
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0,1 };
				dir = Direction::DOWN;

			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1, 0 };
				dir = Direction::LEFT;

			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1,0 };
				dir = Direction::RIGHT;

			}
			
			BrightStarCounter++;
			if (BrightStarCounter >= BrightStarresetMax)
			{
				BrightStarCounter = 0;
			}


			//snek.DirectionUpdate(wnd.kbd);
			
			Snakeresetcounter++;
			if (Snakeresetcounter == SnakeResetMax)
			{
				Snakeresetcounter = 0;
				
				for (int i = 0; i < maxTie; i++)
				{
					const Location next = snek.GetnextHeadLocation(delta_loc);
					if (!brd.InsideBoard(next) ||
						snek.InsideTrialExceptEnd(next) ||
						ties[i].Collision(next))
					{
						GameIsOver = true;
					}
				}
				for (int i = 0; i < maxCargo; i++)
				{

					if (snek.GetnextHeadLocation(delta_loc) == cargos[i].getLocation())
					{
						cargos[i].Respawn(rng, brd, snek);
						snek.Grow();

					}

				}
				snek.DirectionUpdate(dir);
				snek.moveby(delta_loc);
				
				
			}


		}
	}
	else
	{
		GameIsStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

void Game::ComposeFrame()
{
	
	if (GameIsStarted)
	{
		

		for (int i = 0; i < maxRegularStars; i++)
		{
			Regularstars[i].DrawDStar(brd);
		}
		for (int i = 0; i < maxBrightStars; i++)
		{
			if (BrightStarCounter > 50)
			{
				Brightstars[i].DrawBrightStar2(brd);
			}
			else if (BrightStarCounter < 50)
			{
				Brightstars[i].DrawBrightStar1(brd);
			}
		}
		for (int i = 0; i < maxCargo; i++)
		{
			cargos[i].Draw(brd);
		}
		
			for (int i = 0; i < maxTie; i++)
			{
				ties[i].Draw(brd);
				
				if (GameIsOver)
				{
					Titles::EndImage(350, 265, gfx);
				}
			}
		
		snek.Draw(brd);



		brd.DrawBoundry();

		Titles::Screentitle(350, 530, gfx);

	}
	else
	{
		Titles::StartImage(350, 265, gfx);
	}
}
