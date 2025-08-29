#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


struct Book
{
    int id;
    string title;
    string author;
    int year;
};

static const char *DATA_FILE = "books.csv";

// Function: Save catalog to CSV
void save(const map<int, Book> &catalog)
{
    ofstream out(DATA_FILE, ios::trunc);

    if (!out) { 
        cerr << "Cannot write to file\n"; return ;
    } else {
        out << "id, title, author, year\n";
    }

    for (auto &[id, b]: catalog) {
        out << id << "," << b.title << "," << b.author << "," << b.year << endl;
    }
}

// Function: Load catalog from CSV
void load(map<int, Book> &catalog)
{
    catalog.clear();
    ifstream in(DATA_FILE);
    if (!in) return;
    string line;
    getline(in, line); // skip header

    while (getline(in, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        string idStr, title, author, yearStr;

        if (!getline(ss, idStr, ',')) continue;
        if (!getline(ss, title, ',')) continue;
        if ((!getline(ss, author, ','))) continue;
        if ((!getline(ss, yearStr))) continue;
        
        try {
            Book b;
            b.id = stoi(idStr);
            b.title = title;
            b.author = author;
            b.year = stoi(yearStr);
            catalog[b.id] = b;
        } catch (...) {}
    }
}

// Get next ID = max + 1
int nextId(const map<int, Book> &catalog)
{
    // If the catalog is empty, no books exist yet.
    // So the very first book gets ID = 1.
    if (catalog.empty()) return 1;
    // .rbegin() = “reverse begin” = iterator to the last element (largest key).
    // A map stores key–value pairs as std::pair<const Key, T>.
    // .first = the key (e.g., book ID).
    // .second = the value (the Book).
    return catalog.rbegin()->first+1; // last element’s key + 1
}

// List all books
void list(const map<int, Book> &catalog)
{
    if (catalog.empty()) { cout << "No books.\n"; return; }
    cout << left << setw(5) << "ID"
         << setw(25) << "Title"
         << setw(20) << "Author"
         << "Year\n";
    cout << "----------------------------------------------------------\n";

    for (auto &[id,b] : catalog) {
        cout << left << setw(5) << id
             << setw(25) << b.title
             << setw(20) << b.author
             << b.year << "\n";
    }
}

