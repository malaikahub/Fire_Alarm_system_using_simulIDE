// Industrial Safety Monitoring and Control System
// Arduino UNO

// Pin Definitions
#define TEMP_SENSOR A0
#define GAS_SENSOR  A1
#define LED_TEMP    8
#define LED_GAS     9
#define BUZZER      10
#define RESET_BTN   12

// Threshold Values
#define TEMP_THRESHOLD  600
#define GAS_THRESHOLD   600

// Variables
bool alarmActive = false;

void setup() {
  pinMode(LED_TEMP, OUTPUT);
  pinMode(LED_GAS, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RESET_BTN, INPUT_PULLUP);
  
  // Make sure everything is OFF at start
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED_TEMP, LOW);
  digitalWrite(LED_GAS, LOW);
  
  Serial.begin(9600);
  Serial.println("System Started!");
}

void loop() {
  int tempValue = analogRead(TEMP_SENSOR);
  int gasValue  = analogRead(GAS_SENSOR);

  Serial.print("Temp: ");
  Serial.print(tempValue);
  Serial.print(" | Gas: ");
  Serial.println(gasValue);

  // Reset alarm flag first
  alarmActive = false;

  // Temperature Check
  if (tempValue > TEMP_THRESHOLD) {
    digitalWrite(LED_TEMP, HIGH);
    alarmActive = true;
    Serial.println("TEMPERATURE DANGER!");
  } else {
    digitalWrite(LED_TEMP, LOW);
  }

  // Gas Check
  if (gasValue > GAS_THRESHOLD) {
    digitalWrite(LED_GAS, HIGH);
    alarmActive = true;
    Serial.println("GAS DANGER!");
  } else {
    digitalWrite(LED_GAS, LOW);
  }

  // Buzzer ONLY ON when danger
  if (alarmActive) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);  // OFF when safe!
  }

  // Reset Button
  if (digitalRead(RESET_BTN) == LOW) {
    alarmActive = false;
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED_TEMP, LOW);
    digitalWrite(LED_GAS, LOW);
    Serial.println("Alarm Reset!");
    delay(500);
  }

  delay(500);
}