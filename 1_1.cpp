//Реализуйте алгоритм, который определяет все ли символы в строке встречаются один раз, нельзя использовать дополнительные структуры данных
// сначала нужно узнать по поводу кодировки, нельзя создать строку с неповт симолами, если ее длина больше количества символов

#include <iostream>
using namespace std;

//1)Решение в лоб

bool charOnceInSrtInForehead(){
	bool isOnce;
	std::string str;
	std::cin >> str;
	if(str.length() > 128){
		return false;
	}
	for(int i = 0; i < str.length(); i ++){
		for(int j = i + 1; j < str.length(); j ++){
			if(str[i] == str[j]){
				return false;
			}
		}
	}
	return true;
}

//2) Менее затратное по сложности решение для алфавита a - z
bool charOnceInSrtSmarter(){
	std::cout << "Введите количество символов в алфавите: ";
	int raz;
	std::cin >> raz;
	bool *isOne = new bool[raz];
	std::string str;
	std::cout << "Введите строку: ";
	std::cin >> str;
	for (int i = 0; i < raz; i++) {
		isOne[i] = false;
	}
	for (int i = 0; i < str.length(); i++) {
		int index = str[i] - 'a';
		if (isOne[index]) {
			delete[] isOne;
			return false;
		}
		isOne[index] = true;
	}
	delete[] isOne;
	return true;
}

int main(int argc, char *argv[]){
	std::cout <<charOnceInSrtSmarter();
	std::cout <<charOnceInSrtInForehead();
	return 0;
}