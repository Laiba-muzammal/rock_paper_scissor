#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char userChoice, computerChoice;
int userScore = 0;
int computerScore = 0;

char getUserChoice() {
    char choice;
    cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
    cin >> choice;
    return toupper(choice);
}

char getComputerChoice() {
    int num = rand() % 3;
    char choices[] = {'R', 'P', 'S'};
    return choices[num];
}

void determineWinner(char userChoice, char computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if (
        (userChoice == 'R' && computerChoice == 'S') ||
        (userChoice == 'P' && computerChoice == 'R') ||
        (userChoice == 'S' && computerChoice == 'P')
    ) {
        cout << "You win!" << endl;
        userScore++;
    } else {
        cout << "Computer wins!" << endl;
        computerScore++;
    }
}

int main() {
    char playAgain;
    srand(time(NULL));

    do {
        userChoice = getUserChoice();

        if (userChoice != 'R' && userChoice != 'P' && userChoice != 'S') {
            cout << "Invalid input. Please enter R, P, or S." << endl;
            continue;
        }

        computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;

        determineWinner(userChoice, computerChoice);

        cout << "Your score: " << userScore << endl;
        cout << "Computer's score: " << computerScore << endl;

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        cout << endl;

    } while (toupper(playAgain) == 'Y');

    return 0;
}
