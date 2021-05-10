#include <Mouse.h>

#define DEBOUNCE 40
#define BUTTON_PIN A3

boolean pressed = false;
long lastPressed = 0;

void setup() 
{
  Mouse.begin();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() 
{
  boolean currentState = digitalRead(BUTTON_PIN);
  
  long timeSincePressed = millis() - lastPressed;
  
  if (!currentState && timeSincePressed > DEBOUNCE) //Switch ties the pin to ground, thus active low
  { 
      lastPressed = millis();
      pressed = !pressed;   
  }
  
  if(pressed)
  {
    Mouse.press();
  }
  else
  {
    Mouse.release();
  }
}
