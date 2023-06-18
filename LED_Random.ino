// File for Random LED Side Panels

// Setup
    
    // OUTPUT PINS
        int pinL1 = 2; // Left Group 1
        int pinL2 = 3; // Left Group 2
        int pinL3 = 4; // Left Group 3
        int pinL4 = 5; // Left Group 4
        int pinL5 = 6; // Left Group 5
        int pinR1 = 7; // Right Group 1
        int pinR2 = 8; // Right Group 1
        int pinR3 = 9; // Right Group 1
        int pinR4 = 10; // Right Group 1
        int pinR5 = 11; // Right Group 1
        
    // Variables 
        long randomNumber;

void setup() {
    // Setup 
    Serial.begin(9600);

    // Setup Inputs 
    Serial.print("1 of 1 Setting up Pins as OUTPUTS... ");
    pinMode(pinL1, OUTPUT);
    pinMode(pinL2, OUTPUT);
    pinMode(pinL3, OUTPUT);
    pinMode(pinL4, OUTPUT);
    pinMode(pinL5, OUTPUT);
    pinMode(pinR1, OUTPUT);
    pinMode(pinR2, OUTPUT);
    pinMode(pinR3, OUTPUT);
    pinMode(pinR4, OUTPUT);
    pinMode(pinR5, OUTPUT);
    Serial.println("done.");
}


void clearLEDs() {
    Serial.print("Clearing pin signals [clearLEDs]...     ");
    digitalWrite(pinL1, LOW);
    digitalWrite(pinL2, LOW);
    digitalWrite(pinL3, LOW);
    digitalWrite(pinL4, LOW);
    digitalWrite(pinL5, LOW);
    digitalWrite(pinR1, LOW);
    digitalWrite(pinR2, LOW);
    digitalWrite(pinR3, LOW);
    digitalWrite(pinR4, LOW);
    digitalWrite(pinR5, LOW);
    Serial.println("done.");
}

void loop() {
    // RESET
    clearLEDs();

    randomNumber = random(0,9);
    Serial.print("Generating Random Number...  ");
    Serial.print(randomNumber);
    Serial.print(" ... turning on LEDs...  ");


    switch (randomNumber) {
        case 0:
            digitalWrite(pinL1, HIGH);
            digitalWrite(pinR1, HIGH);    
            break;
        case 1:
            digitalWrite(pinL2, HIGH);
            digitalWrite(pinR2, HIGH);    
            break;
         case 2:
            digitalWrite(pinL3, HIGH);
            digitalWrite(pinR3, HIGH);    
            break;
         case 3:
            digitalWrite(pinL4, HIGH);
            digitalWrite(pinR4, HIGH);    
            break;
         case 4:
            digitalWrite(pinL5, HIGH);
            digitalWrite(pinR5, HIGH);    
            break;
        case 5:
            digitalWrite(pinL1, HIGH);
            digitalWrite(pinR5, HIGH);    
            break;
        case 6:
            digitalWrite(pinL2, HIGH);
            digitalWrite(pinR4, HIGH);    
            break;
        case 7:
            digitalWrite(pinL3, HIGH);
            digitalWrite(pinR3, HIGH);    
            break;
        case 8:
            digitalWrite(pinL4, HIGH);
            digitalWrite(pinR2, HIGH);    
            break;
        case 9:
            digitalWrite(pinL5, HIGH);
            digitalWrite(pinR1, HIGH);    
            break;
        default:
            digitalWrite(pinL5, HIGH);
            digitalWrite(pinR1, HIGH);    
            break;
    }
    Serial.println("done.");
}
