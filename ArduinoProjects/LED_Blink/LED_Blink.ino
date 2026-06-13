// Industrial Safety Monitoring and Control System
// Arduino UNO

// Pin Definitions
#define TEMP_SENSOR A0      // Potentiometer 1 - Temperature
#define GAS_SENSOR  A1      // Potentiometer 2 - Gas/Smoke
#define LED_TEMP    8       // Temperature Warning LED
#define LED_GAS     9       // Gas Warning LED
#define BUZZER      10      // Alarm Buzzer
#define RESET_BTN   12      // Reset Button

// Threshold Values
#define TEMP_THRESHOLD  600  // Adjust as needed (0-1023)
#define GAS_THRESHOLD   600  // Adjust as needed (0-1023)

// Variables
bool alarmActive = false;

void setup() {
  pinMode(LED_TEMP, OUTPUT);
  pinMode(LED_GAS, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RESET_BTN, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("Industrial Safety System Started!");
  Serial.println("==================================");
}

void loop() {
  // Read Sensor Values
  int tempValue = analogRead(TEMP_SENSOR);
  int gasValue  = analogRead(GAS_SENSOR);

  // Print values to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(tempValue);
  Serial.print("  |  Gas Level: ");
  Serial.println(gasValue);

  // Temperature Check
  if (tempValue > TEMP_THRESHOLD) {
    digitalWrite(LED_TEMP, HIGH);
    alarmActive = true;
    Serial.println("⚠️ TEMPERATURE DANGER DETECTED!");
  } else {
    digitalWrite(LED_TEMP, LOW);
  }

  // Gas Check
  if (gasValue > GAS_THRESHOLD) {
    digitalWrite(LED_GAS, HIGH);
    alarmActive = true;
    Serial.println("⚠️ GAS DANGER DETECTED!");
  } else {
    digitalWrite(LED_GAS, LOW);
  }

  // Buzzer Alarm
  if (alarmActive) {
    digitalWrite(BUZZER, HIGH);
  }

  // Reset Button Check
  if (digitalRead(RESET_BTN) == LOW) {
    alarmActive = false;
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED_TEMP, LOW);
    digitalWrite(LED_GAS, LOW);
    Serial.println("✅ Alarm Reset by User!");
    delay(500);
  }

  delay(500);
}