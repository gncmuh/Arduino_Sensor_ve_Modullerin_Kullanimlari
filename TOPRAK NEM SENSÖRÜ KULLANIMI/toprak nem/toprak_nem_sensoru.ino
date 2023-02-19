int pin[]={A0};
struct sens_deger {
  
  int sens_deger;
};
struct sens_deger sens;
int sayac=0;
int dizi_limiti=1;
void setup()
{
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

void loop()
{
	sens.sens_deger=sens_okuma(pin[0]);
 	Serial.println(sens.sens_deger);
  	delay(300);
}

int sens_okuma(int pin) {
 
  int deger;int giden;
  if(!bool(0))
  {
   	deger=analogRead(pin);
  }
  int toplam[]={deger};
  if(!bool(0))
  {
   	giden=toplam[sayac];
    sayac++;
    if(sayac>=dizi_limiti) sayac=0;
  }
  return giden;
}