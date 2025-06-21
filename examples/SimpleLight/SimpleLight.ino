/*
  this example show the simple dimmable light toggling every '5 sec' 
  it is not necessary for light to be dimmable 
  some other possible actions are also mentioned in the commented code
*/

#include <WiaLight.h>

WiaLight light(14);

void setup() {
  light.init(); 

  //light.setTransition(true); // if u want light to turn on and off by dimming by default it is set false
  //light.set(true); // set state of light
  //light.set(true, 100); // set state of light with brightness[0 - 100]
  
}

void loop() {
  /*
  light.turnOn();
  delay(5000);

  light.turnOff();
  delay(5000);
  */
  
  // above action canbe performed with this code as well

  light.toggle();
  delay(5000);
}
