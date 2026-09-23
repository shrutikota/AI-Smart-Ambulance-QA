// Smart Ambulance Traffic Clearance System
// Stage 2 - Dynamic Distance Input with Non-Blocking Logic

const int RED_LED = 8;
const int YELLOW_LED = 9;
const int GREEN_LED = 10;
const int BUZZER = 11;
const float NORMAL_DISTANCE_THRESHOLD = 500.0;
const float EMERGENCY_DISTANCE_THRESHOLD = 200.0;
float ambulanceDistance = 0;

unsigned long previousMillis = 0;
const unsigned long interval = 5000;

String inputBuffer = "";

void setup() {

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

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

if (ambulanceDistance > NORMAL_DISTANCE_THRESHOLD) {

    normalState();

  }
  else if (ambulanceDistance > EMERGENCY_DISTANCE_THRESHOLD) {

    approachingState();

  }
  else {

    emergencyState();

  }
}

void readAmbulanceDistance() {

  while (Serial.available() > 0) {

    char c = Serial.read();

    if (c == '\n' || c == '\r') {

      if (inputBuffer.length() > 0) {

        float value = inputBuffer.toFloat();

        if (value >= 0) {

          ambulanceDistance = value;

          updateTrafficState();

          Serial.print("Ambulance Distance: ");
          Serial.print(ambulanceDistance);
          Serial.println(" m");

        }

        inputBuffer = "";

      }

    }
    else if ((c >= '0' && c <= '9') || c == '.') {

      inputBuffer += c;

    }
  }
}

void loop() {

  readAmbulanceDistance();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    updateTrafficState();

  }
}
