#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct { uint16_t keycode; } keyrecord_t;

#define RGBLED_ENABLE

#include "menu.h"

extern menu_t* current_menu;

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
        printf("menu=%d idx=%d\n", current_menu, current_menu->index);
        printf("%s\n", get_entry(current_menu, current_menu->index).menuText);
    }

    return 0;
}
