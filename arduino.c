void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float anaVal;

  anaVal = analogRead(0);
  if (anaVal > 800) {
    Serial.println("!!!!!!!\nwater water water\n!!!!!!!\n");

    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
    delay(300);
  } else if (anaVal > 600) {
    digitalWrite(13, HIGH);
    Serial.println("water!!!\n");
  } else {
    digitalWrite(13, LOW);
    Serial.println("have fun.\n");
  }
}
