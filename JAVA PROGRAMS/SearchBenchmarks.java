import java.util.Random;

public class SearchBenchmarks {
    public static void main(String[] args) {
        Random randomNumbers = new Random();
        
        int[] integers = new int[20];
        for (int i = 0; i < 20; i++) integers[i] = randomNumbers.nextInt(100);
        System.out.print("Benchmark Array: ");
        for (int i = 0; i < 20; i++) System.out.print(integers[i] + " ");
        
        int targetIndex = randomNumbers.nextInt(integers.length);
        int targetValue = integers[targetIndex];
        
        int sequentialComparisons = sequentialSearch(integers, targetValue);
        int binaryComparisons = binarySearch(integers, targetValue);
        System.out.println("");
        System.out.println("Target Value: " + targetValue);
        System.out.println("Sequential Search Algorithm Comparisons: " + sequentialComparisons);
        System.out.println("Binary Search Algorithm Comparisons: " + binaryComparisons);
    }
    public static int sequentialSearch(int[] integers, int targetValue) {
        int comparisons = -1;
        for (int i = 0; i < integers.length; i++) {
            comparisons++;
            if (integers[i] == targetValue) return comparisons;
        }
        return comparisons;
    }
    public static int binarySearch(int[] integers, int targetValue) {
        int comparisons = -1;
        int first = 0;
        int last = integers.length - 1;
        boolean found = false;
        
        while (!found && first <= last) {
            int middle = (first + last) / 2;
            comparisons++;
            if (integers[middle] == targetValue) {
                found = true;
                comparisons = middle;
            } else if (integers[middle] < targetValue) {
                first = middle + 1;
            } else {
                last = middle - 1;
            }
        }
        return comparisons;
    }
}