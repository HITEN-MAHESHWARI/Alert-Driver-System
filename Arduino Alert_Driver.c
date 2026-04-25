#define THRESHOLD_1  20
#define THRESHOLD_2  40
#define THRESHOLD_3  60

int eyePin    = 2;
int buzzerPin = 8;
int relayPin  = 9;

int blink_timer = 0;
int stage = 0;
int eye_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(eyePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.println("Driver Drowsiness System Started");
}

void loop() {

  eye_state = digitalRead(eyePin);

  if (eye_state == HIGH) {
    blink_timer = 0;
    stage = 0;
    reset_system();
  }

  else {
    blink_timer++;

    Serial.print("Timer: ");
    Serial.println(blink_timer);

    if (blink_timer > THRESHOLD_1 && stage < 1) {
      stage = 1;
      stage1_alert();
    }

    else if (blink_timer > THRESHOLD_2 && stage < 2) {
      stage = 2;
      stage2_alert();
    }

    else if (blink_timer > THRESHOLD_3 && stage < 3) {
      stage = 3;
      stage3_alert();
    }
  }

  delay(200);
}

void stage1_alert() {
  Serial.println("Stage 1: Soft Beep");
  digitalWrite(buzzerPin, HIGH);
  delay(300);
  digitalWrite(buzzerPin, LOW);
}

void stage2_alert() {
  Serial.println("Stage 2: Strong Beeps");

  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
  }
}

void stage3_alert() {
  Serial.println("Stage 3: EMERGENCY!");
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(relayPin, HIGH);
  delay(2000);
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);
  Serial.println("Car stopped!");
}

void reset_system() {
  digitalWrite(buzzerPin, LOW);
  digitalWrite(relayPin, LOW);
  Serial.println("Driver Awake - System Reset");
}