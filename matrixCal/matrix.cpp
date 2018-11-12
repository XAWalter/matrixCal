#include "matrix.h"
#include <iostream>
#include <iomanip>


//constructor
//ZERO MATRIX??!?!?
matrix::matrix(int row, int col) {
	rSize = row;
	cSize = col;

	value = new double*[rSize];

	for (int i = 0; i < rSize; i++){
		value[i] = new double[cSize];
	}
	
	int count = 1;
	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < cSize; j++) {
			value[i][j] = count;
			count++;
		}
	}
}

//destructor
matrix::~matrix() {
	//for (int i = 0; i < this->getRSize(); i++) {
	//	delete value[i];
	//}
	//delete value;
}


//return the number of rows
int matrix::getRSize() {
	return rSize;
}


//return the number of cols
int matrix::getCSize() {
	return cSize;
}

//pass which row and col
//return the value in passed row and col
double matrix::getValue(int x, int y) {
	return value[x][y];
}

//set value of passed row and col to new value
void matrix::setValue(int x, int y, double num) {
	value[x][y] = num;
}

//add matrices together if they have the same amount of colums and rows
//else return 0 matrices
matrix matrix::operator+(matrix x) {
	matrix temp(this->getRSize(), this->getCSize());
	if (this->getRSize() == x.getRSize() && this->getCSize() == x.getCSize()){
		for (int i = 0; i < this->getRSize(); i++) {
			for (int j = 0; j < this->getCSize(); j++) {
				temp.setValue(i,j, this->getValue(i, j) + x.getValue(i, j));
			}
		}
	}
		return temp;
}

//subtract matrices if they have the same amount of colums and rows
//else return 0 matrices
matrix matrix::operator-(matrix x) {
	matrix temp(this->getRSize(), this->getCSize());
	if (this->getRSize() == x.getRSize() && this->getCSize() == x.getCSize()) {
		for (int i = 0; i < this->getRSize(); i++) {
			for (int j = 0; j < this->getCSize(); j++) {
				temp.setValue(i, j, this->getValue(i, j) - x.getValue(i, j));
			}
		}
	}
	return temp;
}


//use the * operator to carry out matrices multiplication
matrix matrix::operator*(matrix x) {
	matrix temp(this->getCSize(), x.getRSize());
	double tempN = 0;

	if (this->getCSize() == x.getRSize())
	{
		for (int i = 0; i < this->getRSize(); i++){
			for (int j = 0; j < x.getCSize(); j++){
				for (int k = 0; k < this->getCSize(); k++)
				{
					tempN = tempN + (this->getValue(i, k) * x.getValue(k, j));
				}
				temp.setValue(i, j, tempN);
				tempN = 0;
			}
		}
	}
	return temp;
}

//print matrix
void matrix::printMat() {
	int count = 0;

	for(int i = 0; i < this->getRSize(); i++)
		for (int j = 0; j < this->getCSize(); j++)
		{
			std::cout << std::setw(10) << this->getValue(i,j);
			count++;
			if (count == this->getCSize()) {
				std::cout << std::endl;
				count = 0;
			}
		}
}