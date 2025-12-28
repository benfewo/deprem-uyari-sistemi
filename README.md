# Deprem Uyarı Sistemi

Bu proje Arduino UNO ve MPU6050 sensörü kullanılarak geliştirilmiş,
deprem anında kullanıcıyı sesli ve görsel uyarılarla uyandırmayı amaçlayan
düşük maliyetli bir deprem uyarı sistemidir.

## Kullanılan Donanımlar
- Arduino UNO
- MPU6050 Sensörü
- Buzzer
- Kırmızı & Yeşil LED
- Breadboard
- Jumper Kablolar

## Sistem Mantığı
MPU6050 sensörü sürekli olarak üç eksenli ivme verilerini okur.
Belirlenen eşik değer aşıldığında:
- Kırmızı LED yanar
- Buzzer çalışır
- Yeşil LED kapanır

## Amaç
Deprem anında bireyleri hızlı şekilde uyandırarak güvenli davranış için zaman kazandırmak.

