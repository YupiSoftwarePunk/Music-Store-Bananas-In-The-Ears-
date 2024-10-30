#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

#if defined(max)
#undef max
#endif

/*
	магазин
	система продажи
	склад/динамический
	скидки
	пользователи
	нейминг
	чек
	управляемый склад
*/


// Учетные записи --------------------------------------------------------------------------
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "Admin", "User" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//------------------------------------------------------------------------------------------



// Склад товаров (База данных товаров) -----------------------------------------------------
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
//-------------------------------------------------------------------------------------------




// Функции-----------------------------------------------------------------------------------
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();

void main()
{
	Start();
}



void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\tБананы в ушах\n\n\n";
	if (Login() == true)
	{
		/*std::cin.ignore(std::numeric_limits<std::streamsize>::max());*/
		if (isAdmin == true)
		{
			ShopAdminMenu();
		}
		else
		{
			ShopUserMenu();
		}
	}
}


bool Login()
{
	while (true)
	{
		std::string login, passw;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, passw, '\n');

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && passw == passwordArr[i])
			{
				std::cout << "Добро пожаловать! " << loginArr[i] << "\n";
				isAdmin = false;
				return true;
			}
		}

		if (login == loginArr[0] && passw == passwordArr[0])
		{
			std::cout << "Добро пожаловать! " << loginArr[0] << "\n";
			isAdmin = true;
			return true;
		}


		system("cls");
		std::cout << "Неверно введен логин или пароль!!" << "\n\n";
	}
}


void ShopAdminMenu()
{
	std::string choose;
	do
	{
		std::cout << "1. Начать продажу\n";
		std::cout << "2. Показать склад\n";
		std::cout << "3. Пополнить склад\n";
		std::cout << "4. Списать со склада\n";
		std::cout << "5. Изменить цену\n";
		std::cout << "6. Изменить склад\n";
		std::cout << "7. Изменить персонал\n";
		std::cout << "8. Отчет о прибыли\n";
		std::cout << "0. Закрыть смену\n";

		std::cout << "Ввод: ";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);

	if (choose == "1")
	{

	}
	else if (choose == "2")
	{

	}
	else if (choose == "3")
	{

	}
	else if (choose == "4")
	{

	}
	else if (choose == "5")
	{

	}
	else if (choose == "6")
	{
		
	}
	else if (choose == "7")
	{

	}
	else if (choose == "8")
	{

	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cout << "Admin menu ERROR!!\n";
	}
}


void ShopUserMenu()
{
	std::string choose;
	do
	{
		std::cout << "1. Начать продажу\n";
		std::cout << "2. Показать склад\n";
		std::cout << "3. Пополнить склад\n";
		std::cout << "4. Списать со склада\n";
		std::cout << "5. Отчет о прибыли\n";
		std::cout << "6. Закрыть смену\n";

		std::cout << "Ввод: ";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 54);

	if (choose == "1")
	{

	}
	else if (choose == "2")
	{

	}
	else if (choose == "3")
	{

	}
	else if (choose == "4")
	{

	}
	else if (choose == "5")
	{

	}
	else if (choose == "6")
	{

	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cout << "User menu ERROR!!\n";
	}
}