#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int hiddenNum = rand() % 100 + 1;
    const int TotalChoices = 10;
    int choicesLeft = TotalChoices;

    std::cout << "Guess a number between 1 and 100. You have " << TotalChoices << " choices.\n";

    int guess;
    std::cout << "Enter your guess: ";
    std::cin >> guess;

    while (guess != hiddenNum && choicesLeft > 1) {
        if (guess < hiddenNum) {
            std::cout << "Too low! ";
        } else {
            std::cout << "Too high! ";
        }

        choicesLeft--;
        std::cout << "You have " << choicesLeft << " choices left. Guess again: ";
        std::cin >> guess;
    }

    if (guess == hiddenNum) {
        std::cout << "Congratulations! You guessed the number.\n";
    } else {
        std::cout << "Sorry, you couldn't guess the number. It was " << hiddenNum << ". Better luck next time!\n";
    }

    return 0;
}
