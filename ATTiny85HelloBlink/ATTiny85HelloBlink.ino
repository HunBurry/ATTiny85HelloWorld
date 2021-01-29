int light;

void setup() {
  light = 1;
  pinMode(light, OUTPUT);
}

void loop() {
  digitalWrite(light, true);
  delay(250);
  digitalWrite(light, false);
  delay(250);
}