/*
  ESP32 LED Blink Test
  Hecho para probar si la carga del código funciona correctamente.
*/
#include <Arduino.h>

// La mayoría de las placas ESP32 tienen el LED interno en el GPIO 2
const int LED1_PIN = 18; 
const int LED2_PIN = 19; 
const int LED3_PIN = 21; 
const int LED4_PIN = 22; 

void setup() {
  // Inicializa el puerto serie para ver mensajes en el monitor
  Serial.begin(115200);
  Serial.println("--- ESP32 Listo para la prueba de parpadeo ---");
  
  // Configura el pin del LED como salida
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
}

void loop() {
  // Enciende el LED
  digitalWrite(LED1_PIN, HIGH);
  Serial.println("LED Encendido (HIGH)");
  delay(500); // Espera medio segundo

  // Apaga el LED
  digitalWrite(LED1_PIN, LOW);
  Serial.println("LED Apagado (LOW)");
  delay(500); // Espera medio segundo
    // Enciende el LED
  digitalWrite(LED2_PIN, HIGH);
  Serial.println("LED Encendido (HIGH)");
  delay(500); // Espera medio segundo

  // Apaga el LED
  digitalWrite(LED2_PIN, LOW);
  Serial.println("LED Apagado (LOW)");
  delay(500); // Espera medio segundo
    // Enciende el LED
  digitalWrite(LED3_PIN, HIGH);
  Serial.println("LED Encendido (HIGH)");
  delay(500); // Espera medio segundo

  // Apaga el LED
  digitalWrite(LED3_PIN, LOW);
  Serial.println("LED Apagado (LOW)");
  delay(500); // Espera medio segundo
    // Enciende el LED
  digitalWrite(LED4_PIN, HIGH);
  Serial.println("LED Encendido (HIGH)");
  delay(500); // Espera medio segundo

  // Apaga el LED
  digitalWrite(LED4_PIN, LOW);
  Serial.println("LED Apagado (LOW)");
  delay(500); // Espera medio segundo

  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED3_PIN, HIGH);
  Serial.println("LEDS EncendidoS (HIGH)");
  delay(500); // Espera medio segundo

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  Serial.println("LEDS Apagados (LOW)");
  delay(500); // Espera medio segundo

  digitalWrite(LED2_PIN, HIGH);
  digitalWrite(LED4_PIN, HIGH);
  Serial.println("LEDS Encendidos (HIGH)");
  delay(500); // Espera medio segundo

  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  Serial.println("LEDS Apagados (LOW)");
  delay(500); // Espera medio segundo

  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);
  Serial.println("LEDS Encendidos (HIGH)");
  delay(500); // Espera medio segundo

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  Serial.println("LEDS Apagados (LOW)");
  delay(500); // Espera medio segundo
  digitalWrite(LED3_PIN, HIGH);
  digitalWrite(LED4_PIN, HIGH);
  Serial.println("LEDS Encendidos (HIGH)");
  delay(500); // Espera medio segundo

  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  Serial.println("LEDS Apagados (LOW)");
  delay(500); // Espera medio segundo

  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);
  digitalWrite(LED3_PIN, HIGH);
  digitalWrite(LED4_PIN, HIGH);
  Serial.println("LEDS Encendidos (HIGH)");
  delay(500); // Espera medio segundo

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  Serial.println("LEDS Apagados (LOW)");
  delay(500); // Espera medio segundo
}
