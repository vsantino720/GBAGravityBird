#include "main.h"

void drawFullScreenPartialDMA(int row, int col, int width, int height, const u16* image) {
    for (int r = 0; r < height; r++) {
        DMA[3].src = &image[OFFSET(row + r, col, WIDTH)];
        DMA[3].dst = &videoBuffer[OFFSET(row + r, col, WIDTH)];
        DMA[3].cnt = width | DMA_ON | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT;
    }
}

void drawPillar(struct pillar *cpillar) {
    int row;
    if (!cpillar->origin) {
        row = 0;
    }
    else {
        row = HEIGHT - cpillar->length;
    }
    drawRectDMA(row, cpillar->col, cpillar->width, cpillar->length, cpillar->color);
}

void erasePillar(struct pillar *ppillar, const u16 *background) {
    int row;
    if (!ppillar->origin) {
        row = 0;
    }
    else {
        row = HEIGHT - ppillar->length;
    }
    //drawRectDMA(row, ppillar.col, ppillar.width, ppillar.length, BLACK);
    drawFullScreenPartialDMA(row, ppillar->col, ppillar->width, ppillar->length, background);
}
