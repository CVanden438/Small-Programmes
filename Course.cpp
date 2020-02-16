// Program to allow the user to input course codes and titles and then sort them either numerically or alphabetially
// It can also output the ones for a specified year
// Author: Chris Vanden


//Includes
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;


// Function to use when sorting by course name
bool compareStrings(string a, string b){
	// Gets rid of the part of the string before the course name
	a.erase(0, 10);
	b.erase(0, 10);
	return a < b;
}

// Function to use when sorting by course code
bool compareInts(string a, string b){
	// Getting rid of the string before and after the code
	a.erase(a.begin() + 11, a.end());
	a.erase(0, 4);
	b.erase(b.begin() + 11, b.end());
	b.erase(0, 4);
	// Turning codes into ints to compare
	int c = stoi(a);
	int d = stoi(b);
	return c < d;
}

// Start of main program
int main() {
	string inputString;
//	vector<int> codevec;
//	vector<string> namevec;
	vector<string> data;
	char flag;
	char repeat{ 'y' };
	// Getting thecourse data from the user
	do{
		// Asking the user for the course data
		cout << "Enter course code and name seperated by a space:";
		getline(cin, inputString);
		const int first{ 0 }, last{ 5 };
		// Splitting the input into the code and name sections
		string code = inputString.substr(first, last);
		string name = inputString.substr(last + 1, inputString.length());
		// Turning the code section into an int
		int intcode = stoi(code);
		// Initialising stringsteam
		stringstream ss;
		// Inserting the overall course data into the string stream
		ss << "PHYS " << intcode << ' ' << name;
		// Assigning the stringstream to the line string
		string line{ ss.str() };
		// Adding each course data element to the data vector
		data.push_back(line);
		// Clearing the string stream for next use
		ss.str("");
		cin.clear();
		// Asking user if they want to continue adding courses
		cout << "Do you want to enter another course? Type 'n' to finish or enter any key to continue" << endl;
		cin >> flag;
		cin.clear();
		cin.ignore(100, '\n');
		// Will keep repeating until user enters 'n'
	} while (flag != 'n');

	// Creating iterators
	vector<string>::iterator begin{ data.begin() }, end{ data.end() };
	vector<string>::iterator current;

	// Overall loop to allow user to continue choosing options till they opt out
	while (repeat == 'y'){
		char choice;
		// Giving the user the potential options
		cout << "Choose an option from the list below:" << endl << "1. Output course data unsorted" << endl << "2. Output course data sorted by course code" << endl <<
			"3. Output course data sorted alphabetically" << endl << "4. Output course data for a specific year" << endl << "5. End Program" << endl;
		cin >> choice;
		// Checking the user enters a valid option
		while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5'){
			cout << "Please enter a number 1-5" << endl;
			cin.clear();
			cin.ignore(80, '\n');
			cin >> choice;
		}
		// Choice 1 outputs courses in order they were inputed
		if (choice == '1'){
			for (current = begin; current < end; current++){
				cout << *current << endl;
			}
		}
		// Choice 2 sorts courses by course code
		else if (choice == '2'){
			// Uses sorting algorithm to sort the course data
			sort(begin, end, compareInts);
			// Outputting the sorted data
			for (current = begin; current < end; current++){
				cout << *current << endl;
			}
		}
		// Choice 3 sorts the courses alphabetically
		else if (choice == '3'){
			// Uses sorting algorithm to sort the data by the names
			sort(begin, end, compareStrings);
			// Outputting the sorted data
			for (current = begin; current < end; current++){
				cout << *current << endl;
			}
		}
		// Choice 4 allows the user to see only courses for a specific year
		else if (choice == '4'){
			cout << "Which year do you want data for (Choose 1-4)" << endl;
			char year;
			cin >> year;
			// Making use user inputs a vlid year
			while (year != '1' && year != '2' && year != '3' && year != '4'){
				cout << "Please enter either 1-4" << endl;
				cin.clear();
				cin.ignore(80, '\n');
				cin >> year;
			}
			// Outputting just the courses for that year
			int i = 0;
			for (current = begin; current < end; current++){
				string check;
				check = data[i];
				i++;
				if (check[5] == year){
					cout << *current << endl;
				}
			}
		}
		// Option 5 exits the program
		else if (choice == '5'){
			return EXIT_FAILURE;
		}
		// Asking th euser if they want to pick another option
		cout << "Do you want to pick another option? (y/n)" << endl;
		cin >> repeat;
		// Checking valid input
		while (repeat != 'y' && repeat != 'n'){
			cout << "Please enter either 'y' or 'n'";
			cin.clear();
			cin.ignore(80, '\n');
			cin >> repeat;
		}

	}

	return 0;
}