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



void list(const vector<Task>& tasks)
{
    
}