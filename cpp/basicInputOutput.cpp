#include <iostream>

using namespace std;

int main (void) {
    int i{5};
    cout << "Value of i: " << i << endl;
    cout << "Enter a new value for i:" << endl;
    cin >> i;
    cout << "The value entered is: " << i << endl;

    return (0);
}
