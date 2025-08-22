#include<iostream>
#include<cstdlib> // for rand(), srand()
#include<ctime> // for time()

using namespace std;

int main()
{
    // seed random generator with current time
    srand(time(0));

    int maxRange;
    int choice;

    cout << "Choose difficulty.\n";
    cout << "1. Easy (1-50)\n";
    cout << "2. Medium (1-100)\n";
    cout << "3. Hard (1-500)\n";
    cout << "Enter choice (1-3)\n";
    cin >> choice;

    if (choice == 1) maxRange = 50;
    else if (choice == 2) maxRange = 100;
    else if (choice == 3) maxRange = 500;
    else
    {
        cout << "Invalid choice. Defaulting to Medium level.\n";
        maxRange = 100;
    }

    int secret = rand() % maxRange + 1; // random between 1 and 100
    int guess;
    int attempts = 0;

    cout << "I'm thinking of a number between 1 and " << maxRange << ".\n";

    while (true) 
    {
        cout << "Take a guess: ";
        cin >> guess;
        attempts;

        if (guess == secret)
        {
            cout << "Correct! You gues it right in " << attempts << " tries.\n";

            break;
        }
        else if (guess < secret) {cout << "Too low. Guess again!\n";}
        else {cout << "Too high. Guess again!\n";}
    }
}