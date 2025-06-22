#ifndef WIA_CLASS_SWITCH_DEV
  #define WIA_CLASS_SWITCH_DEV
/*
--------------------------------------------------------------------------------------- 
------------------------------------ Define Checks ------------------------------------ 
--------------------------------------------------------------------------------------- 
*/ 

/*
--------------------------------------------------------------------------------------- 
-------------------------------------- Class ------------------------------------ 
--------------------------------------------------------------------------------------- 
*/  

  class WiaSwitch{
    public:
	  WiaSwitch(int pin) : _pin(pin){}
      bool isInitialized() { return isInit; }
      bool isOn(){ return switchState; }
      bool toggle() { return (switchState? turnOff() : turnOn()); }
      void setDefaultState(bool state){ switchState = state; }
      
      bool init() { if(_pin == -1) return false;
		pinMode(_pin, OUTPUT);
		isInit = true;
		return set(switchState);
	    }
      bool turnOn()  { if(!isInit) return false; digitalWrite(_pin, HIGH); switchState= true; return true; }
      bool turnOff() { if(!isInit) return false; digitalWrite(_pin, LOW); switchState= false; return true; }
      bool set(bool state) { return (state? turnOn() : turnOff()); }
	  
	private:
      bool switchState = false;
      bool isInit = false;
	  int _pin = -1; 

  };

#endif