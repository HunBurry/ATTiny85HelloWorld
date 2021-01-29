#include <Bounce2.h>

int mode, light, button;
boolean state;
Bounce b = Bounce();

void setup() {
  /*
  * Set up variables and create a debouncer for the
  * button to prevent hold issues. Also determine 
  * input/output. 
  */
  mode = 0;
  state = true;
  light = 1;
  button = 0;
  
  b.attach(button, INPUT_PULLUP);
  b.interval(50);

  pinMode(light, OUTPUT);
}

void loop() {
  /*
  * Update button status. If our button is 
  * pressed, we change the mode through the 
  * state button. After checking the button,
  * activate whatever state we are currently in.
  */
  b.update();
  if (b.rose()) {
    changeMode();
  }
  activate();
}

void changeMode() {
  /*
  * Either add one to the mode to increment, or
  * reset back to zero if at max mode. 
  */
  if (mode == 2) {
    mode = 0;
  }
  else {
    mode++;
  }
}

void activate() {
  /*
  * If mode is 0, turn the light off. If the 
  * mode is 1, turn the light one, and if the 
  * mode is 2, we flop whatever state we are in,
  * set the light to the state, and add a delay. 
  */
  if (mode == 0) {
    digitalWrite(light, false);
  }
  else if (mode == 1) {
    digitalWrite(light, true);
  }
  else if (mode == 2) {
   state = !state; 
   digitalWrite(light, state);
   delay(100);
  } 
}
