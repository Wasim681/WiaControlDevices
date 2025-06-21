/*
  this example show the a RGB light changging color every '5 sec'  
  some other possible actions are also mentioned in the commented code
*/

#include <WiaLightRGB.h>

const int red_pin 14;
const int green_pin 12;
const int blue_pin 13;

WiaLightRGB light(red_pin, green_pin, blue_pin);

void setup() {
  light.init();  // default argumnet is true, if u want light to turn on by default
  //light.init(false);   

  //light.setTransition(true); // if u want light to turn on and off by dimming by default it is set false
  //light.set(true); // set state of light
  //light.set(true, 100); // set state of light with brightness[0 - 100]
  light.setColor(255, 0, 0); // setting red color 
  //light.setColor(255, 0, 0, 50); // setting red color with 50 percent brightness[0 - 100]
}
void loop() {
  light.setColor(0, 255, 0);
  delay(5000);
  light.setColor(0, 0, 255);
  delay(5000);
  light.setColor(255, 0 , 0);
  delay(5000);

}
