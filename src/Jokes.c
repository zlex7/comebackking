#include <pebble.h>
#include "comeback.h"
#include "feature_simple_menu_layer.h"
#include "Jokes.h"
static Window *s_main_window4;
static TextLayer *s_time_layer3;  
static TextLayer *s_weather_layer3;
static GFont *s_time_font3;



void push_joke(){
  window_stack_push(s_main_window4, true);
}

char **joke = (char *[]){ "It’s hard to explain puns to kleptomaniacs because they always take things literally.",

"I used to think the brain was the most important organ. Then I thought, look what’s telling me that.",

"The midget fortune teller who kills his customers is a small medium at large.",

"A farmer in the field with his cows counted 196 of them, but when he rounded them up he had 200.",

"What does a nosey pepper do? Get jalapeño business.",

"What is Bruce Lee’s favorite drink? Wataaaaah!",

"The dyslexic devil worshipper sold his soul to Santa.",
                                
                                "BOOBS",

"You kill vegetarian vampires with a steak to the heart.",

 "There was a prison break and I saw a midget climb up the fence. As he jumped down her sneered at me and I thought, well that’s a little condescending.",

"If you want to catch a squirrel just climb a tree and act like a nut.",

"So this guy with a premature ejaculation problem comes out of nowhere.",

"A magician was walking down the street and turned into a grocery store.",

"A blind man walks into a bar. And a table. And a chair.",

"Why don’t you ever see hippopotamus hiding in trees? Because they're really good at it.",

"Did you hear about the Mexican train killer? He had locomotives.",

"How does NASA organize their company parties? They planet.",

"Why can’t you hear a pterodactyl go to the bathroom? Because the “P” is silent.",

 "What kind of shoes do ninjas wear? Sneakers.",

 "Why does Snoop Dogg carry an umbrella? Fo' drizzle.",

"Did you hear about the new corduroy pillows? They're making headlines everywhere!",

"Why was six afraid of seven? Because seven was a well known six offender.",

"What time is it when you have to go to the dentist? Tooth-hurtie.",

"My friend recently got crushed by a pile of books, but he’s only got his shelf to blame.",

"What did Jay-Z call his girlfriend before they got married? Feyoncé.",

"Time flies like an arrow, fruit flies like banana.",

"How many kids with ADHD does it take to change a light bulb? Let’s go play on our bikes.",

"What do you call dangerous precipitation? A rain of terror.",

"What’s the best part about living in Switzerland? Not sure, but the flag is a big plus.",

"Two fish are in a tank. One turns to the other and asks 'How do you drive this thing?'",

"Why can’t a bike stand on its own? It’s two tired.",

"Why didn’t the lifeguard save the hippie? Because he was too far out man!",

"Last night I almost had a threesome, I only needed two more people!",

"What do you call a big pile of kittens? A meowntain.",

  "I wondered why the baseball was getting bigger. Then it hit me.",

"Atheism is a non-prophet organization.",

"Just went to an emotional wedding. Even the cake was in tier.",

"When you get a bladder infection, urine trouble.",

"I wrote a song about a tortilla. Well actually, it’s more of a wrap.",

 "What do you call a dinosaur with a extensive vocabulary? A thesaurus.",

"How did the hipster burn his tongue? He drank his coffee before it was cool.",

"PMS should just be called ovary-acting.",

"Marketing companies should use chromosomes in advertisements because sex cells.",

"Pampered cows produce spoiled milk.",

"Learn sign language, it’s very handy.",

"I started a band called 999 Megabytes — we haven’t gotten a gig yet.",

"You want to hear a pizza joke? Never mind, it’s pretty cheesy.",

"What is the difference between ignorance and apathy? I don’t know, and I don’t care.",


"Dry erase boards are remarkable.",

 "Dwarfs and midgets have very little in common."

"How do you make Holy water? Boil the hell out of it."
};

static void main_window_load(Window *window) {
  // Create GBitmap, then set to created BitmapLayer
 
  s_time_font3 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_fatface_15));
  // Create temperature Layer
  s_weather_layer3 = text_layer_create(GRect(4, 50, 136,100 ));
   text_layer_set_font(s_weather_layer3, s_time_font3);
  text_layer_set_background_color(s_weather_layer3, GColorWhite);
  text_layer_set_text_color(s_weather_layer3, GColorBlack);
  text_layer_set_text_alignment(s_weather_layer3,GTextAlignmentCenter);
  text_layer_set_text(s_weather_layer3, "Click for joke");
  
  // Create time TextLayer

  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_weather_layer3));

  //time layer
}

static void main_window_unload(Window *window) {
    
    // Unload GFont
    fonts_unload_custom_font(s_time_font3);
    // Destroy time layer
    text_layer_destroy(s_time_layer3);
    // Destroy weather layer
    text_layer_destroy(s_weather_layer3);
    // destroy custom font
    // how to destroy the background image?
}
 static char temperature_buffer[100];
  static char conditions_buffer[100];
  static char weather_layer_buffer[1];

void inbox_received_callback3(DictionaryIterator *iterator, void *context) {
  // Store incoming information
 
  
 

  
  // Assemble full string and display
  text_layer_set_text(s_weather_layer3, conditions_buffer);
}
int score2=50;
void select_click_handler3(){ 
   APP_LOG(APP_LOG_LEVEL_ERROR, "click");
 int r = rand() % score2;
  static char buffer[5];
  
  snprintf(buffer, sizeof(buffer), "%d", r); // Adds one to remove 0 from possibilities
  
  // int r = rand() % 7;
  
  text_layer_set_text(s_weather_layer3, joke[r]);              
                           }
static void click_config_provider3(void *context) {
  
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler3);
//register all events
}



void init4() {
 
  // Register with TickTimerService

  
  // Register callbacks


  
  // Create main Window element and assign to pointer
  s_main_window4 = window_create();
   window_set_click_config_provider(s_main_window4, click_config_provider3);
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window4, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the ndow on the watch, with animated=true
  window_stack_push(s_main_window4, true);
  
  // Make sure the time is displayed from the start
}

void deinit4() {
    // Destroy Window
    window_destroy(s_main_window4);
}
/*
int main(void) {
  init3();
  app_event_loop();
  deinit3();
} */