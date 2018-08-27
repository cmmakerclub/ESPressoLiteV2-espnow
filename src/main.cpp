
#include <CMMC_Legend.h>
#include "modules/SensorModule.h"
#include "modules/ESPNowModule.h"

CMMC_Legend os;
SensorModule *sensorModule;

void setup()
{
  sensorModule = new SensorModule();
  os.addModule(sensorModule);
  
  os.addModule(new ESPNowModule());
  os.setup();
  Serial.printf("APP VERSION: %s\r\n", LEGEND_APP_VERSION);
}

void loop()
{
  os.run();
}