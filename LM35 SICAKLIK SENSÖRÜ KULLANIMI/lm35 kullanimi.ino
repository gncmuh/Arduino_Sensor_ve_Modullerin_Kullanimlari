#define lm35 A0

struct sensd {
  
  int sens_deger;
 
};
struct sensd sens;

void setup()
{
  Serial.begin(9600);
  pinMode(lm35,INPUT);
  
}

void loop()
{
  sens.sens_deger=sicaklik_oku(lm35);
  Serial.print("sicaklik=");
  Serial.println(sens.sens_deger);
  delay(100);
  
}

int sicaklik_oku(int pin) {
  
  int sens_deg;
  sens_deg=analogRead(pin);
  int sicaklik;
  sicaklik=sens_deg/9.31;
  
  return sicaklik;
  
}