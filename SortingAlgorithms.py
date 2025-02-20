array1 = [9,2,4,6,8,7,5,25,36,90,45]

# selection sort method for Python
def selectionSort(array):
    for i in range(len(array)):
        for j in range(len(array)):
            temp = i
            if array[i] < array[j]:
                temp = j
                array[i] = array[j]
                array[j] = temp
    return array

#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
# insertionSort method for Python
def insertionSort1(array):
    for i in range(1, len(array)):
        temp = array[i]
        j = i - 1
        while j >= 0 and temp < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        
        array[j + 1] = temp

    return array

#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
def shellSort1(array):
    length = len(array)
    gap = length // 2
    while gap > 0:
        for i in range(gap, length):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= 2
    return array

#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#quicksort function in python
def quickSort(array, left, right):
    if left < right:
        partitionPOS = partition(array, left, right) # partitionPOS which is i returned
        print(partitionPOS, "part pos")
        quickSort(array, left, partitionPOS - 1) #dont forget recursion
        quickSort(array, partitionPOS + 1, right) # 2 calls for both sides of list
    return array
#partition function for the quicksort function
def partition(array, left, right):
    i = left
    j = right - 1
    pivot = array[right]

    while i < j:
        while i < right and array[i] < pivot:
            i += 1
        while j > left and array[j] >= pivot:
            j -= 1
        if i < j:
            array[i], array[j] = array[j], array[i]
    if array[i] > pivot:
        array[i], array[right] = array[right], array[i]
    return i

#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#mergeSort function in python

def mergeSort(array):
    if len(array) > 1:
        left_array = array[:len(array)//2]
        right_array = array[len(array)//2:]

        #recursion Aspect
        mergeSort(left_array)
        mergeSort(right_array)

        #merge
        i = 0 # left_array index
        j = 0 # right_array index
        k = 0 # merged array index

        while i < len(left_array) and j < len(right_array):
            if left_array[i] < right_array[j]:
                array[k] = left_array[i]
                i += 1
            else:
                array[k] = right_array[j]
                j += 1
            k += 1

        while i < len(left_array):
            array[k] = left_array[i]
            i += 1
            k += 1

        while j < len(right_array):
            array[k] = right_array[j]
            j += 1
            k += 1
    return array
print(mergeSort(array1))
