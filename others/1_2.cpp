//для двух строк напишите, является ли одна строка перестановкой другой

//1) Решение в лоб - отсортировать строки и сравнить их
#include <iostream>
#include <map>
using namespace std;

bool isPodStr(std::string str1, std::string str2){
	if(str1.length() != str2.length()){
		return false;
	}
	for(int i = 0; i < str1.length(); i++){
		for(int j = 1; j < str2.length(); j++){
			if(str1[i] < str1[j]){
				char temp = str1[i];
				str1[i]= str1[j];
				str1[j] = temp;
			}
			if(str2[i] < str2[j]){
				char temp = str2[i];
				str2[i]= str2[j];
				str2[j] = temp;
			}
		}
	}
	if(str1 == str2){
		return true;
	}
	return false;
}


// второй вариант - использовать карту(map)

bool isPodStrMap(std::string str1, std::string str2){
	if(str1.length() != str2.length()){
		return false;
	}
	std::map < char, int > strMap;
	for(int i = 0; i < str1.length(); i++){
		strMap[str1[i]] = 0;
	}
	for(int i = 0; i < str1.length(); i++){
		strMap[str1[i]]++;
	}
	for(int i = 0; i < str1.length(); i++){
		strMap[str2[i]]--;
	}
	for(int i = 0; i < str1.length(); i++){
		if(strMap[str1[i]] != 0){
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	std::string str1;
	std::cout << "Введите строку 1: ";
	std::cin >> str1;
	std::string str2;
	std::cout << "Введите строку 2: ";
	std::cin >> str2;
	std::cout << isPodStrMap(str1, str2);
}