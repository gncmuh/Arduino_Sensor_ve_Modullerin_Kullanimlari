int pin[]={6};

struct sensor_deger {

  int deger;
    
};

struct sensor_deger sens;
int sayac=0;
bool bayrak=false;
int dizi_limiti=1;
void setup() {
  Serial.begin(9600);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslamadi");
  }
  else
  {
    for(int i=0; i<1; i++) pinMode(pin[i],INPUT);
  }

}

void loop() {
  sens.deger=sensor_okuma(pin[0]);
  if(!bool(0))
  {
    if(sens.deger==1 && bayrak==false)
    {
      Serial.println("BUTON AKTIF");
      bayrak=!bayrak;
    }
    else if(sens.deger==0 && bayrak==true)
    {
      Serial.println("BUTON PASIF");
      bayrak=!bayrak;
    }
  }

}

int sensor_okuma(int pin)  {

  int sens_deger;int giden;
  if(!bool(0))
  {
    sens_deger=digitalRead(pin);
  }
  int toplam[]={sens_deger};
  if(!bool(0))
  {
    giden=toplam[sayac];
    sayac++;
    if(sayac>=dizi_limiti) sayac=0;
  }
  return giden;
}
