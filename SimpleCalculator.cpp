#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        int value1, value2, result;
        char operation;

        cout << "SIMPLE CALCULATOR!\n";
        cout << "Enter values one by one:";
        cin >> value1 >> value2;

        cout << "Enter The Arithmetic Operation You Want (+, -, /, *, %): ";
        cin >> operation;

        switch (operation) {
            case '+':
                result = value1 + value2;
                cout << "Sum: " << result;
                break;
            case '-':
                result = value1 - value2;
                cout << "Difference: " << result;
                break;
            case '/':
                if (value2 != 0) {
                    result = value1 / value2;
                    cout << "Quotient: " << result;
                } else {
                    cout << "Error: Division by zero.";
                }
                break;
            case '*':
                result = value1 * value2;
                cout << "Product: " << result;
                break;
            case '%':
                result = value1 % value2;
                cout << "Remainder: " << result;
                break;
            default:
                cout << "Error: Invalid Operation";
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
