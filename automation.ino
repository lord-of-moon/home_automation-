#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

int fanPin = 13;  // Replace with the actual pin connected to the fan
int bulbPin = 12; // Replace with the actual pin connected to the bulb

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_Control"); // Bluetooth device name
  pinMode(fanPin, OUTPUT);
  pinMode(bulbPin, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'F':
      digitalWrite(fanPin, HIGH); // Turn on the fan
      break;
    case 'f':
      digitalWrite(fanPin, LOW); // Turn off the fan
      break;
    case 'B':
      digitalWrite(bulbPin, HIGH); // Turn on the bulb
      break;
    case 'b':
      digitalWrite(bulbPin, LOW); // Turn off the bulb
      break;
    default:
      break;
  }
}
