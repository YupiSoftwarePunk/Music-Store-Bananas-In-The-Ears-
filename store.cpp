#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

#if defined(max)
#undef max
#endif

/*
	�������
	������� �������
	�����/������������
	������
	������������
	�������
	���
	����������� �����
*/


// ������� ������ --------------------------------------------------------------------------
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "Admin", "User" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//------------------------------------------------------------------------------------------



// ����� ������� (���� ������ �������) -----------------------------------------------------
int size = 10;
int categorySize = 4;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
std::string* NameCategoryArr = new std::string[categorySize];
//-------------------------------------------------------------------------------------------




// �������-----------------------------------------------------------------------------------
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
	std::cout << "\n\n\t\t������ � ����\n\n\n";
	if (Login() == true)
	{
		/*std::cin.ignore(std::numeric_limits<std::streamsize>::max());*/
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout << "1. ������������ ������� �����\n2. ������� ����� �����\n";
				std::cout << "����: ";
				std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				// ������������ �����
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
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, passw, '\n');

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && passw == passwordArr[i])
			{
				std::cout << "����� ����������! " << loginArr[i] << "\n";
				isAdmin = false;
				return true;
			}
		}

		if (login == loginArr[0] && passw == passwordArr[0])
		{
			std::cout << "����� ����������! " << loginArr[0] << "\n";
			isAdmin = true;
			return true;
		}


		system("cls");
		std::cout << "������� ������ ����� ��� ������!!" << "\n\n";
	}
}


void ShopAdminMenu()
{
	while (true)
	{


		std::string choose;
		do
		{
			std::cout << "1. ������ �������\n";
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. �������� ����\n";
			std::cout << "6. �������� �����\n";
			std::cout << "7. �������� ��������\n";
			std::cout << "8. ����� � �������\n";
			std::cout << "0. ������� �����\n";

			std::cout << "����: ";
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
			std::cout << "1. ������ �������\n";
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. ����� � �������\n";
			std::cout << "6. ������� �����\n";

			std::cout << "����: ";
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
		"1. �������� �������������� ���������", "2. �������� IEM ���������", "3. ���� ������������", "4. ������������ ��������"
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
	std::cout << "ID\t��������\t\t\t����������\t����\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t\t" << countArr[i] << std::left << std::setw(9) << "\t" << priceArr[i] << "\n";
	}
}

void ShowCategoryStorage()
{
	char numberCategory;
	std::cout << "���������\n";
	for (int i = 0; i < categorySize; i++)
	{
		std::cout << NameCategoryArr[i] << "\n";
	}

	std::cout << "\n������� ����� ������ ��������� �������: ";
	std::cin >> numberCategory;

	if (numberCategory == '1')
	{
		std::cout << "ID\t��������\t\t\t����������\t����\n";

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
	std::string idStr;
	std::cout << "���������� ������\n������� ID ������: ";
	std::getline(std::cin, idStr, '\n');

	int id = std::stoi(idStr);
	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\t";
}