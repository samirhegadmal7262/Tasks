#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

Choice getUserChoice() {
    int choice;
    cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
    cin >> choice;
    return static_cast<Choice>(choice);
}

void displayChoice(Choice choice) {
    switch (choice) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }
}

void determineWinner(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == PAPER && computerChoice == ROCK) ||
               (userChoice == SCISSORS && computerChoice == PAPER)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // seed the random number generator

    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice();

    cout << "You chose: ";
    displayChoice(userChoice);
    cout << endl;

    cout << "Computer chose: ";
    displayChoice(computerChoice);
    cout << endl;

    determineWinner(userChoice, computerChoice);

    return 0;
}
