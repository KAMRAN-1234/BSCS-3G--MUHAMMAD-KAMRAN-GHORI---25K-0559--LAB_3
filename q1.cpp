#include <iostream>
using namespace std;

void adjacentSwapper(int arr[], int size) {
    int swapCount = 0;
    int comparisonCount = 0;
    int passCount = 0;

    for (int i = 0; i < size - 1; ++i) {
        bool changed = false;
        ++passCount;

        for (int j = 0; j < size - 1 - i; ++j) {
            ++comparisonCount;

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                ++swapCount;
                changed = true;
            }
        }

        if (!changed) break;
    }

    cout << "\nTotal swaps: " << swapCount << endl;
    cout << "Total comparisons: " << comparisonCount << endl;
    cout << "Passes used: " << passCount << endl;
    cout << "Passes saved: " << (size - 1 - passCount) << endl;
    cout << "Theoretical worst-case comparisons: " << size * (size - 1) / 2 << endl;
    cout << "Actual comparisons: " << comparisonCount << endl;
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

    adjacentSwapper(values, itemCount);

    cout << "\nSorted tracking numbers:\n";
    for (int index = 0; index < itemCount; ++index) {
        cout << values[index] << ' ';
    }

    cout << endl;
    delete[] values;
    return 0;
}