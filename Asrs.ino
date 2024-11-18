#define stepPin_1 2
#define stepPin_2 3
#define stepPin_3 4
#define dirPin_1 5
#define dirPin_2 6
#define dirPin_3 7
#define servoPin_end 8
#define servoPin_gripper 9

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin_gripper, OUTPUT);
  pinMode(servoPin_end, OUTPUT);
  pinMode(stepPin_1, OUTPUT);
  pinMode(stepPin_2, OUTPUT);
  pinMode(stepPin_3, OUTPUT);
  pinMode(dirPin_1, OUTPUT);
  pinMode(dirPin_2, OUTPUT);
  pinMode(dirPin_3, OUTPUT);
  serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(sigPinser_1, HIGH);
  
  
}
const int servoPin = 9; // Pin connected to the servo signal
void setup() {
  pinMode(servoPin, OUTPUT); // Set servo pin as an output
}

void loop() {
  // Move servo to 0 degrees
  writeServo(servoPin, 0);
  millis(1000); // Wait 1 second

  // Move servo to 90 degrees
  writeServo(servoPin, 90);
  millis(1000); // Wait 1 second

  // Move servo to 180 degrees
  writeServo(servoPin, 180);
  millis(1000); // Wait 1 second
}

void writeServo(int pin, int angle) {
  int pulseWidth = map(angle, 0, 180, 1000, 2000); // Map angle to pulse width (1 ms to 2 ms)
  digitalWrite(pin, HIGH); // Start pulse
  delayMicroseconds(pulseWidth); // Keep pulse HIGH for the desired width
  digitalWrite(pin, LOW); // End pulse
  delay(20 - (pulseWidth / 1000)); // Wait for the remainder of the 20 ms period
}
