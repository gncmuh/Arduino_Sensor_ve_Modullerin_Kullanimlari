#include <Wire.h>
#include <SFE_BMP180.h>
#define ALTITUDE 913  

struct veriler {
  
  double sicaklik;
  double basinc;
  double deniz;
  double rakim_d;
  
};
struct veriler veri;
SFE_BMP180 bmp180;
bool durum=0;

void setup() {
  Serial.begin(9600);
  durum=bmp180.begin();
  if(durum!=0)
  {
    Serial.print("*********\n");
    Serial.println("""Basinc Olcumu Basliyor***");
  }
}

void loop() {

   veri.sicaklik=sicaklik_olcumu();
   veri.basinc=basinc_olcumu(veri.sicaklik);
   veri.deniz=deniz_seviyesi(veri.basinc);
   veri.rakim_d=rakim(veri.basinc,veri.deniz);
   
   if(!bool(0))
   {
      Serial.print("Sicaklik=");
      Serial.println(veri.sicaklik);
      Serial.print("Basinc=");
      Serial.println(veri.basinc);
      Serial.print("deniz_seviyesi=");
      Serial.println(veri.deniz);
      Serial.print("Rakim=");
      Serial.println(veri.rakim_d);
     
   } 
}

double sicaklik_olcumu() {

  double sicaklik; bool kontr;
  kontr=bmp180.startTemperature();
  delay(1000);
  if(kontr!=0){
    bmp180.getTemperature(sicaklik);    
  }

  return sicaklik;
  
}

double basinc_olcumu(double sicaklik) {

  double basinc; bool kontr; 
  kontr=bmp180.startPressure(3);
  delay(1000);
  if(kontr!=0){
    bmp180.getPressure(basinc,sicaklik);
  }

  return basinc;
}

double deniz_seviyesi(double basinc) {
  
  double basinc_d;
  if(!bool(0))
  {
    basinc_d=bmp180.sealevel(basinc,ALTITUDE);
  }
  return basinc_d;
   
}

double rakim(double basinc,double basinc_d) {
  double rakim;
  if(!bool(0))
  {
    rakim=bmp180.altitude(basinc,basinc_d);
  }
  return rakim;
}
