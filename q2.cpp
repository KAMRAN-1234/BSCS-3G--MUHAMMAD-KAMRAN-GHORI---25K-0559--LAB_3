#include <iostream>
using namespace std;

void insertionArmSorter(int arr[], int size) {
    int totalShiftDistance = 0;

    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        int shiftCount = 0;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++shiftCount;
        }

        arr[j + 1] = key;
        cout << "\nKey: " << key << endl;

        if (shiftCount == 0) {
            cout << "No shift required" << endl;
        } else {
            cout << "Positions shifted: " << shiftCount << endl;
        }

        totalShiftDistance += shiftCount;
        cout << "Array: ";
        for (int index = 0; index < size; ++index) {
            cout << arr[index] << ' ';
        }
        cout << endl;
    }

    cout << "\nTotal shift distance: " << totalShiftDistance << endl;
}

int main() {
    int itemCount;
    cout << "Enter number of items: ";
    cin >> itemCount;

    int* values = new int[itemCount];
    cout << "Enter tracking numbers:\n";
    for (int index = 0; index < itemCount; ++index) {
        cin >> values[index];
    }

    insertionArmSorter(values, itemCount);

    cout << "\nFinal sorted array: ";
    for (int index = 0; index < itemCount; ++index) {
        cout << values[index] << ' ';
    }
    cout << endl;

    delete[] values;
    return 0;
}