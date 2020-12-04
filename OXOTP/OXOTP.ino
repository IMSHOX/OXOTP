/*
   .+ydmmmmmmmmmmmmmmdho:`     .ymms-              -ymmy.                       
 .ymmmmmmmmmmmmmmmmmmmmmmd+    /mmmmmy-          -ymmmmm/                       
-mmmmmho+++++++++++++smmmmmy    :hmmmmmy-      -ymmmmmy-                        
hmmmm/                `ymmmm/     :hmmmmmy-  -ymmmmmy-                          
mmmmm                  :mmmms       -ymmmmmyymmmmmy-                            
mmmmm                  :mmmmy         -ymmmmmmmmy-                              
mmmmm                  :mmmmy          -dmmmmmmd-                               
mmmmm                  :mmmmy        :hmmmmmmmmmmy-                             
mmmmm`                 +mmmmo      :hmmmmmy--ymmmmmy-                           
ommmmd/`             -ommmmm.    :hmmmmmy-    -ymmmmmy:                         
 ommmmmmmmmmmmmmmmmmmmmmmmd-   .hmmmmmy-        -ymmmmmh.                       
  -sdmmmmmmmmmmmmmmmmmmmh/`    /mmmmy-            -ymmmm/                       
     .:/+++++++++++++/-`        -+/.                ./+-                        
                                                                                
     :+sssssssssssssso/.        +ssssssssssssssssssss`     `sssssssssssssso/.   
  `odo-`            `./yh-                m:               .m:            ./yh- 
  yh`                   :m:               m:               .m:               :m/
 .m-                     sh               m:               .m:                om
 .m.                     sh               m:               .m:                od
 .m.                     sh               m:               .m:               /m:
 .m.                     sh               m:               .m:           `-+hs. 
 .m.                     sh               m:               .myooooooooooooo:`   
 `do                    `do               m:               .m:                  
  .hy-                `/do                m:               .m:                  
    :shyssssssssssssyyy+`                 m:               .m-                  
  
   
   ------------------------------------------
      Copyright (c) 2020 Mezghache imad
             github.com/spacehuhn
  -------------------------------------------
 */



//Download OXOTP APP now ANDROID ONLY, can be made for IOS/WINDOWS but in the future.
//Connect to OXOTP with app instructions.





#define maxOTPs 30                         // max OTP can hande OXOTP
#define timeout_ScreenOn 180000            // The time at which the OXOTP shutdown after inactivity
#define lcd_brightness 9                   // brightness of the LCD

String rondom_letters = "AEF2345689";      // This string contains the characters used to generate the wifi password


#include<WiFi.h>
#include<WebServer.h>
#include<WiFiAP.h>
#include <WiFi.h>
#include<TOTP.h>
#include<M5StickC.h>
#include<TimeLib.h>
#include<ArduinoJson.h>
#include"ArduinoNvs.h"


// Run-Time Variables //


WebServer server(80);

#include"beta15pt7b.h"
#include"beta10pt7b.h"
#include"beta8pt7b.h"
#include"beta5pt7b.h"


#include"variable_runtime.h"

#include"screen.h"
#include"screen1.h"
#include"screen2.h"
#include"screen3.h"

void setup() {

  Serial.begin(115200);
  while (!Serial);

  M5.begin();
  M5.Axp.ScreenBreath(lcd_brightness);
  NVS.begin();

  Serial.println("===============ESP32-OXOTP==============");
  Serial.println("================= V 1.0 ================");
  Serial.println("===============ESP32-OXOTP==============");

  M5.Rtc.GetTime(&TimeStruct);
  M5.Rtc.GetData(&DateStruct);

  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);

  setTime(TimeStruct.Hours, TimeStruct.Minutes, TimeStruct.Seconds, DateStruct.Date, DateStruct.Month, DateStruct.Year);

}

void loop() {

//   this handle the switch 
  switch (menu_index) {
    case 0:
      OTP_screen();
      break;
    case 1:
      Time_screen();
      break;
    case 2:
      Wifi_screen();
      break;
  }
  
  switchscreen();                       
}
