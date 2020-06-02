/********************************************
*				CHRIS FLORES				*
*				ASSIGNMENT 5				*
*											*
********************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.1415926535897932384626433832795;

double toDeg(double angle)
{
	return (angle * 180) / PI;
}

double angToRad(double angle) {
	return (angle * PI) / 180;
}

int main()
{
	int choice;

	double Ax = 0, Ay = 0, Bx = 0, By = 0, Cx = 0, Cy = 0, A = 0, B = 0, C = 0, a = 0, b= 0, c = 0;


	cout << setw(10) << "" << "This program is designed to aid in the analysis of triangles" << endl;
	cout << setw(10) << "" << "Please select the number for the given information you have for your triangle: " << endl;

	do {
		cout << setw(10) << "" << "1. Three vertices. " << endl;
		cout << setw(10) << "" << "2. Three edge lengths. " << endl;
		cout << setw(10) << "" << "3. Two edges and the included angle. " << endl;
		cout << setw(10) << "" << "4. Two angles and the included edge. " << endl;;
		cout << setw(10) << "" << "5. Two angles and the side opposite the first angle. ";
		cin >> choice;

		if (choice < 1 || choice > 5)
		{
			cout << setw(10) << "" << "That's not a good choice. Try again: ";
		}

	} while (choice < 0 || choice > 5);

	switch (choice)
	{
	case 1:
	{
		cout << setw(10) << "" << "Enter the x coordinate of point A: " << endl;
		cin >> Ax;
		cout << setw(10) << "" << "Enter the y coordinate of point A: " << endl;
		cin >> Ay;
		cout << setw(10) << "" << "Enter the x coordinate of point B: " << endl;
		cin >> Bx;
		cout << setw(10) << "" << "Enter the y coordinate of point B: " << endl;
		cin >> By;
		cout << setw(10) << "" << "Enter the x coordinate of point C: " << endl;
		cin >> Cx;
		cout << setw(10) << "" << "Enter the y coordinate of point C: " << endl;
		cin >> Cy;

		a = sqrt((Cx - Bx) * (Cx - Bx) + (Cy - By) * (Cy - By));
		b = sqrt((Ax - Cx) * (Ax - Cx) + (Ay - Cy) * (Ay - Cy));
		c = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
		A = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
		B = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c));
	    C = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b));


		cout << setw(10) << "" << "The side lengths are : a = " << a << ", b = " << b << " and c = " << c << endl;
		cout << setw(10) << "" << "The angles are A = " << A << ", B = " << B << " and C = " << C << endl;

	}
	case 2:
	{
		cout << setw(10) << "" << "Enter the length of side a:" << endl;
		cin >> a;
		cout << setw(10) << "" << "Enter the length of side b:" << endl;
		cin >> b;
		cout << setw(10) << "" << "Enter the length of side c:" << endl;
		cin >> c;

		 A = toDeg(acos(((b * b + c * c - a * a)) / (2 * b * c)));
		 B = toDeg(acos(((a * a + c * c + b - b)) / (2 * a * c)));
		 C = 180 - A + B;

		cout << setw(10) << "" << "The angles are A = " << A << ", B = " << B << " and C = " << C << endl;
		
	}
	case 3:
	{
		cout << setw(10) << "" << "           A \n " << endl;
		cout << setw(10) << "" << "           /\\" << endl;
		cout << setw(10) << "" << "          /  \\" << endl;
		cout << setw(10) << "" << "         /    \\  " << endl;
		cout << setw(10) << "" << "      b /      \\ c" << endl;
		cout << setw(10) << "" << "       /        \\" << endl;
		cout << setw(10) << "" << "      /          \\" << endl;
		cout << setw(10) << "" << "     /____________\\" << endl;
		cout << setw(10) << "" << "    C       a      B" << endl;

		cout << setw(10) << "" << "Enter the length of side b: ";
		cin >> b;
		cout << setw(10) << "" << "Enter the length of side c: ";
		cin >> c;
		cout << setw(10) << "" << "Enter the size of angle A: ";
		cin >> A;

		
	    a = sqrt((b * b + c * c) - (2 * b * c * cos(angToRad(A))));
	    B = toDeg(acos(((a * a - b * b + c * c)) / (2 * a * c)));
	    C = 180 - A - B;

		cout << setw(10) << "" << "The side lengths are : a = " << a << ", b = " << b << " and c = " << c << endl;
		cout << setw(10) << "" << "The angles are A = " << A << ", B = " << B << " and C = " << C << endl;
		
	}
	case 4:
	{
		cout << setw(10) << "" << "Enter the size of angle A: " << endl;
		cin >> A;
		cout << setw(10) << "" << "Enter the size of angle B: " << endl;
		cin >> B;
		cout << setw(10) << "" << "Enter the length of side c: " << endl;
		cin >> c;

	    b = c * sin(angToRad(B)) / sin(angToRad(C));
	    a = c * sin(angToRad(A)) / sin(angToRad(C));
	    C = 180 - A - B;

		cout << setw(10) << "" << "The side lengths are : a = " << a << ", b = " << b << " and c = " << c << endl;
		cout << setw(10) << "" << "The angles are A = " << A << ", B = " << B << " and C = " << C << endl;

	}
	case 5:
	{
		cout << setw(10) << "" << "Enter the size of angle A: " << endl;
		cin >> A;
		cout << setw(10) << "" << "Enter the length of side a: " << endl;
		cin >> a;
		cout << setw(10) << "" << "Enter the length of side b: " << endl;
		cin >> b;

		if (a > b)
		{
			double B = asin(a * (sin(A * PI / 180) / b));

			double C = 180 - A - B;

			double c = b * sin(C * PI / 180) / sin(b * PI / 180);
		}

		
	}

	}
}
