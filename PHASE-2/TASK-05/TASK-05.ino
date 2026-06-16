const int ENA = 9;
const int IN1 = 7;
const int IN2 = 8;

const int ledPin = 5;     // LED on D5
const int estopPin = 2;   // Interrupt pin

volatile bool emergencyStop = false;

void emergencyISR() {
  emergencyStop = true;
}

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ledPin, OUTPUT);

  pinMode(estopPin, INPUT_PULLUP);

  Serial.begin(9600);

  // Motor direction forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor OFF initially
  analogWrite(ENA, 0);

  // LED OFF initially
  digitalWrite(ledPin, LOW);

  // Interrupt setup
  attachInterrupt(
    digitalPinToInterrupt(estopPin),
    emergencyISR,
    FALLING
  );

  Serial.println("Motor PWM Control");
  Serial.println("Enter 0-9");
}

void loop() {

  // Emergency stop
  if (emergencyStop) {

    analogWrite(ENA, 0);   // Stop motor
    digitalWrite(ledPin, LOW); // LED OFF

    Serial.println("EMERGENCY STOP ACTIVATED");

    while (1); // Freeze system
  }

  // Serial input
  if (Serial.available()) {

    char cmd = Serial.read();

    if (cmd >= '0' && cmd <= '9') {

      int pwmValue =
        map(cmd - '0', 0, 9, 0, 255);

      analogWrite(ENA, pwmValue);

      Serial.print("PWM = ");
      Serial.println(pwmValue);

      // LED ON when motor runs
      if (pwmValue > 0) {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
    }
  }
}
