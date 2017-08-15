#include <SoftwareSerial.h>

int cds = A1;
int bufferPosition;
SoftwareSerial BT(5,4); // TX : 2 || RX : 3

void setup()
{
  BT.begin(38400);
  Serial.begin(9600);
  bufferPosition = 0;
  BT.println("check-!");
  Serial.println("check-!");
}

void loop()
{
  if(BT.available() && Serial.available()) {}
    int cdsValue = analogRead(cds);
    Serial.print("cds = ");
    Serial.println(cdsValue);
    point:
    if(cdsValue > 50)
    {
      bufferPosition = 1;
      BT.write(bufferPosition);
      BT.println("Song wonjun");
      delay(5000);
      goto point;
    }
    else
    {
      bufferPosition = 0;
      BT.println("Dokko hyeon");
    }
}
