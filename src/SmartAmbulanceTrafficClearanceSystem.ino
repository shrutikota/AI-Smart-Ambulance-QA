// Smart Ambulance Traffic Clearance System
// Stage 2 - Distance Based Traffic Logic

const int RED_LED = 8;
const int YELLOW_LED = 9;
const int GREEN_LED = 10;
const int BUZZER = 11;

float ambulanceDistance;

void setup() {

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void normalState() {

  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW);
}

void approachingState() {

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW);
}

void emergencyState() {

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BUZZER, HIGH);
}

void loop() {

  // Test distance: 600 m
  ambulanceDistance = 600;

  if (ambulanceDistance > 500) {
    normalState();
  }
  else if (ambulanceDistance > 200) {
    approachingState();
  }
  else {
    emergencyState();
  }

  delay(5000);

  // Test distance: 300 m
  ambulanceDistance = 300;

  if (ambulanceDistance > 500) {
    normalState();
  }
  else if (ambulanceDistance > 200) {
    approachingState();
  }
  else {
    emergencyState();
  }

  delay(5000);

  // Test distance: 100 m
  ambulanceDistance = 100;

  if (ambulanceDistance > 500) {
    normalState();
  }
  else if (ambulanceDistance > 200) {
    approachingState();
  }
  else {
    emergencyState();
  }

  delay(5000);
}
