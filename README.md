# Reflexor ⚡

## About the Project 🎮

This project is an Arduino-based reaction time game that tests how quickly a player can respond to a randomly selected LED.

The game uses three LEDs and three corresponding buttons. After a random delay, one LED lights up and the player must press the matching button as quickly as possible. The player's reaction time is then calculated and displayed on a 16x2 LCD.

## How It Works 🧠

1. The LCD displays **"Get ready..."**
2. The Arduino waits for a random amount of time.
3. One of the three LEDs is randomly selected.
4. The selected LED turns on and the reaction timer starts.
5. The player presses the button corresponding to the lit LED.
6. The timer stops and the reaction time is calculated.
7. The LCD displays the player's reaction time and a performance rating.
8. After a short pause, a new round begins automatically.

## Reaction Ratings 🏆

| Reaction Time | Rating |
|---|---|
| 500 ms or less | You're Amazing! |
| 501–1000 ms | You're Good :) |
| 1001–2000 ms | You're Average.. |
| Over 2000 ms | You're Slow :( |

## Components 🔧

- Arduino Uno R3
- 3 LEDs
- 3 Push Buttons
- 3 Resistors
- 16x2 LCD Display
- Breadboard
- Jumper Wires

## Pin Connections 🔌

### LEDs

| Component | Arduino Pin |
|---|---|
| Blue LED | Pin 2 |
| Green LED | Pin 3 |
| Red LED | Pin 4 |

### Buttons

| Component | Arduino Pin |
|---|---|
| Blue Button | Pin 5 |
| Green Button | Pin 6 |
| Red Button | Pin 7 |

### LCD

The LCD is connected using Arduino pins 13, 12, 11, 10, 9, and 8.

## Key Concepts 💡

This project helped me practice several Arduino programming concepts, including:

- Digital inputs and outputs
- `digitalRead()` and `digitalWrite()`
- `millis()` for measuring reaction time
- `delay()` for timing
- `random()` for randomly selecting LEDs
- `randomSeed()` for randomizing the LED selection
- `while` loops
- `if` / `else if` / `else` statements
- Functions
- LCD display programming
- Variables and data types

## Future Improvements 🚀

Some features I may add in the future:

- Detecting incorrect button presses
- Keeping track of the player's score
- Adding a high-score system
- Tracking the average reaction time
- Adding multiple difficulty levels
- Adding a countdown before each round
- Adding a game-over or win screen

## Built With 🛠️

- Arduino IDE
- Arduino Uno R3
- C/C++ (Arduino)
- LiquidCrystal library

