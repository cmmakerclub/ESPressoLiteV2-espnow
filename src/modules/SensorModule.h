#include <CMMC_Module.h>
#include <Wire.h>
#include <SSD1306.h>
#include <Adafruit_NeoPixel.h> 
#include <CMMC_Interval.h>

#ifndef CMMC_SENSOR_MODULE
#define CMMC_SENSOR_MODULE 

const int MAX_ARRAY = 3;
class SensorModule: public CMMC_Module {
  public:
    void config(CMMC_System *os, AsyncWebServer* server); 
    void setup();
    void loop(); 
    void configLoop();
  protected:
  private:
    Adafruit_NeoPixel *pixels;
    SSD1306 *oled;
    float temp_array[MAX_ARRAY] = { 0.0 };
    float humid_array[MAX_ARRAY] = { 0.0 };

    float _temperature;
    float _humidity;
    CMMC_Interval interval;
};

#endif