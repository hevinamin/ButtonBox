#include <Joystick.h>

Joystick_ joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_GAMEPAD,
  8, 0,               // 8 buttons, 0 hat switches
  false, false, false, // X, Y, Z
  false, false, false, // Rx, Ry, Rz
  false, false, false, false, false  // rudder, throttle, accelerator, brake, steering
);

const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  joystick.begin();
}

void loop() {
  for (int i = 0; i < 8; i++) {
    int pressed = (digitalRead(buttonPins[i]) == LOW);
    joystick.setButton(i, pressed);
  }
}
