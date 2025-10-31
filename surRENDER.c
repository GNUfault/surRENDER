#include "surRENDER.h"
#include <stdlib.h>

surrender *surrender_init(int width, int height, const char *title) {
    surrender *r = malloc(sizeof(surrender));
    r->display = XOpenDisplay(NULL);
    r->screen = DefaultScreen(r->display);
    r->window = XCreateSimpleWindow(
        r->display,
        RootWindow(r->display, r->screen),
        10, 10, width, height, 1,
        BlackPixel(r->display, r->screen),
        WhitePixel(r->display, r->screen)
    );

    XStoreName(r->display, r->window, title);
    XSelectInput(r->display, r->window, ExposureMask | KeyPressMask);
    XMapWindow(r->display, r->window);
    
    XEvent e;
    do {
        XNextEvent(r->display, &e);
    } while (e.type != Expose);

    r->gc = XCreateGC(r->display, r->window, 0, NULL);
    return r;
}

void draw_line(surrender *r, int x1, int y1, int x2, int y2, uint32_t color) {
    XSetForeground(r->display, r->gc, color);
    XDrawLine(r->display, r->window, r->gc, x1, y1, x2, y2);
    XFlush(r->display);
}

