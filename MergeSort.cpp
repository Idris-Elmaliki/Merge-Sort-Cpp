#include <iostream>

class MergeSort {
private: 
    static void merge(int arr[], const int& leftIndex, const int& midIndex, const int& rightIndex) {
    // these int primatives are here to give us the exact size of both sub-arrays!
        int leftArraySize = midIndex - leftIndex + 1; 
        int rightArraySize = rightIndex - midIndex; 

        int leftArray[leftArraySize]; 
        int rightArray[rightArraySize]; 

    // these for loops add the values of each side of the array into 2 sepertae sub-arrays
        for(int i = 0; i < leftArraySize; i++) {
            leftArray[i] = arr[leftIndex + i];
        }

        for(int j = 0; j < rightArraySize; j++) {
            rightArray[j] = arr[midIndex + j + 1]; 
        }

    // Now we need to add the subarrays back into the main array but sorted this time!
        int index = leftIndex;
        int i = 0, j = 0; 

        while(i < leftArraySize && j < rightArraySize) {
            if(leftArray[i] <= rightArray[j]) {
                arr[index] = leftArray[i]; 
                i++; 
            }
            else {
                arr[index] = rightArray[j]; 
                j++; 
            }
            index++;
        }

    // Just in case either the left or right array didn't fully get added in!
        while(i < leftArraySize) {
            arr[index] = leftArray[i]; 
            index++; 
            i++; 
        }

        while(j < rightArraySize) {
            arr[index] = rightArray[j]; 
            index++; 
            j++; 
        }
    }

    
public: 
    static void sort(int arr[], const int& leftIndex, const int& rightIndex) {     
        if(leftIndex >= rightIndex) {
            return; 
        }

        int midIndex =  leftIndex + ((rightIndex - leftIndex)/ 2); 

        sort(arr, leftIndex, midIndex);
        sort(arr, midIndex + 1, rightIndex); 

        merge(arr, leftIndex, midIndex, rightIndex); 
    }
}; 

int main(void) {
    int arr[8] = {8, 5, 99, 33, 71, 45, 11, 1};
    int size = sizeof(arr) / sizeof(arr[0]); 

    MergeSort::sort(arr, 0, size-1); 

    for(auto i : arr) {
        std::cout << i << ' ';
    }

    std::cin.get();
}
