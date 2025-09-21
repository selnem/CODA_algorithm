int n;
void setup(){
    pinMode(12,OUTPUT);
    Serial.begin(9600);
}
void loop(){
    digitalWrite(12,HIGH);
    delay(1000);
    degitalWrite(12,LOW)
}