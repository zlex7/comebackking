#include <pebble.h>
  #include "comeback.h"
  #include "feature_simple_menu_layer.h"
  #include "compliment.h"
  #include "Jokes.h"
#define NUM_MENU_SECTIONS 1
#define NUM_FIRST_MENU_ITEMS 3

static Window *s_main_window;
static SimpleMenuLayer *s_simple_menu_layer;
static SimpleMenuSection s_menu_sections[NUM_MENU_SECTIONS];
static SimpleMenuItem s_first_menu_items[NUM_FIRST_MENU_ITEMS];
static GBitmap *s_menu_icon_image;
static GBitmap *icon_image2;
static GBitmap *joke_icon;

static void menu_select_callback(int index, void *ctx) {
  push_roll();

}

static void special_select_callback(int index, void *ctx) {
  // Of course, you can do more complicated things in a menu item select callback
  // Here, we have a simple toggle
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Index: %d", index);
  push_compliment();

}

static void special_select_callback2(int index, void *ctx) {
  // Of course, you can do more complicated things in a menu item select callback
  // Here, we have a simple toggle
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Index: %d", index);
  push_joke();

}
static void main_window_load(Window *window) {
  s_menu_icon_image = gbitmap_create_with_resource(RESOURCE_ID_fire);
  icon_image2=gbitmap_create_with_resource(RESOURCE_ID_heart);
  joke_icon=gbitmap_create_with_resource(RESOURCE_ID_Joke);
  // Although we already defined NUM_FIRST_MENU_ITEMS, you can define
  // an int as such to easily change the order of menu items later
  int num_a_items = 0;
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Comeback",
    .subtitle = "Spit hot fire!",
    .callback = menu_select_callback,
    .icon=s_menu_icon_image,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Compliments",
    .subtitle = "Flatter your friend",
    .callback = special_select_callback,
    .icon = icon_image2,
  };
   s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Jokes",
    .subtitle = "Please the crowd",
    .callback = special_select_callback2,
    .icon = joke_icon,
  };

  s_menu_sections[0] = (SimpleMenuSection) {
    .num_items = NUM_FIRST_MENU_ITEMS,
    .items = s_first_menu_items,
  };
 

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  s_simple_menu_layer = simple_menu_layer_create(bounds, window, s_menu_sections, NUM_MENU_SECTIONS, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(s_simple_menu_layer));
}

void main_window_unload(Window *window) {
  simple_menu_layer_destroy(s_simple_menu_layer);
  gbitmap_destroy(s_menu_icon_image);
}

static void init() {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  window_stack_push(s_main_window, true);
}

 static void deinit() {
  window_destroy(s_main_window);
}

int main() {
  init4();
init3();
init2();
  init();
  
  app_event_loop();
  deinit4();
  deinit3();
  deinit2();
  deinit();
}
