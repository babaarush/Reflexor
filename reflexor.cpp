int blueLedPin = 2;
int greenLedPin = 3;
int redLedPin = 4;

int blueButtonPin = 5;
int greenButtonPin = 6;
int redButtonPin = 7;

unsigned long startingTime = 0;
unsigned long endingTime = 0;
unsigned long reactionTime = 0;

int selectLed = 0;
int randomDelay = 0;

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


void setup() {

  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(redButtonPin, INPUT_PULLUP);

  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  lcd.begin(16, 2);

  //randomize the LED selection
  randomSeed(analogRead(A0));
}


void showResult() {

  lcd.clear();

  lcd.setCursor(0, 0);

  if (reactionTime <= 500) {
    lcd.print("You're amazing! ");
  }
  else if (reactionTime <= 1000) {
    lcd.print("You're Good :)");
  }
  else if (reactionTime <= 2000) {
    lcd.print("You're Average..");
  }
  else {
    lcd.print("You're Slow :( ");
  }

  lcd.setCursor(0, 1);
  lcd.print(reactionTime);
  lcd.print(" ms");
}


void loop() {

  // turn off all LED'S before starting a new round
  digitalWrite(blueLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Get ready...");

  randomDelay = random(1000, 6000);
  delay(randomDelay);

  // select which LED to turn on
  selectLed = random(0, 3);

  // blue LED
  if (selectLed == 0) {
    digitalWrite(blueLedPin, HIGH);
  }

  // green LED
  else if (selectLed == 1) {
    digitalWrite(greenLedPin, HIGH);
  }

  // red LED
  else {
    digitalWrite(redLedPin, HIGH);
  }

  // starting the timer after the LED has turned on
  startingTime = millis();


  // if blue LED turns on, only blueButtonPin should be able to control it
  if (selectLed == 0) {

    while (digitalRead(blueButtonPin) == HIGH) {
    }

    endingTime = millis();
    digitalWrite(blueLedPin, LOW);
  }

  // if green LED turns on, only greenButtonPin should be able to control it
  else if (selectLed == 1) {

    while (digitalRead(greenButtonPin) == HIGH) {
    }

    endingTime = millis();
    digitalWrite(greenLedPin, LOW);
  }

  //if red LED turns on, only redButtonPin should be able to control it
  else {

    while (digitalRead(redButtonPin) == HIGH) {
    }

    endingTime = millis();
    digitalWrite(redLedPin, LOW);
  }

  reactionTime = endingTime - startingTime;

  showResult();

  // small break before next round
  delay(2500);
}