//
// Created by small on 2025/6/9.
//
#include <iostream>
using namespace std;

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;

                PrintArray(arr, size);
            }
        }
    }
}

int partition(int arr[], int left, int right) {
    int base = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= base)
            right--;

        arr[left] = arr[right];

        while (left < right && arr[left] <= base)
            left++;

        arr[right] = arr[left];
    }
    arr[left] = base;
    return left;
}

void QuickSort(int arr[], int size, int left, int right) {
    if (left < right) {
        int pos = partition(arr, left, right);

        PrintArray(arr, size);

        QuickSort(arr, size, left, pos - 1);
        QuickSort(arr, size, pos + 1, right);
    }
}

void Func() {
    int arr1[] = {7, 2, 6, 3, 8, 4, 5};
    int size = std::size(arr1);

    cout << "BubbleSort:" << endl;
    BubbleSort(arr1, size);

    int arr2[] = {7, 2, 6, 3, 8, 4, 5};
    cout << "QuickSort:" << endl;
    QuickSort(arr2, size, 0, size - 1);
}
