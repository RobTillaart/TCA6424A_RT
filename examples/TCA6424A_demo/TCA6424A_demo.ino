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
  tca.digitalWrite8(0x0080);
  delay(500);
  tca.digitalWrite8(0x0000);
  delay(500);

  tca.digitalWrite8(0x0040);
  delay(500);
  tca.digitalWrite8(0x0000);
  delay(500);

  tca.digitalWrite8(0x0020);
  delay(500);
  tca.digitalWrite8(0x0000);
  delay(500);

  tca.digitalWrite8(0x0010);
  delay(500);
  tca.digitalWrite8(0x0000);
  delay(500);
}


//  -- END OF FILE --
