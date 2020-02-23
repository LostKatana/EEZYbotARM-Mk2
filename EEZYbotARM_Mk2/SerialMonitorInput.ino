void checkSerialInput() {
  if(Serial.available() > 0) {
    String monitor_input = Serial.readStringUntil("!");
    
    if(monitor_input.startsWith("store")) {
      Serial.println("Store settings...");
      
      if(monitor_input.substring(6).startsWith("min")) {
        MIN = monitor_input.substring(10).toInt();
      } else if(monitor_input.substring(6).startsWith("max")) {
        MAX = monitor_input.substring(10).toInt();
      }
      MID = (MAX - MIN) / 2;
      printSettings("Stored settings:");
      testServos();
      
    } else if(String(monitor_input.charAt(0)).toInt() > 0 &&
              String(monitor_input.charAt(0)).toInt() < 3){
      Serial.println("Setting position...");
      String servoNo = monitor_input.substring(0,1);
      String seconds = monitor_input.substring(2);

      if(servoNo.equals("1")){
        Serial.println("---> 1");
        myservo1.writeMicroseconds(seconds.toInt());
      } else if(servoNo.equals("2")){
        Serial.println("---> 2");
        myservo2.writeMicroseconds(seconds.toInt());
      } else if(servoNo.equals("3")){
        Serial.println("---> 3");
        myservo3.writeMicroseconds(seconds.toInt());
      }
    } else {
      Serial.println("unrecognized command!");
    }

    while(Serial.available()){
      Serial.read();
    }
  }
}
