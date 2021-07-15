/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/Labs/lab_19_watchdog_timers/src/lab_19_watchdog_timers.ino"
void setup();
void loop();
#line 1 "d:/Labs/lab_19_watchdog_timers/src/lab_19_watchdog_timers.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include "WatchDog_WCL.h"
#include "oled-wing-adafruit.h"

WatchDog wd;

OledWingAdafruit display;

void setup() {
    pinMode(D5, INPUT);

    display.setup();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.display();
    Serial.begin(9600);

    //check for reset reason
    if  (System.resetReason() == RESET_REASON_WATCHDOG) 
    {
        display.print("watchdog");
        display.display();
        delay(CONCURRENT_WAIT_FOREVER);
    } 

    //init timer
    wd.initialize(5000);
    wd.pet();
}

void loop() {
    //pet if button not pressed
    if (digitalRead(D5) == HIGH) 
    {
      wd.pet();
    }
}