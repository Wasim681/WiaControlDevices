#ifndef WIA_CLASS_LIGHT_DEV_BASE 
  #define WIA_CLASS_LIGHT_DEV_BASE
/*
--------------------------------------------------------------------------------------- 
------------------------------------ Define Checks ------------------------------------ 
--------------------------------------------------------------------------------------- 
*/ 

  #ifndef PWM_LEVEL_MAX
    #if defined(ESP32)
      #define PWM_LEVEL_MAX 4095 
    #else
      #define PWM_LEVEL_MAX 1023
    #endif
  #endif
  #ifndef PWM_LEVEL_MIN
    #define PWM_LEVEL_MIN 0
  #endif

  #ifndef BRIGTHNESS_LEVEL_MAX
    #define BRIGTHNESS_LEVEL_MAX 100
  #endif
  #ifndef BRIGTHNESS_LEVEL_MIN
    #define BRIGTHNESS_LEVEL_MIN 0
  #endif

  #ifndef WIA_LIGHT_ON
    #define WIA_LIGHT_ON 255
  #endif
  #ifndef WIA_LIGHT_OFF
    #define WIA_LIGHT_OFF 0
  #endif

/*
--------------------------------------------------------------------------------------- 
-------------------------------------- Class ------------------------------------ 
--------------------------------------------------------------------------------------- 
*/  

  class WiaLightBase{
    public:
      bool isInitialized() { return isInit; }
      bool isOn(){ return lightState; }
      int getBrightness(){ return brightness * BRIGTHNESS_LEVEL_MAX; }
      bool isTransition(){ return isTrans; }
      void setTransition(bool on){ isTrans = on; }
      bool toggle() { return (lightState? turnOff() : turnOn()); }
      void setDefaultState(bool state){ lightState = state; }
      
      bool turnOn() { return set(true); }
      bool turnOff(){ return set(false); }
	  
      virtual bool init() = 0;
      virtual bool set(bool state) = 0;
      virtual bool set(bool state, int bri) = 0;

    protected:
      void setPwm(int pin, int val){ analogWrite(pin, val * brightness); }
      void setBrightness(int bri) { brightness = constrain(bri, BRIGTHNESS_LEVEL_MIN, BRIGTHNESS_LEVEL_MAX)/BRIGTHNESS_LEVEL_MAX; }
      int brightness = BRIGTHNESS_LEVEL_MAX; 
      bool lightState = false;
      bool isInit = false;
      bool isTrans = false;


  };

#endif