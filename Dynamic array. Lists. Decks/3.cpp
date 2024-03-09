#include <iostream>

void print_dynamic_array(int* arr, int& logical_size, int& actual_size);
int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size);
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
	std::string flag;
	do {
		std::cout << "\nУдалить первый элемент? ";
		std::cin >> flag;
		if (flag == "нет") {
			std::cout << "Спасибо. ";
			printf(arr, logical_size, actual_size);
			break;
		}
		if (flag == "да") {
			arr = remove_dynamic_array_head( arr, logical_size, actual_size);
			if(arr == nullptr){
				break;
			}
			printf(arr, logical_size, actual_size);
		}
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

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size){
	if (logical_size <= 0) {
		std::cout << "Нечего удалять в массиве" ;
		return nullptr;
	}
	if(logical_size - 1 > (actual_size/3)){
		for (int i = 1; i < logical_size; i++) {
			arr[i - 1] = arr[i];
		}
		logical_size--;
		return arr;
	}else{
		int* mass = new int(actual_size/3);
		for (int i = 1; i < logical_size; i++) {
			mass[i - 1] = arr[i];
	    }	
		logical_size--;
		actual_size = logical_size;
		return mass;
    }
}