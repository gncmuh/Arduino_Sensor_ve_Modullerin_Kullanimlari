#include <SoftwareSerial.h>
int pinler[]={3,2};  //RX,TX,LED
int zaman=0;
SoftwareSerial bt(pinler[0],pinler[1]);
void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi");
  }
  else
  {
    for(int i=0; i<2; i++)
    {
      if(i==0)
      {
        pinMode(pinler[i],OUTPUT);
      }
      else
      {
        pinMode(pinler[i],INPUT);
      }
    }
  }  
}
void loop() {

  bt_kontr();
  zaman=millis();
  if(zaman>5000) bt.end();
  delay(1);
  
}

void bt_kontr() {

  bt.listen();
  if(bt.available())
  {
    int gelen=bt.read();
    if(gelen==49) Serial.println("gelen sayi 1");
    else if(gelen==50) Serial.println("gelen sayi 2");
  }
}
