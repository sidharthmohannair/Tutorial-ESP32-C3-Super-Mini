/*
  Blink

  Turns an LED on for two seconds, then off for one second, repeatedly.
  This is coded by Sidharth Mohan : https://github.com/sidharthmohannair/
*/
  /*
  Pin mappings:
  +----------------+--------------+---------------------------------------------+
  | Silkscreen pin | Internal pin | Notes                                       |
  +----------------+--------------+---------------------------------------------+
  | 0              | GPIO0        | ADC1                                        |
  | 1              | GPIO1        | ADC1                                        |
  | 2              | GPIO2        | ADC1, boot mode / strapping pin             |
  | 3              | GPIO3        | ADC1                                        |
  | 4              | GPIO4        | ADC1, JTAG                                  |
  | 5              | GPIO5        | JTAG                                        |
  | 6              | GPIO6        | JTAG                                        |
  | 7              | GPIO7        | JTAG                                        |
  | 8              | GPIO8        | Blue status_led (inverted), boot mode / strapping pin |
  | 9              | GPIO9        | Boot mode / strapping pin, boot button      |
  | 10             | GPIO10       |                                             |
  | 20             | GPIO20       |                                             |
  | 21             | GPIO21       |                                             |
  +----------------+--------------+---------------------------------------------+
*/

/*
  Notes on Pins:
  - The blue status_led is on GPIO8 and is inverted.
  - The Wemos C3 Mini documentation shows an RGB led on GPIO8, but that might be on the C3 Mini only (and not SuperMini).
  - Using status_led toggles a blue on-board LED on the C3 Super Mini.
  - The BOOT button is wired to GPIO9.
  - JTAG is available on GPIO4 - GPIO7.

  Strapping Pins:
  - GPIO2: Floating, controls Boot mode
  - GPIO8: Floating, controls Boot mode, ROM message printing
  - GPIO9: Pull-up, controls Boot mode

  Boot Modes:
  +------------------------+--------+--------+--------+
  | Mode                   | GPIO2  | GPIO8  | GPIO9  |
  +------------------------+--------+--------+--------+
  | SPI boot (default)     | HIGH   | Any    | HIGH   |
  | UART/JTAG download     | HIGH   | HIGH   | LOW    |
  +------------------------+--------+--------+--------+
*/


#define LED_BUILTIN 8 // Internal LED pin is 8 as per schematic

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (LOW because the LED is inverted)
  delay(2000);                      // wait for two seconds
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED off by making the voltage HIGH
  delay(1000);                      // wait for a second
}
