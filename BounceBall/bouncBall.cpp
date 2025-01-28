#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomColor() {
    return COLOR(rand() % 256, rand() % 256, rand() % 256);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 300, y = 200;
    int radius = 20;
    int dx = 5, dy = 5;



    int ballColor = generateRandomColor();

    while (true) {
        cleardevice();
        setcolor(ballColor);
        circle(x, y, radius);

        x += dx;
        y += dy;

        if (x - radius <= 0 || x + radius >= getmaxx()) {
            dx = -dx;
            ballColor = generateRandomColor();
            if (x - radius < 0) {
                x = radius;
            }
            if (x + radius > getmaxx()) {
                x = getmaxx() - radius;
            }
        }

        if (y - radius <= 0 || y + radius >= getmaxy()) {
            dy = -dy;
            ballColor = generateRandomColor();
            if (y - radius < 0) {
                y = radius;
            }
            if (y + radius > getmaxy()) {
                y = getmaxy() - radius;
            }
        }

        delay(15);

        if (kbhit()) {
            break;
        }
    }

    closegraph();
    return 0;
}
