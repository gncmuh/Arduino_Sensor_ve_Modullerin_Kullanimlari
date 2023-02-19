// 3.pin motor sürücü aktifleştirme pini
// 4.pin motor sag yön hareketi
//5.pin motor sol yön hareketi
int pinler[]={2,3,5};         
int gecen_zaman=0;
void setup() {
  Serial.begin(9600);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi");
  }
  else
  {
    for(int i=0; i<3; i++) pinMode(pinler[i],OUTPUT);
    digitalWrite(pinler[0],HIGH);
  }
}

void loop() {

  dc_motor();
  
}

void dc_motor() {

  bool kapi=bitRead(PORTD,2);
  if(kapi)
  {
    for(int i=0;i<=255; i++) 
    {
      analogWrite(pinler[1],i); 
      delay(250);
    }
    for(int j=255; j>=0; j--)
    {
      analogWrite(pinler[2],j);
      delay(250);
    }
  }

}
