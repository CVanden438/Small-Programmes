// Program to store 2d and 3d shapes and print out the area / area and volume of them
// Author: Chris Vanden

// Includes
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

// Base shape class as interface
class shape
{
public:
	// Virtual functions
	virtual ~shape(){}
	virtual void info() = 0;
	virtual void setarea() = 0;
	virtual void setvol() = 0;
	virtual double getarea() = 0;
};
// Abstract class for 2d shapes
class twod : public shape
{
protected:
	double area;
	double volume;
public:
	virtual ~twod(){}
	void setvol(){ volume = 0; };
};
// Abstract class for 3d shapes
class threed : public shape
{
protected:
	double volume;
	double area;
public:
	virtual ~threed(){}
	double getarea(){ return 0; }
};
// Class for rectangles
class rectangle : public twod
{
private:
	double length;
	double width;
public:
	rectangle(double l, double w) : length(l), width(w) {}
	// Function to set area
	void setarea(){ area = length*width; }
	// Function to print out data
	void info(){ cout << "Rectuangle area : " << area << endl; }
	double getarea(){ return area; }
	~rectangle(){}
};
class square : public twod
{
private:
	double length;
public:
	square(double l) : length(l) {}
	// Function to set area
	void setarea(){ area = length*length; };
	// Function to print out data
	void info(){ cout << "Square area : " << area << endl; }
	double getarea(){ return area; }
	~square(){}
};
class circle : public twod
{
private:
	double radius;
public:
	circle(double r) : radius(r) {}
	// Function to set area
	void setarea(){ area = 3.14159*radius*radius; }
	// Function to print out data
	void info(){ cout << "Circle area : " << area << endl; }
	double getarea(){ return area; }
	~circle(){}
};
class ellipse : public twod
{
private:
	double major;
	double minor;
public:
	ellipse(double ma, double mi) : major(ma), minor(mi) {}
	// Function to set area
	void setarea(){ area = 3.14159*major*minor; }
	// Function to print out data
	void info(){ cout << "Ellipse area : " << area << endl; }
	double getarea(){ return area; }
	~ellipse(){}
};
class cuboid : public threed
{
private:
	double length; double width; double depth;
public:
	cuboid(double l, double w, double d) : length(l), width(w), depth(d) {}
	// Function to set volume
	void setvol(){ volume = length*width*depth; }
	// Function to set area
	void setarea(){ area = 4 * length * width + 2 * depth * width; }
	// Function to print out data
	void info(){ cout << "Cuboid volume : " << volume << endl << "Cuboid surface area : " << area << endl; }
	~cuboid(){}
};
class cube : public threed
{
private:
	double length;
public:
	cube(double l) : length(l) {}
	// Function to set volume
	void setvol(){ volume = length*length*length; }
	// Function to set area
	void setarea(){ area = 6 * length * length; }
	// Function to print out data
	void info(){ cout << "Cube volume : " << volume << endl << "Cube surface area : " << area << endl; }
	~cube(){}
};
class ellipsoid : public threed
{
private:
	double a; double b; double c;
public:
	ellipsoid(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {}
	// Function to set volume
	void setvol(){ volume = 4 / 3 * 3.14159*a*b*c; }
	// Function to set area
	void setarea(){
		double temp1 = pow(a*b, 1.6); double temp2 = pow(a*c, 1.6); double temp3 = pow(b*c, 1.6);
		area = 4 * 3.14159 * pow(temp1*temp2*temp3 / 3, 0.625);
	}
	// Function to print out data
	void info(){ cout << "Ellipsoid volume : " << volume << endl << "Elipsoid surface area : " << area << endl; }
	~ellipsoid(){}
};
class sphere : public threed
{
private:
	double radius;
public:
	sphere(double r) : radius(r) {}
	// Function to set volume
	void setvol(){ volume = 4 / 3 * 3.14159 * radius*radius*radius; }
	// Function to set area
	void setarea(){ area = 4 * 3.14159 * radius * radius; }
	// Function to print out data
	void info(){ cout << "Sphere volume : " << volume << endl << "Sphere surface area : " << area << endl; }
	~sphere(){}
};
// Prism class
class prism : public threed
{
private:
	double depth;
	vector<shape*> point;
public:
	prism(double d, vector<shape*> p) : depth(d), point(p) {}
	// Function to set volume
	void setvol(){
		// Sets area as area of 2d shape which pointer is pointing to
		area = point[0]->getarea();
		volume = depth * area;
	}
	void setarea(){ area = 0; }
	void info(){ cout << "Prism volume : " << volume << endl; }
	~prism(){}
};
int main(){
	// Base class pointer
	vector<shape*> shape_vector;
	// Making the 4 2d shapes
	cout << "2D Shapes\n";
	shape_vector.push_back(new rectangle(2, 2));
	shape_vector.push_back(new square(5));
	shape_vector.push_back(new circle(10));
	shape_vector.push_back(new ellipse(4, 5));
	// Setting data and printing it out
	shape_vector[0]->setarea();
	shape_vector[0]->info();
	shape_vector[1]->setarea();
	shape_vector[1]->info();
	shape_vector[2]->setarea();
	shape_vector[2]->info();
	shape_vector[3]->setarea();
	shape_vector[3]->info();
	// Making the 4 3d shapes
	cout << "3D Shapes\n";
	shape_vector.push_back(new cuboid(1, 2, 3));
	shape_vector.push_back(new cube(4));
	shape_vector.push_back(new ellipsoid(1, 2, 3));
	shape_vector.push_back(new sphere(6));
	// Setting data and printing it out
	shape_vector[4]->setvol();
	shape_vector[4]->setarea();
	shape_vector[4]->info();
	shape_vector[5]->setvol();
	shape_vector[5]->setarea();
	shape_vector[5]->info();
	shape_vector[6]->setvol();
	shape_vector[6]->setarea();
	shape_vector[6]->info();
	shape_vector[7]->setvol();
	shape_vector[7]->setarea();
	shape_vector[7]->info();
	// Making a prism
	prism p1 = prism(5, shape_vector);
	// Setting volume and printing it out
	p1.setvol();
	p1.info();
	// Cleaning up
	for (auto shape_vectorit = shape_vector.begin();
		shape_vectorit<shape_vector.end();
		++shape_vectorit) delete *shape_vectorit;
	shape_vector.clear();
	return 0;
}