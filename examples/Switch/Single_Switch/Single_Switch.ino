/*
  In this example a Switch functions and ease for the use is shown 
  a switch is being toggle after 5000 millis  ... with different approch
  some other possible actions are also mentioned in the commented code
*/

#include <WiaSwitch.h>

WiaSwitch switch1(14);

void setup() {
  switch1.setDefaultState(true); // switch default state will be ON
  switch1.init();  // must be initializing before calling any action 

  switch1.set(false); // set state of swtich .... this function must only be called if init() function is already called
}
void loop() {
  switch1.turnOn();  // will turn on switch
  delay(5000);
  switch1.turnOff();  // will turnoff
  delay(5000);
  switch1.toggle(); // toggling will also turn it on here as previous state was off
  delay(5000);
  switch1.set(false); // again this will turn off
  delay(5000);

}
