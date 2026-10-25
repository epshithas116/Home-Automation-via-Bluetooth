/*
 * Task 1: Home Automation via Bluetooth / Serial Control
 * Intern: Surisetty Epshitha
 * Domain: Embedded Systems (Codtech IT Solutions)
 */

const int RELAY_1 = 4;
const int RELAY_2 = 5;
const int RELAY_3 = 6;
const int RELAY_4 = 7;

char cmd;

void setup() {
  Serial.begin(9600);
  
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  // Active-LOW relay initial states (HIGH = OFF)
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  digitalWrite(RELAY_3, HIGH);
  digitalWrite(RELAY_4, HIGH);

  Serial.println("=========================================");
  Serial.println(" SMART HOME AUTOMATION SYSTEM INITIALIZED");
  Serial.println(" Send: '1'/'a' (App 1), '2'/'b' (App 2)");
  Serial.println("       '3'/'c' (App 3), '4'/'d' (App 4)");
  Serial.println("       '9' (All ON), '0' (All OFF)");
  Serial.println("=========================================");
}

void loop() {
  if (Serial.available() > 0) {
    cmd = Serial.read();

    switch (cmd) {
      case '1':
        digitalWrite(RELAY_1, LOW);
        Serial.println("[STATUS] Appliance 1: ON");
        break;
      case 'A':
      case 'a':
        digitalWrite(RELAY_1, HIGH);
        Serial.println("[STATUS] Appliance 1: OFF");
        break;

      case '2':
        digitalWrite(RELAY_2, LOW);
        Serial.println("[STATUS] Appliance 2: ON");
        break;
      case 'B':
      case 'b':
        digitalWrite(RELAY_2, HIGH);
        Serial.println("[STATUS] Appliance 2: OFF");
        break;

      case '3':
        digitalWrite(RELAY_3, LOW);
        Serial.println("[STATUS] Appliance 3: ON");
        break;
      case 'C':
      case 'c':
        digitalWrite(RELAY_3, HIGH);
        Serial.println("[STATUS] Appliance 3: OFF");
        break;

      case '4':
        digitalWrite(RELAY_4, LOW);
        Serial.println("[STATUS] Appliance 4: ON");
        break;
      case 'D':
      case 'd':
        digitalWrite(RELAY_4, HIGH);
        Serial.println("[STATUS] Appliance 4: OFF");
        break;

      case '9':
        digitalWrite(RELAY_1, LOW);
        digitalWrite(RELAY_2, LOW);
        digitalWrite(RELAY_3, LOW);
        digitalWrite(RELAY_4, LOW);
        Serial.println("[STATUS] All Appliances: ACTIVATED");
        break;

      case '0':
        digitalWrite(RELAY_1, HIGH);
        digitalWrite(RELAY_2, HIGH);
        digitalWrite(RELAY_3, HIGH);
        digitalWrite(RELAY_4, HIGH);
        Serial.println("[STATUS] All Appliances: DEACTIVATED");
        break;

      default:
        break;
    }
  }
}
