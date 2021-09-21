#ifndef MAIN_H
#define MAIN_H

#include "gba.h"

// TODO: Create any necessary structs
#define CEILING_ROW (15)
#define FLOOR_ROW (HEIGHT - 15)
#define MIN_COLUMN 90
#define MAX_COLUMN 120
#define MAX_PILLARS 4
/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/

struct player {
	int row;
	int col;
	int width;
	int height;
	const u16 *image;
};

struct pillar {
	int length;
	int width;
	int col;
	int origin;
	u16 color;
};

//Function prototypes
void drawPillar(struct pillar *cpillar);
void erasePillar(struct pillar *ppillar, const u16* background);
void drawFullScreenPartialDMA(int row, int col, int width, int height, const u16* image);

#endif
