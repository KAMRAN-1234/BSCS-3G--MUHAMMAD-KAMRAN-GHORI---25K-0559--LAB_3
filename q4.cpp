#include <iostream>
using namespace std;

void minimalSwapCrane(int arr[], int size) {
    int swapCount = 0;
    int skippedCount = 0;
    int comparisonCount = size * (size - 1) / 2;

    for (int index = 0; index < size - 1; ++index) {
        int minIndex = index;
        for (int nextIndex = index + 1; nextIndex < size; ++nextIndex) {
            if (arr[nextIndex] < arr[minIndex]) {
                minIndex = nextIndex;
            }
        }

        if (minIndex == index) {
            ++skippedCount;
        } else {
            int temp = arr[index];
            arr[index] = arr[minIndex];
            arr[minIndex] = temp;
            ++swapCount;
        }
    }

    cout << "\nTotal actual swaps: " << swapCount << endl;
    cout << "Skipped swaps: " << skippedCount << endl;
    double ratio = ((double)swapCount / comparisonCount) * 100;
    cout << "Total comparisons: " << comparisonCount << endl;
    cout << "Swap-to-Comparison Ratio: " << ratio << "%" << endl;
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

    minimalSwapCrane(values, itemCount);

    cout << "\nSorted tracking numbers: ";
    for (int index = 0; index < itemCount; ++index) {
        cout << values[index] << ' ';
    }
    cout << endl;

    delete[] values;
    return 0;
}