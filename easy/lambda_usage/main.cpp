#include <iostream>
#include <vector>
#include <algorithm> // For std::remove_if
#include <numeric> // for std::iota
#include <iterator>

using namespace std;

int main()
{
    // Simple case
    cout << "Let's start with simple case first" << endl;
    auto add = [](int a, int b) {return a + b;};
    cout << add(2,3) << endl;

    // A bit more sophisticated

    cout << "\n";
    cout << "A bit more sophisticated" << endl;

    int x = 1;
    auto f = [&]() { x++; };
    f();
    cout << x << endl;

    // advanced case with vector

    cout << "\n";
    cout << "Lets move to advanced cases with vector" << endl;

    vector<int> numbers(10);
    iota(numbers.begin(), numbers.end(),1);
    
    cout << "Show the vector ";
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    // auto new_end = remove_if(numbers.begin(), numbers.end(),
    //                         [](int n) { return n % 2 == 0;});
    // numbers.erase(new_end, numbers.end());

    // erase + remove_if combo to filter out
    numbers.erase(remove_if(numbers.begin(), numbers.end(),
                            [](int n) { return n % 2 == 0;}),
                            numbers.end());

    for (int &n: numbers) {
        cout << n << endl;
    }

}