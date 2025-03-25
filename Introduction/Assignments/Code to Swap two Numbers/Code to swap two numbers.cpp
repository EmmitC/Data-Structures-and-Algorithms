#include <iostream>
using namespace std;

int main()
{
    // Declare variables to store two numbers
    int num1, num2, temp;

    // Prompt the user for input
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Swapping the numbers using a temporary variable
    temp = num1;
    num1 = num2;
    num2 = temp;

    // Display the swapped numbers
    cout << "After swapping, the first number is: " << num1 << endl;
    cout << "After swapping, the second number is: " << num2 << endl;

    return 0;
}
