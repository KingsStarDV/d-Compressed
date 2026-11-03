// ESP32-C3 Mini: fire a solenoid valve for a short burst when a button is pressed
//
// Wiring:
//   GPIO0  -> 100 ohm -> MOSFET gate (10k pull-down gate to GND)
//   GPIO21 -> button -> GND  (internal pull-up used, pressed = LOW)
//
// Note: GPIO21 is the UART0 TX pin on the C3, so this sketch does not use
// Serial on UART0. If you need debug prints, enable "USB CDC On Boot" in
// Tools menu and use Serial normally.

const int VALVE_PIN  = 0;    // MOSFET gate
const int BUTTON_PIN = 21;   // button to GND

// How long the valve stays open per button press (milliseconds)
unsigned long single_burst_time = 50;

const unsigned long DEBOUNCE_MS = 30;

void setup() {
  pinMode(VALVE_PIN, OUTPUT);
  digitalWrite(VALVE_PIN, LOW);      // valve closed at startup

  pinMode(BUTTON_PIN, INPUT_PULLUP); // pressed = LOW
}

void fireValve() {
  digitalWrite(VALVE_PIN, HIGH);     // MOSFET on -> valve opens
  delay(single_burst_time);
  digitalWrite(VALVE_PIN, LOW);      // MOSFET off -> valve closes
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(DEBOUNCE_MS);                      // debounce
    if (digitalRead(BUTTON_PIN) == LOW) {    // still pressed -> valid press
      fireValve();

      // Wait for release so holding the button gives only one burst
      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(5);
      }
      delay(DEBOUNCE_MS);                    // debounce on release
    }
  }
}
