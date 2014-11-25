#include <iostream>
#include <cstdio>
using namespace std;

char file(char str[64])// Функция для считывания строки из файла
{
	setlocale(LC_ALL, ".1251");                //Делаем допустимым вывод кириллицы в консоль.
	FILE *in = fopen("in.txt", "r"); //файл находится в папке с проектом.
	//  параметр "r", то есть reed - позволит нам только считать информацию.
	if (in == NULL)                                   //если in(файл) равен NULL,значит он не может открыться.Либо путь не тот.
	{
		cout << "Ошибка в открытии файла in.txt" << endl;
	}
	else
	{
		str[64];       //создаём строку(string) размером 64.
		fgets(str, 64, in);   //записываем в str первую строку.
		while (!feof(in))    //пока не конец файла in ,мы исполняем цикл.
		{
			cout << str;        //выводим на экран первую строку.
			fgets(str, 64, in); //записываем вторую.
		}
		_fcloseall();         //закрываем все открытые (в нашем случае один) файлы.
	}return *str;
}

void sdvig(char a[64], int i)//функция для того чтобы вместо убранной запятой не было пустого места
{
	for (i; a[i + 1] != '\0'; i++)
	    a[i] = a[i + 1];
	std::cout << a << std::endl;
		return;
}

void PutIn(char a[64], int i, int length)//функция для вставки запятой в строку
{
	for (int j = length + 1; j > i; j--)
		a[j] = a[j - 1];
	a[i] = ',';
    std::cout << a << std::endl;
	return;
}

int main(void){
	int i=0,choice=0, length=0;
	char a[64] = "";
	file(a);   //std::cin >> a;
	for (i = 0; a[i] != '\0'; i++); length = i;
	for (i = length; i > 0; i--){
		if ((a[i] == ',') && (a[i + 2] == 'a') && (a[i + 3] == 'n') && (a[i + 4] == 'd') && (a[i + 5] == ' ')){
				std::cout << "Вы хотите убрать оксфордскую запятую? 1/0" << std::endl;
				std::cin >> choice;
				if (choice == 1){
					sdvig(a, i);
					system("pause");
					return(0);
					
				}
				else
					std::cout << a << std::endl;
				system("pause");
				return(0);
			}
		if ((a[i] == ' ') && (a[i + 1] == 'a') && (a[i + 2] == 'n') && (a[i + 3] == 'd') && (a[i + 4] == ' ') && (a[i - 1] != ',')){
			std::cout << "Вы хотите поставить оксфордскую запятую? 1/0" << std::endl;
			std::cin >> choice;
			if (choice == 1){
				PutIn(a, i, length);
				system("pause");
				return(0);
			}
			else
				std::cout << a << std::endl;
			system("pause");
			return(0);
		}
	}
	system("pause"); 
	return(-1);
}
