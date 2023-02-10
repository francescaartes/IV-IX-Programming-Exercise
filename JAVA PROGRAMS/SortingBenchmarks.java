import java.util.Random;

public class SortingBenchmarks {
    public static void main(String[] args) {
        Random randomNumbers = new Random();
        
        int[] integers = new int[20];
        for (int i = 0; i < 20; i++) integers[i] = randomNumbers.nextInt(100);
        System.out.print("Benchmark Array: ");
        for (int i = 0; i < 20; i++) System.out.print(integers[i] + " ");

        int[] bubbleArray = integers.clone();
        int bubbleSwap = bubbleSort(bubbleArray);
        int[] selectionArray = integers.clone();
        int selectionSwap = selectionSort(selectionArray);
        int[] insertionArray = integers.clone();
        int insertionSwap = insertionSort(insertionArray);

        System.out.println(" ");
        System.out.println("Bubble Sort swap count: " + bubbleSwap);
        System.out.println("Selection Sort swap count: " + selectionSwap);
        System.out.println("Insertion Sort swap count: " + insertionSwap);

    }
    public static int bubbleSort(int[] integers) {
        int swapCount = 0;
        int maxElement, index, temp;
        for (maxElement = integers.length -1; maxElement >= 0; maxElement--) {
            for (index = 0; index <= maxElement -1; index++) {
                if (integers[index] > integers[index +1]) {
                    temp = integers[index];
                    integers[index] = integers[index +1];
                    integers[index +1] = temp;
                    swapCount++;
                }
            }
        }
        return swapCount;
    }
    public static int selectionSort(int[] integers) {
        int swapCount = 0;
        int startScan, index, minIndex, minValue;
        for (startScan = 0; startScan < (integers.length -1); startScan++) {
            minIndex = startScan;
            minValue = integers[startScan];
            for (index = startScan +1; index < integers.length; index++) {
                if (integers[index] < minValue) {
                    minValue = integers[index];
                    minIndex = index;
                }
            }
            if (startScan != minIndex) {
                int temp = integers[startScan];
                integers[startScan] = integers[minIndex];
                integers[minIndex] = temp;
                swapCount++;
            }
        }
        return swapCount;
    }
    public static int insertionSort(int[] integers) {
        int swapCount = 0;
        int unsortedValue, scan;
        for (int index = 1; index < integers.length; index++) {
            unsortedValue = integers[index];
            scan = index;
            while (scan > 0 && integers[scan-1] > unsortedValue) {
                integers[scan] = integers[scan -1];
                scan--;
                swapCount++;
            }
        integers[scan] = unsortedValue;
        }
        return swapCount;
    }
}