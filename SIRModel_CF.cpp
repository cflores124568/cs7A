/************************
*						*
*	  CHRIS FLORES		*
*						*
************************/

#include <iostream>
#include <vector>
#include <fstream>

void printToFile(std::ofstream&,std::vector<double>, std::vector<double>, std::vector<double>);

int main() {

	std::ofstream ofs("SIR_data.dat");
	std::vector<double> infectious, susceptible, recovered;
	double b = 0.5, k = 1.0 / 3.0;
	susceptible.push_back(1.0);
	infectious.push_back(1.27e-6);
	recovered.push_back(0);

	double deltaS = -b * susceptible[0] * infectious[0],
		deltaR = k * infectious[0],
		deltaI = -(deltaR + deltaS);
	susceptible.push_back(susceptible[0] + deltaS);
	infectious.push_back(infectious[0] + deltaI);
	recovered.push_back(recovered[0] + deltaR);
	//// insert loop here...set flag when i starts decreasing, and double days from there

	printToFile(ofs, susceptible, infectious, recovered);


}

void printToFile(std::vector<double> susceptible, std::vector<double> infectious, std::vector<double> recovered, std::ofstream ofs) {
	ofs << "Suscepible      Infectious     Recovered\n";
	for (int i = 0; i < susceptible.size(); i++) {
		ofs << susceptible[i] << ", " << infectious[i] << ", " << recovered[i] << "\n";
	}

}