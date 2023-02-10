import random

def main():
    integers = [random.randint(0, 100) for i in range(20)]
    print("Benchmark Array:", *integers)

    targetIndex = random.randint(0, len(integers))
    targetValue = integers[targetIndex]
    
    sequentialComparisons = sequentialSearch(integers, targetValue)
    binaryComparisons = binarySearch(integers, targetValue)
    
    print("Target Value:", targetValue)
    print("Sequential Search Algorithm Comparisons:", sequentialComparisons)
    print("Binary Search Algorithm Comparisons:", binaryComparisons)

def sequentialSearch(integers, targetValue):
    comparisons = -1
    for i in integers:
        comparisons += 1
        if i == targetValue:
            return comparisons
    return comparisons

def binarySearch(integers, targetValue):
    comparisons = -1
    first = 0 
    last = len(integers) - 1
    found = False
    while not found and first <= last:
        middle = (first + last) // 2
        comparisons += 1
        if integers[middle] == targetValue:
            found = True
            comparisons = middle
        elif integers[middle] > targetValue:
            last = middle - 1
        else: first = middle + 1
    return comparisons

main()