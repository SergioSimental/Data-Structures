
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include <fstream>
#include <cmath>

using namespace std;

void print(string& n){
	cout << n << " ";
}

int main()
{
    BinarySearchTree<string> t;
	string name;
	string in;

	t.add("Nancy Drew");
	t.add("Greg Greed");
	t.add("Helen Hail");
	t.add("John Symthe");
	t.add("Orville Corn");
	t.add("Mustang Sally");
	t.add("Xena II");

	cout << "Enter a name to search" << endl;
	getline(cin, name);
	if (t.contains(name))
	{
		cout << "Name found" << endl;
	}
	else
		cout << "Name not found" << endl;

	cout << "Traversing the tree" << endl;
	t.inorderTraverse(print);
	cout << endl << endl;

	cout << "Print the Tree" << endl;
	t.printMap();

	t.remove("Greg Greed");
	cout << "Removed Greg Greed" <<endl;

	cout << "Traversing the tree" << endl ;
	t.inorderTraverse(print);
	cout << endl << endl;

	cout << "Print the Tree" << endl;
	t.printMap();
	system("pause");
}
