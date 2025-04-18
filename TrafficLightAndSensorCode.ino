const int TRIG_PIN1 = 9, ECHO_PIN1 = 8;
const int TRIG_PIN2 = 4, ECHO_PIN2 = 3;

const int LIGHT1_PINS[] = {12, 11, 10}; // Red, Yellow, Green
const int LIGHT2_PINS[] = {7, 6, 5};    // Red, Yellow, Green

int activeLight = 0;        // 0=none, 1=light1, 2=light2
bool inTransition = false;
unsigned long transitionStart;
unsigned long greenStart;
unsigned long greenDuration = 0;

void setup() {
  pinMode(TRIG_PIN1, OUTPUT); pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT); pinMode(ECHO_PIN2, INPUT);
  
  for(int i=0; i<3; i++){
    pinMode(LIGHT1_PINS[i], OUTPUT);
    pinMode(LIGHT2_PINS[i], OUTPUT);
  }

  digitalWrite(LIGHT1_PINS[0], HIGH); // Red
  digitalWrite(LIGHT2_PINS[0], HIGH); // Red
}

float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH, 20000) * 0.034 / 2; // max 20ms timeout
}

void setLight(int light, int state) {
  int* pins = (light == 1) ? LIGHT1_PINS : LIGHT2_PINS;
  for(int i=0; i<3; i++) {
    digitalWrite(pins[i], (i == state) ? HIGH : LOW);
  }
}

void loop() {
  float dist1 = readDistance(TRIG_PIN1, ECHO_PIN1);
  float dist2 = readDistance(TRIG_PIN2, ECHO_PIN2);

  int targetLight = (dist1 < dist2) ? 1 : 2;
  float minDist = min(dist1, dist2);

  if (minDist > 100) targetLight = 0;  // Ignore if far away

  if (targetLight != 0 && activeLight == 0 && !inTransition) {
    if (minDist <= 5) greenDuration = 15000;
    else if (minDist <= 12) greenDuration = 5000;
    else greenDuration = 0;

    if (greenDuration > 0) {
      setLight(targetLight, 2); // Green
      setLight((targetLight == 1 ? 2 : 1), 0); // Other light to Red
      activeLight = targetLight;
      greenStart = millis();
    }
  }

  // After greenDuration, go yellow for 2s
  if (activeLight != 0 && !inTransition && millis() - greenStart >= greenDuration) {
    setLight(activeLight, 1); // Yellow
    inTransition = true;
    transitionStart = millis();
  }

  // After yellow (2s), switch to red and flip other light to green (if applicable)
  if (inTransition && millis() - transitionStart >= 2000) {
    setLight(activeLight, 0); // Red
    int otherLight = (activeLight == 1) ? 2 : 1;

    // If the other sensor still detects a car close, make it green
    float otherDist = (otherLight == 1) ? dist1 : dist2;
    if (otherDist <= 12) {
      setLight(otherLight, 2);
      greenStart = millis();
      greenDuration = (otherDist <= 5) ? 15000 : 5000;
      activeLight = otherLight;
    } else {
      activeLight = 0;
    }

    inTransition = false;
  }

  delay(50);
}
