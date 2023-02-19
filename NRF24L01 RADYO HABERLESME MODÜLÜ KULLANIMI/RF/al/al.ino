#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

RF24 radyo(9,10); //  CE - CSN ŞEKLİNDE YAPIYORUZ

struct haberlesme_verileri {
  
  int gelen;
};
struct haberlesme_verileri veri;
const byte adres[]="ankara";
int sayac=0;
void setup() {
  Serial.begin(9600);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi");
  }
  else
  {
    radyo.begin();
    radyo.startListening();
    radyo.openReadingPipe(0,adres);
  }
}

void loop() {

  radyo.read(&veri.gelen,sizeof(veri.gelen));
  Serial.println(veri.gelen);
  delay(1000);
  
}
