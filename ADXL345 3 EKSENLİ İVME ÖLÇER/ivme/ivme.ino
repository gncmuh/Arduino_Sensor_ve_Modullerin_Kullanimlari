#include <Wire.h>
#include <ADXL345.h>

ADXL345 eksen(ADXL345_ALT);

struct sensor_degerler {

  float gelen_veriler[5];
  
};
struct sensor_degerler sens;
int sayac=0;
int dizi_limiti=2;
byte aygit_adresi;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  aygit_adresi = eksen.readDeviceID();
  if(aygit_adresi!=0)
  {
    Serial.println("aygit okumaya basladi");
    Serial.println(aygit_adresi,HEX);
  }
  else
  {
    Serial.println("aygita bağlanilamadi");
    while(1);
  }
  if(!eksen.writeRate(ADXL345_RATE_200HZ))   
  {
    Serial.println("yazma hizi hatali");
  }
  if(!eksen.writeRange(ADXL345_RANGE_16G)) {
    Serial.println("yazma araligi basarisiz");
  }
  if(!eksen.start())
  {
    Serial.println("sistem baslatilamadi");
    while(1);
  }
  Serial.println("********************");
}

void loop() {

  sens.gelen_veriler[0]=sensor_okuma();
  sens.gelen_veriler[1]=sensor_okuma();
  sens.gelen_veriler[2]=sensor_okuma();

  Serial.print("x=");
  Serial.println(sens.gelen_veriler[0]);
  Serial.print("y=");
  Serial.println(sens.gelen_veriler[1]);
  Serial.print("z=");
  Serial.println(sens.gelen_veriler[2]);

  delay(500);
}

float sensor_okuma() {

  float giden;
  float x,y,z;
  if(eksen.update())
  {
    x=eksen.getX();y=eksen.getY();z=eksen.getZ();
  }
  float toplam[]={x,y,z};
  if(!bool(0))
  {
    giden=toplam[sayac];
    sayac++;
    if(sayac>dizi_limiti) sayac=0;
  }
  return giden;
}
