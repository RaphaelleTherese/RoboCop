#include "Keypad.h"
 
// Password: 6250

const byte ROWS = 4; // number of rows
const byte COLS = 4; // number of columns
char keys[ROWS][COLS] = {
{'1','2','3', 'A'},
{'4','5','6', 'B'},
{'7','8','9', 'C'},
{'#','0','*', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String password = "6250";
String attempt = "";
 
void setup()
{
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}

void loop()
{
	char key = keypad.getKey(); 
	if (key != NO_KEY) {
		attempt += key;

		if (attempt.length() == 4) {
			if (attempt == password) {
				digitalWrite(13, HIGH);
				Serial.println("Correct!");
			} else
			{
				digitalWrite(13, LOW);
				Serial.println("Incorrect!");
			}
			
			Serial.println(attempt);
			attempt = "";
		}
	}
}