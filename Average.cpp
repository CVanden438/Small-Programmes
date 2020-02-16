// Program to compute mean, standard deviation and standard
// error of the mean electronic charge. Data is read from file

// Includes
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<string>
#include <cmath>
using namespace std;

// Funcions
// Function to calculate mean
double getmean(double* myarray, int length){
	// Sums over the array
	double sum = 0.;
	for (int i = 0; i < length; i++){
		sum += myarray[i];
	}
	// Divides by number of points to find mean
	double mean = sum / length;
	return mean;
}
// Function to calculate standard deviation
double getsd(double* myarray, int length, double mean){
	// Sums over the array
	double sum = 0.;
	for (int i = 0; i < length; i++){
		sum += pow((myarray[i] - mean),2);
	}
	// Divides by number of points minus one to find standard deviation
	double var = sum / (length - 1);
	double sd = pow(var, 0.5);
	return sd;
}
// Start of main program
int main(){

	// Declaring variables
	string line;
	int i{ 0 };
	int j{ 0 };
	string filename;

	// Asking user for name of file
	cout << "Input name of file to open";
	cin >> filename;

	// Setting file to myfile and opening it
    fstream myfile(filename);
	// Gives error if file can not be opened and ends program
	if (!myfile.good()){
		cout << "Could not open file!";
		 return EXIT_FAILURE;
	}

	// Finds number of lines in file
	int length = 0;
	for (int i = 0; getline(myfile, line); i++){
		length++;
	}
	// Clearing and setting the point in the file back to the start
	myfile.clear();
	myfile.seekg(0, ios_base::beg);

	// Making dynamic array based on length of file
	double *myarray = new double[length];

	// Adding lines of file to array
	while (!myfile.eof()){
		myfile >> myarray[i];
		// Giving error and ignoring any lines which are invalid (not numbers)
		if (myfile.fail()){
			cerr << "Error:One of the lines in the file could not be read in" << endl;
			myfile.clear();
			myfile.ignore(1000,'\n');
			// Tallying amount of invalid data so program can ignore equivalent number of points at end of array
			j++;
		}
		else{
			i++;
		}
	}
	// Closing file now that it is done with
	myfile.close();

	// Outputting the number of valid data points aquired from file
	cout << "The number of values read in from the file is " << length - j << endl;
	// Sending array to functions to calculate mean and standard deviation from functions and standard error
	double mean = getmean(myarray, length-j);
	double sd = getsd(myarray, length-j, mean);
	double se = sd / pow(length-j, 0.5);
	// Clearing up memory used for array
	delete[] myarray;
	// Outputting the values calculated above
	cout << "The calculated mean is: " << mean << endl << "The calculated standard deviation is: " << sd << endl << "The calculated standard error is: " << se << endl;

	return 0;
}