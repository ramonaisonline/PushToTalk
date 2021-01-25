#include <Keyboard.h>                                   // This library lets a 32u4 board pretend to be a keyboard


#define PIN_LED 5                                       // Set what pins our hardware is connected to
#define BUTTON_PIN 11


bool lastButtonState = HIGH;                            // Variables to track signals from the button
bool currentButtonState = HIGH;


int debounce = 50;                                      // Define a small delay to slow down our sensing so we don't get double-presses
uint32_t lastCheckTime = millis();


void setup() {                                          // The setup function runs once when you press reset or power the board
  
  pinMode(PIN_LED, OUTPUT);                             // Set the LED pin to be an output
  pinMode(BUTTON_PIN, INPUT_PULLUP);                    // Set the button pin to be an input
  
} 


void loop() {                                           // the loop function runs over and over again forever
  
  if (millis() > lastCheckTime + debounce) {            // If it's time to check on our button...

    
    currentButtonState = digitalRead(BUTTON_PIN);       // Read the button state...
    lastCheckTime = millis();

    
    if (currentButtonState != lastButtonState) {        // If it's different than last time we checked...

      
      if (currentButtonState == LOW) {                  // If the button is DOWN...
        digitalWrite(PIN_LED, HIGH);                    // Turn on the light
        Keyboard.press(KEY_RIGHT_GUI);                  // Send a keypress event!!
      }                                                 // Look up the docs for Keyboard.h to figure out what key you want to use :)

      
      else if (currentButtonState == HIGH) {            // If the button is UP...
        digitalWrite(PIN_LED, LOW);                     // Turn off the light
        Keyboard.releaseAll();                          // Send a key release event
      }
  
      lastButtonState = currentButtonState;             // Update our variable to keep track of the button state
    }
    
  }
  
}
