/*#include <pebble.h>
#include "comeback.h"
#include "feature_simple_menu_layer.h"

#define KEY_comeback 0
#define KEY_compliments 1


#include <pebble.h>

static Window *s_main_window2;
static TextLayer *s_time_layer;  
static TextLayer *s_weather_layer;
static GFont *s_time_font;


void push_roll(){
  window_stack_push(s_main_window2, true);
}


static void main_window_load(Window *window) {
  // Create GBitmap, then set to created BitmapLayer
 
  s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_fatface_15));
  // Create temperature Layer
  s_weather_layer = text_layer_create(GRect(4, 20, 136,160 ));
   text_layer_set_font(s_weather_layer, s_time_font);
  text_layer_set_background_color(s_weather_layer, GColorWhite);
  text_layer_set_text_color(s_weather_layer, GColorBlack);
  text_layer_set_text_alignment(s_weather_layer, GTextAlignmentCenter);
  text_layer_set_text(s_weather_layer, "Click for insult");
  APP_LOG(APP_LOG_LEVEL_ERROR, "click handler!");
  APP_LOG(APP_LOG_LEVEL_ERROR, "window load");
  
  
  // Create time TextLayer

  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_weather_layer));

  //time layer
}

static void main_window_unload(Window *window) {
    
    // Unload GFont
    fonts_unload_custom_font(s_time_font);
    // Destroy time layer
    text_layer_destroy(s_time_layer);
    // Destroy weather layer
    text_layer_destroy(s_weather_layer);
    // destroy custom font
    // how to destroy the background image?
}
 static char temperature_buffer[100];
  static char conditions_buffer[100];
  static char weather_layer_buffer[1];

void 
  inbox_received_callback(DictionaryIterator *iterator, void *context) {
  // Store incoming information
 
  
  // Read first item
  Tuple *t = dict_read_first(iterator);

  // For all items
  while(t != NULL) {
    // Which key was received?
    switch(t->key) {
    case KEY_compliments:
      snprintf(temperature_buffer, sizeof(temperature_buffer), "%dF", (int)t->value->int32);
      break;
    case KEY_comeback:
      snprintf(conditions_buffer, sizeof(conditions_buffer), "%s", t->value->cstring);
      break;
    default:
      APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized!", (int)t->key);
      break;
    }

    // Look for next item
    t = dict_read_next(iterator);
  }
  
  // Assemble full string and display
  text_layer_set_text(s_weather_layer, conditions_buffer);
}

void select_click_handler(){ 
APP_LOG(APP_LOG_LEVEL_ERROR, "click handler!");
  DictionaryIterator *iter;
  app_message_outbox_begin(&iter);
   // Add a key-value pair
    dict_write_uint8(iter, 0, 0);
  
    // Send the message!
    app_message_outbox_send();
  text_layer_set_text(s_weather_layer, conditions_buffer); ;
}
             
                           
static void click_config_provider(void *context) {
  
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
//register all events
}



void init2() {
 
  // Register with TickTimerService

  
  // Register callbacks
  app_message_register_inbox_received(inbox_received_callback);
  // Open AppMessage
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());

  
  // Create main Window element and assign to pointer
  s_main_window2 = window_create();
   window_set_click_config_provider(s_main_window2, click_config_provider);
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window2, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the ndow on the watch, with animated=true
  window_stack_push(s_main_window2, true);
  
  // Make sure the time is displayed from the start
}

void deinit2() {
    // Destroy Window
    window_destroy(s_main_window2);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
} */