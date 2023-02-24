#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

 
void admin_menu();
bool admin_login();
void create1();
void main_menu();
void customer_menu();
void searchoption();
void exit();
void display();
void sys();
void sysload();
void sysback();
void sysexit();

//customer page
// rent display function
void allcars()
{
	system("cls");
	system("color 3");
	fstream file;
	int rent;
	string brand, id, model;
	cout << "\t\t <<--------------VIEW ALL CAR RECORD(S)------------->>";

	file.open("carsrecords.txt", ios::in);
	if (!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		system("cls");
		cout << "\t\t            AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
		cout << "\t\t <=======================================================>\n";
		cout << "\t\t <<----------------VIEW ALL CAR RECORD(S)--------------->>\n";
		cout << "\t\t |CAR ID\tBRAND\t\tMODEL\t\tRENT FEE |\n";
		file >> id >> brand;
		file >> model >> rent;

		while (!file.eof()) {
			cout << "\t\t |" << id
				<< "\t\t" << brand
				<< "\t\t" << model
				<< "\t\tPhp." << rent
				<< "\n";
			file >> id >> brand;
			file >> model >> rent;
		}
		cout << "\t\t";
		system("pause");

		file.close();

		display();
	}
}
void allrents()
{
	system("cls");
	system("color 3");
	fstream file;
	int no_days;
	string name, id, date;
	cout << "\t\t <<--------------VIEW ALL RENT RECORD(S)------------->>";

	file.open("rents.txt", ios::in);
	if (!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		system("cls");
		cout << "\t\t            AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
		cout << "\t\t <=======================================================>\n";
		cout << "\t\t <<----------------VIEW ALL CAR RECORD(S)--------------->>\n";
		cout << "\t\t |CAR ID\tCUSTOMER NAME\tNO. OF DAYS\tDATE        |\n";
		file >> id >> name;
		file >> no_days >> date;

		while (!file.eof()) {
			cout << "\t\t |" << id
				<< "\t\t" << name
				<< "\t\t" << no_days
				<< "Days\t\t" << date
				<< "\n";
			file >> id >> name;
			file >> no_days >> date;
		}
		cout << "\t\t";
		system("pause");

		file.close();

		display();
	}
	
}
// rent function
void rent()
{
	system("cls");
	fstream file;
	int id;
	string name, date, no_days;
	cout << "\t\t         AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t <<---------------------RENT CAR-------------------->>" << endl;
	cout << "\t\t | >> ENTER CAR ID: ";
	cin >> id;
	cout << "\t\t | >> CTMR NAME: ";
	cin >> name;
	cout << "\t\t | >> NO. OF DAY(S): ";
	cin >> no_days;
	cout << "\t\t <<------ENTER THE DATE TODAY (ex. 03/03/2023)------>>" << endl;
	cout << "\t\t | >> DATE: ";
	cin >> date;

	file.open("rents.txt", ios::out | ios::app);
	file << " " << id << " " << name << " " << no_days << " " << date << "\n";
	file.close();

	customer_menu();
}
// display function for custome page
void displays()
{
	system("cls");
	system("color 3");
	fstream file;
	int rent;
	string brand, id, model;
	cout << "\t\t <<--------------VIEW ALL CAR RECORD(S)------------->>";

	file.open("carsrecords.txt", ios::in);
	if (!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		system("cls");
		cout << "\t\t            AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
		cout << "\t\t <=======================================================>\n";
		cout << "\t\t <<----------------VIEW ALL CAR RECORD(S)--------------->>\n";
		cout << "\t\t |CAR ID\tBRAND\t\tMODEL\t\tRENT FEE |\n";
		file >> id >> brand;
		file >> model >> rent;

		while (!file.eof()) {
			cout << "\t\t |" << id
				<< "\t\t" << brand
				<< "\t\t" << model
				<< "\t\tPhp." << rent
				<< "\n";
			file >> id >> brand;
			file >> model >> rent;
		}
		cout << "\t\t";
		system("pause");

		file.close();

		customer_menu();
	}
}
// search car by model function
void searchmodel()
{
	system("cls");
	system("color 3");
	fstream file;
	int rent, count = 0;
	string model, id, brand, mo;
	cout << "\t\t <<--------------SEARCH CAR RECORD(S)------------->>";

	file.open("carsrecords.txt", ios::in);
	if (!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		system("cls");
		cout << "\n\n\t\t | >> ENTER CAR MODEL: ";
		cin >> mo;
		file >> id >> brand;
		file >> model >> rent;

		while (!file.eof()) {
			if (mo == model) {
				system("cls");
				cout << "\t\t            AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
				cout << "\t\t <=======================================================>\n";
				cout << "\t\t <<-----------------SEARCH CAR RECORD(S)---------------->>\n";
				cout << "\t\t |CAR ID\tBRAND\t\tMODEL\t\tRENT FEE |\n";
				cout << "\t\t |" << id << "\t\t" << brand << "\t\t" << model << "\t\tPhp." << rent << "|\n";
				break;
			}
			file >> id >> brand;
			file >> model >> rent;
		}
		system("pause");
		file.close();
		searchoption();
		if (count == 0)
			cout << "\t\t <<----------------CAR MODEL NOT FOUND!---------------->>\n\n";
	}

}
// search car by ID function
void searchid()
{
	system("cls");
	system("color 3");
	fstream file;
	int rent, count = 0;
	string id, brand, model, idd;
	cout << "\t\t <<--------------SEARCH CAR RECORD(S)------------->>";

	file.open("carsrecords.txt", ios::in);
	if (!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		system("cls");
		cout << "\n\n\t\t | >> ENTER CAR ID: ";
		cin >> idd;
		file >> id >> brand;
		file >> model >> rent;

		while (!file.eof()) {
			if (idd == id) {
				system("cls");
				cout << "\t\t            AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
				cout << "\t\t <=======================================================>\n";
				cout << "\t\t <<-----------------SEARCH CAR RECORD(S)---------------->>\n";
				cout << "\t\t |CAR ID\tBRAND\t\tMODEL\t\tRENT FEE |\n";
				cout << "\t\t |" << id << "\t\t" << brand << "\t\t" << model << "\t\tPhp." << rent << "|\n";
				break;
			}
			file >> id >> brand;
			file >> model >> rent;
		}
		system("pause");
		file.close();
		searchoption();
		if (count == 0)
			cout << "\t\t <<----------------CAR BRAND NOT FOUND!---------------->>\n\n";
	}

}
// search car by brand function
void searchbrand()
{
	system("cls");
	system("color 3");
	fstream file;
	int rent, count = 0;
	string brand, id, model, br;
	cout << "\t\t <<--------------SEARCH CAR RECORD(S)------------->>";

	file.open("carsrecords.txt", ios::in);
	if(!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		system("cls");
		cout << "\n\n\t\t | >> ENTER CAR BRAND: ";
		cin >> br;
		file >> id >> brand;
		file >> model >> rent;

		while (!file.eof()) {
			if (br == brand) {
				system("cls");
				cout << "\t\t            AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
				cout << "\t\t <=======================================================>\n";
				cout << "\t\t <<-----------------SEARCH CAR RECORD(S)---------------->>\n";
				cout << "\t\t |CAR ID\tBRAND\t\tMODEL\t\tRENT FEE |\n";
				cout << "\t\t |" << id << "\t\t" << brand << "\t\t" << model << "\t\tPhp." << rent << "|\n";
				break;
			}
			file >> id >> brand;
			file >> model >> rent;
		}
		system("pause");
		file.close();
		searchoption();
		if(count == 0)
			cout << "\t\t <<----------------CAR BRAND NOT FOUND!---------------->>\n\n";
	}
	
}
//search function
void searchoption()
{
	system("cls");
	int soption;
	cout << "\n\n\n\n\n\t\t         AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 [1] Search by Brand                  " << endl;
	cout << "\t\t                 [2] Search by ID                     " << endl;
	cout << "\t\t                 [3] Search by Model                  " << endl;
	cout << "\t\t                 [4] Back                             " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t >> Enter Value: ";
	cin >> soption;

	switch (soption)
	{
	case 1:
		searchbrand();
		break;
	case 2:
		searchid();
		break;
	case 3:
		searchmodel();
		break;
	case 4:
		customer_menu();
		break;
	}
	
}
//customer menu
void customer_menu()
{
	system("cls");
	system("color A");
	cout << "\n\n\n\n\n\t\t           AUZARB CAR RENTAL MANAGEMENT SYSTEM" << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                Loading Please wait...." << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                  ";
	char loadingam = 219;
	for (int i = 0; i <= 20; i++)
	{
		cout << loadingam;
		Sleep(100);
	}

	system("cls");
	system("color 7");
	int customermenu;
	cout << "\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 [1] Search Car                       " << endl;
	cout << "\t\t                 [2] View Car List                    " << endl;
	cout << "\t\t                 [3] Rent a Car                       " << endl;
	cout << "\t\t                 [4] Back                             " << endl;
	cout << "\t\t                 [5] Exit The System                  " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t | >> Enter Value: ";
	cin >> customermenu;

	switch (customermenu)
	{
	case 1:
		searchoption();
		break;
	case 2:
		displays();
		break;
	case 3:
		rent();
		break;
	case 4:
		main_menu();
		break;
	case 5:
		exit();
		break;
	}


}

