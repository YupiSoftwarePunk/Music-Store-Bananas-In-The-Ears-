#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>

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



// Категории товаров -----------------------------------------------------------------------
int firstCategory = 3;
int secondCategory = 6;
int thirdCategory = 8;
//-------------------------------------------------------------------------------------------



// Чек --------------------------------------------------------------------------------------
int sizeCheck = 1;
int* countCheckArr = new int[sizeCheck];
double* priceCheckArr = new double[sizeCheck];
double* totalPriceCheckArr = new double[sizeCheck];
std::string* nameCheckArr = new std::string[sizeCheck];
//-------------------------------------------------------------------------------------------



// Касса------------------------------------------------------------------------------------
double cash = 100000;
double emony = 0;
double cashMoney = 0;
//------------------------------------------------------------------------------------------



// Функции-----------------------------------------------------------------------------------
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();

template <typename Any>
void FillStorage(Any staticArr, Any dynamicArr, int size);

void ShowCategoryStorage();

void RefillStorage();
bool isStringDigit(std::string);
void RemoveFromStorage();
void CgangePrice();

void ChangeStaff();
void AddEmployee();
void StaffReduct();
void RemoveStaff();

void StorageReduct();
void AddProduct();
void RenameProduct();
void DeleteProduct();

void Selling();
void AddCheckItem();
void PrintCheck(long double& totalSum);
void Income();
//-------------------------------------------------------------------------------------------



