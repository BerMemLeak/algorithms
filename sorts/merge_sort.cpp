#include <iostream>

void merge_sort(int* arr, int size);
int* merge(int* arr1, int size1, int* arr2, int size2);
void print_arr(int* arr, int size);

int main() {
    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    merge_sort(arr1, size1);
    merge_sort(arr2, size2);
    merge_sort(arr3, size3);

    std::cout << "Sorted arr1: ";
    print_arr(arr1, size1);

    std::cout << "Sorted arr2: ";
    print_arr(arr2, size2);
    
    std::cout << "Sorted arr3: ";
    print_arr(arr3, size3);
    return 0;
}

void merge_sort(int* arr, int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    int* left_half = arr;
    int left_size = mid;
    int* right_half = arr + mid;
    int right_size = size - mid;
    merge_sort(left_half, left_size);
    merge_sort(right_half, right_size);
    int* merged = merge(left_half, left_size, right_half, right_size);
    for (int i = 0; i < size; ++i) {
        arr[i] = merged[i];
    }
    delete[] merged;
}

int* merge(int* arr1, int size1, int* arr2, int size2) {
    int* merged = new int[size1 + size2]; // Создание временного массива для слияния
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
    return merged;
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}
