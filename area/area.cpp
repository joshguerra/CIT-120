// demonstrates overloading funtions
// program calculates area of circle, rectangle, and triangle
// Project Name: area
// Programmer: J. Guerra
// Last Modified: Nov 25, 2015

#include <iostream>
using namespace std;

void printTitle();
void printMenu();
int getIntInRange(int start, int end);
int getInt();
double getNum();
double getPosNum();
double area(double a);
double area(double a, double b);
double area(double a, double b, double c);
void getTriangleSides(double &a, double &b, double &c);

void main() {
	double 
		a, b, c,			// arguements to calculate area
		result;				// hold output
	int o;					// option

	system("color 2f");		// console fun :D | 2 = green background, f = white text

	while (true) {
		printTitle();
		printMenu();

		cout << "Please enter your choice: ";
		o = getIntInRange(1, 4);

		cout << endl;
		switch (o) {
			case 1:				////////	Option 1 (Area of Circle)		////////
				cout << "Give me the radius of a circle: ";
				a = getPosNum();

				result = area(a);

				cout << "\tThe area of the circle is " << result;

				break;

			case 2:				////////	Option 2 (Area of Rectangle)	////////
				cout << "Give me the length of a rectangle: ";
				a = getPosNum();
				cout << "\t... and the width: ";
				b = getPosNum();

				result = area(a, b);

				cout << "\tThe area of the rectangle is " << result;

				break;
			case 3:				////////	Option 3 (Area of Triangle)		////////
				cout << "Give me the lengths of the sides of a triangle." << endl;
				getTriangleSides(a, b, c);

				result = area(a, b, c);

				cout << "\tThe area of the triangle is " << result;

				break;
			case 4:				////////	Option 4 (Close Program)		////////
			default:
				cout << "Thank you for using my program." << endl << endl;
				system("pause");
				exit(0);
		}

		// Wash. Rinse. Repeat.
		cout << endl << endl;
		system("pause");
		system("cls");
	}

}

void printTitle() {
	cout
		<< "\n\t              Lab on Overloading Functions              "
		<< "\n\t Calculate the Area of a Circle, Rectangle, or Triangle "
		<< "\n\t                      By J. Guerra                      " 
		<< endl << endl;
}

void printMenu() {
	cout
		<< "\n\t 1] Calculate the area of a Circle"
		<< "\n\t 2] Calculate the area of a Rectangle"
		<< "\n\t 3] Calculate the area of a Triangle"
		<< "\n\t 3] Exit Program"
		<< endl << endl << endl;
}

int getIntInRange(int start, int end) {
	int x = getInt();

	while (x < start || x > end) {
		cout
			<< "\a\tYour number must be "
			<< (x < start ? "greater" : "less")
			<< " than or equal to "
			<< (x < start ? start : end)
			<< ". \n\tTry again: ";
		x = getInt();
	}

	return x;
}

int getInt() {
	double x = getNum();

	while (int(x) != x) {
		cout << "\a\tYour number is not an integer! \n\tTry Again: ";
		x = getNum();
	}

	return int(x);
}

double getNum() {
	double x;

	while (!(cin >> x)) {
		cin.clear();	cin.ignore(30, '\n');
		cout << "\a\tPlease no inapropriate characters! \n\tTry again: ";
	}
	cin.ignore(80, '\n');

	return x;
}

double getPosNum() {
	double x = getNum();

	while (x < 0) {
		cout << "\aPositive numbers only please. Try again: ";
		x = getNum();
	}

	return x;
}

double area(double a) {
	return 3.1415926 * a * a;
}

double area(double a, double b) {
	return a * b;
}

double area(double a, double b, double c) {
	double p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void getTriangleSides(double &a, double &b, double &c) {
	cout << "Side 1: ";
	a = getPosNum();
	cout << "Side 2: ";
	b = getPosNum();
	cout << "Side 3: ";
	c = getPosNum();

	while (a > b + c || b > a + c || c > a + b) {
		cout
			<< "\aThe sum of two sides of a triangle must be greater than the third side."
			<< "\nTry again.";	
		
		cout << "Side 1: ";
		a = getPosNum();
		cout << "Side 2: ";
		b = getPosNum();
		cout << "Side 3: ";
		c = getPosNum();
	}
}