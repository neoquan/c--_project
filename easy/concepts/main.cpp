#include<iostream>

using namespace std;

int main()
{
    int arr[3] = {10,20,30};

    cout << "arr (address of 1st element): " << arr << endl;
    cout << "&arr[0] (the same as above): " << &arr[0] << endl;
    cout << "arr[0] (value): " << arr[0] << endl;
    cout << "*arr[0]: " << *arr << endl;
    cout << "*arr[1]: " << *(arr + 1) << endl;

    if (arr == &arr[0]) cout << "arr is the same as &arr[0]\n";
    else {
        cout << "Wrong";
    }

    if (arr[1] == *(arr+1)) cout << "arr[1] is the same as *arr[1]\n";
    else {
        cout << "Wrong";
    }


}