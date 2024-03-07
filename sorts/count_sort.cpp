#include <iostream>


void count_sort(int* arr, int size, int start = 10, int end = 24 );
void print_arr(int* arr, int size);
int main() {
	int arr1[] = {19,14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
	int arr2[] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
	int arr3[] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
	
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	
	count_sort(arr1, size1);
	count_sort(arr2, size2);
	count_sort(arr3, size3);
	
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
void count_sort(int* arr, int size, int start, int end){
	int countArrSize = end - start + 1;
	int mass[countArrSize];
	for(int i = 0;i < countArrSize;i++){
		mass[i] =0;
	}
	for(int i = 0; i < size; i++){
		mass[arr[i]-10]++;
	}
	for(int j = 0, k = 0, i = 0; i < size;){
		while(k < mass[j] ){
			arr[i] = j + 10;
			i++;
			k++;
		}
		j++;
		k = 0;
	}
}
void print_arr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
}