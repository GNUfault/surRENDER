#ifndef SURRENDER_H
#define SURRENDER_H

#include <X11/Xlib.h>
#include <stdint.h>

typedef struct {
    Display *display;
    Window window;
    GC gc;
    int screen;
} surrender;

surrender *surrender_init(int width, int height, const char *title);
void draw_line(surrender *r, int x1, int y1, int x2, int y2, uint32_t color);

#endif
