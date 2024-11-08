#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>

class MotorStatus {
private:
    uint8_t motorState; // Each bit represents the status of a motor (on/off)
    uint8_t overheatingMotors; // Motors that are overheating
    int turnCount;

    // Function to randomly initialize motors (on/off) and overheat one motor
    void initialize() {
        srand(time(0));
        motorState = rand() % 256; // Randomly turn motors on/off
        updateOverheating(); // Randomly overheat one motor
        turnCount = 0;
        displayStatus();
    }

    // Incrementally overheat motors with each turn, ensuring the motor is ON and not already overheating
    void updateOverheating() {
        int newMotor;
        do {
            newMotor = rand() % 8; // Randomly select a motor
        } while (((1 << newMotor) & motorState) == 0 || // Ensure the motor is ON
            ((1 << newMotor) & overheatingMotors) != 0); // Ensure the motor is not already overheating

        overheatingMotors |= (1 << newMotor); // Set the selected motor to overheat
        turnCount++;
    }

    void displayStatus() {
        std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) << std::endl;
        std::cout << "Overheating Motors: " << std::bitset<8>(overheatingMotors) << std::endl;
        std::cout << "Turn Count: " << turnCount << std::endl;
    }

public:
    MotorStatus() {
        initialize();
    }

    // Simulate a guess attempt
    bool turnOff(uint8_t guess) {
        // Step 1: Turn off the motors that are overheating and match the guess
        uint8_t motorsToTurnOff = overheatingMotors & guess;
        motorState &= ~motorsToTurnOff; // Turn off guessed motors that are overheating

        // Step 2: Check if the guess was correct (if all guessed motors are turned off)
        if ((motorsToTurnOff == overheatingMotors) && (motorsToTurnOff != 0)) {
            // Correct guess: We turned off the correct overheating motors
            displayStatus();
            return true;
        }

        // Step 3: Incorrect guess - make another motor overheat
        updateOverheating();
        displayStatus();
        return false;
    }

    // Display current motor status (for debugging purposes)
};

int main() {
    MotorStatus motorStatus;

    uint8_t guess = 0b00000001; // Start with the first motor as the guess

    // Loop until the correct motor is turned off
    while (!motorStatus.turnOff(guess)) {
        // Adjust the guess based on feedback
        // For now, we'll just cycle through all motors as a simple strategy
        guess = (guess << 1) | 1; // Move to the next motor
        if (guess > 0b11111111) {
            guess = 0b00000001; // Reset to first motor if we've tried all
        }
    }

    return 0;
}
