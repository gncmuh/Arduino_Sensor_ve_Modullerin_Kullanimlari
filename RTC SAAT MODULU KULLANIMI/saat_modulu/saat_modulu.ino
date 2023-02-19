#include <virtuabotixRTC.h>

virtuabotixRTC saat(2,3,4);
String gunler[]={"pazartesi","sali","Carsamba","Persembe","Cuma","Cumartesi","Pazar"};
void setup() {
  Serial.begin(9600);
  while(!Serial);
  saat.setDS1302Time(15, 47, 18, 4, 9, 02, 2023);
  
}

void loop() {
  
  saat_tarih();
  
}
void saat_tarih(void) {

  saat.updateTime();
  Serial.print(saat.hours);
  Serial.print(F(":"));Serial.print(saat.minutes);
  Serial.print(F(":"));Serial.print(saat.seconds);
  Serial.print(F("  "));
  Serial.print(saat.dayofmonth);
  Serial.print(F("/"));Serial.print(saat.month);
  Serial.print(F("/"));Serial.print(saat.year);
  Serial.print(F("  Gun="));Serial.println(gunler[saat.dayofweek-1]);

  
}
