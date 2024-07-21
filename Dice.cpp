#include <iostream>
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Simulate rolling two dice
    int die1 = rand() % 6 + 1;  // Random number between 1 and 6
    int die2 = rand() % 6 + 1;  // Random number between 1 and 6
    int total = die1 + die2;

    // Display the result
    std::cout << "You rolled:\n";
    std::cout << "Die 1: " << die1 << "\n";
    std::cout << "Die 2: " << die2 << "\n";
    std::cout << "Total: " << total << "\n";

    return 0;
}
