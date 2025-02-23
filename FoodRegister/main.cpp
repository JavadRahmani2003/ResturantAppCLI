//Main header Connected to File
#include "AllHeaders.h"

#include "database.h"

bool NotAppClose = false;
string DbFile = "Database.db";
string foodname;
int foodprice;

int main()
{
	sqlite3* db;
	if (sqlite3_open(DbFile.c_str(), &db) == SQLITE_OK)
	{
		CreateTable(db,"Database.db");
	}
	else
	{
		cout << "Error! Database Not Opened and loaded Successfully: " << sqlite3_errmsg(db) << endl;
	}

	std::cin.get();

	while (!NotAppClose)
	{
		system("cls");

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 6);

		cout << "~~~~~~~~~~~~~~~~~~~~~~{{| Resturant menu -> Food Section |}}~~~~~~~~~~~~~~~~~~~~~~~~";
		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n\t Tip: to add food and price press (o) and to delete press (d)";
		cout << "\n\t To save into database and give to other parts press (esc) to save and quit";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\n\n\t\t\t\tMenu: \n\n\n";

		ShowMenu(db);

		cout << "\n\nEnter a Key: ";
		switch (_getch())
		{
		case 111: // o (small)
			cout << "\nEnter your Food Name: ";
			cin >> foodname;
			cout << "Enter your Food Price: ";
			cin >> foodprice;
			InsertIntoDb(db,foodname,foodprice);
			break;

		case 100: // d (small)
			cout << "\nEnter the Name of Food to Delete: ";
			cin >> foodname;
			DeleteFrmDb(db,foodname);
			break;

		case 27: // esc key
			cout << "\nGood Bye Sir, Have a nice day!" << std::endl;
			NotAppClose = true;
			break;
		}
	}
	system("pause");
	return 0;
}