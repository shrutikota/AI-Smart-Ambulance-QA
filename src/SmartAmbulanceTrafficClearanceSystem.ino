// Smart Ambulance Traffic Clearance System
// Stage 2 - Non-Blocking Distance Based Traffic Logic

const int RED_LED = 8;
const int YELLOW_LED = 9;
const int GREEN_LED = 10;
const int BUZZER = 11;

float ambulanceDistance = 600;

unsigned long previousMillis = 0;
const unsigned long interval = 5000;

int testStage = 0;

void setup() {

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  normalState();
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

void updateTrafficState() {

  if (ambulanceDistance > 500) {

    normalState();

  }
  else if (ambulanceDistance > 200) {

    approachingState();

  }
  else {

    emergencyState();

  }
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    testStage++;

    if (testStage == 1) {

      ambulanceDistance = 300;

    }
    else if (testStage == 2) {

      ambulanceDistance = 100;

    }
    else {

      testStage = 0;
      ambulanceDistance = 600;

    }

    updateTrafficState();
  }
}
