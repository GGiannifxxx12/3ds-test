/*
	Hello World example made by Aurelio Mannara for libctru
	This code was modified for the last time on: 12/12/2014 21:00 UTC+1
*/

#include <3ds.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
int main(int argc, char **argv)
int hp = 100;
int hp2 = 200;
{
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	//Move the cursor to row 15 and column 19 and then prints "Hello World!"
	//To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
	//the row and column where you want your cursor to move
	//The top screen has 30 rows and 50 columns
	//The bottom screen has 30 rows and 40 columns
	printf("\x1b[16;20HHello Friend!");

	printf("\x1b[30;16HPress A to Begin.");
	while(true)
	{
	    hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A) break;
	}
	
	consoleClear();
	while(true)
	{
	    std::cout << "\x1b[1;1HSomeRando HP: " << hp;
		std::cout << "\x1b[3;1HSomeCoolGuy HP: " << hp2;
		printf("\x1b[30;16HPress A to Attack!");
		
		if(hp2 <= 0 || hp <= 0) break
		
		hidScanInput();
		u32 kDown = hidKeysDown();
		
		if(kDown & KEY_A)
		{
		    consoleClear();
			int hpattack = rand() % 10;
			int hp2attack = rand() % 10;
			
			hp2 -= hpattack;
			hp -= hp2attack;
			
			std::cout <<"x1b[27;16HSomeRando HP lost" << hp2attack << "HP";
			std::cout <<"x1b[27;16HSomeCoolGuy HP lost" << hpattack << "HP";
		}
		
	}
	
	if(hp <= 0) std::cout << "\x1b[1;1HSomeCoolGuy Won";
	if(hp2 <= 0) std::cout << "\x1b[1;1HSomeRando Won";
	printf("\x1b[30;16HPress start to Exit.");

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
