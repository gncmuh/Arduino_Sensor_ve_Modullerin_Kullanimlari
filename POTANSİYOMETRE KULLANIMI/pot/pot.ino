#include <Smoothed.h>
int sens_pin[]={A0};
Smoothed <float> pot_deger;

union sens_degerler{

  int pot_loop;
};
union sens_degerler sens;

void setup()  {
  Serial.begin(9600);
  pot_deger.begin(SMOOTHED_AVERAGE,13);
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
  sens.pot_loop=sens_okuma(sens_pin[0]);
  if(!bool(0))
  {
    Serial.println(sens.pot_loop);
  }
  delay(100);
}

int sens_okuma(int pin) {

  int pot;
  pot=analogRead(pin);
  if(!bool(0))
  {
    pot_deger.add(pot);
  }
  int smoothed_gelen=pot_deger.get();
  return smoothed_gelen;
} 
