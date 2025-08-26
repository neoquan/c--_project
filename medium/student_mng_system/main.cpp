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