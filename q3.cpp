#include <iostream>
using namespace std;

void diminishingDistanceScanner(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        int comparisonCount = 0;
        int swapCount = 0;

        for (int index = gap; index < size; ++index) {
            int current = index;
            while (current >= gap) {
                ++comparisonCount;
                if (arr[current - gap] > arr[current]) {
                    int temp = arr[current];
                    arr[current] = arr[current - gap];
                    arr[current - gap] = temp;
                    ++swapCount;
                    current -= gap;
                } else {
                    break;
                }
            }
        }

        double gapPercent = ((double)gap / size) * 100;
        cout << "\nGap size: " << gap << endl;
        cout << "Gap percentage: " << gapPercent << "%" << endl;
        cout << "Comparisons: " << comparisonCount << endl;
        cout << "Swaps: " << swapCount << endl;
    }
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

    diminishingDistanceScanner(values, itemCount);

    cout << "\nSorted tracking numbers: ";
    for (int index = 0; index < itemCount; ++index) {
        cout << values[index] << ' ';
    }
    cout << endl;

    delete[] values;
    return 0;
}