// I dentifies whether a number can divide into another number. 4 version in one program
// divisibleby.exe
// Programmer: Josh Guerra
// Last Modified: Oct. 5, 2015

#include <iostream>
using namespace std;

void main() {
	int num1, num2;

	//////////   DONE
	cout
		<< endl
		<< "\t\t     Divisible or Not" << endl
		<< "\t\t      long if version" << endl
		<< "\t\t       By J. Guerra  " << endl
		<< endl << endl;

	cout << "Please enter an integer: "; 
	cin >> num1;      cin.ignore(20, '\n');
	cout << "Please enter another integer: "; 
	cin >> num2;      cin.ignore(20, '\n');

	if (num1 % num2 == 0) 
		cout << endl << num1 << " is divisible by " << num2 << "." << endl;
	else 
		cout << endl << num1 << " is NOT divisible by " << num2 << "." << endl;

	cout << endl << "Hit ENTER to close Program"; cin.get();


	// --------------------------------------------------------------------------------------
	// common code out     DONE
	cout
		<< endl << endl
		<< "\t\t     Divisible or Not  " << endl
		<< "\t\t        if version     " << endl
		<< "\t\t   with common code out" << endl
		<< "\t\t       By J. Guerra    " << endl
		<< endl << endl;

	cout << "Please enter an integer: "; 
	cin >> num1;      cin.ignore(20, '\n');
	cout << "Please enter another integer: "; 
	cin >> num2;      cin.ignore(20, '\n');

	cout << endl << num1 << " is";
	if (num1 % num2 == 0)
		cout << "";
	else
		cout << " NOT";
	cout << " divisible by " << num2 << "." << endl;

	cout << endl << "Hit ENTER to close Program"; cin.get();


	// --------------------------------------------------------------------------------------
	// if, no else             DONE
	cout
		<< endl << endl
		<< "\t\t     Divisible or Not  " << endl
		<< "\t\t        if version     " << endl
		<< "\t\t       without else    " << endl
		<< "\t\t       By J. Guerra    " << endl
		<< endl << endl;

	cout << "Please enter an integer: "; 
	cin >> num1;      cin.ignore(20, '\n');
	cout << "Please enter another integer: "; 
	cin >> num2;      cin.ignore(20, '\n');
	cout << endl;

	cout << num1 << " is";
	if (num1 % num2 != 0)
		cout << " NOT";
	cout << " divisible by " << num2 << "." << endl;

	cout << endl << "Hit ENTER to close Program"; cin.get();

	// --------------------------------------------------------------------------------------
	// using conditional operator
	cout
		<< endl << endl
		<< "\t\t     Divisible or Not   " << endl
		<< "\t\t       best version     " << endl
		<< "\t\t   conditional operator " << endl
		<< "\t\t       By J. Guerra     " << endl
		<< endl << endl;

	cout << "Please enter an integer: "; 
	cin >> num1;      cin.ignore(20, '\n');
	cout << "Please enter another integer: "; 
	cin >> num2;      cin.ignore(20, '\n');
	cout << endl;

	cout << num1 << " is" << (num1 % num2 == 0 ? "" : " NOT") << " divisible by " << num2 << "." << endl;

	cout << endl << "Hit ENTER to close Program"; 
	cin.get();
}