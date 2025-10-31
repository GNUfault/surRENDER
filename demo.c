#include "surRENDER.h"
#include <unistd.h>

int main() {
    surrender *r = surrender_init(800, 600, "surRENDER Demo");

    while(1) {
        draw_line(r, 100, 100, 200, 300, 0xFF0000);
        draw_line(r, 200, 100, 200, 300, 0x00FF00);
        draw_line(r, 300, 100, 200, 300, 0x0000FF);
        draw_line(r, 100, 100, 300, 100, 0xFFFF00);
    }

    for (;;);
}
