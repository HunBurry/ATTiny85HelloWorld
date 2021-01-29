#include <Bounce2.h>

int mode, light, button;
boolean state;
Bounce b = Bounce();

void setup() {
  mode = 0;
  state = true;
  light = 1;
  button = 0;
  
  b.attach(button, INPUT_PULLUP);
  b.interval(50);

  pinMode(light, OUTPUT);
}

void loop() {
  b.update();
  if (b.rose()) {
    changeMode();
  }
  activate();
}

void changeMode() {
  if (mode == 2) {
    mode = 0;
  }
  else {
    mode++;
  }
}

void activate() {
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
