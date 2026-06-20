/*
  sumo Robot
  
*/

// Motor A (Left)
#define ENA 5
#define IN1 2
#define IN2 3

// Motor B (Right)
#define ENB 6
#define IN3 4
#define IN4 7

char command;

void setup() {
  Serial.begin(9600);   // Bluetooth communication

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {

  if (Serial.available() > 0) {
    command = Serial.read();

    // App buttons send these characters
    if (command == 'F') forward();     // Forward
    else if (command == 'B') backward(); // Backward
    else if (command == 'L') left();    // Left
    else if (command == 'R') right();   // Right
    else if (command == 'S') stopRobot(); // Stop
  }
}