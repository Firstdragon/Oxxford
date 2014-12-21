#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale.h>
using namespace std;

void obrabotka(string &str)
{
	int i = 0, choice = 0;
	i = str.rfind(", and ");
	if (i > 0)
	{
		cout << "Вы хотите убрать оксфордскую запятую в предложении " << str << "? 1/0" <<endl;
		cin >> choice;
		if (choice == 1)
		{
			str.erase(i, 1);
		}
	}
	else
	{
		i = str.rfind(" and ");
		if (i > 0)
		{
			cout << "Вы хотите добавить оксфордскую запятую в предложение " << str << "? 1/0" << endl;
			cin >> choice;
			if (choice == 1)
			{
				str.insert(i, ",");
			}
		}
	}
}

void filein(string &globalstr){
	string str;
	ifstream in("text.txt");
	if (in.is_open())
	{
		while (in.good())
		{
			getline(in, str, '.');
			obrabotka(str);
			globalstr.append(str);
			if (str.length() > 0) globalstr.append(".");
		}
	}
	in.close();
	return;
}

void fileout(string &globalstr){
	ofstream out("result.txt");
		if (out.is_open())
		{
			out << globalstr << endl;
		}
		out.close();
		return;
}


int main(void){
	setlocale(LC_ALL, "Russian");
	string globalstr;
	filein(globalstr);
	cout << globalstr << endl;
	fileout(globalstr);
	system("pause");
	return 0;
}
