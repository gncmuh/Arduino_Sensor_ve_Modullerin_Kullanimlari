
int pin[]={A0};
struct sensor_deger {

   int gelen_deger;
   int fonk_deger;
   
};
struct sensor_deger sens;


void setup() {
  Serial.begin(9600);
  for(int i=0; i<1; i++) pinMode(pin[i],INPUT);

}
void loop() {
  sens.gelen_deger=sensor_okuma(pin[0]);
  Serial.print("MQ-2 DEGER=%");
  Serial.println(sens.gelen_deger);

}

int sensor_okuma(int pin) {
  if(!bool(0))
  {
    sens.fonk_deger=analogRead(pin);
//    sens.fonk_deger=map(sens.fonk_deger,300,10000,0,100); //MQ-2 'nin datasheet üzerindeki 300-10000 ppm arası yoğunluk ölçebildiği belirtilmiştir.
  }

  return sens.fonk_deger;
}






