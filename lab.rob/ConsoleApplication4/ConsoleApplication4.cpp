#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

extern void menu();
extern void show_menu();
extern wstring** enter_login();
extern char** enter_password();
extern wstring** smoky_time();

int startupAuthoriz(int argsC,
	char* argsV[])

{
	int passwordLength = 0;
	for (int argumentIndex = 1;
		argumentIndex < argsC;
		argumentIndex++)
	{
		const char* argK = argsV[argumentIndex];
		const char* argV = argsV[argumentIndex + 1];
		if (strcmp(argK, "-login") == 0)
		{
			cout << "Ваше настроение:\t" << argV << endl;
		}
		else
		{
			if (strcmp(argK, "-password*") == 0)
			{
				passwordLength = strlen(argV);
				break;
			}
		}
	}


	return passwordLength;
}
int main(int argsC,
	char* argsV[],
	char* environmentParameters[]
)
{

	setlocale(LC_ALL, "");



	if (argsC > 1)
	{
		return startupAuthoriz(argsC, argsV);
	}
	else
	{
		menu();
	}

	cin.get();
	return 0;
}

#ifndef INPUT_MAIN_SAMPLE_H
#define INPUT_MAIN_SAMPLE_H


void show_menu()
{

	wcout << L"Здравствуйтe:" << endl;
	wcout << L"1.) Как вашe настроениe?" << endl;
	wcout << L"2.) Как вы провели свой день?" << endl;
	wcout << L"3.) Спасибо за вниманиe" << endl;
	wcout << L"4. Завершить работу" << endl;

}
wstring** enter_login()
{
	wstring* login = new wstring();
	wcout << L"Как вашe настроениe( :) ):" << endl;
	wcin.ignore();
	getline(wcin, *login);

	return &login;

}
char** enter_password()
{
	const short int MAX_PASSWORD_LENGTH = 16;
	char* password = new char[MAX_PASSWORD_LENGTH];

	wcout << L"Опишите мне это, пожалуйста" << endl;
	cin >> password;
	return &password;
}


void menu()
{
	short int selectedMenuItem = 1;
	wstring login = L"";
	char* password = nullptr;
	show_menu();
	cin >> selectedMenuItem;
	switch (selectedMenuItem)
	{
	case 1:
		login = **enter_login();
		break;
	case 2:
		password = *enter_password();
		break;
	case 4:
		exit(0);

	}

	if (!login.empty())
	{
		wcout << L"Вашe настроение:\t" << login << endl;
	}
	


	if (password != nullptr)
	{


		wcout << L"Мне было приятно это увидеть, спасибо):\t"
			<< endl << password;
		delete[] password;
	}


	system("pause");

}
#endif
	
