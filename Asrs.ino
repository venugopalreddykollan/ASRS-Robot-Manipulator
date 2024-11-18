#define stepPin_1 2 // BASE
#define stepPin_2 3 // shoulder
#define stepPin_3 4 // ELBOW
#define dirPin_1 5 // influces direction of Base Motor
#define dirPin_2 6 // influces direction of Shoulder Motor
#define dirPin_3 7 // influces direction of Elbow Motor
#define enaPin_1 10 //influences free drive of Base Motor
#define enaPin_2 11 //influences free drive of Shoulder Motor
#define enaPin_3 12 //influences free drive of Elbow Motor
#define servoPin_end 8 // servo MG995
#define servoPin_gripper 9 // Micro servo motor 
unsigned long current_millis = 0;
unsigned long previous_millis = 0;
volatile float delta;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin_1, OUTPUT);
  pinMode(stepPin_2, OUTPUT);
  pinMode(stepPin_3, OUTPUT);
  pinMode(dirPin_1, OUTPUT);
  pinMode(dirPin_2, OUTPUT);
  pinMode(dirPin_3, OUTPUT);
   pinMode(enaPin_1, OUTPUT);
  pinMode(enaPin_2, OUTPUT);
  pinMode(enaPin_3, OUTPUT);
  pinMode(servoPin_end, OUTPUT);
  pinMode(servoPin_gripper, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  
  writeServo(servoPin_gripper, 0);             // Move servo to 0 degrees
 //millis(1000); // Wait 1 second

  // Move servo to 90 degrees
  writeServo(servoPin_gripper, 90);
  //millis(1000); // Wait 1 second

  // Move servo to 180 degrees
  writeServo(servoPin_gripper, 180);
  //millis(1000); // Wait 1 second
}

void writeServo(int pin, int angle) {
  int pulseWidth = map(angle, 0, 180, 1000, 2000); // Map angle to pulse width (1 ms to 2 ms)
  digitalWrite(pin, HIGH); // Start pulse
  delayMicroseconds(pulseWidth); // Keep pulse HIGH for the desired width
  digitalWrite(pin, LOW); // End pulse
  delay(20 - (pulseWidth / 1000)); // Wait for the remainder of the 20 ms period
}
