#include <iostream>  // Required for input and output functions
#include <cstdlib>   // Required for rand() and srand()
#include <ctime>     // Required for time()

int main() {
    // Initialize random seed based on the current time
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = (std::rand() % 100) + 1;
    int guess;        // Variable to store the user's guess
    int attempts = 0; // Counter for the number of attempts

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    // Loop until the user guesses the correct number
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess; // Take the user's guess as input
        attempts++;        // Increment the number of attempts

        if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
            std::cout << "It took you " << attempts << " attempts." << std::endl;
        }
    } while (guess != randomNumber); // Repeat until the correct number is guessed

    return 0;
}
