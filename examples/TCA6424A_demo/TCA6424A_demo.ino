//
//    FILE: TCA6424A_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test basic behaviour and performance
//     URL: https://github.com/RobTillaart/TCA6424A_RT


#include "TCA6424A.h"


TCA6424A tca(0x20);


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("TCA6424A_LIB_VERSION: ");
  Serial.println(TCA6424A_LIB_VERSION);
  Serial.println();

  Wire.begin();
  Wire.setClock(400000);

  if (tca.begin() == false)
  {
    Serial.println("No TCA found.");
    while (1);
  }

  //  Set P0–P7 as inputs, P8–P23 as outputs
  tca.setPinMode24(0x00FFFF);

  //  Invert INPUT polarity so pressing button == 1
  tca.setPolarity24(0x00FFFF);


  //  Initialize outputs to OFF
  tca.digitalWrite24(0x00FFFF);

  Serial.print(millis());
  Serial.println(": config done..");
}


void loop(void)
{
  uint32_t data = tca.digitalRead24();

  tca.digitalWrite24(0xFFFFFF);
  delay(500);

  tca.digitalWrite24(0x000000);
  delay(500);

  tca.digitalWrite24(data << 8);
  delay(500);

  //  Print input/output states
  Serial.print(" Inputs (P0–P7): ");
  for (uint16_t mask = 0x0001; mask < 0x0100; mask <<= 1)
  {
    Serial.print((data & mask) ? 1 : 0);
  }
  Serial.println();

  delay(2000);
}


//  -- END OF FILE --
