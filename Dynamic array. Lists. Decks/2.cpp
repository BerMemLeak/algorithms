#include <iostream>

void print_dynamic_array(int* arr, int& logical_size, int& actual_size);
int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int num);
void printf(int* arr, int& logical_size, int& actual_size);

int main(int argc, char *argv[]) {
	int logical_size = 0;
	int actual_size = 0;
	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> actual_size;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;
	int* arr = new int (actual_size);
	print_dynamic_array(arr,logical_size,actual_size);
	printf(arr, logical_size, actual_size);
	int num = 0;
	do {
		std::cout << "\nВведите элемент для добавления: ";
		std::cin >> num;
		if (num == 0) {
			std::cout << "Спасибо. ";
			printf(arr, logical_size, actual_size);
			break;
		}
		arr = append_to_dynamic_array( arr, logical_size, actual_size, num);
		printf(arr, logical_size, actual_size);
	} while (1);
	
	delete arr;
	return 0;
}

void printf(int* arr, int& logical_size, int& actual_size){
	std::cout << "Динамический массив: ";
	for(int i = 0; i < logical_size; i++){
		std::cout << arr[i]<<" ";
	}
	for(int i = logical_size; i < actual_size; i++){
		std::cout << "_"<<" ";
	}
}

void print_dynamic_array(int* arr, int& logical_size, int& actual_size) {
	if (logical_size > actual_size) {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!";
		return;
	}
	for (int i = 0; i < logical_size; i++) {
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr[i];
	}
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int num){
	if(logical_size >= actual_size){
		actual_size  = actual_size*2;
		int* mass= new int(actual_size);
		for(int i = 0; i < logical_size; i++){
			mass[i] = arr[i];
		}
		mass[logical_size]= num;
		logical_size++;
		return mass;
	}else{
		arr[logical_size]= num;
		logical_size++;
		return arr;
	}
}