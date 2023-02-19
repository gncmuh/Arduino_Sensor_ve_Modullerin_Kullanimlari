int pin[]={A0,13};
struct sens_degerler {

  int sens_deger;
  
};
bool bayrak=false;
struct sens_degerler sens;
int sayac=0;
bool zaman=true;
void setup() {
  Serial.begin(9600);
  digitalWrite(pin[1],LOW);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatilamadi");
  }
  else
  {
    for(int i=0; i<2; i++)
    {
      if(i==0) pinMode(pin[i],INPUT); 
      if(i==1) pinMode(pin[i],OUTPUT);
    }
  }

}

void loop() {
  sens.sens_deger=sens_okuma(pin[0]);
//  Serial.print("SES DURUMU=");
//  Serial.println(sens.sens_deger);
  if(!bool(0)){
    if(sens.sens_deger<600 && bayrak==false)
    { 
      do{
        digitalWrite(pin[1],HIGH);
        delay(5000);
        zaman=!zaman;
      }while(zaman==true);
      bayrak=!bayrak;
    }
    else if(sens.sens_deger>600 && bayrak==true)
    {
      digitalWrite(pin[1],LOW);
      bayrak=!bayrak;
    }
  }
  
}

int sens_okuma(int pin){

  int ses;int giden;
  int dizi_limiti=1;
  if(!bool(0))
  {
    ses=analogRead(pin);
  }
  int toplam[]={ses};
  if(!bool(0))
  {
    giden=toplam[sayac];
    sayac++;
    if(sayac>=dizi_limiti) sayac=0;
  }
  return giden;
}
