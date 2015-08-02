#include <pebble.h>
#include "comeback.h"
#include "feature_simple_menu_layer.h"


#include <pebble.h>

static Window *s_main_window3;
static TextLayer *s_time_layer2;  
static TextLayer *s_weather_layer2;
static GFont *s_time_font2;



void push_compliment(){
  window_stack_push(s_main_window3, true);
}

char **compliments = (char *[]){
      "Have you been working out?",
      "Hello, good looking.",
      "I would share my dessert with you.",
      "You could probably lead a rebellion.",
      "Being awesome is hard, but you\'ll manage.",
      "My mom always asks me why I can\'t be more like you",
      "The Force is strong with you.",
      "You complete me",
      "Glorious things are waiting for you.",
      "You\'re crazy hygienic, always brushing and flossing",
      "Your eyes are hella disarming",
      "You have a great sense of humor - that\'s personality",
      "You\'re a good listener even when you\'re exhausted",
  "Your booty is sweeter than eminems.",
      
"If I freeze, it's not a computer virus. I was just stunned by your beauty.",

"You make my data circuits skip a beat.",

"I'm jealous of the other apps you use, because I enjoy seeing you so much!",

"When I grow up, I want to be just like you.",

"Is it hot in here or is it just you?",

"You have a good taste in apps.",

"You have a very youthful wrist.",

"I appreciate you more than Santa appreciates chimney grease.",

"I usually don't say this on a first date, but will you marry me?",
"I request the highest of fives.",

"I love you more than bacon.",

"You're more fun than bubble wrap.",

"You are Chuck Norris's equal.",

"On a Cool Scale from 1-10, you're an eleventy-seven.",

"You make awkward silences not awkward.",

"I bet even your farts smell great.",

"You make me forget what time it is.",

"I would volunteer to replace you in the Hunger Games.",

"Your wrist compliments my form perfectly.",

"You listen to the best music.",

"Me without you is like Jarvis without Mr. Stark.",

"You make me short circuit.",

"You make me feel like a Dumbwatch.",

"You're smart enough to convince Lady Gaga to wear normal clothes.",

"I'd give you the time of day.",

"You make me forget my programming.",

"Do you have a map? I got lost in your eyes.",

"You could outsmart Batman.",

"You must work out. I'd bet you could beat the Hulk in an arm wrestle.",

"Next to you, I feel like a Grain-of-Sand Smartwatch.",

"You make always make me feel fully charged.",

"You are the reason I wish I had a microphone and speaker.",

"Your jokes always make me laugh.",

  "You have to most outstanding wrist I've ever felt.",};



static void main_window_load(Window *window) {
  // Create GBitmap, then set to created BitmapLayer
 
  s_time_font2 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_fatface_15));
  // Create temperature Layer
  s_weather_layer2 = text_layer_create(GRect(4, 50, 136,100 ));
   text_layer_set_font(s_weather_layer2, s_time_font2);
  text_layer_set_background_color(s_weather_layer2, GColorWhite);
  text_layer_set_text_color(s_weather_layer2, GColorBlack);
  text_layer_set_text_alignment(s_weather_layer2, GTextAlignmentCenter);
  text_layer_set_text(s_weather_layer2, "Click for compliment");
  
  // Create time TextLayer

  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_weather_layer2));

  //time layer
}

static void main_window_unload(Window *window) {
    
    // Unload GFont
    fonts_unload_custom_font(s_time_font2);
    // Destroy time layer
    text_layer_destroy(s_time_layer2);
    // Destroy weather layer
    text_layer_destroy(s_weather_layer2);
    // destroy custom font
    // how to destroy the background image?
}
 static char temperature_buffer[100];
  static char conditions_buffer[100];
  static char weather_layer_buffer[1];

void inbox_received_callback2(DictionaryIterator *iterator, void *context) {
  // Store incoming information
 
  
 

  
  // Assemble full string and display
  text_layer_set_text(s_weather_layer2, conditions_buffer);
}
int score=50;
void select_click_handler2(){ 
   APP_LOG(APP_LOG_LEVEL_ERROR, "click");
 int r = rand() % score;
  
  static char buffer[5];
  
  snprintf(buffer, sizeof(buffer), "%d", r); // Adds one to remove 0 from possibilities
  
  // int r = rand() % 7;
  
  text_layer_set_text(s_weather_layer2, compliments[r]);              
                           }
static void click_config_provider2(void *context) {
  
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler2);
//register all events
}



void init3() {
 
  // Register with TickTimerService

  
  // Register callbacks


  
  // Create main Window element and assign to pointer
  s_main_window3 = window_create();
   window_set_click_config_provider(s_main_window3, click_config_provider2);
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window3, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the ndow on the watch, with animated=true
  window_stack_push(s_main_window3, true);
  
  // Make sure the time is displayed from the start
}

void deinit3() {
    // Destroy Window
    window_destroy(s_main_window3);
}

/*int main(void) {
  init();
  app_event_loop();
  deinit();
} */