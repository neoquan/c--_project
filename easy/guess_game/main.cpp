#include<iostream>
#include<cstdlib> // for rand(), srand()
#include<ctime> // for time()

using namespace std;

int main()
{
    // seed random generator with current time
    srand(time(0));

    int secret = rand() * 100 + 1; // random between 1 and 100
    int guess;
    int attempts = 0;

    cout << "I'm thinking of a number between 1 and 100.\n";

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
        else if (guess < secret) {cout << "Too low. Guess again!";}
        else {cout << "Too high. Gues again";}
    }
}