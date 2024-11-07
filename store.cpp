#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

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
int categorySize = 4;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
std::string* NameCategoryArr = new std::string[categorySize];
//-------------------------------------------------------------------------------------------




// Функции-----------------------------------------------------------------------------------
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
template <typename Any>
void FillStorage(Any staticArr, Any dynamicArr, int size);
void ShowCategoryStorage();
void ShowStorage();
void RefillStorage();
bool isStringDigit(std::string);
void RemoveFromStorage();
void CgangePrice();
void ChangeStaff();
void AddEmployee();
void StaffReduct();
void RemoveStaff();
void StorageReduct();
// -------------------------------------------------------------------------------------------

int main()
{
	Start();


	delete[]loginArr;
	delete[] passwordArr;
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]NameCategoryArr;

	return 0;
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
			std::string choose;
			do
			{
				std::cout << "1. Использовать готовый склад\n2. Создать новый склад\n";
				std::cout << "Ввод: ";
				std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				// динамический склад
			}
			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
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
	while (true)
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
			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowCategoryStorage();
			/*ShowStorage();*/
		}
		else if (choose == "3")
		{
			RefillStorage();
		}
		else if (choose == "4")
		{
			RemoveFromStorage();
		}
		else if (choose == "5")
		{
			CgangePrice();
		}
		else if (choose == "6")
		{
			RemoveFromStorage();
		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{
			
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "Admin menu ERROR!!\n";
		}
	}
}


void ShopUserMenu()
{
	while (true)
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
			ShowStorage();
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
			break;
		}
		else
		{
			std::cout << "User menu ERROR!!\n";
		}
	}
}


void CreateStaticStorage()
{
	const int staticSize = 10;
	const int categoryStaticSize = 4;

	int idStaticArr[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::string CategoryArr[categoryStaticSize]
	{
		"1. Наушники полноразмерные проводные", "2. Наушники IEM проводные", "3. ЦАПы стационарные", "4. Беспроводные наушники"
	};

	std::string nameStaticArr[staticSize]
	{
		"Sennheiser HD 650", "HIFIMAN Ananda Nano", "Sony MDR-7506", "TRN Medusa", "FiiO JD1", "KZ PR2", "Tempotec March III-M3",
		"FiiO K11", "OnePlus Buds 3", "Bowers & Wilkins Px7"
	};
	int countStaticArr[staticSize]{ 10, 15, 20, 50, 60, 40, 25, 15, 8, 10 };
	double priceStaticArr[staticSize]{ 54890.0, 59990.0, 11990.0, 4900.0, 1990.0, 4500.0, 13800.0, 16890.0, 8000.0, 60000.0 };

	FillStorage(idStaticArr, idArr, staticSize);
	FillStorage(nameStaticArr, nameArr, staticSize);
	FillStorage(countStaticArr, countArr, staticSize);
	FillStorage(priceStaticArr, priceArr, staticSize);
	FillStorage(CategoryArr, NameCategoryArr, categoryStaticSize);
}


template <typename Any>
void FillStorage(Any staticArr, Any dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}


void ShowStorage()
{
	std::cout << "ID\tНазвание\t\t\tКоличество\tЦена\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t\t" << countArr[i] << std::left << std::setw(9) << "\t" << priceArr[i] << "\n";
	}
}

void ShowCategoryStorage()
{
	char numberCategory;
	std::cout << "Категории\n";
	for (int i = 0; i < categorySize; i++)
	{
		std::cout << NameCategoryArr[i] << "\n";
	}

	std::cout << "\nВведите номер нужной категории товаров: ";
	std::cin >> numberCategory;

	if (numberCategory == '1')
	{
		std::cout << "ID\tНазвание\t\t\tКоличество\tЦена\n";

		for (int i = 0; i < 3; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t\t" << countArr[i] << std::left << std::setw(9) << "\t" << priceArr[i] << "\n";
		}
	}
	else if (numberCategory == '2')
	{
		for (int i = 3; i < 6; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t\t" << countArr[i] << std::left << std::setw(9) << "\t" << priceArr[i] << "\n";
		}
	}
	else if (numberCategory == '3')
	{
		for (int i = 6; i < 8; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t\t" << countArr[i] << std::left << std::setw(9) << "\t" << priceArr[i] << "\n";
		}
	}
	else if (numberCategory == '4')
	{
		for (int i = 8; i < 10; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t\t" << countArr[i] << std::left << std::setw(9) << "\t" << priceArr[i] << "\n";
		}
	}
}

void RefillStorage()
{
	std::string idStr, addStr, choose;
	int id{}, add;
	bool exit = false;

	while (!exit)
	{


		while (true)
		{
			std::cout << "Пополнение склада\nВведите ID товара: ";
			std::getline(std::cin, idStr, '\n');

			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "Ошибка ввода!!\n";
			}
			if (id > 0 && id <= size)
			{
				break;
			}
			else
			{
				std::cout << "Неверный ID\n";
			}
		}

		std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\t";

		while (true)
		{
			std::cout << "\nВведите количество товара для пополнения: ";
			std::getline(std::cin, addStr, '\n');

			if (isStringDigit(addStr))
			{
				add = std::stoi(addStr);

				if (add >= 0 && add < 500)
				{
					break;
				}

				else
				{
					std::cout << "Ошибка ввода!!!\n";
				}
			}
		}

		while (true)
		{

			std::cout << "Добавить " << add << " товара(ов) " << nameArr[id - 1] << " ?";
			std::cout << "1 - Да\t2 - Нет\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');

			if (choose == "1")
			{
				countArr[id - 1] += add;
				std::cout << "Товар успешно пополнен\n\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "Ошибка ввода!!\n";
			}
		}
	}
}

