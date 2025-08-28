#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Student
{
    int id;
    string name;
    double gpa;
};

// create a data_file named student.csv
static const char* DATA_FILE = "student.csv";

// Loop through every student to find highest id.
// nextId will return next id.
int nextId(const vector<Student> &v)
{
    int mx = 0;
    for (auto &s : v) {
        mx = max(mx, s.id);
    }
    return mx + 1;
}

// Function: save vector Student to file.
// Description: output file stream ofstream to DATA_FILE
// after truncating DATA_FILE
void save(const vector<Student> &v)
{
    ofstream out(DATA_FILE, ios::trunc);
    if (!out) {
        cerr << "Cannot open file for write.\n";
        return ;
    }

    out << "id, name, gpa\n"; // Write to file

    for (auto &s : v) {
        out << s.id << ', ' << s.name << ', ' << s.gpa << '\n';
    }
}

void load(vector<Student> &v ) {
    v.clear();
    ifstream in(DATA_FILE);
    if (!in) return;
    string line;
    getline(in, line); // Đọc từng dòng trong file in và store vào string line.
    while (getline(in, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        string idStr, name, gpaStr;
        if (!getline(ss, idStr, ',')) continue;
        if (!getline(ss, name, ',')) continue;
        if (!getline(ss, gpaStr)) continue;

        try {
            Student s;
            s.id = stoi(idStr);
            s.name = name;
            s.gpa = stoi(gpaStr);
            v.push_back(s);
        } catch (...) {}
    }
}

void list(const vector<Student> &v)
{
    if (v.empty()) {
        cout << "No students.\n";
    }

    cout << left << setw(6) << "ID"
        << setw(24) << "Name"
        << "GPA\n";

    cout << "-------------------------------------------\n";

    for (auto& s : v)
        cout << left << setw(6) << s.id
                  << setw(24) << s.name
                  << fixed << setprecision(2) << s.gpa << '\n';
}


// Returning a pointer lets the caller know whether a student was found:
// If found → return address of that Student inside the vector.
// If not found → return nullptr.
Student* findById(vector<Student> &v, int id)
{
    for (auto &s : v) {
        if (s.id == id) {
            return &s; // return pointer to the matching student
            
        }
    }
    return nullptr; // return null if no match found
}

int readInt(const char* prompt){
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) {
            return -1;
        }
        try {
            return stod(s);
        } catch (...) {
            cout << "Enter a number.\n";
        }
    }
}

double readDouble(const char* prompt) 
{
    cout << prompt;
    string s;
    if (!getline(cin, s)) {
        return 0.0;
    }
    try {
        return stod(s);
    } catch (...) {
        cout << "Enter a number.\n";
    }
}

int main()
{
    vector<Student> db;
    load(db);

    while (true) {
        cout << "\n=== Student Management ===\n"
            << "1) List\n"
            << "2) Add\n"
            << "3) Search by ID\n"
            << "4) Edit GPA\n"
            << "5) Delete\n"
            << "6) Save\n"
            << "0) Exit\n"
            << "Choose: ";

        string choice;
        if (!getline(cin, choice)) break; // If reading input fails (user closed stdin, pressed Ctrl+D on Linux), the program will break;

        if (choice == "1") {
            list(db);
        } else if (choice == "2") {
            Student s;
            s.id = nextId(db);
            cout << "Name: ";
            getline(cin, s.name);
            s.gpa = readDouble("GPA (0.0-4.0): ");
            db.push_back(s);
            cout << "Added student #" << s.id << ".\n";
        } else if (choice == "3") {
            int id = readInt("ID: "); if (id < 0) continue;
            if (auto *s = findById(db,id)) {
                // Uses s-> (arrow operator) to access fields of the Student object through the pointer.
                cout << "Found → ID=" << s->id 
                    << ", Name=" << s->name
                    << ", GPA=" << fixed << setprecision(2) << s->gpa << '\n';
            }
        } else if (choice == "4" ) {
            int id = readInt("ID: "); if (id < 0) continue;
            if (auto *s = findById(db,id)) {
                s->gpa = readDouble("New GPA: ");
                cout << "Updated.\n";
            }
        } else if (choice == "5") {
            int id = readInt("ID: "); if (id < 0) continue;
            // std::remove_if scans the vector db from begin() to end().
            // For each Student s, it calls the lambda:
            // Captures id from outside scope => [&].
            // Returns true if this student’s id matches the one the user entered.
            auto it = remove_if(
                db.begin(), 
                db.end(),
                [&] (const Student &s) { return s.id == id; }
            );
            if (it != db.end()) { 
                db.erase(it, db.end()); 
                cout << "Deleted.\n"; 
            }
            else cout << "Not found.\n";
        } else if (choice == "6") {
            save(db);
            cout << "Saved to " << DATA_FILE << ".\n";
        } else if (choice == "0") {
            save(db);
            cout << "Bye!\n";
            break;
        } else {
            cout <<"Invalid!\n";
        }
    }   

}