#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct { uint16_t keycode; } keyrecord_t;

#include "menu.h"

#define RGBLED_ENABLE

typedef struct {
    MenuKeys menu;
    uint8_t idx;
} MenuLoc;

extern MenuLoc current_menu;

int main() {
    while (true) {
        char in;
        scanf("%c", &in);
        printf("in=%c", in);
        switch (in) {
        case 'j':
            menu_left();
            break;
        case 'k':
            menu_up();
            break;
        case 'l':
            menu_down();
            break;
        case ';':
            keyrecord_t foo = { 0 };
            menu_right(&foo);
            break;
        }
        printf("menu=%d idx=%d", current_menu.menu, current_menu.idx);
    }

    return 0;
}