bool isStringDigit(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
}

void RemoveFromStorage()
{
	std::string idStr, removeStr, choose;
	int id{}, remove;
	bool exit = false;

	while (!exit)
	{


		while (true)
		{
			std::cout << "Списание со склада\nВведите ID товара: ";
			std::getline(std::cin, idStr, '\n');

			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "Ошибка ввода!!\n";
			}
			if (id > 0 && id <= size)
			{
				break;
			}
			else
			{
				std::cout << "Неверный ID\n";
			}
		}

		std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\t";

		while (true)
		{
			std::cout << "\nВведите количество товара для списания: ";
			std::getline(std::cin, removeStr, '\n');

			if (isStringDigit(removeStr))
			{
				remove = std::stoi(removeStr);

				if (remove >= 0 && remove <= countArr[id -1])
				{
					break;
				}

				else
				{
					std::cout << "Ошибка ввода!!!\n";
				}
			}
		}

		while (true)
		{

			std::cout << "Списать " << remove << " товара(ов) " << nameArr[id - 1] << " ?";
			std::cout << "1 - Да\t2 - Нет\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');

			if (choose == "1")
			{
				countArr[id - 1] += remove;
				std::cout << "Товар успешно списан\n\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "Ошибка ввода!!\n";
			}
		}
	}
}



void CgangePrice()
{
	std::string idStr, choose, newPriceStr;
	int id{}, price{};
	bool exit = false;
	double newPrice;

	while (!exit)
	{


		while (true)
		{
			std::cout << "Изменить цену\nВведите ID товара: ";
			std::getline(std::cin, idStr, '\n');

			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "Ошибка ввода!!\n";
			}
			if (id > 0 && id <= size)
			{
				break;
			}
			else
			{
				std::cout << "Неверный ID\n";
			}
		}

		std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\t";

		while (true)
		{
			std::cout << "\nВведите новую цену: ";
			std::getline(std::cin, newPriceStr, '\n');

			if (isStringDigit(newPriceStr))
			{
				newPrice = std::stoi(newPriceStr);

				if (price >= 0 && price <= 100000)
				{
					break;
				}

				else
				{
					std::cout << "Некоректная цена!!!\n";
				}
			}
		}

		while (true)
		{

			std::cout << "Назначить " << nameArr[id -1] << " новую цену " << newPrice << " ?";
			std::cout << "1 - Да\t2 - Нет\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');

			if (choose == "1")
			{
				countArr[id - 1] = newPrice;
				std::cout << "Цена успешно изменена\n\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "Ошибка ввода!!\n";
			}
		}
	}
}



void ChangeStaff()
{
	std::string choose;

	while (true)
	{
		std::cout << "ID\tЛогин\tПароль ";
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << "\n";
		}

		std::cout << "\n1. Добавить нового сотрудника\n2. Отредактировать сотрудника\n3 - Удалить сотрудника\n0. Выход\n\nВвод: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "1")
		{
			AddEmployee();
		}
		else if (choose == "2")
		{
			StaffReduct();
		}
		else if (choose == "3")
		{
			RemoveStaff();
		}
		else if (choose == "0")
		{
			break;
		}
	}
}

void AddEmployee()
{
	userCount++;
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];

	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника: ";
	std::getline(std::cin, newPass, '\n');

	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}

	tempLogin[userCount - 1] = newLogin;
	tempPass[userCount - 1] = newPass;

	std::swap(loginArr, tempLogin);
	std::swap(passwordArr, tempPass);

	delete []loginArr;
	delete []passwordArr;
}

void StaffReduct()
{
	std::string choose, newLogin, newPass;
	int empId;
	while (true)
	{


		std::cout << "ID\tЛогин\tПароль ";
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << "\n";
		}

		std::cout << "Введите ID сотрудника:\t 0. Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "0")
		{
			break;
		}
		else if (isStringDigit(choose))
		{
			empId = std::stoi(choose);
			for (int i = 0; i < userCount; i++)
			{
				if (i == empId -1)
				{
					std::cout << "Введите новый логин: ";
					std::getline(std::cin, newLogin, '\n');
					std::cout << "Введите новый пароль: ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newLogin;
					passwordArr[i] = newPass;

					break;
				}
				else
				{
					std::cout << "Нет сотрудника с таким ID\n";
				}
			}
		}
		else
		{
			std::cout << "Ошибка ввода!!\n\n";
		}

	}
}


void RemoveStaff()
{
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];

	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}

	delete[]loginArr;
	delete[]passwordArr;

	userCount--;
	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];


	std::string choose;
	int empId;
	while (true)
	{
		std::cout << "Введите ID сотрудника:\t 0. Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "0")
		{
			break;
		}
		else if (isStringDigit(choose))
		{
			empId = std::stoi(choose);

			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];

			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passwordArr[i];
			}

			delete[]loginArr;
			delete[]passwordArr;
			userCount--;
			loginArr = new std::string[userCount];
			passwordArr = new std::string[userCount];


			for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
			{
				if (i == empId - 1)
				{
					i++;
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
				else
				{
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
			}

			break;
		}
		else
		{
			std::cout << "Ошибка ввода!!\n\n";
		}

	}
}


void StorageReduct()
{
	// на некст паре будем это делать
}