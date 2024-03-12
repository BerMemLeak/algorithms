#include <iostream>

void print_pyramid(int* arr, int size);
int getLevel(int* arr, int n) ;
int main(int argc, char *argv[]) {
	int arr[] = {94, 67 ,18 ,44, 55, 12, 6, 42};
	int size = sizeof(arr)/sizeof(arr[0]);
	print_pyramid(arr, size);
	return 0;
}

void print_pyramid(int* arr, int size){
	std::cout<< "Исходный массив: ";
	for(int i = 0; i < size; i++){
		std::cout<< arr[i] <<" ";
	}
	std::cout<< "\nПирамида: \n";
	for (int i = 0, k = 0 , z = 0; i < size; i++) {
		if (i == 0) {
			std::cout << getLevel(arr, i) << " root " << arr[i]<< std::endl;
		}else if (i % 2 == 0) {
			std::cout << getLevel(arr, i) << " right(" << arr[(i-1)/2]<< ") "<< arr[i]<< std::endl;
		}else {
			std::cout << getLevel(arr, i) << " left(" << arr[(i-1)/2]<< ") "<< arr[i]<< std::endl;
		}
}
}
int getLevel(int* arr, int n) {
	int level = 0;
	int lastIndex = n - 1;
	int nodes = 0;
	
	while (lastIndex >= 0) {
		level++;
		nodes = pow(2, level);
		lastIndex -= nodes;
	}
	
	return level;
}
