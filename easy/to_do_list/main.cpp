#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm> // for max

using namespace std;

struct Task
{
    int id;
    bool done;
    string text;
};

// Tạo 1 biến constant DATA_FILE pointer vào text task.txt (char* DATA_FILE hay char *DATA_FILE đều giống nhau)
static const char* DATA_FILE = "task.txt"; 


// vector<Task> là 1 dynamic array của Task
// & là reference tới tasks trong memory => không cần copy lại, thường sử dụng chung với pointer.
// Loop từng reference Task t (const nghĩa là chỉ read, không có modify), mx sẽ là max giữa max và t.id
int nextId(const vector<Task>& tasks)
{
    int mx = 0;
    for (const Task& t : tasks)
        mx = max(mx, t.id);
    return mx + 1;
}

// nếu tìm thấy tab character (\t) thì thay bằng space.
// ở đây ta modify biến c nên không cần const char& c
// Why? Because tasks are stored in tab-separated format in the file. Tabs would break the format.
string sanitize(const string& s)
{
    string out = s;
    for (char& c : out)
        if (c == '\t') 
            c = ' ';
    return out;
}

// ofstream là output file stream, ios::trunc là mỗi lần mở file là truncate (xóa) nội dung file.
// Nếu !out (không có file) => file ko mở được
// loop qua t trong tasks; viết mỗi task thành 1 dòng => id done text => 1 0 Buy milk

void save(const vector<Task>& tasks)
{
    ofstream out(DATA_FILE, ios::trunc);
    if (!out)
    {
        cerr << "Warning: could not open " << DATA_FILE << " for writing.\n";
        return;
    }
    for (const Task& t : tasks)
        {
            out << t.id << '\t' << (t.done ? 1 : 0) << '\t' << sanitize(t.text) << '\n';
        }
}


// Clear the current task list.
// Open tasks.txt and reads line by line.

// getline là đọc toàn bộ line cho đến khi qua dòng mới (\n).
// istringstream là input string stream
// stoi là string to integer

// Split each line into id, done, and text.
// Build a Task and puts it in the vector.

void load(vector<Task>& tasks)
{
    tasks.clear();
    ifstream in(DATA_FILE);
    if (!in) return;
    string line;
    while (getline(in, line))
    {
        if (line.empty()) continue; 
        istringstream ss(line);
        string idStr, doneStr, text;

        // getline reads characters from the stream ss until a tab. 
        // If find id before the 1st tab, then store it in idStr.
        // If not find anything, continue to next line.
        if (!getline(ss, idStr, '\t')) continue; 
        if (!getline(ss, doneStr, '\t')) continue;
        if (!getline(ss, text)) text = "";
        Task t{};
        try 
        {
            t.id = stoi(idStr);
            t.done = (stoi(doneStr) != 0);
            t.text = text;
            tasks.push_back(t); // append t to tasks
        } catch (...)
        {
            // skip bad lines
        }

    }
}

// List ra toàn tasks trong vector
// Nếu empty thì return null
// Nếu có thì for loop in ra
void list(const vector<Task>& tasks)
{
    if (tasks.empty()) 
    {
        cout << "No tasks yets.\n";
        return;
    }

    cout << "ID Status Task\n";
    cout << "----------------------------------------\n";

    for (const Task& t : tasks) 
    {
        cout << t.id << "   "
             << (t.done ? "[x]  " : "[]   ")
             << t.text << '\n';
    }
}

// add t to tasks

void add(vector<Task>& tasks, const string& text)
{
    Task t{ nextId(tasks), false, text};
    tasks.push_back(t);
    cout << "Added tasks." << t.id << ".\n";
}


// nếu task id giống id thì đảo ngược bool của t.done lại
// true thành false và false thành true
bool toggle(vector<Task>& tasks, int id)
{
    for (Task& t: tasks) {
        if (t.id == id) {
            t.done = !t.done;
            cout << "Task #" << id << (t.done ? " marked done.\n" : " marked NOT done.\n");
            return true;
        }
    }
    return false;
}

// its job is to delete a task from the list based on id
// size_t is an unsigned integer type used for sizes/indices.
bool remove(vector<Task>& tasks, int id)
{
    // loop technique: start, end, jump_step of i
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == id) {
            // static_cast<long>(i) just converts i (a size_t) into a long so the addition works (compiler safety).
            // tasks.begin() + i = iterator pointing to element at index i.
            tasks.erase(tasks.begin() + static_cast<long>(i));
            cout << "Deleted task #" << id << ".\n";
            return true;
        }
    }
    return false;
}

//  const & = we don’t copy the string, just borrow it read-only.
// ✅ Summary of what readInt does:
// Print a prompt.
// Read a line of input.
// Try to convert it to an integer.
// If it works → return that number.
// If not → show an error and try again.
// If input ends unexpectedly → return -1.

int readInt(const string& prompt)
{
    while (true) 
    {
        cout << prompt;
        string s;
        // getline(cin, s) → reads a whole line of input from the user.
        // If it fails (for example, if the user hits Ctrl+D / end of input), then !getline(...) is true.
        // In that case we return -1 as a signal: “No number was read.”
        if (!getline(cin, s)) return -1;
        try {
            return stoi(s);
        } catch (...) {
            cout << "Please enter a valid number.\n";
        }
    }
}

bool edit(vector<Task>& tasks, int id, const string& newText)
{
    for (Task& t : tasks) {
        if (t.id == id) {
            t.text = sanitize(newText);
            cout << "Update Task: " << id << ".\n";
            return true;
        }
    }
    return false;
}


int main() 
{
    vector<Task> tasks;
    load(tasks);

    while (true) {
        cout << "\n=== To-Do List ===\n"
             << "1) List tasks\n"
             << "2) Add task\n"
             << "3) Toggle done/undone\n"
             << "4) Delete task\n"
             << "5) Save\n"
             << "6) Edit\n"
             << "0) Exit\n";
        cout << "Choose: ";

        string choice;
        if (!getline(cin, choice)) break;

        if (choice == "1") {
            list(tasks);
        } else if (choice == "2") {
            cout << "Task text: ";
            string text;
            getline(cin, text);
            if (text.empty()) {
                cout << "Task cannot be empty.\n";
            } else {
                add(tasks, text);
            }
        } else if (choice == "3") {
            int id = readInt("Enter task ID to toggle: ");
            if (id < 0) continue;
            if (!toggle(tasks, id)) cout << "No task with that ID.\n";
        } else if (choice == "4") {
            int id = readInt("Enter task ID to delete: ");
            if (id < 0) continue;
            if (!remove(tasks, id)) cout << "No task with that ID.\n";
        } else if (choice == "5") {
            save(tasks);
            cout << "Saved to " << DATA_FILE << ".\n";
        
        } else if (choice == "6") {
            int id = readInt("Enter task ID to edit: ");
            if (id < 0) continue;

            cout << "New text: ";
            string text;
            getline(cin, text);

            if (text.empty()) {
                cout << "Text cannot be empty.\n";
            } else if (!edit(tasks, id, text)) {
                cout << "No task with that ID.\n";
            }
        } else if (choice == "0") {
            save(tasks);
            cout << "Good bye!\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
}