#include <SoftwareSerial.h>
// Khai báo các chân RX và TX cho espsoftwareserial
#define RX_PIN 4 // D2
#define TX_PIN 5 // D1

// Tạo một đối tượng espsoftwareserial với tốc độ baud là 9600
SoftwareSerial mySerial(RX_PIN, TX_PIN);

void setup() {
  // Khởi tạo cổng nối tiếp phần cứng với tốc độ baud là 115200
  Serial.begin(115200);

  // Khởi tạo cổng nối tiếp phần mềm với tốc độ baud là 9600
  mySerial.begin(9600);

  // In ra thông báo khởi động
  // Serial.println("ESP8266 UART Communication Example");
}

void loop() {
  if (mySerial.available()) 
  { 
    Serial.println(mySerial.read()); 
  }

}
