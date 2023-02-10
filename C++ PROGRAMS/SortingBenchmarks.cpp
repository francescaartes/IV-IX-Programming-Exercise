#include <iostream>
#include <ctime>
using namespace std;

void swap(int &a, int &b);
int bubbleSort(int *bubbleArray);
int selectionSort(int *selectionArray);
int insertionSort(int *insertionArray);

int main() {
    srand(time(0));
    int SIZE = 20;
    int bubbleArray[SIZE], selectionArray[SIZE], insertionArray[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        bubbleArray[i] = rand() % 100;
        selectionArray[i] = bubbleArray[i];
        insertionArray[i] = bubbleArray[i];
    }
    cout << "Benchmark Array: ";
    for (int i = 0; i < 20; i++)
        cout << bubbleArray[i] << " ";
    cout << endl;
    
    int bubbleSwaps = bubbleSort(bubbleArray);
    cout << "Bubble Sort swap count: " << bubbleSwaps << endl;
    
    int selectionSwaps = selectionSort(selectionArray);
    cout << "Selection Sort swap count: " << selectionSwaps << endl;
    
    int insertionSwaps = insertionSort(insertionArray);
    cout << "Insertion Sort swap count: " << insertionSwaps << endl;
    
    return 0;
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int bubbleSort(int *bubbleArray) {
    int swapCount = 0;
    int maxElement, index, temp;
    for (maxElement = 20-1; maxElement >= 0; maxElement--) {
        for (index = 0; index <= maxElement -1; index++) {
            if (bubbleArray[index] > bubbleArray[index +1]) {
                temp = bubbleArray[index];
                bubbleArray[index] = bubbleArray[index +1];
                bubbleArray[index +1] = temp;
                swapCount++;
            }
        }
    }
    return swapCount;
}
int selectionSort(int *selectionArray) {
    int swapCount = 0;
    int startScan, index, minIndex, minValue;
    for (startScan = 0; startScan < (20-1); startScan++) {
        minIndex = startScan;
        minValue = selectionArray[startScan];
        for (index = startScan+1; index < 20; index++) {
            if (selectionArray[index] < minValue) {
                minValue = selectionArray[index];
                minIndex = index;
            }
        }
        if (minIndex != startScan) {
            swap(selectionArray[minIndex], selectionArray[startScan]);
            swapCount++;
        }
    }
    return swapCount;
}
int insertionSort(int *insertionArray) {
    int swapCount = 0;
    int unsortedValue, scan;
    for (int index = 1; index < 20; index++) {
        unsortedValue = insertionArray[index];
        scan = index;
        while (scan > 0 && insertionArray[scan-1] > unsortedValue) {
            insertionArray[scan] = insertionArray[scan-1];
            scan--;
            swapCount++;
        }
        insertionArray[scan] = unsortedValue;
    }
    return swapCount;
}