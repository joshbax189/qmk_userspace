
#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    MENU_SUB, // data is another menu
    MENU_KC,  // data is a keycode
    MENU_FN,  // data is a function
} menu_action_t;

typedef struct menu_entry_t menu_entry_t;
typedef union menu_data_t menu_data_t;
typedef struct menu_t menu_t;

struct menu_t {
    menu_entry_t* entries;
    uint8_t index;
    menu_t* parent; // linked list path to current menu
};

union menu_data_t {
    uint16_t keycode;
    menu_t* subMenu;
    void (*menuFn)(keyrecord_t*);
};

struct menu_entry_t {
    char* menuText;
    menu_action_t menuType;
    menu_data_t menuData; // either a pointer or a keycode
};

void menu_up(void);
void menu_down(void);
void menu_left(void);
bool menu_right(keyrecord_t*);
void menu_reset(void);
menu_entry_t get_entry(menu_t*, uint8_t);

void oled_print_menu(void);
