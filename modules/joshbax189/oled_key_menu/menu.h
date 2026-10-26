
#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    MENU_SUB, // data is another menu
    MENU_KC,  // data is a keycode
    MENU_FN,  // data is a function
} menu_action_t;

typedef struct menu_t menu_t;

typedef union {
    uint16_t keycode;
    menu_t* sub_menu;
    void (*callback)(keyrecord_t*);
} menu_data_t;

/* A single displayed line in a menu */
typedef struct {
    char* text;
    menu_action_t action_type;
    menu_data_t data;
} menu_entry_t;

/* A submenu together with its state */
struct menu_t {
    menu_entry_t* entries;
    uint8_t index;
    /* Forms a linked list back to top_menu, whose parent is NULL */
    menu_t* parent;
};

void menu_up(void);
void menu_down(void);
void menu_left(void);
bool menu_right(keyrecord_t*);
void menu_reset(void);
menu_entry_t menu_get_entry(uint8_t);

void menu_render_oled(void);

/* Menu Delimiter */
#define MENU_END { NULL, MENU_SUB, { 0 }}

# define SUB_MENU(name) MENU_SUB, { .sub_menu = &name }
# define FUNC_ACTION(name) MENU_FN, { .callback = &name }
# define KEY_ACTION(name) MENU_KC, { .keycode = name }

#define MAKE_MENU(name, ...) menu_entry_t name ## _entries[] = { __VA_ARGS__ MENU_END }; menu_t name = { .entries = name ## _entries, .index = 0, .parent = NULL }

#define TOP_MENU(...) MAKE_MENU(top_menu, __VA_ARGS__)
