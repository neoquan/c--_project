#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    bool isPalin = true;
    int n = input.size();

    // độ phức tạo O(n)
    for (int i = 0; i < n/2; i++) {
        if (input[i] != input[n-i-1]) {
            isPalin = false;
            break;
        }
    }

    if (isPalin) cout << "[OK] Palindrome" << endl;
    else cout << "[X] Not a palindrome" << endl;

    return 0;

}