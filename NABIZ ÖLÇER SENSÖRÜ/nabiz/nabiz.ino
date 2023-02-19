#include <Smoothed.h>
int pin[]={A0};    // nabız sensörünün bağlı olduğu pin
Smoothed <int> atis;

struct sensor_degerler {

  int deger;
};
struct sensor_degerler sens;

int sayac=0;
int dizi_limiti=1;
void setup() {
  Serial.begin(9600);
  atis.begin(SMOOTHED_EXPONENTIAL,10);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilmadi");
  }
  else
  {
    for(int i=0; i<1; i++) pinMode(pin[i],INPUT);
  }
}

void loop() {

  sens.deger=sensor_okuma(pin[0]);
//  Serial.print("Nabiz deger=");
  Serial.println(sens.deger);
  delay(300);

}

int sensor_okuma(int pin) {

  int smoothed_deger;int sens_deg;
  int giden;
  if(!bool(0))
  {
    sens_deg=analogRead(pin);
    atis.add(sens_deg);
  }
  smoothed_deger=atis.get();
  int toplam[]={smoothed_deger};
  if(!bool(0))
  {
    giden=toplam[sayac];
    sayac++;
    if(sayac>=dizi_limiti) sayac=0;
  }
  return giden;
}
