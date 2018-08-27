#include "SensorModule.h"

#define NUMPIXELS      7

void swap(float &a, float &b)
{
  int t = a;
  a = b;
  b = t;
}

int partition(float *arr, const int left, const int right)
{
  const int mid = left + (right - left) / 2;
  const int pivot = arr[mid];
  // move the mid point value to the front.
  swap(arr[mid], arr[left]);
  int i = left + 1;
  int j = right;
  while (i <= j)
  {
    while (i <= j && arr[i] <= pivot)
    {
      i++;
    }

    while (i <= j && arr[j] > pivot)
    {
      j--;
    }

    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i - 1], arr[left]);
  return i - 1;
}

void quickSort(float *arr, const int left, const int right)
{
  if (left >= right)
  {
    return;
  }

  int part = partition(arr, left, right);

  quickSort(arr, left, part - 1);
  quickSort(arr, part + 1, right);
}

int median(float arr[], int maxValues)
{
  quickSort(arr, 0, maxValues - 1);
  return arr[maxValues / 2];
}

void SensorModule::config(CMMC_System *os, AsyncWebServer* server) { 
  static SensorModule *that = this;
  pixels  = new Adafruit_NeoPixel(NUMPIXELS, 15, NEO_GRB + NEO_KHZ800);
  oled  = new SSD1306(0x3c, 4, 5);
  pixels->begin();
}

void SensorModule::configLoop() { 
   for(int i=0;i<NUMPIXELS;i++){ 
    pixels->setPixelColor(i, pixels->Color(253, 10 , 2)); // Moderately bright green color. 
    pixels->show();
    delay(10);
  } 
}

void SensorModule::setup() {

  oled  = new SSD1306(0x3c, 4, 5);
  pixels  = new Adafruit_NeoPixel(NUMPIXELS, 15, NEO_GRB + NEO_KHZ800); 
  pixels->begin();
  
  oled->init();
  oled->flipScreenVertically();
  oled->setContrast(255);
  oled->clear();
  oled->setFont(ArialMT_Plain_10); 
  oled->println("starting...");
  oled->display();
}

void SensorModule::loop() { 
}
