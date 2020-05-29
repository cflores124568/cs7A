/*********************************
*				 *
*           CHRIS FLORES	 *
**********************************

#include <iostream>
#include <string>
#include <cmath>

const double PI = 3.14159265358979323846;

int main() {

	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, m1 = 0, m2 = 0;

	std::cout << "\n\nEnter the coordinates x1, y1, x2, y2: ";
	std::cin >> x1 >> y1 >> x2 >> y2;
	float ux = (x2 - x1);
	float uy = (y2 - y1);
	float slope = uy / ux;
	std::cout << "You entered the points: (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")\n";
	std::cout << "The slope of the line through these points is: " << slope;
	if (slope == 0) {
		std::cout << "A vertical line has no slope!";
		return 0;
	}

	float magnitude = sqrt((ux * ux) + (uy * uy));
	std::cout << "\nThis line makes the angle " << atan2(y2 - y1, x2 - x1) << " radians with the horizontal.";
	std::cout << "\nThis is equivalent to " << atan2(y2 - y1, x2 - x1) * 180 / PI;
	std::cout << "\nA unit vector parallel to this line is:  " << "(" << (ux / magnitude) << ", (" << (uy / magnitude) << ")";
	std::cout << "\nEnter the masses of the two objects at these points in kg: ";
	std::cout << "\nm1 = ";
	std::cin >> m1;
	std::cout << "m2 = ";
	std::cin >> m2;
	float gravity = 6.67e-11;
	float r = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	float force = (gravity * m1 * m2) / (r * r);
	std::cout << "The force of gravitational between these two masses is the vector
		(" << force * (ux / magnitude) << ", " << force * (uy / magnitude) << ") Newtons. ";



}
