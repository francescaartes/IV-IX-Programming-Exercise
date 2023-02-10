import random

def main():    
    integers = [random.randint(0, 100) for i in range(20)]
    print("Benchmark Array:", *integers)

    bubbleArray = list(integers)
    bubbleSwap = bubbleSort(bubbleArray)
    selectionArray = list(integers)
    selectionSwap = selectionSort(selectionArray)
    insertionArray = list(integers)
    insertionSwap = insertionSort(insertionArray)

    print("Bubble Sort swap count: " + str(bubbleSwap))
    print("Selection Sort swap count: " + str(selectionSwap))
    print("Insertion Sort swap count: " + str(insertionSwap))

def bubbleSort(bubbleArray):
    swapCount = 0
    maxElement = len(bubbleArray)-1
    while maxElement >= 0:
        index = 0
        while index <= maxElement-1:
            if bubbleArray[index] > bubbleArray[index+1]:
                temp = bubbleArray[index]
                bubbleArray[index] = bubbleArray[index+1]
                bubbleArray[index+1] = temp
                swapCount += 1
            index += 1
        maxElement -= 1
    return swapCount

def selectionSort(selectionArray):
    swapCount = 0
    startScan = 0
    while startScan < len(selectionArray) - 1:
        minIndex = startScan
        minValue = selectionArray[startScan]
        index = startScan + 1
        while index < len(selectionArray):
            if selectionArray[index] < minValue:
                minValue = selectionArray[index]
                minIndex = index
            index += 1
        if minIndex != startScan:
            selectionArray[minIndex] = selectionArray[startScan]
            selectionArray[startScan] = minValue
            swapCount += 1
        startScan += 1
    return swapCount

def insertionSort(insertionArray):
    swapCount = 0
    index = 1
    while index < len(insertionArray):
        unsortedValue = insertionArray[index]
        scan = index
        while scan > 0 and insertionArray[scan-1] > unsortedValue:
            insertionArray[scan] = insertionArray[scan-1]
            scan -= 1
            swapCount += 1
        insertionArray[scan] = unsortedValue
        index += 1
    return swapCount
main()