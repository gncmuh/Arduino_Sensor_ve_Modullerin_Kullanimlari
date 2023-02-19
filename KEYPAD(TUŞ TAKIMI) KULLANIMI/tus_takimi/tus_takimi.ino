#include <Keypad.h>

const byte satir=4;
const byte sutun=4;
bool bayrak=false;
char tus_takimi[satir][sutun]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte satirPinleri[satir]={9,8,7,6};byte sutunPinleri[sutun]={5,4,3,2};

Keypad tusTakimi=Keypad(makeKeymap(tus_takimi),satirPinleri,sutunPinleri,satir,sutun);

void setup() {
  Serial.begin(9600);
  if(!Serial)
  {
    Serial.println("Seri haberlesme baslatimadi");
  }
  else
  {
    byte gelen=tusTakimi.isPressed(tus_takimi[0][3]);
    Serial.println(gelen);
  }

}

void loop() {
  
  tus_takimi_fonk();
  byte gelen=tusTakimi.isPressed(tus_takimi[0][3]);
  
  if(!bool(0))
  {
    if(gelen==true && bayrak==false) Serial.println("A TUSUNA BASILDI"); bayrak=!bayrak;    
  }
}

void tus_takimi_fonk() {
  char gelen_karakter=tusTakimi.getKey();
  if(!bool(0))
  {
    if(gelen_karakter)
    {
      Serial.print("GELEN KARAKTER=");
      Serial.println(gelen_karakter);
    }
  }
    
}
