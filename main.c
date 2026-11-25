#include <snes.h>

int main(void) {
    u16 pad;
    u16 x = 128, y = 112;

    consoleInit();
    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);

    // Set background to dark green
    setPaletteColor(0, RGB5(0, 15, 0));
    setScreenOn();

    while(1) {
        pad = padsCurrent(0);

        if(pad & KEY_LEFT)  x--;
        if(pad & KEY_RIGHT) x++;
        if(pad & KEY_UP)    y--;
        if(pad & KEY_DOWN)  y++;

        WaitForVBlank();

        // Draw a simple 16x16 box using sprites
        oamSet(0, x, y, 3, 0, 0, 0, 0);
        oamSet(1, x+8, y, 3, 0, 1, 0, 0);
        oamSet(2, x, y+8, 3, 0, 2, 0, 0);
        oamSet(3, x+8, y+8, 3, 0, 3, 0, 0);
        oamUpdate();
    }
    return 0;
}
