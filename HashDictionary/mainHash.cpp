
#include <iostream>
#include <string>
#include "HashedDictionary.h"
#include <fstream>

using namespace std;

void visit(int& age)
{
	cout << " " << age;
}

int main()
{
	int selection;
	ifstream inFile;
	HashedDictionary<string, int> table;
	int key = 0;
	int age = 0;
	string name;
	string file;

	do
	{
		cout << "1. Print Hash table\n"
			<< "2. Retrieve hash item\n"
			<< "3. Delete item\n"
			<< "4. Read names from file\n"
			<< "5. Save names to file\n"
			<< "6. Add item\n"
			<< "0. Quit \n"
			<< "\nEnter selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
			table.traverse(visit);
			break;
		case 2:
			cout << "Item selection: ";
			cin.ignore();
			getline(cin, name);
			cout << name << "'s age is " <<table.getItem(name) << endl;
			break;
		case 3:
			cout << "Delete item: ";
			cin.ignore();
			getline(cin, name);
			table.remove(name);
			cout << "Removed" << endl;
			break;
		case 4:
			cout << "Enter file name: " << endl;
			cin.ignore();
			cin >> file;
			inFile.open(file);
			while (!inFile.eof())
			{
				inFile >> age;
				getline(inFile, name);
				name = name.substr(1, name.length());
				table.add(name, age);
			}
			break;
		case 5:
			table.writeFile("newFileNames.txt");
			break;
		case 6:
			cout << "Add item name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Add item age: ";
			cin.clear();
			cin >> age;
			table.add(name, age);
			cout << "Added "<<endl;
			break;
		case 0:
			cout << "Quitting\n";
			break;
		default:
			cout << "Invalid selection\n";
		}
	} while (selection != 0);


	system("pause");
}
