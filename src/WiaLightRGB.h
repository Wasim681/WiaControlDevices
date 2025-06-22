#ifndef WIA_CLASS_LIGHT_RGB_DEV 
  #define WIA_CLASS_LIGHT_RGB_DEV
/*
--------------------------------------------------------------------------------------- 
------------------------------------ Define Checks ------------------------------------ 
--------------------------------------------------------------------------------------- 
*/  
  #include "WiaLightBase.h"

  #ifndef COLOR_LEVEL_MAX
    #define COLOR_LEVEL_MAX 255
  #endif
  #ifndef COLOR_LEVEL_MIN
    #define COLOR_LEVEL_MIN  0
  #endif
/*
--------------------------------------------------------------------------------------- 
-------------------------------------- Class ------------------------------------ 
--------------------------------------------------------------------------------------- 
*/  
  class WiaLightRGB: public WiaLightBase{
    public:
      WiaLightRGB(int r = -1, int g = -1, int b = -1):_gpr(r), _gpg(g), _gpb(b){ }
      
      int getR(){ return cr; }
      int getG(){ return cg; }
      int getB(){ return cb; }
      
      bool init() override { if(_gpr == -1 || _gpg == -1 || _gpb == -1) return false;
        pinMode(_gpr, OUTPUT);
        pinMode(_gpg, OUTPUT);
        pinMode(_gpb, OUTPUT);
        isInit = true;
		return set(lightState);
        }
      bool set(bool state) 			override { if(!isInit) return false; 
		if(state) takeAction(cr, cg, cb); else takeAction(WIA_LIGHT_OFF, WIA_LIGHT_OFF, WIA_LIGHT_OFF);
        lightState = state;
		return true;
        }
      bool set(bool state, int bri) override { if(!isInit) return false;
        setBrightness(bri);
        return set(state);
        }
      bool setColor(int r, int g, int b)	 	 { if(!isInit) return false;
        takeAction(r, g, b);
        cr = constrain(r, WIA_LIGHT_OFF, WIA_LIGHT_ON);
        cg = constrain(g, WIA_LIGHT_OFF, WIA_LIGHT_ON);
        cb = constrain(b, WIA_LIGHT_OFF, WIA_LIGHT_ON);
        return true;
        }
      bool setColor(int r, int g, int b, int bri){ if(!isInit) return false;
        setBrightness(bri);
        return setColor(r, g, b);
        }
      void setDefaultColor(int r, int g, int b){
        cr = constrain(r, WIA_LIGHT_OFF, WIA_LIGHT_ON);
        cg = constrain(g, WIA_LIGHT_OFF, WIA_LIGHT_ON);
        cb = constrain(b, WIA_LIGHT_OFF, WIA_LIGHT_ON);
      }
    protected:
      void takeAction(int toR, int toG, int toB, int delayTime = 30, int steps = 30) {
        if(!isTrans){
          setPwm(_gpr, toR);
          setPwm(_gpg, toG);
          setPwm(_gpb, toB);
          return;
        }
        
        int fr = WIA_LIGHT_OFF, fg = WIA_LIGHT_OFF, fb = WIA_LIGHT_OFF;
        if(lightState){ fr = cr; fg = cg; fb = cb; }

        int newValR, newValG, newValB;
        for (int i = 0; i <= steps; i++) {   

          newValR = map(i, 0, steps, fr, toR);  
          newValG = map(i, 0, steps, fg, toG);  
          newValB = map(i, 0, steps, fb, toB);  

          setPwm(_gpr, newValR);
          setPwm(_gpg, newValG);
          setPwm(_gpb, newValB);

          delay(delayTime);
        }
      }  
    private:      

      int cr = WIA_LIGHT_ON; 
      int cg = WIA_LIGHT_ON;
      int cb = WIA_LIGHT_ON;

      int _gpr, _gpg, _gpb;  
  };

#endif