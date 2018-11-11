#include "matrix.h"
#include <iostream>
#include <iomanip>


//constructor
//ZERO MATRIX??!?!?
matrix::matrix(int row, int col) {
	rSize = row;
	cSize = col;

	value = new int*[rSize];

	for (int i = 0; i < rSize; i++){
		value[i] = new int[cSize];
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
int matrix::getValue(int x, int y) {
	return value[x][y];
}

//set value of passed row and col to new value
void matrix::setValue(int x, int y, int num) {
	value[x][y] = num;
}

//add matrices together if they have the same amount of colums and rows
//else return 0 matrices
matrix matrix::operator+(matrix x) {
	matrix temp(this->getRSize(), this->getCSize());
	std::cout << "TEST" << std::endl;
	if (rSize == x.rSize && cSize == x.cSize){
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < cSize; j++) {
				temp.setValue(i,j, this->getValue(i, j) + x.getValue(i, j));
				std::cout << "TEST 2" << std::endl;
			}
		}
	}
		return temp;
}

//subtract matrices if they have the same amount of colums and rows
//else return 0 matrices
matrix matrix::operator-(matrix x) {
	matrix temp(rSize, cSize);
	if (rSize == x.rSize && cSize == x.cSize) {
		for (int i = 0; i < rSize; i++) {
			for (int j = 0; j < cSize; j++) {
				temp.setValue(i, j, this->getValue(i, j) - x.getValue(i, j));
			}
		}
	}
	return temp;
}


//print matrix
void matrix::printMat() {
	int count = 0;

	for(int i = 0; i < rSize; i++)
		for (int j = 0; j < cSize; j++)
		{
			std::cout << std::setw(10) << value[i][j];
			count++;
			if (count == cSize) {
				std::cout << std::endl;
				count = 0;
			}
		}
}