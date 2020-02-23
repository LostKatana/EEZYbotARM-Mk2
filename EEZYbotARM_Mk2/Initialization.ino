void initServos() {
  Serial.println("Initialize servos...");

  if(!servosAttached) {
    Serial.println("Attaching servos...");
    myservo1.attach(8);
    myservo2.attach(9);
    myservo3.attach(10);

    servosAttached = true;
  }
  testServos();
}

void initModule() {
  Serial.begin(57600);     //Baudrate ffor communication with serial monitor
  
  Serial.println("Initialize..."); 
  Serial.println();
  
  Serial.println("Configure HC-05 Modul:"); 
  HC05.begin(38400);

  Serial.println("Reset HC-05 -> Slave mode, Baudrate 38400, Password:1234, Device-Name: 'hc01.com HC-05'");
  if(!read("AT+ORGL").startsWith("OK")) {
    Serial.println("Error!");
    return;
    //while(1);     
  }
  
  //Delete all Devices from pairing list
  if(!read("AT+RMAAD").startsWith("OK")) {
    Serial.println("Fehler!");
    while(1);     
  }
  
  //Read MAC-Adress and build bluetooth name
  String addr = read("AT+ADDR?");
  Name.concat(addr.substring(addr.lastIndexOf(":")+1,addr.lastIndexOf(":")+4));
  Serial.println(Name);
  
  //Set bluetooth name to "Servocontrol_XXX"
  String result = read("AT+NAME="+Name);
  Serial.println("Bluetooth name: " + result);
  if(!result.startsWith("OK")) {
    Serial.println("Fehler!");
    while(1);     
  }

  //Checke if Baudrate set to 38400
  if(!read("AT+UART?").startsWith("+UART:38400,0,0")) {
    Serial.println("Fehler!");
    while(1);     
  }

  //Read version of module
  String version = read("AT+VERSION?");
 
  //Restart module resetting connections
  if(!read("AT+RESET").startsWith("OK")) {
    Serial.println("Fehler!");
    while(1);     
  }
  delay(1000);  //So ein Reset dauert seine Zeit...

  //Stop all connections and make visible
  read("AT+INIT");
  read("AT+DISC");
  
  //Gibt den Status des Moduls an
  read("AT+STATE?");

  pinMode(bluetoothStatePin, INPUT);
}

String read(String Befehl){
  char rc;
  String result = "";
  HC05.println(Befehl);
  delay(500);
  
  while(HC05.available() > 0) {
    rc = HC05.read(); 
    result.concat(rc);
  }  
  return result;
}
