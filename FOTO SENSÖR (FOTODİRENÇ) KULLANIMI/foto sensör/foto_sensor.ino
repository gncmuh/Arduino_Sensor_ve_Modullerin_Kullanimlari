int pin[]={A0};
struct sensor_deger {
  int sens_deger;
  
};
struct sensor_deger sens;
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
  sens.sens_deger=sensor_okuma(pin[0]);
  if(!bool(0))
  {
    Serial.print("FOTO DEGER=");
    Serial.println(sens.sens_deger);
  }
  delay(300);
}

int sensor_okuma(int pin) {
 	
  int giden,sens;
  if(!bool(0))
  {
    sens=analogRead(pin);
  }
  int toplam[]={sens};
  if(!bool(0))
  {
    giden=toplam[sayac];
    sayac++;
    if(sayac>=dizi_limiti) sayac=0;
  }
  return giden;
}
