// -*- compile-command: "gcc -D QMK_KEYBOARD_H='\"test_menu.h\"' test_menu.c default_menu.c menu.c"; -*-

#include "menu.h"

extern menu_t* current_menu;

// stub
void process_record_quantum(keyrecord_t* x) {
    return;
}

int main() {
    while (true) {
        char in;
        scanf("%c", &in);
        printf("in=%c", in);
        switch (in) {
        case 'j':
            menu_back();
            break;
        case 'k':
            menu_up();
            break;
        case 'l':
            menu_down();
            break;
        case ';':
            keyrecord_t foo = { 0 };
            menu_act(&foo);
            break;
        }
        printf("menu=%d idx=%d\n", current_menu, current_menu->index);
        printf("%s\n", menu_get_entry(current_menu->index).text);
    }

    return 0;
}
