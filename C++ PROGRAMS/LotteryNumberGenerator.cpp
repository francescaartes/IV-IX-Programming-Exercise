#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    
    int size = 7;
    int lotteryNumbers[size];
    for (int digit = 0; digit < size; digit++) {
        lotteryNumbers[digit] = rand() % 10;
    }
    cout << "Lottery Numbers: ";
    for (int digit = 0; digit < size; digit++) {
        cout << lotteryNumbers[digit] << " ";
    }
    cout << endl;
    
    return 0;
}