// динамический склад
//--------------------------------------------------------------------------------------------
void CreateDynamicStorage();
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
				CreateDynamicStorage();
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
				std::cout << "\n\n" << "Добро пожаловать! " << loginArr[i] << "\n\n\n";
				isAdmin = false;
				return true;
			}
		}

		if (login == loginArr[0] && passw == passwordArr[0])
		{
			std::cout << "\n\n" << "Добро пожаловать! " << loginArr[0] << "\n\n\n";
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
			system("cls");
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. Изменить персонал\n";
			std::cout << "8. Отчет о прибыли\n\n";
			std::cout << "0. Закрыть смену\n";

			std::cout << "\nВвод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);

		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowCategoryStorage();
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
			StorageReduct();
		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{
			Income();
		}
		else if (choose == "0")
		{
			system("cls");
			while (true)
			{
				std::cout << "1 - Закрыть смену\n2 - Отмена\nВвод: ";
				std::getline(std::cin, choose, '\n');
				if (isStringDigit(choose))
				{
					break;
				}
				else
				{
					std::cout << "\n\nНекорректный ввод!\n\n";
				}
			}
			if (std::stoi(choose) == 1)
			{
				Income();
				std::cout << "\nСмена закрыта. Удачи!\n\n";
				break;
			}
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
			Selling();
		}
		else if (choose == "2")
		{
			ShowCategoryStorage();
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
			Income();
		}
		else if (choose == "6")
		{
			system("cls");
			while (true)
			{
				std::cout << "1 - Закрыть смену\n2 - Отмена\nВвод: ";
				std::getline(std::cin, choose, '\n');
				if (isStringDigit(choose))
				{
					break;
				}
				else
				{
					std::cout << "\n\nНекорректный ввод!\n\n";
				}
			}
			if (std::stoi(choose) == 1)
			{
				Income();
				std::cout << "\nСмена закрыта. Удачи!\n\n";
				break;
			}
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


void ShowCategoryStorage()
{
	while (true)
	{
		std::string choose;
		std::cout << "Категории\n\n";
		for (int i = 0; i < categorySize; i++)
		{
			std::cout << NameCategoryArr[i] << "\n";
		}

		std::cout << "\nВведите номер нужной категории товаров:\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');

		system("cls");

		std::cout << "ID\tНазвание\t\tКоличество\tЦена\n";

		if (choose == "1")
		{
			for (int i = 0; i < firstCategory; i++)
			{
				std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t" << countArr[i] << std::left << std::setw(2) << "\t\t" << priceArr[i] << "\n";
			}
		}
		else if (choose == "2")
		{
			for (int i = firstCategory; i < secondCategory; i++)
			{
				std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t" << countArr[i] << std::left << std::setw(2) << "\t\t" << priceArr[i] << "\n";
			}
		}
		else if (choose == "3")
		{
			for (int i = secondCategory; i < thirdCategory; i++)
			{
				std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t" << countArr[i] << std::left << std::setw(2) << "\t\t" << priceArr[i] << "\n";
			}
		}
		else if (choose == "4")
		{
			for (int i = thirdCategory; i < size; i++)
			{
				std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t" << countArr[i] << std::left << std::setw(2) << "\t\t" << priceArr[i] << "\n";
			}
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			std::cout << "\n\nТакого номера категории не существует!!\n\n";
			continue;
		}
		system("pause");
		break;
	}
}



struct Product
{
	int id{};
	std::string name;
	int quantity{};
	double price{};
};


void CreateDynamicStorage()
{
	system("cls");
	std::string countChoice;
	int numProducts{};

	std::cout << "Введите количество товаров которое хотите добавить: ";
	std::cin >> numProducts;

	if (numProducts < 1)
	{
		std::cout << "Неверно введено количество товаров!\n\n";
	}
	else
	{
		std::vector<Product> dynamicArr;  // Тип вектора Product

		for (int i = 0; i < numProducts; i++)
		{
			Product product;
			product.id = i;

			std::cin.ignore();
			std::cout << "Введите название товара " << i + 1 << ": ";
			std::cin >> product.name;

			std::cout << "Введите количество товара " << i + 1 << ": ";
			std::cin >> product.quantity;

			std::cout << "Введите цену товара " << i + 1 << ": ";
			std::cin >> product.price;

			dynamicArr.push_back(product);       // Добавляем товар в вектор
		}

		std::cout << "\n\nДинамический список товаров: \n\n";
		std::cout << "ID\tНазвание\tКол-во\tЦена\n";
		for (const auto& product : dynamicArr)          /*       перебор всех товаров в векторе dynamicArr.
														Используется const auto&, чтобы избежать копирования объектов
														и обеспечить доступ только для чтения.                 */
		{
			std::cout << product.id << "\t"
				<< product.name << "\t\t"
				<< product.quantity << "\t"
				<< product.price << " руб.\n";
		}
		system("pause");
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

				if (remove >= 0 && remove <= countArr[id - 1])
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
				countArr[id - 1] -= remove;
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
				std::cout << "Ошибка ввода!!\n\n";
			}
			if (id > 0 && id <= size)
			{
				break;
			}
			else
			{
				std::cout << "Неверный ID\n\n";
			}
		}

		std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\t";

		while (true)
		{
			std::cout << "\nВведите новую цену: ";
			std::getline(std::cin, newPriceStr, '\n');

			if (isStringDigit(newPriceStr))
			{
				newPrice = std::stod(newPriceStr);

				if (price >= 0 && price <= 10000000)
				{
					break;
				}

				else
				{
					std::cout << "Некоректная цена!!!\n\n";
				}
			}
		}

		while (true)
		{

			std::cout << "Назначить " << nameArr[id - 1] << " новую цену " << std::fixed << newPrice << " ?";
			std::cout << "1 - Да\t2 - Нет\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');

			if (choose == "1")
			{
				priceArr[id - 1] = newPrice;
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
				std::cout << "Ошибка ввода!!\n\n";
			}
		}
	}
}



void ChangeStaff()
{
	std::string choose;

	while (true)
	{
		std::cout << "ID\tЛогин\t\tПароль ";
		for (int i = 0; i < userCount; i++)
		{
			std::cout << "\n" << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i];
		}


		std::cout << "\n\n1. Добавить нового сотрудника\n2. Отредактировать сотрудника\n3 - Удалить сотрудника\n0. Выход\n\nВвод: ";
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
			system("cls");
			break;
		}
		else
		{
			std::cout << "Ошибка ввода!!\n\n";
		}
	}
}


void AddEmployee()
{
	system("cls");

	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];

	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}

	delete[]loginArr;
	delete[]passwordArr;

	userCount++;

	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];

	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}

	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника: ";
	std::getline(std::cin, newPass, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;

	delete[]tempLogin;
	delete[]tempPass;
}


