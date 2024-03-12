#include <iostream>

void print_pyramid(int* arr, int size);
int getLevel(int* arr, int n) ;
void move(int* arr, int size);
void ptrPlace(int* arr,int i);
int main(int argc, char *argv[]) {
	int arr[] = {94, 67 ,18 ,44, 55, 12, 6, 42};
	int size = sizeof(arr)/sizeof(arr[0]);
	print_pyramid(arr, size);
	move( arr, size);
	return 0;
}

void print_pyramid(int* arr, int size){
	std::cout<< "Исходный массив: ";
	for(int i = 0; i < size; i++){
		std::cout<< arr[i] <<" ";
	}
	std::cout<< "\nПирамида: \n";
	for (int i = 0, k = 0 , z = 0; i < size; i++) {
		ptrPlace(arr, i);
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
void ptrPlace(int* arr,int i){
	if (i == 0) {
		std::cout << getLevel(arr, i) << " root " << arr[i]<< std::endl;
	}else if (i % 2 == 0) {
		std::cout << getLevel(arr, i) << " right(" << arr[(i-1)/2]<< ") "<< arr[i]<< std::endl;
	}else {
		std::cout << getLevel(arr, i) << " left(" << arr[(i-1)/2]<< ") "<< arr[i]<< std::endl;
	}

};
void move(int* arr, int size){
	int locationIndex = 0;
	std::string input;
	do {
		std::cout <<"Вы находитесь здесь: ";
		ptrPlace(arr, locationIndex);
		std::cout << "Введите команду: ";
		std::cin >> input;
	try {
			if (input == "right") {
                if ((locationIndex * 2) + 2 >= size) {
                    throw std::out_of_range("Ошибка! Отсутствует правый потомок");
                }
				locationIndex = (locationIndex*2) + 2;
			}
			if (input == "left") {
                if ((locationIndex * 2) + 1 >= size) {
                    throw std::out_of_range("Ошибка! Отсутствует левый потомок");
                }
				locationIndex = (locationIndex*2) + 1;
			}
			if (input == "up") {
                if (locationIndex == 0) {
                    throw std::out_of_range("Ошибка! Отсутствует родитель");
                }
				locationIndex = (locationIndex-1)/2;
			}
			if (input == "exit") {
				return;
			}
			ptrPlace(arr, locationIndex);
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
	} while (1);
	
};