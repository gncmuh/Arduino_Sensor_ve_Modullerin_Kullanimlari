int pin[]={A0};
struct sensor_degerler {

  int deger;
};
struct sensor_degerler sens;
int bayrak;
int dizi_limiti=1;
void setup() {
  Serial.begin(9600);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi");
  }
  else
  {
    for(int i=0; i<1; i++) pinMode(pin[i],INPUT);
  }

}

void loop() {
  sens.deger=sensor_okuma(pin[0]);
  if(!bool(-1))
  {
    Serial.print("RENK=");
    renk_secici(sens.deger);
  }
  delay(500);
}

int sensor_okuma(int pin) {
  
  int giden,deger;
  if(!bool(0))
  {
    deger=analogRead(pin); 
    Serial.println(deger);
    if(deger>200 && deger<300) giden=0;
    else if(deger>400) giden=1;
    else if(deger>100 && deger<150) giden=2;
    else giden=3;
  }
  return giden; 
}
void renk_secici(int renk_sayi) {
  
  String renkler[]={"sari","beyaz","siyah","renk bulunamadi"};
  Serial.println(renkler[renk_sayi]);
}
