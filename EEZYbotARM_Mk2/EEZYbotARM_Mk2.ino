#include <SoftwareSerial.h>
#include <Servo.h>

#define bluetoothRx 6
#define bluetoothTx 7
#define bluetoothStatePin 4

// default servo movement:
int MIN = 1000, MID = 1500, MAX = 2000;

// Bluetooth
String Name = "Servocontrol_";

// do not modify these
boolean connected = false;
boolean servosAttached = false;
SoftwareSerial HC05(bluetoothTx, bluetoothRx);
Servo myservo1, myservo2, myservo3;

//-----------------------------------
void setup()
{
  initModule();
  initServos();
  printServoInfo();
  printSettings("Default settings:");
}

void loop()
{
  checkBluetoothConnectionState();
  checkSerialInput();
  checkHC05Input();
}
