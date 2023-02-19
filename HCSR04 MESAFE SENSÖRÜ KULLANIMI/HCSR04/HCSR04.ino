const int pinler[2] PROGMEM={4,5};

struct gelen_veriler {

  int sure;int mesafe;int fonk_deger;
  
};

struct gelen_veriler gelen;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<=1; i++) {
    if(i==0) pinMode(pinler[i],OUTPUT); 
    else if(i==1) pinMode(pinler[i],INPUT);
  }
 
}
void loop() {

  gelen.fonk_deger=sensor_degeri();
  Serial.print("mesafe(cm)=");Serial.println(gelen.fonk_deger);
    
}

int sensor_degeri() {
  digitalWrite(pinler[0],HIGH);
  delayMicroseconds(1000);
  digitalWrite(pinler[0],LOW);

  if(!bool(0))
  {
    gelen.sure=pulseIn(pinler[1],HIGH);
    gelen.mesafe=(gelen.sure/2)/29.1;
  }
  return gelen.mesafe;
  
}
