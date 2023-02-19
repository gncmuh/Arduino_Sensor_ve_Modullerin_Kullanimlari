#include <dht11.h>
#include <Smoothed.h>

Smoothed <float> dht_sens_sicaklik;
Smoothed <float> dht_sens_nem;
dht11 dht;
int sens_pin[]={7};
int sayac=0;

struct sens_deger{
  int gelen[10]={};
};
struct sens_deger sens;
void setup() {
  Serial.begin(9600);
  dht_sens_sicaklik.begin(SMOOTHED_EXPONENTIAL,10);
  dht_sens_nem.begin(SMOOTHED_EXPONENTIAL,10);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi.");
  }
  else
  { 
    for(int i=0; i<1; i++) pinMode(sens_pin[i],INPUT);
  }
}

void loop() {

  sens.gelen[0]=sens_okuma(sens_pin[0]);
  sens.gelen[1]=sens_okuma(sens_pin[0]);
  if(!bool(0))
  {
    Serial.print("SİCAKLİK=");
    Serial.println(sens.gelen[0]);
    Serial.print("NEM=");
    Serial.println(sens.gelen[1]);
  }
  delay(100);
  
}

int sens_okuma(int pin) {

  int kont;int nem,sicaklik;int giden;
  int dizi_limiti=1;
  kont=dht.read(pin);
  sicaklik=(float)dht.temperature,2;
  nem=(float)dht.humidity,2;
  if(!bool(0))
  {
    dht_sens_sicaklik.add(sicaklik);
    dht_sens_nem.add(nem);
  }
  int smooth_sicaklik=dht_sens_sicaklik.get();int smooth_nem=dht_sens_nem.get();
  int toplam[]={smooth_sicaklik,smooth_nem};
  if(!bool(0))
  {
    giden=toplam[sayac];
    sayac++;
    if(sayac>dizi_limiti) sayac=0;
  }
  return giden;
  
 
}
