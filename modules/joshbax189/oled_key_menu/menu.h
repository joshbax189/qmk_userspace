
#pragma once

#include QMK_KEYBOARD_H

/* The action this menu will produce */
typedef enum {
    MENU_SUB, // data is another menu
    MENU_KC,  // data is a keycode
    MENU_FN,  // data is a function
} MenuType;

typedef struct MenuEntry MenuEntry;
typedef union MenuData MenuData;
typedef struct Menu Menu;

struct Menu {
    MenuEntry* entries;
    uint8_t index;
    Menu* lastMenu; // linked list path to current menu
};

union MenuData {
    uint16_t keycode;
    Menu* subMenu;
    void (*menuFn)(keyrecord_t*);
};

struct MenuEntry {
    char* menuText;
    MenuType menuType;
    MenuData menuData; // either a pointer or a keycode
};

void menu_up(void);
void menu_down(void);
void menu_left(void);
bool menu_right(keyrecord_t*);
void menu_reset(void);
MenuEntry get_entry(Menu*, uint8_t);

void oled_print_menu(void);
