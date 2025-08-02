#include <Servo.h>

// پین‌ها
#define TRIG_PIN D1
#define ECHO_PIN D2
#define SERVO_PIN D3

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN); // اتصال سروو
  myServo.write(0); // شروع با زاویه صفر
}

void loop() {
  long duration;
  float distance_cm;

  // ارسال پالس TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // خواندن پالس برگشتی از ECHO
  duration = pulseIn(ECHO_PIN, HIGH);
  distance_cm = duration * 0.034 / 2;

  Serial.print("فاصله: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // کنترل سروو بر اساس فاصله
  if (distance_cm > 0 && distance_cm < 10) {
    myServo.write(160);  // حرکت به ۶۰ درجه
  } else {
    myServo.write(0);   // بازگشت به ۰ درجه
  }

  delay(1000); // تأخیر برای پایداری
}