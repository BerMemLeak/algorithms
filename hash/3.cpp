#include <iostream>


int find_substring_light_rabin_karp(std::string fullStr, std::string findStr);
int real_string_hash(std::string word, int firstIndex, int lastIndex);

int main(int argc, char *argv[]) {
	std::string fullStr;
	std::string findStr;
	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> fullStr;
	
	do {
		std::cout <<"\nВведите подстроку, которую нужно найти: ";
		std::cin >> findStr;
		int res = find_substring_light_rabin_karp(fullStr, findStr);
		if (res == -1) {
			std::cout << "Подстрока "<<findStr<<" не найдена\n";
		}else {
			std::cout << "Подстрока "<< findStr <<" найдена по индексу "<< find_substring_light_rabin_karp(fullStr, findStr);
		}
	} while (findStr != "exit");
		
		
}
//тут нужно посчитать хэш нашей подстроки, после чего берем первые элементы по размеру подстроки в соновной строке и проверяем значение хэша, если они равны, то все ок, если нет, то прибавляем к индексу единицу и смотрим в основной строке дальше, по итогу у будет сложность линейная, профит))
int find_substring_light_rabin_karp(std::string fullStr, std::string findStr){
	int index = -1;
	int findstrHash = real_string_hash(findStr,0,findStr.size());
	for (int i = 0; i < fullStr.size(); i++) {
		if (findstrHash == real_string_hash(fullStr,i,i + findStr.size() )) {
			index = i;
			bool flag = true;
			for (int j = index,k = 0; j < index + findStr.size(); j++, k++) {
				if(findStr[k] != fullStr[j]){
					flag = false;
				}
			}
			if (flag == false) {
				continue;
			}
			break;
		}
	}

	return index;
};

int real_string_hash(std::string word, int firstIndex , int lastIndex ){
	int p = 29;
	int n = 1000;
	int res = 0;
	for(int i = firstIndex; i < lastIndex ;i++){
		res += int(word[i])* pow(p,i- firstIndex);
	}
	return res % n;
}




//Задача 3. Упрощённый алгоритм Рабина-Карпа
//
//В этом задании вам нужно реализовать функцию, которая находит в предоставленной строке заданную подстроку с помощью упрощённого алгоритма Рабина-Карпа. Назовём её find_substring_light_rabin_karp.
//
//Функция должна принимать на вход две строки: в одной вы будете искать подстроку, а вторая будет этой подстрокой. Функция должна возвращать индекс найденной подстроки в строке. Если подстрока не была найдена, то возвращается -1.
//
//После написания функции её необходимо протестировать. Для этого организуйте работу с пользователем. Попросите его ввести строку. В этой строке вы будете искать подстроки. Дальше попросите пользователя ввести подстроку, которую надо найти в введённой ранее строке. Программа должна вывести на консоль индекс найденной подстроки, а если подстрока не была найдена, то программа должна сообщить об этом пользователю. Продолжайте спрашивать у пользователя подстроку до тех пор, пока он не введёт exit. После того, как он ввёл exit, попытайтесь найти подстроку exit, сообщите пользователю о результате и завершите работу программы.
//
//Пример работы программы
//
//Введите строку, в которой будет осуществляться поиск: hellohellomydearfriend
//Введите подстроку, которую нужно найти: hello
//Подстрока hello найдена по индексу 0
//Введите подстроку, которую нужно найти: lomy
//Подстрока lomy найдена по индексу 8
//Введите подстроку, которую нужно найти: year
//Подстрока year не найдена
//Введите подстроку, которую нужно найти: exit
//Подстрока exit не найдена