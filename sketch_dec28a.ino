// MPU6050+Led+Buzzer İle Deprem Alarmı
#include <Wire.h>
#include <MPU6050.h>

MPU6050 sensor;

const int ledPin_K = 6; // Yeşil LED uyarı pini
const int ledPin_Y = 7; // Kırmızı LED uyarı pini
const int buzzer = 8; // Buzzer uyarı pini
const int threshold = 21000; // Sarsıntı eşiği (deneyerek ayarlayabilirsin)

void setup() {
  Serial.begin(9600);
  Wire.begin();
  sensor.initialize();

  pinMode(ledPin_K, OUTPUT);
  pinMode(ledPin_Y, OUTPUT);
  pinMode(buzzer, OUTPUT);

  if (sensor.testConnection()) {
    Serial.println("MPU6050 bağlantısı başarılı.");
  } else {
    Serial.println("MPU6050 bağlantı hatalı!");
    while (1);
  }
}

void loop() {
  int16_t ax, ay, az;   // X, Y, Z eksenlerindeki ivme değerleri

  sensor.getAcceleration(&ax, &ay, &az);

  // Mutlak ivme büyüklüğü (sarsıntı şiddeti)
  long toplamIvme = abs(ax) + abs(ay) + abs(az);

  Serial.print("Toplam İvme: ");
  Serial.println(toplamIvme);

  if (toplamIvme > threshold) {
  for(int i=0; i<30; i++){
    digitalWrite(ledPin_Y, LOW); 
    digitalWrite(ledPin_K, HIGH);
    digitalWrite(buzzer, HIGH);
  delay(50);
    digitalWrite(ledPin_K, LOW);
    digitalWrite(buzzer, LOW);
  delay(50);
    Serial.println("!!! Sarsıntı Tespit Edildi !!!");
  } 
  }
  else {
    digitalWrite(ledPin_Y, HIGH); 
    digitalWrite(ledPin_K, LOW);
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}