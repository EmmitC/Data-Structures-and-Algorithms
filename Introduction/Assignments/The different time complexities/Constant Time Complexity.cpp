
#include <iostream>
using namespace std;

void accessElement(int arr[], int index) {
    cout << "Element at index " << index << ": " << arr[index] << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    accessElement(arr, 2); // Always takes the same time
    return 0;
}





