void StaffReduct()
{
	system("cls");

	std::string choose, newLogin, newPass;
	int empId;
	while (true)
	{


		std::cout << "ID\tЛогин\t\tПароль ";
		for (int i = 0; i < userCount; i++)
		{
			std::cout << "\n" << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i];
		}

		std::cout << "\n\nВведите ID сотрудника:\t 0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "0")
		{
			system("cls");
			break;
		}
		else if (isStringDigit(choose))
		{
			empId = std::stoi(choose);
			for (int i = 0; i < userCount; i++)
			{
				if (empId < 1 || empId > userCount)
				{
					std::cout << "Нет сотрудника с таким ID\n\n";
					break;
				}


				if (i == empId - 1)
				{
					std::cout << "Введите новый логин: ";
					std::getline(std::cin, newLogin, '\n');
					std::cout << "Введите новый пароль: ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newLogin;
					passwordArr[i] = newPass;

					break;
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
	system("cls");

	std::string choose;
	int empId;
	while (true)
	{
		std::cout << "\nID\n";
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\n";
		}


		std::cout << "\n\nВведите ID сотрудника для удаления:\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');


		if (choose == "0")
		{
			system("cls");
			break;
		}
		else if (isStringDigit(choose) && choose != "1")
		{
			empId = std::stoi(choose);


			if (empId < 1 || empId > userCount)
			{
				std::cout << "Неверный ID!!!\n\n";
				break;
			}

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

			std::cout << "\n\nСотрудник успешно удален!\n\n";

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
	std::string choose;
	std::cout << "Изменение склада магазина\n\n";

	while (true)
	{
		std::cout << "1. Добавить новый товар\t2. Изменить название товара\t3. Удаление товара\n 0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			system("cls");
			break;
		}
		else if (choose == "1")
		{
			AddProduct();
		}
		else if (choose == "2")
		{
			RenameProduct();
		}
		else if (choose == "3")
		{
			DeleteProduct();
		}
		else
		{
			std::cout << "Некорретный ввод\n\n";
		}
	}
}



void AddProduct()
{
	system("cls");
	std::string choose12;
	while (true)
	{
		std::cout << "1 - Добавить новый товар\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose12, '\n');
		if (choose12 == "0")
		{
			system("cls");
			break;
		}
		else if (choose12 == "1")
		{
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}


			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;

			size++;
			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];


			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempId[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			std::string newName, newCountStr, newPriceStr;

			while (true)
			{
				std::cout << "Введите название нового товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[size - 1] = newName;
					break;
				}
				else
				{
					std::cout << "Слишком большое название\n\n";
				}
			}

			while (true)
			{
				std::cout << "Введите количество нового товара: ";
				std::getline(std::cin, newCountStr, '\n');

				if (isStringDigit(newCountStr))
				{
					if (std::stoi(newCountStr) >= 0 && std::stoi(newCountStr) < 1000)
					{
						countArr[size - 1] = std::stoi(newCountStr);
						break;
					}
				}
				else
				{
					std::cout << "Некорректный ввод\n\n";
				}

			}


			while (true)
			{
				std::cout << "Введите цену нового товара: ";
				std::getline(std::cin, newPriceStr, '\n');

				if (isStringDigit(newPriceStr))
				{
					if (std::stod(newPriceStr) >= 0)
					{
						priceArr[size - 1] = std::stod(newPriceStr);
						break;
					}
				}
				else
				{
					std::cout << "Некорректный ввод\n\n";
				}

			}

			idArr[size - 1] = size;

			std::cout << "\n\n" << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t" <<
				countArr[size - 1] << "\t" << std::fixed << priceArr[size - 1] << "\n" << "Новый товар успешно добавлен\n\n";



			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

		}
		else
		{
			std::cout << "\nНекорректный ввод\n\n";
		}
	}
}



void RenameProduct()
{
	system("cls");
	std::string choose;
	std::string idStr, newName;
	int id{};
	while (true)
	{
		std::cout << "1 - Изменить название\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "0")
		{
			system("cls");
			break;
		}
		else if (choose == "1")
		{
			while (true)
			{
				std::cout << "Введите ID: ";
				std::getline(std::cin, idStr, '\n');

				if (isStringDigit(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "Некорректный ID!!\n\n";
					}
				}
			}
			while (true)
			{
				std::cout << "\n\n" << idArr[id - 1] << "\t" << std::left << std::setw(30) << nameArr[id - 1] << "\n\n";
				std::cout << "Введите новое название товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[id - 1] = newName;
					break;
				}
				else
				{
					std::cout << "Максимальная длина названия 30 исмволов\n\n";
				}
			}

			std::cout << "\n\n" << idArr[id - 1] << "\t" << std::left << std::setw(30) << nameArr[id - 1] << "\t" <<
				countArr[id - 1] << "\t" << priceArr[id - 1] << "\n" << "Название товара изменено\n\n";

		}
		else
		{
			std::cout << "Некорректный ввод!!\n\n";
		}
	}


}

