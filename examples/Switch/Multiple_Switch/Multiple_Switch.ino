/*
  In this example a Switch functions and ease for the use is shown 
  two switchs are being toggle after 10000 millis.... apart each 5000 millis
  some other possible actions are also mentioned in the commented code
*/

#include <WiaSwitch.h>

WiaSwitch switch1(14);
WiaSwitch switch2(13);

void setup() {
  switch1.setDefaultSate(true); // switch default state will be ON
  switch1.init();  // must be initializing before calling any action 
  switch2.init();  // must be initializing before calling any action 

  switch1.set(false);   // set state of swtich .... this function must only be called if init() function is already called
}
void loop() {
  switch1.turnOn();   // switch 1 -> ON
  delay(5000);
  switch2.turnOff();  // switch 2 -> OFF
  delay(5000);
  switch1.toggle();   // switch 1 -> OFF
  delay(5000);
  switch2.set(true);  // switch 2 -> ON
  delay(5000);

}
