#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir dimensiones de la pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int LED1_PIN = 18; 
const int LED2_PIN = 19; 
const int LED3_PIN = 12; 
const int LED4_PIN = 13; 

// Variables para rastrear el estado de los LEDs dinámicamente
bool estadoLED1 = false;
bool estadoLED2 = false;
bool estadoLED3 = false;
bool estadoLED4 = false;

// Función para refrescar la OLED con Adafruit
void actualizarOLEDDinamico() {
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Estado de Secuencia:");

  const char* flecha = "---";
  const char* desc = "Todo Apagado";

  // Evaluamos qué combinación está encendida para mostrar la flecha adecuada
  if (estadoLED1 && !estadoLED2 && !estadoLED3 && !estadoLED4) {
    flecha = "<----";
  } else if (!estadoLED1 && estadoLED2 && !estadoLED3 && !estadoLED4) {
    flecha = "---->";
  } else if (!estadoLED1 && !estadoLED2 && estadoLED3 && !estadoLED4) {
    flecha = "<-----";
  } else if (!estadoLED1 && !estadoLED2 && !estadoLED3 && estadoLED4) {
    flecha = "---->";
  } else if (estadoLED1 && !estadoLED2 && estadoLED3 && !estadoLED4) {
    flecha = "<<== \n <<== ";
    desc = "LEDS 1 y 3";
  } else if (!estadoLED1 && estadoLED2 && !estadoLED3 && estadoLED4) {
    flecha = "==>> \n ==>>";
    desc = "LEDS 2 y 4";
  } else if (estadoLED1 && estadoLED2 && !estadoLED3 && !estadoLED4) {
    flecha = " ^ ^\n | |"; // LEDs 1 y 2 hacia arriba
    desc = "LEDS 1 y 2";
  } else if (!estadoLED1 && !estadoLED2 && estadoLED3 && estadoLED4) {
    flecha = " | |\n v v"; // LEDs 3 y 4 hacia abajo
  } else if (estadoLED1 && estadoLED2 && estadoLED3 && estadoLED4) {
    flecha = "<======>";
    desc = "TODOS ENCENDIDOS";
  }

  // Dibujar la flecha grande en el centro
  display.setTextSize(2);
  display.setCursor(10, 25);
  display.println(flecha);

  // Dibujar el texto descriptivo abajo
  display.setTextSize(1);
  display.setCursor(10, 52);
  display.println(desc);

  display.display();
}

// Macro para interceptar los digitalWrite y actualizar la pantalla automáticamente
#define digitalWrite(pin, val) do { \
  ::digitalWrite(pin, val); \
  if((pin) == LED1_PIN) estadoLED1 = (val == HIGH); \
  if((pin) == LED2_PIN) estadoLED2 = (val == HIGH); \
  if((pin) == LED3_PIN) estadoLED3 = (val == HIGH); \
  if((pin) == LED4_PIN) estadoLED4 = (val == HIGH); \
  actualizarOLEDDinamico(); \
} while(0)


// ==========================================
// TU SECUENCIA ORIGINAL INTACTA
// ==========================================

void setup() {
  // Inicializar la pantalla OLED con la dirección I2C común (0x3C)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // Se detiene si hay error
  }

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