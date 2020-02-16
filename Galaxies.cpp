#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

// Hubble types: E[0-7], S0, S[a-c], SB[a-c], Irr
// Redshift z in range [0,10]
// Total mass M_tot in range [1e7,1e12] M_sun
// Stellar mass fraction f_* in range [0,0.05]


class galaxy{
private:
	string hubbleType;
	double redshift, totalMass, stellarMassFraction;
	vector <galaxy*> satalite;
public:
	// Default constructor
	galaxy() : hubbleType( "Default" ), redshift{ 0 }, totalMass{ 0 }, stellarMassFraction{ 0 } {};
	// Parametised constructor
	galaxy(string gType, double gredshift, double gtotalMass, double gstellarMassFraction) :
		hubbleType( gType ), redshift{ gredshift }, totalMass{ gtotalMass }, stellarMassFraction{ gstellarMassFraction }
	{};
	// Destructor
	~galaxy(){ cout << "Destroying " << hubbleType << endl;}


	void changeType(string newType){
		hubbleType = newType;
	}
	double stellarMass(){
		return(stellarMassFraction * totalMass);
	}
	void print_data();
	void addSatalite(galaxy *g){
		satalite.push_back(g);
	}
};
void galaxy::print_data(){
	cout << "The galaxy has properties [Type,Redshift,Total Mass, Stellar Mass Fraction] = [" << hubbleType << "," << redshift << "," << totalMass << 
		"," << stellarMassFraction << "]"<<endl;
	// cout << satalite.size();
	if (!satalite.empty()){
		cout << "The number of satalite galaxies is: " << satalite.size() << endl;
		vector<galaxy*>::iterator scur;
		for (scur = satalite.begin(); scur < satalite.end(); ++scur){
			cout << "The satalite has properties [Type,Redshift,Total Mass, Stellar Mass Fraction] = [" << hubbleType << "," << redshift << "," << totalMass <<
				"," << stellarMassFraction << "]" << endl;
		}
	}
}

string getType(){
	vector <string> allowedTypes{ "E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "S0", "Sa", "Sb", "Sc", "SBa", "SBb", "SBc" };
	cout << "Enter type of galaxy (allowed types are:E[0-7],S0,S[a-c],SB[a-c]" << endl;
	string gType;
	int flag{ 0 };
	cin >> gType;
	while (flag != 1){
		if (find(allowedTypes.begin(), allowedTypes.end(), gType) != allowedTypes.end()) {
			cin.clear();
			cin.ignore(80, '\n');
			flag = 1;
		}
		else {
			cout << "Please input one of the allowed types" << endl;
			cin.clear();
			cin.ignore(80, '\n');
			cin >> gType;
		}
	}
	return gType;
}
double getRedshift(){
	double gRedshift{ 100 };
	while (gRedshift < 0 || gRedshift > 10){
		cout << "Enter the redshift of the galaxy (must be in range 0-10)" << endl;
		cin >> gRedshift;
		cin.clear();
		cin.ignore(80, '\n');
	}
	return gRedshift;
}
double getTotalMass(){
	double gTotalMass{ 0 };
	while (gTotalMass < 10e7 || gTotalMass > 10e12){
		cout << "Enter the total mass of the galaxy (must be in range 10e7 - 10e12)" << endl;
		cin >> gTotalMass;
		cin.clear();
		cin.ignore(80, '\n');
	}
	return gTotalMass;
}
double getSMF(){
	double gSMF{ 1 };
	while (gSMF < 0 || gSMF > 0.05){
		cout << "Enter the stellar mass fraction of the galaxy (must be in range 0-0.05)" << endl;
		cin >> gSMF;
		cin.clear();
		cin.ignore(80, '\n');
	}
	return gSMF;
}
int main(){
	// Using default
	galaxy* g1 = new galaxy();
	g1->print_data();


	// Vector storing galaxies
	vector<galaxy*> galaxy_data;

//	cout << "Enter the number of galaxies you wish to input" << endl;
//	int gNum;
//	cin >> gNum;

//	string gType;
//	double gRedshift{ 0 };
//	double gTotalMass{ 0 };
//	double gStellarMassFraction{ 1 };
//	for (int i = 0; i < gNum; i++){
//		getData();
//		galaxy* g = new galaxy(gType, gRedshift, gTotalMass, gStellarMassFraction);
//		galaxy_data.push_back(g);
//	}
	galaxy* g2 = new galaxy("E0", 2, 1e7, 0.01);
	galaxy* g3 = new galaxy("Sa", 5, 2e7, 0.02);
	galaxy_data.push_back(g2);
	galaxy_data.push_back(g3);

	vector<galaxy*>::iterator gcur;
	for (gcur = galaxy_data.begin(); gcur < galaxy_data.end(); ++gcur){
		(*gcur)->print_data();
	}

	cout << "Example of changing hubble type:" << endl;
	g2->changeType("Irr");
	g2->print_data();


	// Satalites
	cout << "Enter the number of satalite galaxies you wish to input" << endl;
	int gNum;
	cin >> gNum;
	string gType;
	double gRedshift{ 0 };
	double gTotalMass{ 0 };
	double gStellarMassFraction{ 1 };
	for (int i = 0; i < gNum; i++){
		string gType = getType();
		double gRedshift = getRedshift();
		double gTotalMass = getTotalMass();
		double gSMF = getSMF();
		galaxy *g = new galaxy(gType, gRedshift, gTotalMass, gSMF);
		g->addSatalite(g);
	}
	for (gcur = galaxy_data.begin(); gcur < galaxy_data.end(); ++gcur){
		(*gcur)->print_data();
	}
	return 0;
}