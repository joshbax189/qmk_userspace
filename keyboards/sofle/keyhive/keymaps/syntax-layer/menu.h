#pragma once

// longest sub menu
#define MENU_MAX_LENGTH 10

typedef enum {
    _TOP,
    _RGB,
    _UG,
    _BOOT
} MenuKeys;

/* The action this menu will produce */
typedef enum {
    MENU_SUB, // data is another menu
    MENU_KC,  // data is a keycode
} MenuType;

typedef struct MenuEntry MenuEntry;
typedef union MenuData MenuData;

union MenuData {
    uint16_t keycode;
    MenuKeys subMenu;
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
MenuEntry get_entry(MenuKeys, uint8_t);

void oled_print_menu(void);
