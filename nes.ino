/*
Modified by Zane Swafford in May of 2012.
Originally written by Ali Raheem at:
https://letshackstuff.com/?s=blog&m=permalink&x=easy-hacky-nes-controller-adapter-with-teensy
*/

int pulsePin = PIN_D0;
int latchPin = PIN_D1;
int dataPin = PIN_D2;
int modifiers;
void setup(){
  pinMode(pulsePin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, INPUT);
}
void loop(){
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  Keyboard.set_key1((digitalRead(dataPin))?0:KEY_A);
  pulse();
  Keyboard.set_key2((digitalRead(dataPin))?0:KEY_B);
  pulse();
  modifiers = 0;
  if(!digitalRead(dataPin))
    modifiers = MODIFIERKEY_CTRL;
  pulse();
  if(!digitalRead(dataPin))
    modifiers |= MODIFIERKEY_SHIFT;
  pulse();
  Keyboard.set_key3((digitalRead(dataPin))?0:KEY_UP);
  pulse();
  Keyboard.set_key4((digitalRead(dataPin))?0:KEY_DOWN);
  pulse();
  Keyboard.set_key5((digitalRead(dataPin))?0:KEY_LEFT);
  pulse();
  Keyboard.set_key6((digitalRead(dataPin))?0:KEY_RIGHT);
  pulse();
  Keyboard.set_modifier(modifiers);
  Keyboard.send_now();
}
void pulse(){
  digitalWrite(pulsePin, HIGH);
  digitalWrite(pulsePin, LOW);
}
