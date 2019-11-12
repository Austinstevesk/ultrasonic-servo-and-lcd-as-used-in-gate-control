#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(2,3,4,5,6,7);
Servo testservo;
int motionsensor = 10;

const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 13; // Echo Pin of Ultrasonic Sensor

const int pingPin2 = 10; // Trigger Pin of Ultrasonic Sensor
const int echoPin2 = 11; // Echo Pin of Ultrasonic Sensor
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("IoT Club");
  testservo.attach(9);
  pinMode(10, INPUT);
  Serial.begin(9600);
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  //--------------------------------------------------------
      long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   //---------------------------------------------------
          long duration2, inches2, cm2;
   pinMode(pingPin2, OUTPUT);
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   pinMode(echoPin2, INPUT);
   duration2= pulseIn(echoPin2, HIGH);
   inches2 = microsecondsToInches(duration2);
   cm2 = microsecondsToCentimeters(duration2);

   //-------------------------------------------

   Serial.print("ultrasonic1 => ");
   Serial.print(cm);
   Serial.print("  Ultrasonic2 => ");
   Serial.println(cm2);

  if (cm <= 30){
    testservo.write(180);
    lcd.print("Gate open");
    delay(1000);
    lcd.clear();
  }
  else {
    testservo.write(90);
    lcd.print("Gate closed");
    delay(500);
    lcd.clear();
    
  }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
