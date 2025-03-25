#include <iostream>
using namespace std;

int main()
{
    // Example array
    int arr[] = {1, 2, 3, 4, 5};

    // Size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Traversing the array
    for (int i = 0; i < n; i++)
    {
        cout << "Element at index " << i << ": " << arr[i] << endl;
    }

    return 0;
}
