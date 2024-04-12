#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 
#include <SoftwareSerial.h> // Thư viện cho cổng nối tiếp mềm

LiquidCrystal_I2C lcd(0x27,16,2); 

#define moisturePin A0
#define tmpPin A1
#define ledPin 4
#define servoPin 9

#define RX_PIN 10 // Chân RX của cổng nối tiếp mềm
#define TX_PIN 11 // Chân TX của cổng nối tiếp mềm

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Tạo một đối tượng cổng nối tiếp mềm

Servo myservo;

int sensorValue;

float reading;
float temp;

void setup() {
  mySerial.begin(9600);
  
  lcd.init();                    
  lcd.backlight();
  pinMode(ledPin, OUTPUT);
  pinMode(tmpPin, INPUT);
  myservo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly
  reading = analogRead(tmpPin);
  temp = getTempValue(reading);  

  sensorValue = analogRead(moisturePin);
  displayLCD(temp, sensorValue);

  if (sensorValue >= 1000)
  {
    mySerial.write("1");
    myservo.write(0);
    turnOnLed();
  }
  else 
  {
    mySerial.write("0");
    myservo.write(90);
    turnOffLed();
  }

  delay(1000);        
}

float getTempValue(float reading) {
  return (reading * 4.88 / 10.0);
}

void turnOnLed()
{
  digitalWrite(ledPin, HIGH);
}

void turnOffLed()
{
  digitalWrite(ledPin, LOW);
}

void displayLCD(float temp, int moisture) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("Moisture: ");
  lcd.print(moisture);
}

















