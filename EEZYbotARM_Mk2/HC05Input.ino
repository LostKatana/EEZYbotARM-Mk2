void checkHC05Input() {
  //Read from bluetooth and write to usb serial
  if(HC05.available() >= 2) {
    unsigned int servopos = HC05.read();
    unsigned int servopos1 = HC05.read();
    unsigned int realservo = (servopos1 * 256) + servopos; 
    
    if(realservo >= 1000 && realservo <1180){
      double servo1 = map(realservo, 1000,1180,MIN,MAX);
      myservo1.writeMicroseconds(servo1);
      delay(10);
    } 
        
    if(realservo >=2000 && realservo <2180){
      double servo2 = map(realservo,2000,2180,MIN,MAX);
      myservo2.writeMicroseconds(servo2);
      delay(10);
    }
    
    if(realservo >=3000 && realservo < 3180){
      double servo3 = map(realservo, 3000, 3180,MIN,MAX);
      myservo3.writeMicroseconds(servo3);
      delay(10);
    }
  }
}
