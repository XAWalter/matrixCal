#ifndef MATRIX_H
#define MATRIX_H

class matrix {
private:
	int rSize;
	int cSize;
	double** value;
public:
	//constructor
	matrix(int, int);
	//destructor
	~matrix();

	//getters
	int getRSize();
	int getCSize();
	double getValue(int, int);

	//setters
	void setValue(int, int, double);

	//overloaded operators
	matrix operator+(matrix);
	matrix operator-(matrix);
	matrix operator*(matrix);

	//functions
	void printMat();

};


#endif