//admin page
// exit function
void exit()
{
	system("cls");
	system("color A");
	cout << "\n\n\n\n\n\t\t <===================================================>" << endl;
	cout << "\t\t                 THANK YOU & GOODBYE!                 " << endl;
	cout << "\t\t                   HAVE A GREAT DAY!                  " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 LEAVING, PLEASE WAIT!                " << endl;
	cout << "\t\t                 ";

	char loading = 219;
	for (int i = 0; i <= 20; i++)
	{
		cout << loading;
		Sleep(100);
	}
}
//log out function
void logout()
{
	system("cls");
	system("color A");
	cout << "\n\n\n\n\n\t\t <===================================================>" << endl;
	cout << "\t\t                   AUZARB CAR RENTAL                  " << endl;
	cout << "\t\t                   MANAGEMENT SYSTEM                  " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                LOGGING OUT, PLEASE WAIT!             " << endl;
	cout << "\t\t                 ";

	char loading = 219;
	for (int i = 0; i <= 20; i++)
	{
		cout << loading;
		Sleep(100);
	}
	system("color 7");
	main_menu();
}
void display()
{
	system("cls");
	int displaychoice;
	cout << "\n\n\n\n\n\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 [1] Display All Cars                 " << endl;
	cout << "\t\t                 [2] Display All Rents                " << endl;
	cout << "\t\t                 [3] Back                             " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t | >> Enter Value: ";
	cin >> displaychoice;

	switch (displaychoice)
	{
	case 1:
		allcars();
		break;
	case 2:
		allrents();
		break;
	case 3:
		admin_menu();
		break;
	}
}
//delete function
void delet()
{
	system("cls");
	fstream file, file1;
	int rent, count = 0;
	string id, idd, brand, model;
	cout << "\t\t <<---------------DELETE CAR RECORD(S)-------------->>";

	file1.open("carsrecords1.txt", ios::app | ios::out);
	file.open("carsrecords.txt", ios::in);

	if(!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		cout << "\n\n\t\t | >> ENTER CAR ID: ";
		cin >> id;
		file >> idd >> brand;
		file >> model >> rent;
		while (!file.eof()) {
			if (id == idd) {
				system("cls");
				cout << "\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
				cout << "\t\t <===================================================>\n";
				cout << "\t\t <<---------------DELETE CAR RECORD(S)-------------->>\n";
				cout << "\t\t | >> ENTER CAR ID: ";
				cout << "\n\n\t\t | >> CAR RECORD DELETED SUCCESSFULLY!\n\n";
				count++;
			}
			else
				file1 << " " << idd
				<< " " << brand
				<< " " << model
				<< " " << rent
				<< "\n\n";
			file >> idd >> brand;
			file >> model >> rent;
		}
		if(count == 0)
			cout << "\t\t <<----------------CAR ID NOT FOUND!---------------->>\n\n";
	}
	system("pause");

	file.close();
	file1.close();
	remove("carsrecords.txt");
	rename("carsrecords1.txt", "carsrecords.txt");

	admin_menu();
}
//edit record
void edit()
{
	system("cls");
	fstream file, file1;
	int rent, re, count = 0;
	string brand, br, model;
	string mo, idd, id;

	cout << "\t\t <<----------------EDIT CAR RECORD(S)--------------->>";
	file1.open("carsrecords1.txt",
		ios::app | ios::out);
	file.open("carsrecords.txt", ios::in);

	if (!file)
		cout << "\t\t <<------------------CAN'T OPEN FILE---------------->>";
	else {
		cout << "\n\n\t\t | >> ENTER CAR ID: ";
		cin >> id;
		file >> idd >> brand;
		file >> model >> rent;

		while (!file.eof())
		{
			if (id == idd)
			{
				system("cls");
				cout << "\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         \n";
				cout << "\t\t <===================================================>\n";
				cout << "\t\t <<----------------EDIT CAR RECORD(S)--------------->>\n";
				cout << "\t\t | >> ENTER BRAND: ";
				cin >> br;
				cout << "\t\t | >> ENTER MODEL: ";
				cin >> mo;
				cout << "\t\t | >> ENTER RENT FEE: ";
				cin >> re;
				file1 << " " << id << " "
					<< br << " " << mo << " " << re 
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << idd 
				<< " " << brand 
				<< " " << model 
				<< " " << rent 
				<< "\n\n";
			file >> idd >> brand;
			file >> model >> rent;
		}
		if (count == 0)
		cout << "\t\t <<----------------CAR ID NOT FOUND!---------------->>\n\n";
	}
	cout << endl;
	system("pause");


	file.close();
	file1.close();
	remove("carsrecords.txt");
	rename("carsrecords1.txt", "carsrecords.txt");

	admin_menu();
}
//create record
void create()
{
	system("cls");
	fstream file;
	int rent;
	string brand, model, id;
	cout << "\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t <<----------------NEW CAR RECORD(S)---------------->>" << endl;
	cout << "\t\t | >> CAR ID: ";
	cin >> id;
	cout << "\t\t | >> CAR BRAND: ";
	cin >> brand;
	cout << "\t\t | >> CAR MODEL: ";
	cin >> model;
	cout << "\t\t | >> RENT FEE: ";
	cin >> rent;

	file.open("carsrecords.txt", ios::out | ios::app);
	file << " " << id << " " << brand << " " << model << " " << rent << "\n";
	file.close();

	create1();
}
void create1()
{
	int choicenew;
	cout << "\n\n\n\n\n\t\t >> Do You Want To Add New Record Again?" << endl;
	cout << "\t\t >> [1] YES [2] NO" << endl;
	cout << "\t\t >> ENTER VALUE: ";
	cin >> choicenew;

	switch (choicenew)
	{
	case 1:
		create();
		break;

	case 2:
		system("cls");
		system("color A");
		cout << "\n\n\n\n\n\t\t           AUZARB CAR RENTAL MANAGEMENT SYSTEM" << endl;
		cout << "\t\t <===================================================>" << endl;
		cout << "\t\t                Loading Please wait...." << endl;
		cout << "\t\t <===================================================>" << endl;
		cout << "\t\t                ";
		char loadingam = 219;
		for (int i = 0; i <= 20; i++)
		{
			cout << loadingam;
			Sleep(100);
		}
		admin_menu();
		break;
	}
}
//admin menu function
void admin_menu()
{
	system("cls");
	system("color 7");
	int adminchoice;
	cout << "\n\n\n\n\n\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 [1] Create Car Record                " << endl;
	cout << "\t\t                 [2] Edit Car Record                  " << endl;
	cout << "\t\t                 [3] Delete Car Record                " << endl;
	cout << "\t\t                 [4] Display Records                  " << endl;
	cout << "\t\t                 [5] Log Out                          " << endl;
	cout << "\t\t                 [6] Exit The System                  " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t >> Enter Value: ";
	cin >> adminchoice;

	switch (adminchoice)
	{
	case 1:
		create();
		break;
	case 2:
		edit();
		break;
	case 3:
		delet();
		break;
	case 4:
		display ();
		break;
	case 5:
		logout();
		break;
	case 6:
		exit();
		break;
	}
}
bool admin_login()
{
	system("cls");
	string adminun;
	string adminpw;
	bool LoginSuccess = false;
	cout << "\n\n\n\n\n\t\t           AUZARB CAR RENTAL MANAGEMENT SYSTEM" << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t              Enter Username: ";
	cin >> adminun;
	cout << "\t\t              Enter Password: ";
	cin >> adminpw;
	cout << "\t\t <===================================================>" << endl;


	if (adminun == "auza-admin" && adminpw == "060105")
	{
		LoginSuccess = true;

		system("cls");
		system("color A");
		cout << "\n\n\n\n\n\t\t           AUZARB CAR RENTAL MANAGEMENT SYSTEM" << endl;
		cout << "\t\t <===================================================>" << endl;
		cout << "\t\t                  LOG IN SUCCESSFULLY!" << endl;
		cout << "\t\t                Loading Please wait...." << endl;
		cout << "\t\t <===================================================>" << endl;
		cout << "\t\t                  ";
		char loadingam = 219;
		for (int i = 0; i <= 20; i++)
		{
			cout << loadingam;
			Sleep(100);
		}
		admin_menu();
	}
	else
	{
		system("cls");
		system("color 4");
		cout << "\n\n\n\n\n\t\t           AUZARB CAR RENTAL MANAGEMENT SYSTEM" << endl;
		cout << "\t\t <===================================================>" << endl;
		cout << "\t\t                     LOG IN FAILED!" << endl;
		cout << "\t\t     Please Enter The Correct Username & Password." << endl;
		cout << "\t\t <===================================================>" << endl;
		cout << "\t\t               LOADING! PLEASE WAIT |>> ";
		char loadingam = 219;
		for (int i = 0; i <= 20; i++)
		{
			cout << loadingam;
			Sleep(100);
		}
		system("color 7");
		admin_login();
	}
	return 0;
}

//system information
void sysload()
{
	system("cls");
	system("color 2");
	cout << "\n\n\n\n\n\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 Loading Please Wait...               " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 ";

	char loadingsys = 219;
	for (int i = 0; i <= 20; i++)
	{
		cout << loadingsys;
		Sleep(100);
	}
	sys();
}
void sys()
{
	system("cls");
	system("color 7");
	cout << "\n\n\n\n\n\t\t           AUZARB CAR RENTAL MANAGEMENT SYSTEM" << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                      MISSION" << endl;
	cout << "\t\t  This systen will ensure a stress-free car rental    " << endl;
	cout << "\t\t  experience by providing superior services that      " << endl;
	cout << "\t\t  cater to our customers' individual needs.\n\n       " << endl;
	cout << "\t\t  >> Project Name: AUZARB Car Rental Management System" << endl;
	cout << "\t\t  >> Project Developer: Ronnel Brent D. Brutas        " << endl;
	cout << "\t\t  >> Project Manager: Franklin Anthony R. Chin        " << endl;
	cout << "\t\t <===================================================>" << endl;

	int optionsys;
	cout << "\t\t  |            [1] Back [2] Exit Program             |" << endl;
	cout << "\t\t  |>> Enter Value: ";
	cin >> optionsys;

	switch (optionsys)
	{
	case 1:
		sysback();
		break;

	case 2:
		sysexit();
		break;
	}

}
void sysback()
{
	system("cls");
	system("color 2");
	cout << "\n\n\n\n\n\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 Loading Please Wait...               " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 ";
	char loadingsys = 219;
	for (int i = 0; i <= 20; i++)
	{
		cout << loadingsys;
		Sleep(100);
	}
	system("color 7");
	main_menu();
}
void sysexit()
{
	system("cls");
	system("color 4");
	cout << "\n\n\n\n\n\t\t          AUZARB CAR RENTAL MANAGEMENT SYSTEM         " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t             THANK YOU & HAVE A GREAT DAY!            " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 ";
	char loadingsysex = 219;
	for (int i = 0; i <= 20; i++)
	{
		cout << loadingsysex;
		Sleep(100);
	}
	return;
}

//main menu function
void main_menu()
{
	system("cls");
	int mainchoice;
	cout << "\n\n\n\n\n\t\t           AUZARB CAR RENTAL MANAGEMENT SYSTEM" << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t |            WELCOME TO AUZARB CAR RENTAL           |" << endl;
	cout << "\t\t |                 MANAGEMENT SYSTEM                 |" << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t | [1] Admin | [2] Customer | [3] System Information |" << endl;
	cout << "\t\t |                 [4] Exit Program                  |" << endl;
	cout << "\t\t >> Enter Value: ";
	cin >> mainchoice;

	switch (mainchoice)
	{
	case 1:
		admin_login();
		break;
	case 2:
		customer_menu();
		break;
	case 3:
		sysload();
		break;
	case 4:
		exit();
		break;

	default:
		cout << "\n\n\t\t Invalid value, please try again!";

	}
}
int main()
{
	system("title AUZA CRMS");
	cout << "\n\n\n\n\n\t\t <===================================================>" << endl;
	cout << "\t\t              WELCOME TO AUZARB CAR RENTAL            " << endl;
	cout << "\t\t                   MANAGEMENT SYSTEM                  " << endl;
	cout << "\t\t <===================================================>" << endl;
	cout << "\t\t                 LOADING, PLEASE WAIT!                " << endl;
	cout << "\t\t                 ";

	char loading = 219;
	for (int i = 0; i <= 20; i++)
	{
		cout << loading;
		Sleep(100);
	}
	main_menu();
}