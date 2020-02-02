// 0 - off, 1 - short repeat, 2 - long repeat
int buzz_mode = 1;
unsigned long buzz_timer = 0;
unsigned long buzz_on = 0;
unsigned long buzz_start = 0;
unsigned long buzz_dwell_short = 1000;
unsigned long buzz_dwell_long = 2000;
int last_button = HIGH;
unsigned long button_time = 0;
unsigned long debounce_time = 500;
int interval = 0;
int lastOne = -1; // 0 = right, 1 = left
int lastTwo = -2; // 0 = right, 1 = left


void leftBuzz() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}

void rightBuzz() {
  digitalWrite(13, HIGH);
  delay(450);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  delay(450);
  digitalWrite(13, LOW);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  randomSeed(analogRead(2));
  buzz_start = millis();
  interval = random(5, 10) * 1000;
}

void loop() {
//  if (last_button == HIGH && digitalRead(8) == LOW && millis() - button_time > debounce_time) {
//    last_button = LOW;
//    buzz_mode = buzz_mode + 1;
//    if (buzz_mode > 2) {
//      buzz_mode = 0;
//    }
//    button_time = millis();
//  } else if (last_button == LOW && digitalRead(8) == HIGH && millis() - button_time > debounce_time) {
//    last_button = HIGH;
//    button_time = millis();
//  }
  // end of button nonsense

  
  if (millis() > buzz_start + interval) {
    buzz_start = millis();
    int left = random(0, 2); // 0 = go right, 1 = go left
    if (lastOne = lastTwo) {
      if (lastOne) { // left last time 
        lastTwo = lastOne;
        lastOne = 0;
        rightBuzz();
      } else { // right last time
        lastTwo = lastOne;
        lastOne = 1;
        leftBuzz();
      }
    }
    if (left) {
      lastTwo = lastOne;
      lastOne = 1;
      leftBuzz();
    } else {
      lastTwo = lastOne;
      lastOne = 0;
      rightBuzz();
    }
    interval = random(3, 9) * 1000;
  }
}
