#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() 
{
    // tạo 1 hash_map là scores.
    unordered_map<string, int> scores;

    scores["Alice"] = 79;
    scores["Bob"] = 69;
    scores["Charlie"] = 82;

    cout << "Alice: " << scores["Alice"] << endl;

    if (scores.find("Bob") != scores.end()) {
        cout << "Bob is in the map\n";
    }

    for ( auto& pair: scores ) {
        cout << pair.first << " => " << pair.second << endl;
    }
}