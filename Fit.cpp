// Programme to read in data in the form X,Y,Error and calculate error weighted line of best fit and Chi-Sq
// Author: Chris Vanden

// includes
#include<iostream>
#include<fstream>

// namespace shortcut
using namespace std;

// define my own data structure
struct point {
	double x;
	double y;
	double s;
};

// main program
int main() {
	// declare variables
	int i = 0;
	int n = 0;
	double Swx, Swy, Swxy, Sw, Swxx, SwxSqr, m, c, risSq;
	double Swxtot, Swytot, Swxytot, Swxxtot, SwxtotSqr, Swtot, ChiSq;
	Swxtot = 0;
	Swytot = 0;
	Swxytot = 0;
	Swtot = 0;
	Swxxtot = 0;
	SwxtotSqr = 0;
	ChiSq = 0;
	// array of point structures to hold the data
	point thePoints[1000];

	// open a file to read in
	ifstream theFile("XYSData.txt");

	// check if it opened successfully
	if (theFile.is_open()) {
		// file is open
		// read it in
		while (!theFile.eof()) {
			// not at end of file
			theFile >> thePoints[i].x >> thePoints[i].y >> thePoints[i].s;
			// increment i
			i++; // i = i + 1
		}
		theFile.close(); // close the file
	}
	else {
		// something went wrong
		cout << "Error opening file!\n";
		// die
		exit(1);
	}
	// loops through data points, calculating various sums to use to find m, c and ChiSq later on
	for (int j = 0; j < i; j++) {
		Swx = thePoints[j].x / pow(thePoints[j].s, 2);
		Swxtot = Swxtot + Swx;
		Swy = thePoints[j].y / pow(thePoints[j].s, 2);
		Swytot = Swytot + Swy;
		Swxy = thePoints[j].x * thePoints[j].y / pow(thePoints[j].s, 2);
		Swxytot = Swxytot + Swxy;
		Sw = 1 / pow(thePoints[j].s, 2);
		Swtot = Swtot + Sw;
		Swxx = pow(thePoints[j].x, 2) / pow(thePoints[j].s, 2);
		Swxxtot = Swxxtot + Swxx;
	}
	SwxtotSqr = pow(Swxtot, 2);

	// Calculating the weighted line of best fit
	double D = Swtot * Swxxtot - SwxtotSqr;
	m = (Swtot * Swxytot - Swxtot*Swytot) / D;
	double dm = pow(Swtot / D, 0.5);
	c = (Swytot * Swxxtot - Swxtot * Swxytot) / D;
	double dc = pow(Swxxtot / D, 0.5);
	// Calculating ChiSq
	for (int k = 0; k < i; k++) {
		risSq = pow(thePoints[k].x * m + c - thePoints[k].y, 2) / pow(thePoints[k].s, 2);
		ChiSq = ChiSq + risSq;
	}

	// writes out the weighted line of best fir with errors and the value of ChiSq
	printf("Error-weighted line of best fit = %8.6f+-%8.6f x + %8.6f+-%8.6f\n", m, dm, c, dc);
	printf("The Chi-squared value of this fit is %8.6f\n", ChiSq);

	return 0;
}



