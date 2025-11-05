#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  //BUTTON PRESSES
  if (CircuitPlayground.rightButton()) {
    // pink glow and high beep
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 255, 20, 147);
    }
    CircuitPlayground.playTone(1000, 200);
  }
  else if (CircuitPlayground.leftButton()) {
  //green glow and low beep
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
    CircuitPlayground.playTone(500, 200);
  }

  //setting up motion detetion
  float x = CircuitPlayground.motionX();
  float y = CircuitPlayground.motionY();
  float z = CircuitPlayground.motionZ();

  // Calculate shake strength
  float shakeyshake = sqrt(x * x + y * y + z * z);

  //any number below 15 will activate this by just picking up the circuit
  if (shakeyshake > 15) {
    // flash red and blue 3 times
    for (int flashes = 0; flashes < 3; flashes++) {
      // red
      for (int i = 0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 0);
      }
      delay(150);
      // blue
      for (int i = 0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, 0, 0, 255);
      }
      delay(150);
    }
    // turn lights off after flashing
    CircuitPlayground.clearPixels();
  }

  delay(50);
}