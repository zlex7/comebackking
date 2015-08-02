#include <pebble.h>
#include "comeback.h"
#include "feature_simple_menu_layer.h"


#include <pebble.h>

static Window *s_main_window2;
static TextLayer *s_time_layer;  
static TextLayer *s_weather_layer;
static GFont *s_time_font;



void push_roll(){
  window_stack_push(s_main_window2, true);
}

char **Insult = (char *[]){
"Kanye West has more talent than you.",
"You are the reason why McDonald's charges for condiments.",
"A sheep looks intelligent next to you.",
"You make a sloth look like an Olympic track runner.",
"I'd rather listen to a donkey sing than you speak.",
"You smell so bad, the maggots reject you.",
"Even starving kids in Africa don't envy your life.",
"You could turn Medusa to stone.",
"Do you still love Mother Earth despite what she did to you?",
"If opposites attract, I'd bet you'll meet an extremely hot genius.",
"If laughter is the best medicine, your face should cure any disease.",
"You're so ugly, Hello Kitty said 'goodbye' to you.",
"Brains aren't everything. In your case, they're not anything.",
"Don't let your mind wander. It's too small to be let out on its own.",
"I think your train of thought got derailed several years back.",
"Can I borrow your face for a few days? My ass is going taking a holiday.",
"If I wanted to kill myself, I'd jump from your ego to your IQ.",
"You're less useful than snake combat boots.",
"Wait... I thought that Kansas girl dropped a house on you...",
"I'm jealous of people who've never met you.",
"If we were the last people on Earth, I still wouldn't speak to you.",
"Mother Earth only created you to have someone to laugh at.",
"I could have a more interesting conversation with a mute.",
"I've scraped more interesting things off the bottom of my shoe.",
"If you think you need beauty sleep, I suggest hibernating for the winter.",
"Is your ass jealous of all the shit that just spewed out of your mouth?",
"Roses are red. Violets are blue. I have five fingers. The third one's for you.",
"If you were on fire and I had water, I'd water my daisies.",
"If you were on life support, I'd unplug you so I could charge my phone.",
"You have some food on your chin. No, your third one.",
"I would agree with you, but then we'd both be wrong.",
"If you tried to speak your mind, you'd be left speechless.",
"Your face makes onions cry.",
"Your parents must be twins.",
"You're the reason the genepool needs a lifeguard.",
"Looks aren’t everything. In your case, they're not anything.",
"You're so ugly, when you threw a boomerang, it didn't come back.",
"I'd like to help you out. Which way did you come in?",
"I wonder what you’d be like if you'd had oxygen at birth?",
"If your brain exploded, it wouldn't even mess up your hair.",
"You're evidence against Darwin's theory of evolution.",
"If I was your parent, I'd have thrown you out and kept the stork.",
"I'd like to give you a going-away present, but you've got to do your part.",
"Your inferiority complex is totally justified.",
"I'd ask you how old you are, but I doubt you can count that high.",
"Oh my God! Is it Halloween already?",
"I'd like to ask you out. The door is that way.",
"I've seen people like you before, but I usually have to pay admission.",
"I don't have enough middle fingers to describe my opinion of you.",
"I'd recommend never entering a battle of wits unarmed.",
};



static void main_window_load(Window *window) {
  // Create GBitmap, then set to created BitmapLayer
 
  s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_fatface_15));
  // Create temperature Layer
  s_weather_layer = text_layer_create(GRect(4, 20, 136,150 ));
   text_layer_set_font(s_weather_layer, s_time_font);
  text_layer_set_background_color(s_weather_layer, GColorWhite);
  text_layer_set_text_color(s_weather_layer, GColorBlack);
  text_layer_set_text_alignment(s_weather_layer, GTextAlignmentCenter);
  text_layer_set_text(s_weather_layer, "Click for insult");
  
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

void inbox_received_callback(DictionaryIterator *iterator, void *context) {
  // Store incoming information
 
  
 

  
  // Assemble full string and display
  text_layer_set_text(s_weather_layer, conditions_buffer);
}
int score3=50;
void select_click_handler(){ 
   APP_LOG(APP_LOG_LEVEL_ERROR, "click");
 int r = rand() % score3;
  
  static char buffer[5];
  
  snprintf(buffer, sizeof(buffer), "%d", r); // Adds one to remove 0 from possibilities
  
  // int r = rand() % 7;
  
  text_layer_set_text(s_weather_layer, Insult[r]);              
                           }
static void click_config_provider(void *context) {
  
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
//register all events
}



void init2() {
 
  // Register with TickTimerService

  
  // Register callbacks


  
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

/*int main(void) {
  init();
  app_event_loop();
  deinit();
} */