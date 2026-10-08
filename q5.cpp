#include <iostream>
using namespace std;

int midpointSplitSearch(int arr[], int size, int targetID) {
    for (int index = 0; index < size - 1; ++index) {
        if (arr[index] > arr[index + 1]) {
            cout << "Error: Conveyor is unsorted. Search aborted." << endl;
            return -1;
        }
    }

    int maxDepth = 0;
    int remaining = size;
    while (remaining > 1) {
        remaining /= 2;
        ++maxDepth;
    }
    ++maxDepth;

    int low = 0;
    int high = size - 1;
    int stepCount = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        ++stepCount;

        double remainingSpace = ((double)(high - low + 1) / size) * 100;
        cout << "\nStep " << stepCount << ":" << endl;
        cout << "Low: " << low << endl;
        cout << "Mid: " << mid << endl;
        cout << "High: " << high << endl;
        cout << "Remaining search space: " << remainingSpace << "%" << endl;
        cout << "Steps: " << stepCount << " / " << maxDepth << endl;

        if (arr[mid] == targetID) {
            return mid;
        } else if (targetID < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int itemCount;
    cout << "Enter number of items: ";
    cin >> itemCount;

    int* values = new int[itemCount];
    cout << "Enter tracking IDs: ";
    for (int index = 0; index < itemCount; ++index) {
        cin >> values[index];
    }

    int targetID;
    cout << "Enter tracking ID to search: ";
    cin >> targetID;

    int result = midpointSplitSearch(values, itemCount, targetID);
    if (result != -1) {
        cout << "\nTarget found at index: " << result << endl;
    } else {
        cout << "\nTarget not found." << endl;
    }

    delete[] values;
    return 0;
}