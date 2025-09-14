#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I've generated a random number between 1 and 100." << std::endl;

    while (userGuess != secretNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << secretNumber << std::endl;
        }
    }

    return 0;
}