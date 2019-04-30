#include <Wire.h>
#define Addr 0x44
 
void setup()
{
  Wire.begin();
  Serial.begin(115200);
  delay(5000);

}
 
void loop()
{
  unsigned int data[6];

  Wire.beginTransmission(Addr);
  Wire.write(0x2c);
  Wire.write(0x06);

  Wire.requestFrom(Addr, 6);

  if(Wire.available()==6);

{
  data[0] = Wire.read();
  data[1] = Wire.read();
  data[2] = Wire.read();
  data[3] = Wire.read();
  data[4] = Wire.read();
  data[5] = Wire.read();
}
  float cTemp = ((((data[0] * 256.0) + data[1]) * 175) / 65535.0) - 45;
  float fTemp = (cTemp * 1.8) + 32;
  float humidity = ((((data[3] * 256.0) + data[4]) * 100) / 65535.0);


  // Output data to serial monitor
  Serial.print("Relative Humidity : ");
  Serial.print(humidity);
  Serial.println(" %RH");
  Serial.print("Temperature in Celsius : ");
  Serial.print(cTemp);
  Serial.println(" C");
  Serial.print("Temperature in Fahrenheit : ");
  Serial.print(fTemp);
  Serial.println(" F");
  delay(5000);

 

}
