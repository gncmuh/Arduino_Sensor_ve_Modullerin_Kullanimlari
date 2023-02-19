int pin[]={13};
bool guc=LOW;
void setup() {
  for(int i=0;i<1;i++) pinMode(pin[i],OUTPUT);
}

void loop() {

  lazer_calistir();
}

void lazer_calistir() {

  digitalWrite(pin[0],!guc);
  delay(300);
  digitalWrite(pin[0],guc);
  delay(300);
  
    
}
