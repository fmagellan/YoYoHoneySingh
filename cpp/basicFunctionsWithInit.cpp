#include <iostream>

using namespace std;

int getInputValue() {
    int input;
    cout << "Enter an integer value: " ;
    cin >> input;

    return (input);
}

int main () {
    int a{getInputValue()};
    int b{getInputValue()};

    cout << "a + b = " << a + b << endl;

    return (0);
}
