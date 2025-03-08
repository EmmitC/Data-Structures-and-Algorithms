#include <iostream>
using namespace std;

void traverseArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "";
        // processing the element
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    traverseArray(arr , size);
    return 0;
}