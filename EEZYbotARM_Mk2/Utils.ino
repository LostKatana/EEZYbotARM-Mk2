void printServoInfo() {
  Serial.println("------------------------------------");
  Serial.println("Fine tune the endpoints:");
  Serial.println("Open a serial monitor on 576000");
  Serial.println("Enter the numer of the servo followed by the microsecond value.");
  Serial.println("See: https://www.arduino.cc/en/Reference/ServoWriteMicroseconds");
  Serial.println("1 1500 -> resulting in servo 1 being set to 1500 (90°)");
  Serial.println("Store the settings:");
  Serial.println("store min|max value");
  Serial.println("e.g. 'store min 900'");
  Serial.println("To terminate the command set an exclamation mark to the end!");
  Serial.println("------------------------------------");
}

void testServos() {
  Serial.print("Testing: 0°");
  myservo1.writeMicroseconds(MIN);
  myservo2.writeMicroseconds(MIN);
  myservo3.writeMicroseconds(MIN);
  delay(2 * 1000);

  Serial.print(", 180°");
  myservo1.writeMicroseconds(MAX);
  myservo2.writeMicroseconds(MAX);
  myservo3.writeMicroseconds(MAX);
  delay(2 * 1000);

  Serial.println(", 90°");
  myservo1.writeMicroseconds(MID);
  myservo2.writeMicroseconds(MID);
  myservo3.writeMicroseconds(MID);
}

void printSettings(String text) {
  Serial.println(text
        + "\nMIN: " + String(MIN)
        + "\nMAX: " + String(MAX)
        + "\nMID: " + String(MID)
      ); 
}

void checkBluetoothConnectionState() {
  if(digitalRead(bluetoothStatePin) == HIGH && connected == false) {
    Serial.println("Connected...");
    connected = true;
  } else if(digitalRead(bluetoothStatePin) == LOW && connected == true) {
    Serial.println("Connection lost!");
    connected = false;
  }
}
