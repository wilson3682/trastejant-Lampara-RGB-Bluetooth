#include <SoftwareSerial.h>
#include <FastLED.h>

SoftwareSerial BT1(11,10); // RX, TX recorder que se cruzan


#define NUM_LEDS 16 // Número de leds de la tira
#define DATA_PIN 3  // El pin en la placa de arduino para conectar con el pin de datos de la tira

CRGB leds[NUM_LEDS];

int orden,i,ihue = 0;

void setup()
   {
       Serial.begin(9600);
       Serial.println("Enter AT commands:");
       BT1.begin(9600);
       
       FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   }

void loop(){
       if (BT1.available())
           orden = BT1.read();
           Serial.flush();
           char comando = char(orden);
           Serial.println(orden, DEC);
           
           switch(orden){
             case '0':
               for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::Black;}
               FastLED.show(); 
               delay(30); 
               break;
              
              case '1':
               for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::Red;}
               FastLED.show(); 
               delay(30); 
               break;
               
               case '2':
                for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::Green;}
                FastLED.show(); 
                delay(30);
                break;
               
              case '3':
                for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::Blue;FastLED.show(); }
                delay(30);
                break;
              
              case '4':
                for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::Orange;}
                FastLED.show(); 
                delay(30);
                break;
                
              case '5':
                for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::Pink;}
                FastLED.show(); 
                delay(30);
                break;
                
                case '6':
                for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::Yellow;}
                FastLED.show(); 
                delay(30);
                break;
                
                case '7':
                for(i = 0; i < NUM_LEDS; i++) {leds[i] = CRGB::White;}
                FastLED.show(); 
                delay(30);
                break;
                
                case '8':
                  rainbow_fade();
                break;
              
              case '9':
                cambiarIntensidad();
                break;                

           }
  BT1.flush();
  delay(500);           
}

  void cambiarIntensidad(){
    for(int b = 0; b<255; b++){FastLED.setBrightness(b);FastLED.show();delay(50);}    
  }
  
void rainbow_fade() {                         
    for(int i=0; i<25; i++) {
      ihue++;
      if (ihue > 255) {ihue = 0;}
      for(int idex = 0 ; idex < NUM_LEDS; idex++ ) {
        leds[idex] = CHSV(ihue, 255, 255);
      }
      LEDS.show();    
      delay(100);
    }
    
}