void DeleteProduct()
{
	system("cls");
	std::string choose;

	while (true)
	{
		std::cout << "1 - Удалить товар\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			system("cls");
			break;
		}
		else if (choose == "1")
		{
			std::string idStr, newName;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара: ";
				std::getline(std::cin, idStr, '\n');

				if (isStringDigit(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "Некорректный ID!!\n\n";
					}
				}
				else
				{
					std::cout << "\nНекорректный ввод\n\n";
				}
			}



			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}


			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;

			size--;
			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];


			for (int i = 0, j = 0; i < size, j < size; i++, j++)
			{
				if (i == id - 1)
				{
					i++;
					idArr[j] = tempId[j];
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
				}
				else
				{
					idArr[j] = tempId[j];
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
				}
			}


			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			size--;

			std::cout << "Товар успешно удален!!" << "\n";

			break;
		}
	}
}



void Selling()
{
	std::string chooseId, chooseCount, choosePay, userCash;
	std::string tempChoose;
	int id{}, count{};
	bool isFirst = true;
	sizeCheck = 1;
	long double totalSum{};
	double discount = 0.2;
	double itemOnSale = 0.15;



	while (true)
	{
		system("cls");

		std::cout << "Желаете совершить покупки?\tВведите 1 - чтобы продолжить или 0 - для выхода\nВвод: ";
		std::getline(std::cin, tempChoose, '\n');
		if (tempChoose == "1")
		{
			isFirst = true;
			totalSum = 0;
			delete[]priceCheckArr;
			delete[]countCheckArr;
			delete[]totalPriceCheckArr;
			delete[]nameCheckArr;
			sizeCheck = 1;
			priceCheckArr = new double[sizeCheck];
			countCheckArr = new int[sizeCheck];
			totalPriceCheckArr = new double[sizeCheck];
			nameCheckArr = new std::string[sizeCheck];


			while (true)
			{
				ShowCategoryStorage();
				std::cout << "Введите ID товара для покупки или 0 - для выхода\nВвод: "; // доп просьба на 0 иначе костыли придумывать
				std::getline(std::cin, chooseId, '\n');
				if (!isStringDigit(chooseId))
				{
					std::cout << "\nНеверный ID\n";
					continue;
				}
				else if (isStringDigit(chooseId))
				{
					id = std::stoi(chooseId);
					if (id == 0)
					{
						break;
					}
					else if (id == 10)
					{
						totalSum - (totalSum * itemOnSale);
					}
					else if (id > 0 && id <= size)
					{
						while (true)
						{
							std::cout << "Введите количество товара " << nameArr[id - 1] << ": ";
							std::getline(std::cin, chooseCount, '\n');
							if (!isStringDigit(chooseCount))
							{
								std::cout << "\n\nНекорректный ввод\n\n";
								continue;
							}
							else if (isStringDigit(chooseCount))
							{
								count = std::stod(chooseCount);
								if (count > 0 && count <= countArr[id - 1])
								{
									std::cout << std::left << std::setw(30) << nameArr[id - 1] << " " << count << " добавлен в чек\n\n";
									if (isFirst)
									{
										priceCheckArr[sizeCheck - 1] = priceArr[id - 1];
										nameCheckArr[sizeCheck - 1] = nameArr[id - 1];
										totalPriceCheckArr[sizeCheck - 1] = priceArr[id - 1] * count;
										countCheckArr[sizeCheck - 1] = count;
										totalSum += priceArr[id - 1] * count;
										isFirst = false;
										countArr[id - 1] -= count;
									}
									else
									{
										AddCheckItem();
										priceCheckArr[sizeCheck - 1] = priceArr[id - 1];
										nameCheckArr[sizeCheck - 1] = nameArr[id - 1];
										totalPriceCheckArr[sizeCheck - 1] = priceArr[id - 1] * count;
										countCheckArr[sizeCheck - 1] = count;
										totalSum += priceArr[id - 1] * count;
										countArr[id - 1] -= count;
									}
									break;
								}
								else
								{
									std::cout << "\n\nНекорректное кол-во\n\n";
								}
							}
							else
							{
								std::cout << "\n\nНекорректный ввод\n\n";
							}
						}
					}
					else
					{
						std::cout << "\n\nНекорректный ввод\n\n";
					}
				}
				else if (chooseId == "0") // добавил это
				{
					break;
				}
			}

			if (!isFirst)
			{
				if (totalSum >= 100000)
				{
					totalSum - (totalSum * discount);
				}
				PrintCheck(totalSum);
				std::cout << "\n\n\tИтоговая сумма: " << std::fixed << totalSum << " рублей\n\n\n";
				while (true)
				{
					std::cout << "Выберите способ оплаты:\n1 - Наличные\n2 - Безналичные\nВвод: ";
					std::getline(std::cin, choosePay, '\n');
					if (!isStringDigit(choosePay))
					{
						std::cout << "Некорректный ввод\n\n";
					}
					else
					{
						if (std::stoi(choosePay) == 1)
						{
							while (true)
							{
								std::cout << "Введите сумму наличных: ";
								std::getline(std::cin, userCash, '\n');
								if (!isStringDigit(userCash))
								{
									std::cout << "Некорректный ввод!!\n\n";
								}
								else
								{
									if (std::stod(userCash) < totalSum)
									{
										std::cout << "Недостаточно средств\n\n";
									}
									else if (cash >= std::stod(userCash) - totalSum)
									{
										std::cout << "\n\nВы дали: " << std::stod(userCash) << "\n\nОплата прошла успешно!\n\n" << "Сдача: " << std::stod(userCash) - totalSum << " руб.\n\n";
										cashMoney += totalSum;
										cash += std::stod(userCash);
										cash -= std::stod(userCash) - totalSum;
										break;
									}
								}
							}
							break;
						}
						else if (std::stoi(choosePay) == 2)
						{
							std::cout << "Оплата прошла успешно!\n\n";
							emony += totalSum;
							break;
						}
						else
						{
							std::cout << "Некорректный ввод!!\n\n";
						}
					}
				}

			}
			else
			{
				break;
			}

		}
		else if (tempChoose == "0") // добавил это
		{
			break;
		}
		else
		{
			system("cls");
			std::cout << "\n\nНекорректный ввод\n\n";// добавил это

		}
	}
}


