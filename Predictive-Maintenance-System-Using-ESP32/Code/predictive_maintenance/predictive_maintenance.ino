#define BLYNK_TEMPLATE_ID "TMPL3Gn4qKkTU"
#define BLYNK_TEMPLATE_NAME "notification"
#define BLYNK_AUTH_TOKEN "-udRq3DhcRNrMNwxtWSKYfU8gyJIHGcV"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

char ssid[] = "neha";
char pass[] = "123456789";

#define TEMP_PIN 5
#define RELAY_PIN 17
#define VIB_PIN 34
#define CURRENT_PIN 32
#define BUZZER_PIN 25

OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

bool isMotorFaulted = false;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(VIB_PIN, INPUT); // Pin 34 is Input-only
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Start with Motor ON (Relay LOW for Active-Low)
  digitalWrite(RELAY_PIN, LOW);
  sensors.begin();
  
  // Robust connection method
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // TEST: If you see this on your phone, the connection is working!
  Blynk.logEvent("notification", "System Started - Monitoring Active");
  Serial.println("System Online");
}

void loop() {
  Blynk.run();

  if (!isMotorFaulted) {
    // 1. Temperature Sensing
    sensors.requestTemperatures();
    float avgTemp = sensors.getTempCByIndex(0);

    // 2. Vibration Sensing (Checking twice to ensure we catch it)
    int vib = digitalRead(VIB_PIN);
    if (vib == LOW) { delay(2); vib = digitalRead(VIB_PIN); }

    // 3. Current Sensing
    float curSum = 0;
    for(int i=0; i<10; i++) {
      curSum += abs(((analogRead(CURRENT_PIN) / 4095.0 * 3.3) - 2.5) / 0.185);
    }
    float avgCurrent = curSum / 10.0;

    // 4. Fault Logic
    if (avgTemp > 34.35 || avgCurrent > 0.6 || vib == HIGH) {
       isMotorFaulted = true;
       
       digitalWrite(RELAY_PIN, HIGH); // STOP MOTOR
       digitalWrite(BUZZER_PIN, HIGH);
       
       // Send critical notification
       Blynk.logEvent("notification", "CRITICAL FAULT: Motor Permanent Shutdown");
       
       Serial.println("\n***********************************");
       Serial.println("FAULT DETECTED: SYSTEM SHUTDOWN");
       Serial.printf("T: %.2f | C: %.2f | V: %d\n", avgTemp, avgCurrent, vib);
       Serial.println("***********************************");
    }

    // 5. Dashboard (Stops after fault)
    static unsigned long debugTimer = 0;
    if (millis() - debugTimer > 1000) {
      Serial.print("T:"); Serial.print(avgTemp);
      Serial.print(" C:"); Serial.print(avgCurrent);
      Serial.print(" V:"); Serial.print(vib);
      Serial.println(" State: RUNNING");
      debugTimer = millis();
    }
  } 
  else {
    digitalWrite(RELAY_PIN, HIGH); // Ensure motor stays off
  }
}