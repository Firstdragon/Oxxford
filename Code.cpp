#include <iostream>

int main(void){
	int i, length;
	char a[1000] = "", b[1] = "";
	std::cin >> a;
	for (i = 0; a[i] != '\0'; i++); length = i;
	for (i = length; i == 0; i--);
	if ((a[i] == ',') && (a[i + 2] == 'a') && (a[i + 3] == 'n') && (a[i + 4] == 'd') && (a[i + 5] == ' ')){
		std::cout << "Вы хотите убрать оксфордскую запятую? Y/N" << std::endl;
		std::cin >> b;
		if (b[0] == 'Y')
		for (i = i; a[i + 1] != '\0'; i++){
			a[i] = a[i + 1];
			std::cout << a << std::endl;
			system("pause");
			return(0);
		}
		else
			std::cout << a << std::endl;
		system("pause");
		return(0);
	}
}