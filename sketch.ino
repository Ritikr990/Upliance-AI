#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22
#define HEATER_PIN 8
#define BUZZER_PIN 9

#define HEAT_ON_TEMP 25.0
#define HEAT_OFF_TEMP 30.0
#define OVERHEAT_TEMP 40.0

enum State { IDLE, HEATING, STABILIZING, TARGET_REACHED, OVERHEAT };
State currentState = IDLE;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(HEATER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(HEATER_PIN, LOW);
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read temperature!");
    delay(1000);
    return;
  }

  switch (currentState) {
    case IDLE:
      digitalWrite(HEATER_PIN, LOW);
      noTone(BUZZER_PIN);
      if (temperature < HEAT_ON_TEMP) currentState = HEATING;
      break;

    case HEATING:
      digitalWrite(HEATER_PIN, HIGH);
      if (temperature >= HEAT_OFF_TEMP) currentState = STABILIZING;
      break;

    case STABILIZING:
      digitalWrite(HEATER_PIN, LOW);
      if (temperature < HEAT_OFF_TEMP) currentState = TARGET_REACHED;
      if (temperature >= OVERHEAT_TEMP) currentState = OVERHEAT;
      break;

    case TARGET_REACHED:
      digitalWrite(HEATER_PIN, LOW);
      if (temperature < HEAT_ON_TEMP) currentState = HEATING;
      if (temperature >= OVERHEAT_TEMP) currentState = OVERHEAT;
      break;

    case OVERHEAT:
      digitalWrite(HEATER_PIN, LOW);
      tone(BUZZER_PIN, 1000);
      if (temperature < HEAT_OFF_TEMP) {
        noTone(BUZZER_PIN);
        currentState = IDLE;
      }
      break;
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C, State: ");
  Serial.println(stateToString(currentState));

  delay(1000);
}

String stateToString(State s) {
  switch (s) {
    case IDLE: return "IDLE";
    case HEATING: return "HEATING";
    case STABILIZING: return "STABILIZING";
    case TARGET_REACHED: return "TARGET_REACHED";
    case OVERHEAT: return "OVERHEAT";
    default: return "UNKNOWN";
  }
}
