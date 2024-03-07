#include <iostream>


void print_arr(int* arr, int size);
void quick_sort(int* arr, int size);
int pivoting(int* arr, int pivot,int size);
int main() {
    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    quick_sort(arr1, size1);
    quick_sort(arr2, size2);
    quick_sort(arr3, size3);
    
    std::cout << "Sorted arr1: ";
    print_arr(arr1, size1);
    std::cout << std::endl;
    
    std::cout << "Sorted arr2: ";
    print_arr(arr2, size2);
    std::cout << std::endl;
    
    std::cout << "Sorted arr3: ";
    print_arr(arr3, size3);
    std::cout << std::endl;
    
    return 0;
}

void quick_sort(int* arr, int size){
    if(size == 1){
        return;
    }
    int pi = size/2;
    int boarder = pivoting(arr, pi,size);
    quick_sort(arr, boarder);
    quick_sort(&arr[boarder], size - boarder );
};

int pivoting(int* arr,int pi,int size){
    int left = 0;
    int right = size - 1;
    int pivot = arr[pi];
    while(1){
        while (arr[left] < pivot){
            left++;
        }
        while (arr[right] > pivot){
            right--;
        }
        if(left >= right){
            return left;
        }
        int b = arr[left];
        arr[left] = arr[right];
        arr[right] = b;
        left++;
        right--;
    }
};

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
}