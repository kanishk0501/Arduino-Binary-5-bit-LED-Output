int pin;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (pin = 8; pin<=12; pin++){
    pinMode(pin,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    int c = Serial.parseInt();
    Serial.println(c);
    if (c>32||c<0)
    {
      for (int i = 0; i<3; i++){
        
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      delay(250);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      delay(250);
      }
    }
    else if (c>=0 || c<32){
      for (pin = 8; pin<=12; pin++){
      digitalWrite(pin, c%2);
      c = c/2;
    }
    Serial.setTimeout(10000);
  }
}
}
