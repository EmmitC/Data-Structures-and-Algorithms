#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> friendsStack;
    int choice;
    string name;

    do {
        cout << "1. Push a friend's name into the stack\n";
        cout << "2. Display stack contents\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter friend's name: ";
                getline(cin, name);
                friendsStack.push(name);
                cout << name << " has been added to the stack.\n";
                break;

            case 2:
                if (friendsStack.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack contents (top to bottom):\n";
                    stack<string> tempStack = friendsStack;
                    while (!tempStack.empty()) {
                        cout << tempStack.top() << endl;
                        tempStack.pop();
                    }
                }
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}