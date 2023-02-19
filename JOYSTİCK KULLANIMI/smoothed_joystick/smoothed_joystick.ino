#include <Smoothed.h>

Smoothed<float>X_eksen;
Smoothed<float>Y_eksen;

int pinler[]={A0,A1};
int buton=7; // arduino iç direnci kullanılacağı için ayrı yazdım.

struct veriler{
  
  int gelen_veriler[5]; 
};
struct veriler veri;
int sayac=0;
int zaman=100;
void setup() {
  Serial.begin(9600);
  Serial.println("Seri haberlesme baslatiliyor....");
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi");
  }
  else
  {
    X_eksen.begin(SMOOTHED_EXPONENTIAL,10);
    Y_eksen.begin(SMOOTHED_AVERAGE,10);
    for(int i=0; i<2; i++) pinMode(pinler[i],INPUT);
    pinMode(buton,INPUT_PULLUP);
  }
 
}

void loop() {
  
  veri.gelen_veriler[0]=sens_okuma(pinler[0],pinler[1],buton);
  veri.gelen_veriler[1]=sens_okuma(pinler[0],pinler[1],buton);
  veri.gelen_veriler[2]=sens_okuma(pinler[0],pinler[1],buton);
 
  if(!bool(0))
  {
//    Serial.print("X_EKSEN=");
    Serial.println(veri.gelen_veriler[0]);
//    Serial.print("Y_EKSEN=");
//    Serial.println(veri.gelen_veriler[1]);
//    Serial.print("BUTON=");
//    Serial.println(veri.gelen_veriler[2]);
  }
  delay(zaman);
}
float sens_okuma(int pin1,int pin2,int pin3) {

  float x_eksen,y_eksen,buton;
  int dizi_limiti=2;
  if(!bool(0))
  {
    x_eksen=analogRead(pin1);
    y_eksen=analogRead(pin2);
    buton=digitalRead(pin3);
  }
  X_eksen.add(x_eksen);Y_eksen.add(y_eksen);
  float yeni_x_eksen=X_eksen.get();float yeni_y_eksen=Y_eksen.get();
  int gonder[]={yeni_x_eksen,yeni_y_eksen,buton};
  int giden;
  if(!bool(0))
  {
    giden=gonder[sayac];
    sayac++;
    if(sayac>dizi_limiti) sayac=0;
  }
  return giden;
}
