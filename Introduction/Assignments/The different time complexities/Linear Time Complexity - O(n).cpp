#include <iostream>
using namespace std;

void findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    findElement(arr, 6, 7);
    return 0;
}
