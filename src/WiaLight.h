#ifndef WIA_CLASS_LIGHT_DEV 
  #define WIA_CLASS_LIGHT_DEV

  #include "WiaLightBase.h"
/*
--------------------------------------------------------------------------------------- 
-------------------------------------- Class ------------------------------------ 
--------------------------------------------------------------------------------------- 
*/  

  class WiaLight : public WiaLightBase{
    public:
      WiaLight(int pin = -1):_gpo(pin){ }
      bool init(bool defaultState = true) override { if(_gpo == -1) return false;
        pinMode(_gpo, OUTPUT);
        isInit = true;
        lightState = defaultState;
        
        (lightState ? turnOn() : turnOff());
        
        return true;
        }
  
      bool set(bool state) override { if(!isInit) return false;
        takeAction(state? WIA_LIGHT_ON : WIA_LIGHT_OFF);
        lightState = state;
        return true;
        }
      bool set(bool state, int bri) override { if(!isInit) return false;
        setBrightness(bri);
        return set(state);
        }
      bool turnOn() override {if(!isInit) return false;
        takeAction(WIA_LIGHT_ON);
        lightState = true;
        return true;
        }
      bool turnOff() override {if(!isInit) return false;
        takeAction(WIA_LIGHT_OFF);
        lightState = false;
        return true;
        }
    protected: 
      void takeAction(int to, int delayTime = 30, int steps = 30) {
        if(!isTrans){
          setPwm(_gpo, to);
          return;
        }
        int from = (lightState? WIA_LIGHT_ON : WIA_LIGHT_OFF);
        int newVal;
        for (int i = 0; i <= steps; i++) {    
          newVal = map(i, 0, steps, from, to);  
          setPwm(_gpo, newVal);
          delay(delayTime);
        }
      }  
    private:        
      int _gpo;   
  };

#endif