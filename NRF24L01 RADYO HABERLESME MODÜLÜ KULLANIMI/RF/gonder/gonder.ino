#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

RF24 radyo(8,9); //  CE - CSN ŞEKLİNDE YAPIYORUZ

struct haberlesme_verileri {

  int sayi_dizileri[10];
  int giden;
};
struct haberlesme_verileri veri;
const byte adres[]="ankar";
int sayac=0;
int zaman=0;
bool bayrak=false;
void setup() {
  Serial.begin(9600);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi");
  }
  else
  {
    randomSeed(analogRead(A0));
    radyo.begin();
    radyo.stopListening();
    radyo.openWritingPipe(adres);
  }
}

void loop() {

  veri.giden=sayilar();
  veri_al(veri.giden);
  int gelen=radyo.isValid();
  Serial.println(gelen);
  if(millis()-zaman>=5000)
  {
    zaman=millis();
    if(zaman>=5000) 
    {
      radyo.powerDown();
      bayrak=!bayrak;
    }
    delay(1);
  }
  if(bayrak==true)
  {
    Serial.println("Sistem durdu");
  }
}
int sayilar() {

  int giden;
  if(!bool(0))
  {
    for(int i=0; i<10; i++) veri.sayi_dizileri[i]=random(1,20);
  }
  if(!bool(0)){
    giden=veri.sayi_dizileri[sayac];
    sayac++;
    if(sayac>=9) sayac=0;
  }
  return giden;
}

void veri_al(int veriG) {
  radyo.write(&veriG,sizeof(veriG));
}