void AddCheckItem()
{

	double* tempPriceCheck = new double[sizeCheck];
	int* tempCountCheck = new int[sizeCheck];
	double* tempTotalPriceCheck = new double[sizeCheck];
	std::string* tempNameCheck = new std::string[sizeCheck];
	for (int i = 0; i < sizeCheck; i++)
	{
		tempPriceCheck[i] = priceCheckArr[i];
		tempCountCheck[i] = countCheckArr[i];
		tempTotalPriceCheck[i] = totalPriceCheckArr[i];
		tempNameCheck[i] = nameCheckArr[i];
	}


	delete[]priceCheckArr;
	delete[]countCheckArr;
	delete[]totalPriceCheckArr;
	delete[]nameCheckArr;

	sizeCheck++;
	countCheckArr = new int[sizeCheck];
	priceCheckArr = new double[sizeCheck];
	totalPriceCheckArr = new double[sizeCheck];
	nameCheckArr = new std::string[sizeCheck];


	for (int i = 0; i < sizeCheck - 1; i++)
	{
		priceCheckArr[i] = tempPriceCheck[i];
		countCheckArr[i] = tempCountCheck[i];
		totalPriceCheckArr[i] = tempTotalPriceCheck[i];
		nameCheckArr[i] = tempNameCheck[i];
	}

	delete[]tempPriceCheck;
	delete[]tempCountCheck;
	delete[]tempTotalPriceCheck;
	delete[]tempNameCheck;

}


void PrintCheck(long double& totalSum)
{
	std::cout << "№\tНазвание\t\t\tКоличество\tЦена за ед\tИтого\n";
	for (int i = 0; i < sizeCheck; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(35) << nameCheckArr[i] << "\t" << countCheckArr[i] << "\t" << priceCheckArr[i] << "\t\t" << totalPriceCheckArr[i] << "\n\n";
	}

}



void Income()
{
	std::cout << "\n\t\tОтчет о прибыли\n\n";
	std::cout << "Прибыль за наличный рассчет:\t\t" << cashMoney << "\n";
	std::cout << "Прибыль за безналичный расчет:\t\t" << emony << "\n\n\n";
	std::cout << "Наличные на кассе:\t\t\t" << cash << "\n\n";
	std::cout << "Итоговая выручка:\t\t\t" << cashMoney + emony << "\n\n";
}
