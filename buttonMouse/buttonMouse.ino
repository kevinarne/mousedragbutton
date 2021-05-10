#include <Mouse.h>

#define DEBOUNCE 140
#define BUTTON_PIN A3

boolean pressed = false;
long lastPressed = 0;
boolean stateToggled = false;

void setup() 
{
  Mouse.begin();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() 
{
  boolean currentState = digitalRead(BUTTON_PIN); //Low means the button is pressed
  
  long timeSincePressed = millis() - lastPressed;
  
  if (!currentState && timeSincePressed > DEBOUNCE) //Switch ties the pin to ground, thus active low
  { 
      lastPressed = millis();
      pressed = !pressed; //Toggle state
      stateToggled = true;  //Flag that the state has changed
  }
  
  if(pressed && stateToggled)
  {
    Mouse.press();
    stateToggled = false;
  }
  if (pressed == false)
  {
    Mouse.release();
  }
}
