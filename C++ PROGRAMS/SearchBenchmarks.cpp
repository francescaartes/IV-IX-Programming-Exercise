#include <iostream>
#include <ctime>
using namespace std;

int sequentialSearch(int *integers, int targetValue);
int binarySearch(int *integers, int targetValue);

int main() {
    srand(time(0));

    int integers[20];
    for (int i = 0; i < 20; i++) integers[i] = rand() % 100;
    cout << "Benchmark Array: ";
    for (int i = 0; i < 20; i++) cout << integers[i] << " ";
    
    int targetIndex = rand() % 20;
    int targetValue = integers[targetIndex];
    
    int sequentialComparisons = sequentialSearch(integers, targetValue);
    int binaryComparisons = binarySearch(integers, targetValue);
    
    cout << " " << '\n';
    cout << "Target Value: " << targetValue << '\n';
    cout << "Sequential Search Algorithm Comparisons: " << sequentialComparisons << '\n';
    cout << "Binary Search Algorithm Comparisons: " << binaryComparisons << endl;

    return 0;
}
int sequentialSearch(int *integers, int targetValue) {
    int comparisons = -1;
    for (int i = 0; i < 20; i++) {
        comparisons++;
        if (integers[i] == targetValue) return comparisons;
    }
    return comparisons;
}
int binarySearch(int *integers, int targetValue) {
    int comparisons = -1;
    int first = 0;
    int last = 20 - 1;
    bool found = false;
    while (!found && first <= last) {
        int middle = (first + last) / 2;
        comparisons++;
        if (integers[middle] == targetValue) {
            found = true;
            comparisons = middle;}
        else if (integers[middle] > targetValue) last = middle - 1;
        else first = middle + 1;
    }
    return comparisons;
}