#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
int main(int argc, char *argv[]) {
	int logical_size = 0;
	int actual_size = 0;
	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> actual_size;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;
	int* arr = new int (actual_size);
	print_dynamic_array(arr,logical_size,actual_size);
	delete arr;
	return 0;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size){
	if(logical_size > actual_size){
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!";
		return;
	}
	for(int i = 0; i < logical_size; i++){
		std::cout << "Введите arr["<< i <<"]: ";
		std::cin >> arr[i];
	}
	std::cout << "Динамический массив: ";
	for(int i = 0; i < logical_size; i++){
		
		std::cout << arr[i]<<" ";
	}
	for(int i = logical_size; i < actual_size; i++){
		std::cout << "_"<<" ";
	}
};