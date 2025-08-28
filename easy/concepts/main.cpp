#include<iostream>

using namespace std;

int main()
{
    // int arr[3] = {10,20,30};

    // cout << "arr (address of 1st element): " << arr << endl;
    // cout << "&arr[0] (the same as above): " << &arr[0] << endl;
    // cout << "arr[0] (value): " << arr[0] << endl;
    // cout << "*arr[0]: " << *arr << endl;
    // cout << "*arr[1]: " << *(arr + 1) << endl;

    // if (arr == &arr[0]) cout << "arr is the same as &arr[0]\n";
    // else {
    //     cout << "Wrong";
    // }

    // if (arr[1] == *(arr+1)) cout << "arr[1] is the same as *arr[1]\n";
    // else {
    //     cout << "Wrong";
    // }

    char megaman = 'M';
    char *character = &megaman;

    cout << "*character (value) = " << *character << endl;
    cout << "character (addr)  = " << static_cast<void*>(character) << endl;

    char megamanarray[] = "MegaMan";
    char *charray = megamanarray; // same as &megaman[0]

    cout << "*charray (first char) = " << *charray << endl;
    cout << "charray (string)     = " << charray << endl;
    cout << "charray (addr)       = " << static_cast<void*>(charray) << endl;
}