#include <Arduino.h>
#include <M5Unified.h>
#include <BluetoothSerial.h>

		BluetoothSerial M5SerialBT;
 		char incomingChar;
    String message="";



void setup() {
  auto cfg = M5.config();
  cfg.serial_baudrate = 115200;
  M5.begin(cfg);
  M5.Lcd.begin();
  M5.Lcd.setTextSize(3);

	M5SerialBT.begin("M5GO"); //Bluetooth device name

  M5.Lcd.clear(YELLOW);
  M5.Lcd.print("M5 Bluetooth is ready - send message");
  M5.Lcd.setCursor(0 , 0);

}

void loop() {
  while (M5SerialBT.available()) {
      incomingChar = M5SerialBT.read();
      switch (incomingChar) {
        case ';' :
          M5.Lcd.clear(YELLOW);
          M5.Lcd.print(message);
          M5.Lcd.setCursor(0 , 0);
          message = "";
          break;
        default :
          message += String(incomingChar);
        }
    }
}