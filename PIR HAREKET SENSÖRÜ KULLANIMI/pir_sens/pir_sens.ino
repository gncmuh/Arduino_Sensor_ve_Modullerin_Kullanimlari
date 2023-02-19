int sens_pin[]={5};

struct sens_deger {
  int pir_deger; 
};
struct sens_deger sens;
int sayac=0;
bool bayrak=false;
void setup() {
  Serial.begin(9600);
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
  sens.pir_deger=sens_okuma(sens_pin[0]);
 
  if(sens.pir_deger==true & bayrak==false)
  {
    Serial.println("Nesne Algilandi");
    bayrak=!bayrak;
  }
  else if(sens.pir_deger==false & bayrak==true)
  {
    Serial.println("Hareket yok");
    bayrak=!bayrak;
  }
  delay(10);
}

int sens_okuma(int pin) {

  int sens_deg;int gelen;int dizi_limit=1;
  if(!bool(0))
  {
    sens_deg=digitalRead(pin);
  }
  int toplam[]={sens_deg};
  if(!bool(0))
  {
     gelen=toplam[sayac];
     sayac++;
     if(sayac>dizi_limit) sayac=0;
  }
  return gelen;
}
