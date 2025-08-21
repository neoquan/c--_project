#include<iostream>

using namespace std;

int main ()
{
    double value1, value2;
    char operator_char;

    cout << "Please enter 1st number: ";
    cin >> value1;

    cout << "Please enter operator, such as (+, -, /, *): ";
    cin >> operator_char;

    cout << "Please enter 2nd number: ";
    cin >> value2;

    double result;

    switch (operator_char)
    {
        case '+':
            result = value1 + value2;
            break;

        case '-':
            result = value1 - value2;
            break;

        case '*':
            result = value1 * value2;
            break;
        
        case '/':
            if (value2 != 0 ) result = value1 / value2;
            else 
                {
                    cout << "Division by zero!" << endl;
                    return 1;
                }
            break;
    
        default:
            cout << "Invalid operator!" << endl;
            return 1;
    }

    cout << "Result from the calculation: " << result << endl;
    return 0;
}
